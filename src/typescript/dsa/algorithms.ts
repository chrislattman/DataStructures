import { MyArrayList } from "./myarraylist";
import { MyList } from "./mylist";
import { MyPriorityQueue } from "./mypriorityqueue";

/**
 * Functions to search and sort lists.
 */
export class Algorithms {
    // The below TypeScript overload signatures aren't functionally necessary,
    // but they make code documentation cleaner when using the methods

    /**
     * Default constructor which should not be documented.
     * @ignore
     */
    constructor() {
        // Empty constructor
    }

    /**
     * Performs a binary search on a range of a list for a specified key, and
     * returns the index of the first match found. Result is undefined for an
     * unsorted list.
     * @param list list to search in
     * @param key key to find
     * @param startIndex index of first element to search. Defaults to 0.
     * @param endIndex index of last element to search. Defaults to
     * mylist.size() - 1.
     */
    static binarySearch<T>(list: MyList<T>, key: T, startIndex?: number,
        endIndex?: number): number;

    /**
     * Performs a binary search on a range of an array for a specified key, and
     * returns the index of the first match found. Result is undefined for an
     * unsorted array.
     * @param array array to search in
     * @param key key to find
     * @param startIndex index of first element to search. Defaults to 0.
     * @param endIndex index of last element to search. Defaults to
     * array.length - 1.
     */
    static binarySearch<T>(array: T[], key: T, startIndex?: number,
        endIndex?: number): number;

    // TypeScript implementation signature
    static binarySearch<T>(listOrArray: MyList<T> | T[], key: T, startIndex = 0,
            endIndex?: number): number {
        if (endIndex === undefined) {
            if (this.instanceOfMyList<T>(listOrArray)) {
                endIndex = listOrArray.size() - 1;
            } else {
                endIndex = listOrArray.length - 1;
            }
        }
        return -1;
    }

    /**
     * Performs an in-memory merge sort of the list.
     * @param list list to sort
     */
    static mergesort<T>(list: MyList<T>): void;

    /**
     * Performs an in-memory merge sort of the array.
     * @param array array to sort
     */
    static mergesort<T>(array: T[]): void;

    static mergesort<T>(listOrArray: MyList<T> | T[]): void {
        let size: number;
        let temp: MyList<T> | T[];
        if (this.instanceOfMyList(listOrArray)) {
            size = listOrArray.size();
            temp = new MyArrayList<T>(size);
            for (let i = 0; i < size; i++) {
                temp.add(listOrArray.get(i));
            }
        } else {
            size = listOrArray.length;
            temp = Array.from(listOrArray);
        }
        this.internal_mergesort(listOrArray, temp, 0, size - 1);
    }

    /**
     * Performs an in-memory quicksort of the list.
     * @param list list to sort
     */
    static quicksort<T>(list: MyList<T>): void;

    /**
     * Performs an in-memory quicksort of the array.
     * @param array array to sort
     */
    static quicksort<T>(array: T[]): void;

    static quicksort<T>(listOrArray: MyList<T> | T[]): void {
        let size: number;
        if (this.instanceOfMyList(listOrArray)) {
            size = listOrArray.size();
        } else {
            size = listOrArray.length;
        }
        this.internal_quicksort(listOrArray, 0, size - 1);
    }

    /**
     * Performs an in-memory heapsort of the list.
     * @param list list to sort
     */
    static heapsort<T>(list: MyList<T>): void;

    /**
     * Performs an in-memory heapsort of the array.
     * @param array array to sort
     */
    static heapsort<T>(array: T[]): void;

    static heapsort<T>(listOrArray: MyList<T> | T[]): void {
        let size: number;
        if (this.instanceOfMyList(listOrArray)) {
            size = listOrArray.size();
        } else {
            size = listOrArray.length;
        }
        const minHeap = new MyPriorityQueue<T>(size);
        if (this.instanceOfMyList(listOrArray)) {
            for (let i = 0; i < size; i++) {
                minHeap.offer(listOrArray.remove(i));
            }
            for (let i = 0; i < size; i++) {
                listOrArray.add(minHeap.poll());
            }
        } else {
            for (const element of listOrArray) {
                minHeap.offer(element);
            }
            for (let i = 0; i < listOrArray.length; i++) {
                listOrArray[i] = minHeap.poll();
            }
        }
    }

    /**
     * Internal merge sort divide and conquer function for lists or arrays.
     * @param listOrArray list or array to sort
     * @param temp temporary list or array
     * @param left left index
     * @param right right index
     */
    private static internal_mergesort<T>(listOrArray: MyList<T> | T[],
            temp: MyList<T> | T[], left: number, right: number): void {

    }

    /**
     * Internal high level quicksort function for lists or arrays.
     * @param listOrArray list or array to sort
     * @param left left index
     * @param right right index
     */
    private static internal_quicksort<T>(listOrArray: MyList<T> | T[],
            left: number, right: number): void {
        if (left < right) {
            const pivotIndex = this.partition(listOrArray, left, right);
            this.internal_quicksort(listOrArray, left, pivotIndex - 1);
            this.internal_quicksort(listOrArray, pivotIndex, right);
        }
    }

    /**
     * Partition function for quicksort for lists or arrays.
     * @param listOrArray list or array to sort
     * @param left left index
     * @param right right index
     * @returns pivot location
     */
    private static partition<T>(listOrArray: MyList<T> | T[], left: number,
            right: number): number {
        let pivot: T;
        if (right - left > 1) {
            if (this.instanceOfMyList(listOrArray)) {
                pivot = this.findMedian(listOrArray.get(left),
                    listOrArray.get((left + right) / 2),
                    listOrArray.get(right));
            } else {
                pivot = this.findMedian(listOrArray[left],
                    listOrArray[(left + right) / 2], listOrArray[right]);
            }
        } else {
            if (this.instanceOfMyList(listOrArray)) {
                pivot = listOrArray.get(left);
            } else {
                pivot = listOrArray[left];
            }
        }
        return 0;
    }

    /**
     * Finds the median of three values. Used for quicksort.
     * @param a first value
     * @param b second value
     * @param c third value
     * @returns the median of the first, second, and third values
     */
    private static findMedian<T>(a: T, b: T, c: T): T {
        return b;
    }

    /**
     * Helper function to determine if an object implements the MyList
     * interface.
     * @param obj object to check
     * @returns true if obj implements MyList, false otherwise
     */
    // eslint-disable-next-line @typescript-eslint/no-explicit-any
    private static instanceOfMyList<T>(obj: any): obj is MyList<T> {
        return obj.discriminator === "LIST";
    }
}
