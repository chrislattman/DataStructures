#pragma once

#include <cstring>
#include <sstream>

#include "myarraylist.hpp"
#include "mymap.h"

using namespace std;

/**
 * Implementations need to be in this header file due to generic templates.
 * Otherwise you could leave method signatures here and implement the
 * functions in a .cpp file like:
 *
 * template<typename K, typename V>
 * return-type MyHashMap<K, V>::method(args) {
 *     ...
 * }
 */

/// @brief A hash map data structure utilizing quadratic probing (open addressing). Also called a hash table.
///
/// @tparam K key data type
/// @tparam V value data type
/// @tparam Hash hash function used for keys
template<typename K, typename V, class Hash = hash<K>>
class MyHashMap: public MyMap<K, V> {
private:
    K *keys;
    V *value_array;
    unsigned int map_size, map_length;
    float loadFactor;
    static const unsigned int defaultCapacity = 16;
    static constexpr float defaultLoadFactor = 0.75F;

    /// @brief Internal function used to add or modify a key-value pair in this map.
    ///
    /// @param key key to add
    /// @param newValue value to be associated with key
    /// @param oldValue current value to check for (existing key only), leave as NULL if not applicable
    /// @param addOnlyIfAbsent if false, replace current value with specified new value
    /// @param addOnlyIfKeyExists if true, only replace value if key already exists
    /// @return previous or current value associated with key, or NULL if either key was not found, key is NULL,
    /// or newValue is NULL
    V insert(const K &key, const V &newValue, const V &oldValue, bool addOnlyIfAbsent, bool addOnlyIfKeyExists) {
        if (key == K(NULL) || newValue == V(NULL)) {
            return V(NULL);
        }
        if (map_length == 0) {
            clear();
        } else if ((float) map_size > loadFactor * map_length) {
            resizeMap();
            return insert(key, newValue, oldValue, addOnlyIfAbsent, addOnlyIfKeyExists);
        }
        unsigned int hash_value = (unsigned int) Hash{}(key);
        for (unsigned int i = 0; i < map_length; i++) {
            unsigned int mapIndex = (hash_value + i*i) % map_length;
            K currentKey = keys[mapIndex];
            if (currentKey == K(NULL)) {
                if (!addOnlyIfKeyExists) {
                    keys[mapIndex] = key;
                    value_array[mapIndex] = newValue;
                    ++map_size;
                }
                return V(NULL);
            }
            if (currentKey == key) {
                V previous = value_array[mapIndex];
                if ((oldValue == V(NULL) || oldValue == previous) && !addOnlyIfAbsent) {
                    value_array[mapIndex] = newValue;
                } else if (oldValue != V(NULL)) {
                    return V(NULL);
                }
                return previous;
            }
        }
        // Needed if loadFactor == 1
        resizeMap();
        return insert(key, newValue, oldValue, addOnlyIfAbsent, addOnlyIfKeyExists);
    }

    /// @brief Increases the map size and rehashes the key-value pairs when load factor has been surpassed.
    void resizeMap() {
        K *keysCopy = new K[map_length];
        V *valuesCopy = new V[map_length];
        memcpy(keysCopy, keys, map_length * sizeof(K));
        memcpy(valuesCopy, value_array, map_length * sizeof(V));
        K *newKeys = new K[map_length * 2];
        V *newValues = new V[map_length * 2];
        delete[] keys;
        delete[] value_array;
        keys = newKeys;
        value_array = newValues;
        for (unsigned int i = 0; i < map_length; i++) {
            put(keysCopy[i], valuesCopy[i]);
        }
        delete[] keysCopy;
        delete[] valuesCopy;
        map_length *= 2;
    }

public:
    /// @brief Constructs a hash map instance with the specified initial capacity and load factor.
    ///
    /// @param initialCapacity initial capacity of this hash map
    /// @param loadFactor maximum value of (number of key-value pairs / number of total slots in hash map) before
    /// rehashing occurs
    MyHashMap(unsigned int initialCapacity, float loadFactor) {
        if (loadFactor <= 0) {
            throw invalid_argument("Load factor is nonpositive");
        }
        keys = new K[initialCapacity];
        value_array = new V[initialCapacity];
        this->loadFactor = loadFactor;
        map_length = initialCapacity;
        map_size = 0;
    }

