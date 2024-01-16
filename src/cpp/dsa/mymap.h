#pragma once

#include "mylist.h"
#include <string>

/// @brief Abstract class (used as an interface) which defines methods for maps.
///
/// @tparam K key data type
/// @tparam V value data type
template<typename K, typename V>
class MyMap {
    public:
        /// @brief Empties this map of all key-value pairs.
        virtual void clear() = 0;

        /// @brief Checks if a key is in this map.
        ///
        /// @param key key to check for
        /// @return true if key was found, false otherwise
        virtual bool containsKey(const K &key) const = 0;

        /// @brief Checks if a value is in this map.
        ///
        /// @param value value to check for
        /// @return true if value was found, false otherwise
        virtual bool containsValue(const V &value) const = 0;

        /// @brief Returns the value associated with the specified key.
        ///
        /// @param key key to search for
        /// @return value associated with key, or NULL if key was not found
        virtual V get(const K &key) const = 0;

        /// @brief Returns the value associated with the specified key, or a default value if the key was not found.
        ///
        /// @param key key to search for
        /// @param defaultValue value to return if key was not found in this map
        /// @return value associated with key, or defaultValue if key was not found
        virtual V getOrDefault(const K &key, const V &defaultValue) const = 0;

        /// @brief Checks if this map has no key-value pairs.
        ///
        /// @return true if this map is empty, false otherwise
        virtual bool isEmpty() const = 0;

        /// @brief Returns a copy of the keys in this map.
        ///
        /// @return a list of the keys
        virtual MyList<K> *keyList() const = 0;

        /// @brief Inserts a key-value pair into this map. Null keys and NULL values are not permitted.
        ///
        /// @param key key to add
        /// @param value value associated with key
        /// @return previous value associated with key, or NULL if either key was not found, key is NULL, or value is NULL
        virtual V put(const K &key, const V &value) = 0;

        /// @brief Inserts a key-value pair into this map only if key was not found. Null keys and NULL values are not permitted.
        ///
        /// @param key key to add
        /// @param value value associated with key
        /// @return current value associated with key, or NULL if either key was not found, key is NULL, or value is NULL
        virtual V putIfAbsent(const K &key, const V &value) = 0;

        /// @brief Removes a key-value pair from this map.
        ///
        /// @param key key to remove
        /// @return value associated with key prior to removal, or NULL if key was not found
        virtual V remove(const K &key) = 0;

        /// @brief Removes a key-value pair from this map only if the key's current value matches the specified value.
        ///
        /// @param key key to remove
        /// @param value value to check for
        /// @return true if the specific key-value pair was found, false otherwise
        virtual bool remove(const K &key, const V &value) = 0;

        /// @brief Replaces the value for a key with another value. Null values are not permitted.
        ///
        /// @param key key to modify value of
        /// @param value new value for key
        /// @return previous value associated with key, or NULL if key was not found or value is NULL
        virtual V replace(const K &key, const V &value) = 0;

        /// @brief Replaces the value for a key only if the key's current value matches the specified old value.
        /// Null values are not permitted.
        ///
        /// @param key key to modify value of
        /// @param oldValue old value for key
        /// @param newValue new value for key
        /// @return true if the key was found and had a value of oldValue, false otherwise
        virtual bool replace(const K &key, const V &oldValue, const V &newValue) = 0;

        /// @brief Returns the number of key-value pairs in this map.
        ///
        /// @return size of map
        virtual int size() const = 0;

        /// @brief Returns a string representation of this map, e.g. "{key1=value1, key2=value2, key3=value3, ..., keyN=valueN}".
        ///
        /// @return string form of this map
        virtual std::string toString() const = 0;

        /// @brief Returns a copy of the values in this map.
        ///
        /// @return a list of the values
        virtual MyList<V> *values() const = 0;
};
