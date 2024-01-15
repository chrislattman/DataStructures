/**
 * Interface which defines methods for lists.
 */
export interface MyList<T> {
    discriminator: "LIST";

    /**
     * Inserts an element at the specified index.
     * @param element element to add
     * @param index index to add element. Defaults to last index.
     */
    add(element: T, index?: number): void;

    /**
     * Empties this list of all elements.
     */
    clear(): void;

    /**
     * Checks if an element is in this list.
     * @param element element to check for
     * @returns true if found, false otherwise
     */
    contains(element: T): boolean;

    /**
     * Compares an object with this list for equality.
     * @param obj object to compare to this list
     * @returns true if object and this list are equal
     */
    equals(obj: object): boolean;

    /**
     * Retrieves, but does not remove, an element from this list at the
     * specified index.
     * @param index index to retrieve element from
     * @returns element found
     */
    get(index: number): T;

    /**
     * Returns the index of the first occurrence of an element found in this
     * list.
     * @param element element to search for
     * @returns index of the first occurrence of element, or -1 if not found
     */
    indexOf(element: T): number;

    /**
     * Checks if this list has no elements.
     * @returns true if this list is empty, false otherwise
     */
    isEmpty(): boolean;

    /**
     * Returns the index of the last occurrence of an element found in this
     * list.
     * @param element element to search for
     * @returns index of the last occurrence of element, or -1 if not found
     */
    lastIndexOf(element: T): number;

    /**
     * Retrieves and removes an element from this list at a specified index.
     * @param index index to remove element from
     * @returns element found at index
     */
    remove(index: number): T;

    /**
     * Removes the first occurrence of an element from this list.
     * @param element element to remove first occurrence of
     * @returns true if successful, false otherwise
     */
    removeElement(element: T): boolean;

    /**
     * Sets the existing element at a specified index to a new value.
     * @param index index to set element at
     * @param element new value to set existing element to
     * @returns old value of the element at position index
     */
    set(index: number, element: T): T;

    /**
     * Returns the number of elements in this list.
     * @returns size of list
     */
    size(): number;

    /**
     * Returns an array containing all the elements in this list.
     * @returns array of list elements
     */
    toArray(): T[];

    /**
     * Returns a string representation of this list, e.g.
     * "[element1, element2, element3, ..., elementN]".
     * @returns string form of this list
     */
    toString(): string;
}