    /// @brief Constructs a hash map instance with the specified initial capacity and a default load factor of 0.75.
    ///
    /// @param initialCapacity initial capacity of this hash map
    MyHashMap(unsigned int initialCapacity): MyHashMap(initialCapacity, defaultLoadFactor) {}

    /// @brief Constructs a hash map instance with a default initial capacity of 16 and a default load factor of 0.75.
    MyHashMap(): MyHashMap(defaultCapacity, defaultLoadFactor) {}

    /// @brief Frees dynamically allocated resources.
    virtual ~MyHashMap() {
        delete[] keys;
        delete[] value_array;
    }

    /// @brief Empties this map of all key-value pairs.
    void clear() {
        delete[] keys;
        delete[] value_array;
        keys = new K[defaultCapacity];
        value_array = new V[defaultCapacity];
        map_length = defaultCapacity;
        map_size = 0;
    }

    /// @brief Checks if a key is in this map.
    ///
    /// @param key key to check for
    /// @return true if key was found, false otherwise
    bool containsKey(const K &key) const {
        return getOrDefault(key, V(NULL)) != V(NULL);
    }

    /// @brief Checks if a value is in this map.
    ///
    /// @param value value to check for
    /// @return true if value was found, false otherwise
    bool containsValue(const V &value) const {
        for (unsigned int i = 0; i < map_length; i++) {
            if (value == value_array[i]) {
                return true;
            }
        }
        return false;
    }

    /// @brief Compares an object with this map for equality.
    ///
    /// @param map object to compare to this map
    /// @return true if object and this map are equal
    bool operator==(const MyHashMap<K, V> &map) const {
        if (&map == this) {
            return true;
        }
        if (map.size() != map_size) {
            return false;
        }
        MyList<K> *other_keys = map.keyList();
        MyList<V> *other_values = map.values();
        bool retval = false;
        if (other_keys == keyList() && other_values == values()) {
            retval = true;
        }
        delete other_keys;
        delete other_values;
        return retval;
    }

    /// @brief Returns the value associated with the specified key.
    ///
    /// @param key key to search for
    /// @return value associated with key, or NULL if key was not found
    V get(const K &key) const {
        return getOrDefault(key, V(NULL));
    }

    /// @brief Returns the value associated with the specified key.
    /// Can also be used to modify the hash map.
    ///
    /// @param key key to search for
    /// @return value associated with key, or NULL if key was not found
    V& operator[](const K &key) {
        if (key == K(NULL)) {
            return V(NULL);
        }
        unsigned int hash = (unsigned int) Hash{}(key);
        for (unsigned int i = 0; i < map_length; i++) {
            unsigned int mapIndex = (hash + i*i) % map_length;
            K currentKey = keys[mapIndex];
            if (key == currentKey) {
                return value_array[mapIndex];
            }
            if (currentKey == K(NULL) && value_array[mapIndex] == V(NULL)) {
                return V(NULL);
            }
        }
        return V(NULL);
    }

    /// @brief Returns the value associated with the specified key, or a default value if they key was not found.
    ///
    /// @param key key to search for
    /// @param defaultValue value to return if key was not found in this map
    /// @return value associated with key, or defaultValue if key was not found
    V getOrDefault(const K &key, const V &defaultValue) const {
        if (key == K(NULL)) {
            return V(NULL);
        }
        unsigned int hash = (unsigned int) Hash{}(key);
        for (unsigned int i = 0; i < map_length; i++) {
            unsigned int mapIndex = (hash + i*i) % map_length;
            K currentKey = keys[mapIndex];
            if (key == currentKey) {
                return value_array[mapIndex];
            }
            if (currentKey == K(NULL) && value_array[mapIndex] == V(NULL)) {
                return defaultValue;
            }
        }
        return defaultValue;
    }

    /// @brief Checks if this map has no key-value pairs.
    ///
    /// @return true if this map is empty, false otherwise
    bool isEmpty() const {
        return map_size == 0;
    }

    /// @brief Returns a copy of the keys in this map.
    ///
    /// @return a list of the keys
    MyList<K> *keyList() const {
        MyList<K> *list = new MyArrayList<K>();
        for (unsigned int i = 0; i < map_length; i++) {
            if (keys[i] != K(NULL)) {
                list->add(keys[i]);
            }
        }
        return list;
    }

    /// @brief Inserts a key-value pair into this map. Null keys and NULL values are not permitted.
    ///
    /// @param key key to add
    /// @param value value associated with key
    /// @return previous value associated with key, or NULL if either key was not found, key is NULL, or value is NULL
    V put(const K &key, const V &value) {
        return insert(key, value, V(NULL), false, false);
    }

