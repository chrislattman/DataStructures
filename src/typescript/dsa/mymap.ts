import MyList from "./mylist";

/**
 * Interface which defines methods for maps.
 */
export default interface MyMap<K, V> {
    /**
     * Empties this map of all elements.
     */
    clear(): void;

    /**
     * Checks if a key is in this map.
     * @param key key to check for
     * @returns true if key was found, false otherwise
     */
    containsKey(key: K): boolean;

    /**
     * Checks if a value is in this map.
     * @param value value to check for
     * @returns true if value was found, false otherwise
     */
    containsValue(value: V): boolean;

    /**
     * Compares an object with this map for equality.
     * @param obj object to compare to this map
     * @returns true if object and this map are equal
     */
    equals(obj: object): boolean;

    /**
     * Returns the value associated with the specified key.
     * @param key key to search for
     * @returns value associated with key, or null if key was not found
     */
    getValue(key: K): V;

    /**
     * Returns the value associated with the specified key, or a default value
     * if the key was not found.
     * @param key key to search for
     * @param defaultValue value to return if key was not found in this map
     * @returns value associated with key, or defaultValue if key was not found
     */
    getOrDefault(key: K, defaultValue: V): V;

    /**
     * Checks if this map has no key-value pairs.
     * @returns true if this map is empty, false otherwise
     */
    isEmpty(): boolean;

    /**
     * Returns a copy of the keys in this map.
     * @returns a list of the keys
     */
    keyList(): MyList<K>;

    /**
     * Inserts a key-value pair into this map. Null keys and null values are not
     * permitted.
     * @param key key to add
     * @param value value associated with key
     * @returns previous value associated with key, or null if either key was
     * not found, key is null, or value is null
     */
    put(key: K, value: V): V;

    /**
     * Inserts a key-value pair into this map only if key was not found. Null
     * keys and null values are not permitted.
     * @param key key to add
     * @param value value associated with key
     * @returns current value associated with key, or null if either key was not
     * found, key is null, or value is null
     */
    putIfAbsent(key: K, value: V): V;

    /**
     * Removes a key-value pair from this map.
     * @param key key to remove
     * @returns value associated with key prior to removal, or null if key was
     * not found
     */
    remove(key: K): V;

    /**
     * Removes a key-value pair from this map only if the key's current value
     * matches the specified value.
     * @param key key to remove
     * @param value value to check for
     * @returns true if the specific key-value pair was found, false otherwise
     */
    removeIfPresent(key: K, value: V): boolean;

    /**
     * Replaces the value for a key with another value. Null values are not
     * permitted.
     * @param key key to modify value of
     * @param value new value for key
     * @returns previous value associated with key, or null if key was not found
     * or value is null
     */
    replace(key: K, value: V): V;

    /**
     * Replaces the value for a key only if the key's current value matches the
     * specified old value. Null values are not permitted.
     * @param key key to modify value of
     * @param oldValue old value for key
     * @param newValue new value for key
     * @returns true if the key was found and had a value of oldValue, false
     * otherwise
     */
    replaceIfPresent(key: K, oldValue: V, newValue: V): boolean;

    /**
     * Returns the number of key-value pairs in this map.
     * @returns size of map
     */
    size(): number;

    /**
     * Returns a string representation of this map, e.g.
     * "{key1=value1, key2=value2, key3=value3, ..., keyN=valueN}".
     * @returns string form of this map
     */
    toString(): string;

    /**
     * Returns a copy of the values in this map.
     * @returns a list of the values
     */
    values(): MyList<V>;
}
