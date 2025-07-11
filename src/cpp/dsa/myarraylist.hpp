#pragma once

#include "mylist.h"
#include <stdexcept>
#include <sstream>
#include <cstring>

using namespace std;

/**
 * Implementations need to be in this header file due to generic templates.
 * Otherwise you could leave method signatures here and implement the
 * functions in a .cpp file like:
 *
 * template<typename T>
 * return-type MyArrayList<T>::method(args) {
 *     ...
 * }
 */

/// @brief An array list data structure. This class demonstrates explicit use of
/// the `override` keyword. It should be used for all overridden methods or
/// none of them (as is the case for the other classes).
///
/// @tparam T data type
template<typename T>
class MyArrayList: public MyList<T> {
private:
    T *array;
    int array_size, array_length;
    static const int defaultCapacity = 10;
    const int minArrLenThreshold = 100;

    /// @brief Doubles or halves the size of the internal array depending on size. Used in add and remove methods.
    void checkCapacity() {
        if (array_length == 0) {
            delete[] array;
            array = new T[defaultCapacity];
            array_length = defaultCapacity;
        } else if (array_size == array_length) {
            T *newArray = new T[array_size * 2];
            memcpy(newArray, array, array_size);
            delete[] array;
            array = newArray;
        } else if (array_length > minArrLenThreshold && array_size * 2 < array_length) {
            T *newArray = new T[array_length / 2];
            memcpy(newArray, array, array_size);
            delete[] array;
            array = newArray;
        }
    }

    /// @brief Helper function for index validation.
    ///
    /// @param index index to validate
    /// @param upperBound value that index must be strictly less than
    void checkIndex(int index, int upperBound) const {
        if (index < 0 || index >= upperBound) {
            throw out_of_range("Index is out of bounds");
        }
    }

public:
    /// @brief Constructs an array list instance with a specified initial capacity.
    ///
    /// @param initialCapacity initial capacity of this array list
    MyArrayList(int initialCapacity) {
        if (initialCapacity < 0) {
            throw invalid_argument("Negative capacity provided.");
        }
        array = new T[initialCapacity];
        array_length = initialCapacity;
        array_size = 0;
    }

    /// @brief Constructs an array list instance with a default initial capacity of 10.
    MyArrayList(): MyArrayList(defaultCapacity) {};

    /// @brief Frees dynamically allocated resources.
    virtual ~MyArrayList() {
        delete[] array;
    }

    /// @brief Inserts an element at the specified index.
    ///
    /// @param index index to add element
    /// @param element element to add
    void add(int index, const T &element) override {
        checkIndex(index, array_size + 1);
        checkCapacity();
        if (index < array_size) {
            memmove(array + index + 1, array + index, (array_size - index) * sizeof(T));
        }
        array[index] = element;
        ++array_size;
    }

    /// @brief Inserts an element at the end of this list.
    ///
    /// @param element element to add
    void add(const T &element) override {
        add(array_size, element);
    }

    /// @brief Empties this list of all elements.
    void clear() override {
        delete[] array;
        array = new T[defaultCapacity];
        array_length = defaultCapacity;
        array_size = 0;
    }

    /// @brief Checks if an element is in this list.
    ///
    /// @param element element to check for
    /// @return true if found, false otherwise
    bool contains(const T &element) const override {
        for (int i = 0; i < array_size; i++) {
            if (element == array[i]) {
                return true;
            }
        }
        return false;
    }

    /// @brief Compares an object with this list for equality.
    ///
    /// @param list object to compare to this list
    /// @return true if object and this list are equal
    bool operator==(const MyArrayList<T> &list) const {
        if (&list == this) {
            return true;
        }
        if (list.size() != array_size) {
            return false;
        }
        for (int i = 0; i < array_size; i++) {
            if (list.get(i) != array[i]) {
                return false;
            }
        }
        return true;
    }

    /// @brief Retrieves, but does not remove, an element from this list at the specified index.
    ///
    /// @param index index to retrieve element from
    /// @return element found
    T get(int index) const override {
        checkIndex(index, array_size);
        return array[index];
    }

    /// @brief Retrieves, but does not remove, an element from this list at the specified index.
    /// Can also be used to modify the array list.
    ///
    /// @param index index to retrieve element from
    /// @return element found
    T& operator[](int index) {
        checkIndex(index, array_size);
        return array[index];
    }

    /// @brief Returns the index of the first occurrence of an element found in this list.
    ///
    /// @param element element to search for
    /// @return index of the first occurrence of element, or -1 if not found
    int indexOf(const T &element) const override {
        for (int i = 0; i < array_size; i++) {
            if (element == array[i]) {
                return i;
            }
        }
        return -1;
    }

    /// @brief Checks if this list has no elements.
    ///
    /// @return true if this list is empty, false otherwise
    bool isEmpty() const override {
        return array_size == 0;
    }

    /// @brief Returns the index of the last occurrence of an element found in this list.
    ///
    /// @param element element to search for
    /// @return index of the last occurrence of element, or -1 if not found
    int lastIndexOf(const T &element) const override {
        for (int i = array_size - 1; i >= 0; i--) {
            if (element == array[i]) {
                return i;
            }
        }
        return -1;
    }

    /// @brief Retrieves and removes an element from this list at a specified index.
    ///
    /// @param index index to remove element from
    /// @return element found at index
    T remove(int index) override {
        checkIndex(index, array_size);
        T element = array[index];
        --array_size;
        if (index + 1 < array_size) {
            memmove(array + index, array + index + 1, (array_size - index - 1) * sizeof(T));
        }
        checkCapacity();
        return element;
    }

    /// @brief Retrieves and removes the first occurrence of an element from this list.
    ///
    /// @param element element to remove first occurrence of
    /// @return true if successful, false otherwise
    bool removeElement(const T &element) override {
        for (int i = 0; i < array_size; i++) {
            if (element == array[i]) {
                --array_size;
                if (i + 1 < array_size) {
                    memmove(array + i, array + i + 1, (array_size - i - 1) * sizeof(T));
                }
                checkCapacity();
                return true;
            }
        }
        return false;
    }

    /// @brief Sets the existing element at a specified index to a new value.
    ///
    /// @param index index to set element at
    /// @param element new value to set existing element to
    /// @return old value of the element at position index
    T set(int index, const T &element) override {
        checkIndex(index, array_size);
        T oldValue = array[index];
        array[index] = element;
        return oldValue;
    }

    /// @brief Returns the number of elements in this list.
    ///
    /// @return size of list
    int size() const override {
        return array_size;
    }

    /// @brief Returns an array containing all the elements in this list.
    ///
    /// @return array of list elements
    T *toArray() const override {
        T *arrayCopy = new T[array_size];
        memcpy(arrayCopy, array, array_size);
        return arrayCopy;
    }

    /// @brief Returns a string representation of this list, e.g. "[element1, element2, element3, ..., elementN]".
    ///
    /// @return string form of this list
    string toString() const override {
        stringstream builder;
        builder << "[";
        int lastIndex = array_size - 1;
        for (int i = 0; i < array_size; i++) {
            builder << array[i];
            if (i != lastIndex) {
                builder << ", ";
            }
        }
        builder << "]";
        return builder.str();
    }
};

/// @brief Prints out the array list without needing to manually call toString().
///
/// @tparam T data type
/// @param str ostream
/// @param list array list to print out
/// @return updated ostream
template<typename T>
ostream& operator<<(ostream &str, const MyArrayList<T> &list) {
    return str << list.toString();
}
