#pragma once

#include <string>

/// @brief Abstract class (used as an interface) which defines methods for lists.
///
/// @tparam T data type
template<typename T>
class MyList {
    public:
        /// @brief Frees dynamically allocated resources.
        virtual ~MyList() {};

        /// @brief Inserts an element at the specified index.
        ///
        /// @param index index to add element
        /// @param element element to add
        virtual void add(int index, const T &element) = 0;

        /// @brief Inserts an element at the end of this list.
        ///
        /// @param element element to add
        virtual void add(const T &element) = 0;

        /// @brief Empties this list of all elements.
        virtual void clear() = 0;

        /// @brief Checks if an element is in this list.
        ///
        /// @param element element to check for
        /// @return true if found, false otherwise
        virtual bool contains(const T &element) const = 0;

        /// @brief Retrieves, but does not remove, an element from this list at the specified index.
        ///
        /// @param index index to retrieve element from
        /// @return element found
        virtual T get(int index) const = 0;

        /// @brief Returns the index of the first occurrence of an element found in this list.
        ///
        /// @param element element to search for
        /// @return index of the first occurrence of element, or -1 if not found
        virtual int indexOf(const T &element) const = 0;

        /// @brief Checks if this list has no elements.
        ///
        /// @return true if this list is empty, false otherwise
        virtual bool isEmpty() const = 0;

        /// @brief Returns the index of the last occurrence of an element found in this list.
        ///
        /// @param element element to search for
        /// @return index of the last occurrence of element, or -1 if not found
        virtual int lastIndexOf(const T &element) const = 0;

        /// @brief Retrieves and removes an element from this list at a specified index.
        ///
        /// @param index index to remove element from
        /// @return element found at index
        virtual T remove(int index) = 0;

        /// @brief Removes the first occurrence of an element from this list.
        ///
        /// @param element element to remove first occurrence of
        /// @return true if successful, false otherwise
        virtual bool removeElement(const T &element) = 0;

        /// @brief Sets the existing element at a specified index to a new value.
        ///
        /// @param index index to set element at
        /// @param element new value to set existing element to
        /// @return old value of the element at position index
        virtual T set(int index, const T &element) = 0;

        /// @brief Returns the number of elements in this list.
        ///
        /// @return size of list
        virtual int size() const = 0;

        /// @brief Returns an array containing all the elements in this list.
        ///
        /// @return array of list elements
        virtual T *toArray() const = 0;

        /// @brief Returns a string representation of this list, e.g. "[element1, element2, element3, ..., elementN]".
        ///
        /// @return string form of this list
        virtual std::string toString() const = 0;
};
