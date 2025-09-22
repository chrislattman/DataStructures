#pragma once

#include <atomic>

/// @brief A lock-free SPSC (single producer, single consumer) queue (ring buffer/FIFO)
/// built on top of an array. SPSC queues are used in HFT pipelines, audio/video
/// processing, real-time control, and GPU/CPU communication.
///
/// @tparam T data type
template<typename T>
class MySPSCArrayQueue {
private:
    const size_t mask;
    T *buffer;
    // char pad0[64];                               // padding to avoid false sharing on same 64 byte cache line
    std::atomic_size_t head;
    // char pad1[64 - sizeof(std::atomic_size_t)];  // padding to avoid false sharing on same 64 byte cache line
    std::atomic_size_t tail;
    // char pad2[64 - sizeof(std::atomic_size_t)];  // padding to avoid false sharing on same 64 byte cache line

public:
    /// @brief Constructs a lock-free SPSC queue with the given capacity.
    ///
    /// @param k the value such that this queue has a usable capacity of 2^k - 1
    MySPSCArrayQueue(size_t k)
        : mask((1 << k) - 1),
        buffer(new T[(1 << k)]),
        head(0),
        tail(0) {}

    /// @brief Frees dynamically allocated resources.
    virtual ~MySPSCArrayQueue() {
        delete[] buffer;
    }

    /// @brief Checks if this lock-free SPSC queue has no elements.
    ///
    /// @return true if this queue is empty, false otherwise
    bool isEmpty() const {
        return head.load(std::memory_order_acquire) == tail.load(std::memory_order_acquire);
    }

    /// @brief Inserts an element to this lock-free SPSC queue.
    ///
    /// @param element element to add
    /// @return true if successful, false otherwise
    bool offer(const T &element) {
        // tail.load(std::memory_order_relaxed) technically works for SPSC
        size_t current_tail = tail.load(std::memory_order_acquire);
        size_t next_tail = (current_tail + 1) & mask;
        if (next_tail == head.load(std::memory_order_acquire)) {
            return false;
        }
        buffer[current_tail] = element;
        tail.store(next_tail, std::memory_order_release);
        return true;
    }

    /// @brief Retrieves, but does not remove, the element at the front of this lock-free SPSC queue.
    ///
    /// @return element at the front of this queue, or NULL if queue is empty
    T peek() const {
        size_t current_head = head.load(std::memory_order_acquire);
        size_t current_tail = tail.load(std::memory_order_acquire);
        if (current_head == current_tail) {
            return T{};
        }
        return buffer[current_head];
    }

    /// @brief Retrieves and removes the element at the front of this lock-free SPSC queue.
    ///
    /// @return element at the front of this queue, or NULL if queue is empty
    T poll() {
        // head.load(std::memory_order_relaxed) technically works for SPSC
        size_t current_head = head.load(std::memory_order_acquire);
        if (current_head == tail.load(std::memory_order_acquire)) {
            return T{};
        }
        T value = buffer[current_head];
        buffer[current_head] = T{};
        head.store((current_head + 1) & mask, std::memory_order_release);
        return value;
    }
};
