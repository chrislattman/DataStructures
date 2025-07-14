#pragma once

#include <memory>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "mylist.h"

/**
 * Implementations need to be in this header file due to generic templates.
 * Otherwise you could leave method signatures here and implement the
 * functions in a .cpp file like:
 *
 * template<typename T>
 * return-type MyModernLinkedList<T>::method(args) {
 *     ...
 * }
 */

/// @brief A singly linked list data structure using modern C++ techniques.
///
/// @tparam T data type
template<typename T>
class MyModernLinkedList: public MyList<T> {
private:
    /// @brief Internal node representation.
    typedef struct Node {
        T data;
        std::unique_ptr<Node> next;
    } Node;

    std::unique_ptr<Node> head = nullptr;
    unsigned int list_size = 0;

    /// @brief Helper function for index validation.
    ///
    /// @param index index to validate
    /// @param upperBound value that index must be strictly less than
    void checkIndex(unsigned int index, unsigned int upperBound) const {
        if (index >= upperBound) {
            throw std::out_of_range("Index is out of bounds");
        }
    }

public:
    /// @brief Inserts an element at the specified index.
    ///
    /// @param index index to add element
    /// @param element element to add
    void add(unsigned int index, const T &element) {
        checkIndex(index, list_size + 1);
        if (isEmpty()) {
            head = std::make_unique<Node>();
            head->data = element;
        } else {
            auto newnode = std::make_unique<Node>();
            newnode->data = element;
            if (index == 0) {
                newnode->next = std::move(head);
                head = std::move(newnode);
            } else {
                auto current = head.get();
                unsigned int stop = index - 1;
                for (unsigned int i = 0; i < stop; i++) {
                    current = current->next.get();
                }
                newnode->next = std::move(current->next);
                current->next = std::move(newnode);
            }
        }
        ++list_size;
    }

    /// @brief Inserts an element at the end of this list.
    ///
    /// @param element element to add
    void add(const T &element) {
        add(list_size, element);
    }

    /// @brief Empties this list of all elements.
    void clear() {
        head.reset();
        list_size = 0;
    }

    /// @brief Checks if an element is in this list.
    ///
    /// @param element element to check for
    /// @return true if found, false otherwise
    bool contains(const T &element) const {
        auto current = head.get();
        while (current != nullptr) {
            if (element == current->data) {
                return true;
            }
            current = current->next.get();
        }
        return false;
    }

    /// @brief Compares an object with this list for equality.
    ///
    /// @param list object to compare to this list
    /// @return true if object and this list are equal
    bool operator==(const MyModernLinkedList<T> &list) const {
        if (&list == this) {
            return true;
        }
        if (list.list_size != list_size) {
            return false;
        }
        auto currentself = head.get();
        auto currentother = list.head.get();
        while (currentself != nullptr && currentother != nullptr) {
            if (currentself->data != currentother->data) {
                return false;
            }
            currentself = currentself->next.get();
            currentother = currentother->next.get();
        }
        return currentself == nullptr && currentother == nullptr;
    }

    /// @brief Retrieves, but does not remove, an element from this list at the specified index.
    ///
    /// @param index index to retrieve element from
    /// @return element found
    T get(unsigned int index) const {
        checkIndex(index, list_size);
        auto current = head.get();
        for (unsigned int i = 0; i < index; i++) {
            current = current->next.get();
        }
        return current->data;
    }

    /// @brief Returns the index of the first occurrence of an element found in this list.
    ///
    /// @param element element to search for
    /// @return index of the first occurrence of element, or -1 if not found
    long indexOf(const T &element) const {
        auto current = head.get();
        for (long i = 0; i < (long)list_size; i++) {
            if (element == current->data) {
                return i;
            }
            current = current->next.get();
        }
        return -1;
    }

    /// @brief Checks if this list has no elements.
    ///
    /// @return true if this list is empty, false otherwise
    bool isEmpty() const {
        return list_size == 0;
    }

    /// @brief Returns the index of the last occurrence of an element found in this list.
    ///
    /// @param element element to search for
    /// @return index of the last occurrence of element, or -1 if not found
    long lastIndexOf(const T &element) const {
        long index = -1;
        auto current = head.get();
        for (long i = 0; i < (long)list_size; i++) {
            if (element == current->data) {
                index = i;
            }
            current = current->next.get();
        }
        return index;
    }

    /// @brief Retrieves and removes an element from this list at a specified index.
    ///
    /// @param index index to remove element from
    /// @return element found at index
    T remove(unsigned int index) {
        checkIndex(index, list_size);
        if (index == 0) {
            auto old = std::move(head);
            head = std::move(old->next);
            --list_size;
            return old->data;
        }
        auto current = head.get();
        unsigned int stop = index - 1;
        for (unsigned int i = 0; i < stop; i++) {
            current = current->next.get();
        }
        auto old = std::move(current->next);
        current->next = std::move(old->next);
        --list_size;
        return old->data;
    }

    /// @brief Removes the first occurrence of an element from this list.
    ///
    /// @param element element to remove first occurrence of
    /// @return true if successful, false otherwise
    bool removeElement(const T &element) {
        auto current = head.get();
        if (current != nullptr && element == current->data) {
            head = std::move(current->next);
            --list_size;
            return true;
        }
        while (current != nullptr) {
            auto nextnode = current->next.get();
            if (nextnode != nullptr && element == nextnode->data) {
                current->next = std::move(nextnode->next);
                --list_size;
                return true;
            }
            current = current->next.get();
        }
        return false;
    }

    /// @brief Sets the existing element at a specified index to a new value.
    ///
    /// @param index index to set element at
    /// @param element new value to set existing element to
    /// @return old value of the element at position index
    T set(unsigned int index, const T &element) {
        checkIndex(index, list_size);
        auto current = head.get();
        for (unsigned int i = 0; i < index; i++) {
            current = current->next.get();
        }
        T oldValue = current->data;
        current->data = element;
        return oldValue;
    }

    /// @brief Returns the number of elements in this list.
    ///
    /// @return size of list
    unsigned int size() const {
        return list_size;
    }

    /// @brief Returns an array containing all the elements in this list.
    ///
    /// @return array of list elements
    T *toArray() const {
        T *array = new T[list_size];
        auto current = head.get();
        for (unsigned int i = 0; i < list_size; i++) {
            array[i] = current->data;
            current = current->next.get();
        }
        return array;
    }

    /// @brief Returns a string representation of this list, e.g. "[element1, element2, element3, ..., elementN]".
    ///
    /// @return string form of this list
    std::string toString() const {
        std::stringstream builder;
        builder << "[";
        auto current = head.get();
        while (current != nullptr) {
            builder << current->data;
            if (current->next.get() != nullptr) {
                builder << ", ";
            }
            current = current->next.get();
        }
        builder << "]";
        return builder.str();
    }
};

/// @brief Prints out the linked list without needing to manually call toString().
///
/// @tparam T data type
/// @param str ostream
/// @param list linked list to print out
/// @return updated ostream
template<typename T>
std::ostream& operator<<(std::ostream &str, const MyModernLinkedList<T> &list) {
    return str << list.toString();
}
