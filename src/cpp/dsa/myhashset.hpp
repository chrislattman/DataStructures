#pragma once

#include <sstream>

#include "myhashmap.hpp"
#include "mylist.h"
#include "myset.h"

using namespace std;

/**
 * Implementations need to be in this header file due to generic templates.
 * Otherwise you could leave method signatures here and implement the
 * functions in a .cpp file like:
 *
 * template<typename T>
 * return-type MyHashSet<T>::method(args) {
 *     ...
 * }
 */

/// @brief A hash set data structure built upon a hash map.
///
/// @tparam T data type
template<typename T>
class MyHashSet: public MySet<T> {
private:
    MyHashMap<T, int> *map;
    static const unsigned int defaultCapacity = 16;
    static constexpr float defaultLoadFactor = 0.75F;

public:
    /// @brief Constructs a hash set instance with the specified initial capacity and load factor.
    ///
    /// @param initialCapacity initial capacity of this hash set
    /// @param loadFactor maximum value of (number of elements / number of total slots in hash set) before rehashing
    /// occurs
    MyHashSet(unsigned int initialCapacity, float loadFactor) {
        map = new MyHashMap<T, int>(initialCapacity, loadFactor);
    }

    /// @brief Constructs a hash set instance with the specified initial capacity and a default load factor of 0.75.
    ///
    /// @param initialCapacity initial capacity of this hash set
    MyHashSet(unsigned int initialCapacity): MyHashSet(initialCapacity, defaultLoadFactor) {}

    /// @brief Constructs a hash set instance with a default initial capacity of 16 and a default load factor of 0.75.
    MyHashSet(): MyHashSet(defaultCapacity, defaultLoadFactor) {}

    /// @brief Frees dynamically allocated resources.
    ~MyHashSet() {
        delete map;
    }

    /// @brief Inserts an element into this set if it is not already there.
    ///
    /// @param element element to add
    /// @return true if element was not present, false otherwise
    bool add(const T &element) {
        unsigned int currentSize = map->size();
        map->putIfAbsent(element, 0);
        unsigned int newSize = map->size();
        return currentSize != newSize;
    }

    /// @brief Empties this set of all elements.
    void clear() {
        map->clear();
    }

    /// @brief Checks if an element is in this set.
    ///
    /// @param element element to check for
    /// @return true if found, false otherwise
    bool contains(const T &element) const {
        return map->containsKey(element);
    }

    /// @brief Compares an object with this set for equality.
    ///
    /// @param set object to compare to this set
    /// @return true if object and this set are equal
    bool operator==(const MyHashSet<T> &set) const {
        if (&set == this) {
            return true;
        }
        if (set.size() != size()) {
            return false;
        }
        T *elements = set.toArray();
        T *array = toArray();
        unsigned int array_length = size();
        for (unsigned int i = 0; i < array_length; i++) {
            if (elements[i] != array[i]) {
                return false;
            }
        }
        return true;
    }

    /// @brief Checks if this set has no elements.
    ///
    /// @return true if this set is empty, false otherwise
    bool isEmpty() const {
        return map->isEmpty();
    }

    /// @brief Removes an element from this set.
    ///
    /// @param element element to remove
    /// @return true if element found, false otherwise
    bool remove(const T &element) {
        return map->remove(element) != T(NULL);
    }

    /// @brief Returns the number of elements in this set.
    ///
    /// @return size of set
    unsigned int size() const {
        return map->size();
    }

    /// @brief Returns an array containing all the elements in this set.
    ///
    /// @return array of set elements
    T *toArray() const {
        MyList<T> *keys = map->keyList();
        unsigned int array_length = size();
        T *array = new T[array_length];
        for (unsigned int i = 0; i < array_length; i++) {
            array[i] = keys->get(i);
        }
        return array;
    }

    /// @brief Returns a string representation of this set, e.g. "[element1, element2, element3, ..., elementN]".
    ///
    /// @return string form of this set
    string toString() const {
        MyList<T> *keys = map->keyList();
        stringstream builder;
        builder << "[";
        unsigned int length = size();
        long lastIndex = (long)length - 1;
        for (unsigned int i = 0; i < length; i++) {
            builder << keys->get(i);
            if ((long)i != lastIndex) {
                builder << ", ";
            }
        }
        builder << "]";
        return builder.str();
    }
};

/// @brief Prints out the hash set without needing to manually call toString().
///
/// @tparam T data type
/// @param str ostream
/// @param list hash set to print out
/// @return updated ostream
template<typename T>
ostream& operator<<(ostream &str, const MyHashSet<T> &set) {
    return str << set.toString();
}
