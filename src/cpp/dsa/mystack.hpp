#pragma once

#include <sstream>
#include <string>

using namespace std;

/**
 * Implementations need to be in this header file due to generic templates.
 * Otherwise you could leave method signatures here and implement the
 * functions in a .cpp file like:
 *
 * template<typename T>
 * return-type MyStack<T>::method(args) {
 *     ...
 * }
 */

/// @brief A stack data structure (LIFO).
///
/// @tparam T data type
template<typename T>
class MyStack {
private:
    T *array;
    unsigned int array_size, array_length;
    static const unsigned int defaultCapacity = 10;
    const unsigned int minArrLenThreshold = 100;

    /// @brief Doubles or halves the size of the internal array depending on size. Used in pop and push methods.
    void checkCapacity() {
        if (array_length == 0) {
            delete[] array;
            array = new T[defaultCapacity];
            array_length = defaultCapacity;
        } else if (array_size == array_length) {
            T *newArray = new T[array_size * 2];
            memcpy(newArray, array, array_size * sizeof(T));
            delete[] array;
            array = newArray;
        } else if (array_length > minArrLenThreshold && array_size * 2 < array_length) {
            T *newArray = new T[array_length / 2];
            memcpy(newArray, array, array_size * sizeof(T));
            delete[] array;
            array = newArray;
        }
    }

public:
    /// @brief Default constructor for this stack.
    MyStack() {
        array = new T[defaultCapacity];
        array_length = defaultCapacity;
        array_size = 0;
    }

    /// @brief Constructs a stack instance with the copied contents of another stack.
    ///
    /// @param stack other stack to deep copy from
    MyStack(const MyStack<T> &stack) {
        array = new T[stack.array_length];
        memcpy(array, stack.array, stack.array_size * sizeof(T));
        array_length = stack.array_length;
        array_size = stack.array_size;
    }

    /// @brief Reinitalizes assignee (left hand side) stack instance from another stack.
    ///
    /// @param stack other stack to deep copy from
    /// @return updated version of assignee stack
    MyStack &operator=(const MyStack<T> &stack) {
        if (this != &stack) {
            delete[] array;
            array = new T[stack.array_length];
            memcpy(array, stack.array, stack.array_size * sizeof(T));
            array_length = stack.array_length;
            array_size = stack.array_size;
        }
        return *this;
    }

    /// @brief Frees dynamically allocated resources.
    virtual ~MyStack() {
        delete[] array;
    }

    /// @brief Empties this stack of all elements.
    void clear() {
        delete[] array;
        array = new T[defaultCapacity];
        array_length = defaultCapacity;
        array_size = 0;
    }

    /// @brief Compares an object with this stack for equality.
    ///
    /// @param stack object to compare to this stack
    /// @return true if object and this stack are equal
    bool operator==(const MyStack<T> &stack) {
        if (&stack == this) {
            return true;
        }
        if (stack.size() != array_size) {
            return false;
        }
        T *elements = stack.toArray();
        bool retval = true;
        for (unsigned int i = 0; i < array_size; i++) {
            if (elements[i] != array[i]) {
                retval = false;
                break;
            }
        }
        delete[] elements;
        return retval;
    }

    /// @brief Checks if this stack has no elements.
    ///
    /// @return true if this stack is empty, false otherwise
    bool isEmpty() const {
        return array_size == 0;
    }

    /// @brief Retrieves, but does not remove, the element at the top of this stack.
    ///
    /// @return topmost element on stack, or NULL if stack is empty
    T peek() const {
        if (isEmpty()) {
            return T(NULL);
        }
        return array[array_size - 1];
    }

    /// @brief Retrieves and removes the element at the top of this stack.
    ///
    /// @return topmost element on stack, or NULL if stack is empty
    T pop() {
        if (isEmpty()) {
            return T(NULL);
        }
        T element = array[array_size - 1];
        --array_size;
        checkCapacity();
        return element;
    }

    /// @brief Inserts an element at the top of this stack.
    ///
    /// @param element element to add
    void push(const T &element) {
        checkCapacity();
        array[array_size] = element;
        ++array_size;
    }

    /// @brief Returns the number of elements in this stack.
    ///
    /// @return size of stack
    unsigned int size() const {
        return array_size;
    }

    /// @brief Returns an array containing all the elements in this stack.
    ///
    /// @return array of stack elements
    T *toArray() const {
        T *arrayCopy = new T[array_size];
        memcpy(arrayCopy, array, array_size * sizeof(T));
        return arrayCopy;
    }

    /// @brief Returns a string representation of this stack, e.g. "[element1, element2, element3, ..., elementN]".
    ///
    /// @return string form of this stack
    string toString() const {
        stringstream builder;
        builder << "[";
        long lastIndex = (long)array_size - 1;
        for (unsigned int i = 0; i < array_size; i++) {
            builder << array[i];
            if ((long)i != lastIndex) {
                builder << ", ";
            }
        }
        builder << "]";
        return builder.str();
    }
};

/// @brief Prints out the stack without needing to manually call toString().
///
/// @tparam T data type
/// @param str ostream
/// @param stack stack to print out
/// @return updated ostream
template<typename T>
ostream& operator<<(ostream &str, const MyStack<T> &stack) {
    return str << stack.toString();
}
