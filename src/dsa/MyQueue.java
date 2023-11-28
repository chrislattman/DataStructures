package dsa;

/**
 * Interface which defines methods for queues.
 *
 * @param <T> data type
 */
public interface MyQueue<T> {
    /**
     * Empties this queue of all elements.
     */
    public void clear();

    /**
     * Compares an object with this queue for equality.
     *
     * @param object object to compare to this queue
     * @return true if object and this queue are equal
     */
    @Override
    public boolean equals(Object object);

    /**
     * Checks if this queue has no elements.
     *
     * @return true if this queue is empty, false otherwise
     */
    public boolean isEmpty();

    /**
     * Inserts an element to this queue. Null elements are not permitted.
     *
     * @param element element to add
     */
    public void offer(T element);

    /**
     * Retrieves, but does not remove, the element at the front of this queue.
     *
     * @return element at the front of this queue, or null if queue is empty
     */
    public T peek();

    /**
     * Retrieves and removes the element at the front of this queue.
     *
     * @return element at the front of this queue, or null if queue is empty
     */
    public T poll();

    /**
     * Returns the number of elements in this queue.
     *
     * @return size of queue
     */
    public int size();

    /**
     * Returns an array containing all the elements in this queue.
     *
     * @return array of queue elements
     */
    public Object[] toArray();

    /**
     * Returns a string representation of this queue, e.g. "[element1, element2, element3, ..., elementN]".
     *
     * @return string form of this queue
     */
    @Override
    public String toString();
}
