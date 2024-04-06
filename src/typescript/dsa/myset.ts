/**
 * Interface which defines methods for sets.
 */
export default interface MySet<T> {
    discriminator: string;

    /**
     * Inserts an element into this set if it is not already there.
     * @param element element to add
     * @returns true if element was not present, false otherwise
     */
    add(element: T): boolean;

    /**
     * Empties this set of all elements.
     */
    clear(): void;

    /**
     * Checks if an element is in this set.
     * @param element element to check for
     * @returns true if found, false otherwise
     */
    contains(element: T): boolean;

    /**
     * Compares an object with this set for equality.
     * @param obj object to compare to this set
     * @returns true if object and this set are equal
     */
    equals(obj: object): boolean;

    /**
     * Checks if this set has no elements.
     * @returns true if this set is empty, false otherwise
     */
    isEmpty(): boolean;

    /**
     * Removes an element from this set.
     * @param element element to remove
     * @returns true if element found, false otherwise
     */
    remove(element: T): boolean;

    /**
     * Returns the number of elements in this set.
     * @returns size of set
     */
    size(): number;

    /**
     * Returns an array containing all the elements in this set.
     * @returns array of set elements
     */
    toArray(): T[];

    /**
     * Returns a string representation of this set, e.g.
     * "[element1, element2, element3, ..., elementN]".
     * @returns string form of this set
     */
    toString(): string;
}