    /// @brief Inserts a key-value pair into this map only if key was not found. Null keys and NULL values are not permitted.
    ///
    /// @param key key to add
    /// @param value value associated with key
    /// @return current value associated with key, or NULL if either key was not found, key is NULL, or value is NULL
    V putIfAbsent(const K &key, const V &value) {
        return insert(key, value, V(NULL), true, false);
    }

    /// @brief Removes a key-value pair from this map.
    ///
    /// @param key key to remove
    /// @return value associated with key prior to removal, or NULL if key was not found
    V remove(const K &key) {
        if (key == K(NULL)) {
            return V(NULL);
        }
        unsigned int hash = (unsigned int) Hash{}(key);
        for (unsigned int i = 0; i < map_length; i++) {
            unsigned int mapIndex = (hash + i*i) % map_length;
            K currentKey = keys[mapIndex];
            if (key == currentKey) {
                keys[mapIndex] = K(NULL);
                --map_size;
                return value_array[mapIndex];
            }
            if (currentKey == K(NULL) && value_array[mapIndex] == V(NULL)) {
                return V(NULL);
            }
        }
        return V(NULL);
    }

    /// @brief Removes a key-value pair from this map only if the key's current value matches the specified value.
    ///
    /// @param key key to remove
    /// @param value value to check for
    /// @return true if the specific key-value pair was found, false otherwise
    bool remove(const K &key, const V &value) {
        if (key == K(NULL) || value == V(NULL)) {
            return false;
        }
        unsigned int hash = (unsigned int) Hash{}(key);
        for (unsigned int i = 0; i < map_length; i++) {
            unsigned int mapIndex = (hash + i*i) % map_length;
            K currentKey = keys[mapIndex];
            V currentValue = value_array[mapIndex];
            if (key == currentKey && value == currentValue) {
                keys[mapIndex] = K(NULL);
                --map_size;
                return true;
            }
            if (currentKey == K(NULL) && currentValue == V(NULL)) {
                return false;
            }
        }
        return false;
    }

    /// @brief Replaces the value for a key with another value. Null values are not permitted.
    ///
    /// @param key key to modify value of
    /// @param value new value for key
    /// @return previous value associated with key, or NULL if key was not found or value is NULL
    V replace(const K &key, const V &value) {
        return insert(key, value, V(NULL), false, true);
    }

    /// @brief Replaces the value for a key only if the key's current value matches the specified old value.
    /// Null values are not permitted.
    ///
    /// @param key key to modify value of
    /// @param oldValue old value for key
    /// @param newValue new value for key
    /// @return true if the key was found and had a value of oldValue, false otherwise
    bool replace(const K &key, const V &oldValue, const V &newValue) {
        return insert(key, newValue, oldValue, false, true) != V(NULL);
    }

    /// @brief Returns the number of key-value pairs in this map.
    ///
    /// @return size of map
    unsigned int size() const {
        return map_size;
    }

    /// @brief Returns a string representation of this map, e.g. "{key1=value1, key2=value2, key3=value3, ..., keyN=valueN}".
    ///
    /// @return string form of this map
    string toString() const {
        stringstream builder;
        builder << "{";
        for (unsigned int i = 0; i < map_length; i++) {
            K currentKey = keys[i];
            if (currentKey != K(NULL)) {
                builder << currentKey;
                builder << "=";
                builder << value_array[i];
                builder << ", ";
            }
        }
        string result = builder.str();
        if (map_size > 0) {
            result.erase(result.length() - 2, 2);
        }
        result += "}";
        return result;
    }

    /// @brief Returns a copy of the values in this map.
    ///
    /// @return a list of the values
    MyList<V> *values() const {
        MyList<V> *list = new MyArrayList<V>();
        for (unsigned int i = 0; i < map_length; i++) {
            if (value_array[i] != V(NULL)) {
                list->add(value_array[i]);
            }
        }
        return list;
    }
};

/// @brief Prints out the hash map without needing to manually call toString().
///
/// @tparam K key data type
/// @tparam V value data type
/// @param str ostream
/// @param list hash map to print out
/// @return updated ostream
template<typename K, typename V>
ostream& operator<<(ostream &str, const MyHashMap<K, V> &map) {
    return str << map.toString();
}
