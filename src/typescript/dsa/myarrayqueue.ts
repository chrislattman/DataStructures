import MyQueue from "./myqueue";

/**
 * An array queue data structure (FIFO).
 */
export default class MyArrayQueue<T> implements MyQueue<T> {
    discriminator = "QUEUE";
    private array: T[];
    private array_size: number;
    private static readonly defaultCapacity = 16;
    private readonly minArrLenThreshold = 100;

    /**
     * Constructs an array queue instance with a specified initial capacity.
     * @param initialCapacity initial capacity of this array list. Defaults to
     * 16.
     */
    constructor(initialCapacity?: number) {
        if (initialCapacity === undefined) {
            initialCapacity = MyArrayQueue.defaultCapacity;
        } else if (initialCapacity < 0) {
            throw new Error("Negative capacity provided");
        }
        this.array = new Array<T>(initialCapacity);
        this.array_size = 0;
    }

    clear(): void {

    }

    equals(obj: object): boolean {
        return false;
    }

    isEmpty(): boolean {
        return true;
    }

    offer(element: T): void {

    }

    peek(): T {
        return null;
    }

    poll(): T {
        return null;
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
     * Doubles or halves the size of the internal array depending on size.
     * Used in offer and poll methods.
     */
    private checkCapacity(): void {

    }
}
