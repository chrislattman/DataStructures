import { MyQueue } from "./myqueue";

/**
 * A priority queue data structure. Also called a (binary) heap.
 */
export class MyPriorityQueue<T> implements MyQueue<T> {
    private array: T[];
    private array_size: number;
    private isMinHeap: boolean;
    private static readonly defaultCapacity = 11;
    private readonly minArrLenThreshold = 100;

    /**
     * Constructs either a min heap or a max heap with a specified initial
     * capacity.
     * @param initialCapacity initial capacity of this priority queue. Defaults
     * to 11.
     * @param isMinHeap if true, this priority queue will be a min heap;
     * otherwise, it will be a max heap
     */
    constructor(initialCapacity?: number, isMinHeap = true) {
        if (initialCapacity === undefined) {
            initialCapacity = MyPriorityQueue.defaultCapacity;
        } else if (initialCapacity < 0) {
            throw new Error("Negative capacity provided");
        }
        this.array = new Array<T>(initialCapacity);
        this.array_size = 0;
        this.isMinHeap = isMinHeap;
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

    /**
     * Returns the index of the lesser element of the internal array if this is
     * a min heap. Otherwise, returns the index of the greater element. Indices
     * should be distinct and increasing.
     * @param leftIndex left array index
     * @returns the index of the desired element, or -1 if: leftIndex is out of
     * bounds, array[leftIndex] and array[leftIndex + 1] are both null, or
     * array[array.length - 1] is null; in a non-null tie, left element wins
     */
    private getBestIndex(leftIndex: number): number {
        return -1;
    }
}
