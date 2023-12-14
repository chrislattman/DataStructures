#pragma once

#include <string>

/// @brief Abstract class (used as an interface) which defines methods for queues.
///
/// @tparam T data type
template<typename T>
class MyQueue {
    public:
        /// @brief Empties this queue of all elements.
        virtual void clear() = 0;

        /// @brief Checks if this queue has no elements.
        ///
        /// @return true if this queue is empty, false otherwise
        virtual bool isEmpty() const = 0;

        /// @brief Inserts an element to this queue. Null elements are not permitted.
        ///
        /// @param element element to add
        virtual void offer(const T &element) = 0;

        /// @brief Retrieves, but does not remove, the element at the front of this queue.
        ///
        /// @return element at the front of this queue, or null if queue is empty
        virtual T peek() const = 0;

        /// @brief Retrieves and removes the element at the front of this queue.
        ///
        /// @return element at the front of this queue, or null if queue is empty
        virtual T poll() = 0;

        /// @brief Returns the number of elements in this queue.
        ///
        /// @return size of queue
        virtual int size() const = 0;

        /// @brief Returns an array containing all the elements in this queue.
        ///
        /// @return array of queue elements
        virtual T *toArray() const = 0;

        /// @brief Returns a string representation of this queue, e.g. "[element1, element2, element3, ..., elementN]".
        ///
        /// @return string form of this queue
        virtual std::string toString() const = 0;
};
