import MyList from "./mylist";

/**
 * Internal node object used by this linked list.
 */
class Node<T> {
    data?: T;
    // eslint-disable-next-line no-use-before-define
    next?: Node<T>;
}

/**
 * A singly linked list data structure.
 */
export default class MyLinkedList<T> implements MyList<T> {
    discriminator = "LIST";
    private head: Node<T>;
    private list_size: number;

    /**
     * Default constructor for this linked list.
     */
    constructor() {
        this.clear();
    }

    add(element: T, index?: number): void {

    }

    clear(): void {
        this.head = null;
        this.list_size = 0;
    }

    contains(element: T): boolean {
        return false;
    }

    equals(obj: object): boolean {
        return false;
    }

    get(index: number): T {
        throw new Error("Index out of bounds");
    }

    indexOf(element: T): number {
        return -1;
    }

    isEmpty(): boolean {
        return true;
    }

    lastIndexOf(element: T): number {
        return -1;
    }

    remove(index: number): T {
        throw new Error("Index out of bounds");
    }

    removeElement(element: T): boolean {
        return false;
    }

    set(index: number, element: T): T {
        throw new Error("Index out of bounds");
    }

    size(): number {
        return 0;
    }

    toArray(): T[] {
        return new Array<T>();
    }

    toString(): string {
        return "[]";
    }

    /**
     * Helper function for index validation.
     * @param index index to validate
     * @param upperBound value that index must be strictly less than
     */
    private checkIndex(index: number, upperBound: number): void {

    }
}
