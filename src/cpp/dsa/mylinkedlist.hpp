#pragma once

#include "mylist.h"
#include <stdexcept>
#include <sstream>

using namespace std;

/**
 * Implementations need to be in this header file due to generic templates.
 * Otherwise you could leave method signatures here and implement the
 * functions in a .cpp file like:
 *
 * template<typename T>
 * return-type MyLinkedList<T>::method(args) {
 *     ...
 * }
 */

/// @brief A singly linked list data structure.
///
/// @tparam T data type
template<typename T>
class MyLinkedList: public MyList<T> {
private:
    /// @brief Internal node representation.
    typedef struct Node {
        T data;
        struct Node *next;
    } Node;

    Node *head;
    unsigned int list_size;

    /// @brief Helper function for index validation.
    ///
    /// @param index index to validate
    /// @param upperBound value that index must be strictly less than
    void checkIndex(unsigned int index, unsigned int upperBound) const {
        if (index >= upperBound) {
            throw out_of_range("Index is out of bounds");
        }
    }

public:
    /// @brief Default constructor for this linked list.
    MyLinkedList() {
        head = nullptr;
        list_size = 0;
    }

    /// @brief Constructs a linked list instance with the copied contents of another linked list.
    ///
    /// @param list other linked list to deep copy from
    MyLinkedList(const MyLinkedList<T> &list) {
        if (list.list_size > 0) {
            head = new Node();
            head->data = list.head->data;
            Node *curr = head;
            Node *otherCurr = list.head->next;
            while (otherCurr != nullptr) {
                curr->next = new Node();
                curr->next->data = otherCurr->data;
                curr = curr->next;
                otherCurr = otherCurr->next;
            }
            list_size = list.list_size;
        } else {
            head = nullptr;
            list_size = 0;
        }
    }

    /// @brief Reinitalizes assignee (left hand side) linked list instance from another linked list.
    ///
    /// @param list other linked list to deep copy from
    /// @return updated version of assignee list
    MyLinkedList &operator=(const MyLinkedList<T> &list) {
        if (this != &list) {
            clear();
            if (list.list_size > 0) {
                head = new Node();
                head->data = list.head->data;
                Node *curr = head;
                Node *otherCurr = list.head->next;
                while (otherCurr != nullptr) {
                    curr->next = new Node();
                    curr->next->data = otherCurr->data;
                    curr = curr->next;
                    otherCurr = otherCurr->next;
                }
                list_size = list.list_size;
            }
        }
        return *this;
    }

    /// @brief Frees dynamically allocated resources.
    virtual ~MyLinkedList() {
        clear();
    }

    /// @brief Inserts an element at the specified index.
    ///
    /// @param index index to add element
    /// @param element element to add
    void add(unsigned int index, const T &element) {
        checkIndex(index, list_size + 1);
        if (isEmpty()) {
            head = new Node();
            head->data = element;
        } else {
            Node *newNode = new Node();
            newNode->data = element;
            if (index == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                Node *current = head;
                unsigned int stop = index - 1;
                for (unsigned int i = 0; i < stop; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
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
        while (head != nullptr) {
            Node *next = head->next;
            delete head;
            head = next;
        }
        list_size = 0;
    }

    /// @brief Checks if an element is in this list.
    ///
    /// @param element element to check for
    /// @return true if found, false otherwise
    bool contains(const T &element) const {
        for (Node *current = head; current != nullptr; current = current->next) {
            if (element == current->data) {
                return true;
            }
        }
        return false;
    }

    /// @brief Compares an object with this list for equality.
    ///
    /// @param list object to compare to this list
    /// @return true if object and this list are equal
    bool operator==(const MyLinkedList<T> &list) const {
        if (&list == this) {
            return true;
        }
        if (list.size() != list_size) {
            return false;
        }
        Node *current = head;
        for (unsigned int i = 0; i < list_size; i++) {
            if (list.get(i) != current->data) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    /// @brief Retrieves, but does not remove, an element from this list at the specified index.
    ///
    /// @param index index to retrieve element from
    /// @return element found
    T get(unsigned int index) const {
        checkIndex(index, list_size);
        Node *current = head;
        for (unsigned int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    /// @brief Returns the index of the first occurrence of an element found in this list.
    ///
    /// @param element element to search for
    /// @return index of the first occurrence of element, or -1 if not found
    long indexOf(const T &element) const {
        Node *current = head;
        for (long i = 0; i < (long)list_size; i++) {
            if (element == current->data) {
                return i;
            }
            current = current->next;
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
        Node *current = head;
        for (long i = 0; i < (long)list_size; i++) {
            if (element == current->data) {
                index = i;
            }
            current = current->next;
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
            T oldValue = head->data;
            head = head->next;
            --list_size;
            return oldValue;
        }
        Node *current = head;
        unsigned int stop = index - 1;
        for (unsigned int i = 0; i < stop; i++) {
            current = current->next;
        }
        T oldValue = current->next->data;
        current->next = current->next->next;
        --list_size;
        return oldValue;
    }

    /// @brief Retrieves and removes the first occurrence of an element from this list.
    ///
    /// @param element element to remove first occurrence of
    /// @return true if successful, false otherwise
    bool removeElement(const T &element) {
        if (element == head->data) {
            head = head->next;
            --list_size;
            return true;
        }
        for (Node *current = head; current != nullptr; current = current->next) {
            Node *nextNode = current->next;
            if (nextNode != nullptr && element == nextNode->data) {
                current->next = nextNode->next;
                --list_size;
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
    T set(unsigned int index, const T &element) {
        checkIndex(index, list_size);
        Node *current = head;
        for (unsigned int i = 0; i < index; i++) {
            current = current->next;
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
        Node *current = head;
        for (unsigned int i = 0; i < list_size; i++) {
            array[i] = current->data;
            current = current->next;
        }
        return array;
    }

    /// @brief Returns a string representation of this list, e.g. "[element1, element2, element3, ..., elementN]".
    ///
    /// @return string form of this list
    string toString() const {
        stringstream builder;
        builder << "[";
        for (Node *current = head; current != nullptr; current = current->next) {
            builder << current->data;
            if (current->next != nullptr) {
                builder << ", ";
            }
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
ostream& operator<<(ostream &str, const MyLinkedList<T> &list) {
    return str << list.toString();
}
