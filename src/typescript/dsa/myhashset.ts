import MyHashMap from "./myhashmap";
import MySet from "./myset";

/**
 * A hash set data structure built upon a hash map.
 */
export default class MyHashSet<T> implements MySet<T> {
    private map: MyHashMap<T, number>;

    /**
     * Constructs a hash set instance with the specified initial capacity and load factor.
     * @param initialCapacity initial capacity of this hash set
     * @param loadFactor maximum value of (number of key-value pairs / number of
     * total slots in hash set) before rehashing occurs
     */
    constructor(initialCapacity?: number, loadFactor?: number) {
        this.map = new MyHashMap<T, number>(initialCapacity, loadFactor);
    }

    add(element: T): boolean {
        return true;
    }

    clear(): void {

    }

    contains(element: T): boolean {
        return false;
    }

    equals(obj: object): boolean {
        return false;
    }

    isEmpty(): boolean {
        return true;
    }

    remove(element: T): boolean {
        return false;
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
}
