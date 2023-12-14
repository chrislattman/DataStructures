#pragma once

#include <string>

/// @brief Abstract class (used as an interface) which defines methods for sets.
///
/// @tparam T data type
template<typename T>
class MySet {
    public:
        /// @brief Inserts an element into this set if it is not already there.
        ///
        /// @param element element to add
        /// @return true if element was not present, false otherwise
        virtual bool add(const T &element) = 0;

        /// @brief Empties this set of all elements.
        virtual void clear() = 0;

        /// @brief Checks if an element is in this set.
        ///
        /// @param element element to check for
        /// @return true if found, false otherwise
        virtual bool contains(const T &element) = 0;

        /// @brief Checks if this set has no elements.
        ///
        /// @return true if this set is empty, false otherwise
        virtual bool isEmpty() = 0;

        /// @brief Removes an element from this set.
        ///
        /// @param element element to remove
        /// @return true if element found, false otherwise
        virtual bool remove(const T &element) = 0;

        /// @brief Returns the number of elements in this set.
        ///
        /// @return size of set
        virtual int size() = 0;

        /// @brief Returns an array containing all the elements in this set.
        ///
        /// @return array of set elements
        virtual T *toArray() = 0;

        /// @brief Returns a string representation of this set, e.g. "[element1, element2, element3, ..., elementN]".
        ///
        /// @return string form of this set
        virtual std::string toString() = 0;
};
