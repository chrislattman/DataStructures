package dsa;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * A lock-free SPSC (single producer, single consumer) queue (ring buffer/FIFO)
 * built on top of an array. SPSC queues are used in HFT pipelines, audio/video
 * processing, real-time control, and GPU/CPU communication.
 *
 * Note: C# uses Interlocked.Exchange(ref head, int newVal) to update integer "head" atomically
 *
 * @param <T> data type
 */
public class MySPSCArrayQueue<T> {
    private final int mask;
    private final T[] buffer;
    // long p1,p2,p3,p4,p5,p6,p7,p8;    // padding to avoid false sharing on same 64 byte cache line
    private final AtomicInteger head;
    // long q1,q2,q3,q4,q5,q6,q7;       // padding to avoid false sharing on same 64 byte cache line
    private final AtomicInteger tail;
    // long r1,r2,r3,r4,r5,r6,r7;       // padding to avoid false sharing on same 64 byte cache line

    /**
     * Constructs a lock-free SPSC queue with the given capacity.
     *
     * @param k the value such that this queue has a usable capacity of 2^k - 1
     */
    @SuppressWarnings("unchecked")
    public MySPSCArrayQueue(int k) {
        int capacity = 1 << k;
        this.mask = capacity - 1;
        this.buffer = (T[]) new Object[capacity];
        this.head = new AtomicInteger(0);
        this.tail = new AtomicInteger(0);
    }

    /**
     * Checks if this lock-free SPSC queue has no elements.
     *
     * @return true if this queue is empty, false otherwise
     */
    public boolean isEmpty() {
        return this.head.get() == this.tail.get();
    }

    /**
     * Inserts an element to this lock-free SPSC queue.
     *
     * @param element element to add
     * @return true if successful, false otherwise
     */
    public boolean offer(T element) {
        // tail.getPlain() technically works for SPSC
        int currentTail = this.tail.get();
        int nextTail = (currentTail + 1) & this.mask; // & mask is equivalent to % capacity
        if (nextTail == this.head.get()) {
            return false;
        }
        this.buffer[currentTail] = element;
        this.tail.set(nextTail);
        return true;
    }

    /**
     * Retrieves, but does not remove, the element at the front of this lock-free SPSC queue.
     *
     * @return element at the front of this queue, or null if queue is empty
     */
    public T peek() {
        int currentHead = this.head.get();
        int currentTail = this.tail.get();
        if (currentHead == currentTail) {
            return null;
        }
        return this.buffer[currentHead];
    }

    /**
     * Retrieves and removes the element at the front of this lock-free SPSC queue.
     *
     * @return element at the front of this queue, or null if queue is empty
     */
    public T poll() {
        // head.getPlain() technically works for SPSC
        int currentHead = this.head.get();
        if (currentHead == this.tail.get()) {
            return null;
        }
        T value = this.buffer[currentHead];
        this.buffer[currentHead] = null;
        this.head.set((currentHead + 1) & this.mask); // & mask is equivalent to % capacity
        return value;
    }
}
