#pragma once

#include "myqueue.h"
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
 * return-type MyArrayQueue<T>::method(args) {
 *     ...
 * }
 */

/// @brief An array queue data structure (FIFO).
///
/// @tparam T data type
template<typename T>
class MyArrayQueue: public MyQueue<T> {
    private:
        T *array;
        int array_size, array_length;
        static const int defaultCapacity = 16;
        const int minArrLenThreshold = 100;

        /// @brief Doubles or halves the size of the internal array depending on size. Used in offer and poll methods.
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
                T *newArray = new T[array_size / 2];
                memcpy(newArray, array, array_size);
                delete[] array;
                array = newArray;
            }
        }

    public:
        /// @brief Constructs an array queue instance with a specified initial capacity.
        ///
        /// @param initialCapacity initial capacity of this array queue
        MyArrayQueue(int initialCapacity) {
            if (initialCapacity < 0) {
                throw invalid_argument("Negative capacity provided.");
            }
            array = new T[initialCapacity];
            array_length = initialCapacity;
            array_size = 0;
        }

        /// @brief Constructs an array queue instance with a default initial capacity of 16.
        MyArrayQueue(): MyArrayQueue(defaultCapacity) {};

        /// @brief Frees dynamically allocated resources.
        virtual ~MyArrayQueue() {
            delete[] array;
        }

        /// @brief Empties this queue of all elements.
        void clear() {
            delete[] array;
            array = new T[defaultCapacity];
            array_length = defaultCapacity;
            array_size = 0;
        }

        /// @brief Compares an object with this queue for equality.
        ///
        /// @param object object to compare to this queue
        /// @return true if object and this queue are equal
        bool operator==(const MyArrayQueue<T> &queue) const {
            if (&queue == this) {
                return true;
            }
            if (queue.size() != array_size) {
                return false;
            }
            T *elements = queue.toArray();
            bool retval = true;
            for (int i = 0; i < array_size; i++) {
                if (elements[i] != array[i]) {
                    retval = false;
                    break;
                }
            }
            delete[] elements;
            return retval;
        }

        /// @brief Checks if this queue has no elements.
        ///
        /// @return true if this queue is empty, false otherwise
        bool isEmpty() const {
            return array_size == 0;
        }

        /// @brief Inserts an element to this queue. NULL elements are not permitted.
        ///
        /// @param element element to add
        void offer(const T &element) {
            if (element != T(NULL)) {
                checkCapacity();
                array[array_size] = element;
                ++array_size;
            }
        }

        /// @brief Retrieves, but does not remove, the element at the front of this queue.
        ///
        /// @return element at the front of this queue, or NULL if queue is empty
        T peek() const {
            if (isEmpty()) {
                return T(NULL);
            }
            return array[0];
        }

        /// @brief Retrieves and removes the element at the front of this queue.
        ///
        /// @return element at the front of this queue, or NULL if queue is empty
        T poll() {
            if (isEmpty()) {
                return T(NULL);
            }
            T element = array[0];
            --array_size;
            memmove(array, array + 1, array_size);
            checkCapacity();
            return element;
        }

        /// @brief Returns the number of elements in this queue.
        ///
        /// @return size of queue
        int size() const {
            return array_size;
        }

        /// @brief Returns an array containing all the elements in this queue.
        ///
        /// @return array of queue elements
        T *toArray() const {
            T *arrayCopy = new T[array_size];
            memcpy(arrayCopy, array, array_size);
            return arrayCopy;
        }

        /// @brief Returns a string representation of this queue, e.g. "[element1, element2, element3, ..., elementN]".
        ///
        /// @return string form of this queue
        string toString() const {
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

/// @brief Prints out the array queue without needing to manually call toString().
///
/// @tparam T data type
/// @param str ostream
/// @param queue array queue to print out
/// @return updated ostream
template<typename T>
ostream& operator<<(ostream &str, const MyArrayQueue<T> &queue) {
    return str << queue.toString();
}
