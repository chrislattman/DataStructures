import { MyArrayList } from "./myarraylist";
import { MyList } from "./mylist";
import { MyMap } from "./mymap";

/**
 * A hash map data structure utilizing quadratic probing (open addressing).
 * Also called a hash table.
 */
export class MyHashMap<K, V> implements MyMap<K, V> {
    private keys: K[];
    private values_array: V[];
    private map_size: number;
    private loadFactor: number;
    private static readonly defaultCapacity = 16;
    private static readonly defaultLoadFactor = 0.75;

    /**
     * Constructs a hash map instance with the specified initial capacity and
     * load factor.
     * @param initialCapacity initial capacity of this hash map. Defaults to 16.
     * @param loadFactor maximum value of (number of key-value pairs / number of
     * total slots in hash map) before rehashing occurs. Defaults to 0.75.
     */
    constructor(initialCapacity?: number, loadFactor?: number) {
        if (initialCapacity === undefined) {
            initialCapacity = MyHashMap.defaultCapacity;
        } else if (initialCapacity < 0) {
            throw new Error("Negative capacity provided");
        }
        if (loadFactor === undefined) {
            loadFactor = MyHashMap.defaultLoadFactor;
        } else if (loadFactor <= 0) {
            throw new Error("Load factor is nonpositive");
        }
        this.keys = new Array<K>(initialCapacity);
        this.values_array = new Array<V>(initialCapacity);
        this.loadFactor = loadFactor;
        this.map_size = 0;
    }

    clear(): void {

    }

    containsKey(key: K): boolean {
        return false;
    }

    containsValue(value: V): boolean {
        return false;
    }

    equals(obj: object): boolean {
        return false;
    }

    getValue(key: K): V {
        return null;
    }

    getOrDefault(key: K, defaultValue: V): V {
        return null;
    }

    isEmpty(): boolean {
        return true;
    }

    keyList(): MyList<K> {
        return new MyArrayList<K>();
    }

    put(key: K, value: V): V {
        return null;
    }

    putIfAbsent(key: K, value: V): V {
        return null;
    }

    remove(key: K): V {
        return null;
    }

    removeIfPresent(key: K, value: V): boolean {
        return false;
    }

    replace(key: K, value: V): V {
        return null;
    }

    replaceIfPresent(key: K, oldValue: V, newValue: V): boolean {
        return false;
    }

    size(): number {
        return 0;
    }

    toString(): string {
        return "{}";
    }

    values(): MyList<V> {
        return new MyArrayList<V>();
    }

    /**
     * Internal function used to add or modify a key-value pair in this hash
     * map.
     * @param key key to add
     * @param newValue value to be associated with key
     * @param oldValue current value to check for (existing key only), leave as
     * null if not applicable
     * @param addOnlyIfAbsent if false, replace current value with specified new
     * value
     * @param addOnlyIfKeyExists if true, only replace value if key already
     * exists
     * @returns previous or current value associated with key, or null if either
     * key was not found, key is null, or newValue is null
     */
    private insert(key: K, newValue: V, oldValue: V, addOnlyIfAbsent: boolean,
            addOnlyIfKeyExists: boolean): V {
        return null;
    }

    /**
     * Increases the hash map size and rehashes the key-value pairs when load
     * factor has been surpassed.
     */
    private resizeMap(): void {

    }
}
