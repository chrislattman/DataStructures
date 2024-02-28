/**
 * Interface which defines methods for queues.
 */
export default interface MyQueue<T> {
    /**
     * Empties this queue of all elements.
     */
    clear(): void;

    /**
     * Compares an object with this queue for equality.
     * @param obj object to compare to this queue
     * @returns true if object and this queue are equal
     */
    equals(obj: object): boolean;

    /**
     * Checks if this queue has no elements.
     * @returns true if this queue is empty, false otherwise
     */
    isEmpty(): boolean;

    /**
     * Inserts an element to this queue. Null elements are not permitted.
     * @param element element to add
     */
    offer(element: T): void;

    /**
     * Retrieves, but does not remove, the element at the front of this queue.
     * @returns element at the front of this queue, or null if queue is empty
     */
    peek(): T;

    /**
     * Retrieves and removes the element at the front of this queue.
     * @returns element at the front of this queue, or null if queue is empty
     */
    poll(): T;

    /**
     * Returns the number of elements in this queue.
     * @returns size of queue
     */
    size(): number;

    /**
     * Returns an array containing all the elements in this queue.
     * @returns array of queue elements
     */
    toArray(): T[];

    /**
     * Returns a string representation of this queue, e.g.
     * "[element1, element2, element3, ..., elementN]".
     * @returns string form of this queue
     */
    toString(): string;
}
