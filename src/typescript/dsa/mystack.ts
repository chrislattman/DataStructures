/**
 * A stack data structure (LIFO).
 */
export class MyStack<T> {
    private array: T[];
    private array_size: number;
    private readonly defaultCapacity = 10;
    private readonly minArrLenThreshold = 100;

    /**
     * Default constructor for this stack.
     */
    constructor() {
        this.clear();
    }

    /**
     * Empties this stack of all elements.
     */
    clear(): void {
        this.array = new Array<T>(this.defaultCapacity);
        this.array_size = 0;
    }

    /**
     * Compares an object with this stack for equality.
     * @param obj object to compare to this stack
     * @returns true if object and this stack are equal
     */
    equals(obj: object): boolean {
        return false;
    }

    /**
     * Checks if this stack has no elements.
     * @returns true if this stack is empty, false otherwise
     */
    isEmpty(): boolean {
        return true;
    }

    /**
     * Retrieves, but does not remove, the element at the top of this stack.
     * @returns topmost element on stack, or null if stack is empty
     */
    peek(): T {
        return null;
    }

    /**
     * Retrieves and removes the element at the top of this stack.
     * @returns topmost element on stack, or null if stack is empty
     */
    pop(): T {
        return null;
    }

    /**
     * Inserts an element at the top of this stack.
     * @param element element to add
     */
    push(element: T): void {

    }

    /**
     * Returns the number of elements in this stack.
     * @returns size of stack
     */
    size(): number {
        return 0;
    }

    /**
     * Returns an array containing all the elements in this stack.
     * @returns array of stack elements
     */
    toArray(): T[] {
        return new Array<T>();
    }

    /**
     * Returns a string representation of this stack, e.g.
     * "[element1, element2, element3, ..., elementN]".
     * @returns string form of this stack
     */
    toString(): string {
        return "[]";
    }

    /**
     * Doubles or halves the size of the internal array depending on size.
     * Used in pop and push methods.
     */
    private checkCapacity(): void {

    }
}
