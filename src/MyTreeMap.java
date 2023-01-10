/**
 * A tree map data structure based on an AVL tree.
 *
 * @param <K> key data type which much implement Comparable
 * @param <V> value data type
 */
public class MyTreeMap<K extends Comparable<? super K>, V> implements MyMap<K, V> {
    private Node root;
    private int size;

    /**
     * Default constructor for this tree map.
     */
    public MyTreeMap() {
        clear();
    }

    /**
     * Returns the least key greater than or equal to the given key, or null if no such key exists.
     *
     * @param key key to reference
     * @return ceiling key
     */
    public K ceilingKey(K key) {
        return null;
    }

    @Override
    public void clear() {
        root = null;
        size = 0;
    }

    @Override
    public boolean containsKey(Object key) {
        return getOrDefault(key, null) != null;
    }

    @Override
    public boolean containsValue(Object value) {
        return findValue(root, value);
    }

    @Override
    public boolean equals(Object object) {
        if (object == this) {
            return true;
        }
        if (object == null) {
            return false;
        }
        if (!(object instanceof MyTreeMap<?, ?> obj)) {
            return false;
        }
        if (obj.size() != size) {
            return false;
        }
        MyArrayList<?> keys = obj.keyList();
        MyArrayList<?> values = obj.values();
        return keys.equals(keyList()) && values.equals(values());
    }

    /**
     * Returns the smallest key.
     *
     * @return first key
     */
    public K firstKey() {
        K key = null;
        Node current = root;
        while (current.left != null) {
            key = current.key;
            current = current.left;
        }
        return key;
    }

    /**
     * Returns the greatest key less than or equal to the given key, or null if no such key exists.
     *
     * @param key key to reference
     * @return floor key
     */
    public K floorKey(K key) {
        return null;
    }

    @Override
    public V get(Object key) {
        return getOrDefault(key, null);
    }

    @Override
    public V getOrDefault(Object key, V defaultValue) {
        V value = findKey(root, key);
        if (value == null) {
            return defaultValue;
        }
        return value;
    }

    /**
     * Returns the least key strictly greater than the given key, or null if no such key exists.
     *
     * @param key key to reference
     * @return next greater key
     */
    public K higherKey(K key) {
        return null;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public MyArrayList<K> keyList() {
        MyArrayList<K> keys = new MyArrayList<>();
        collectKeys(root, keys);
        return keys;
    }

    /**
     * Returns the largest key.
     *
     * @return last key
     */
    public K lastKey() {
        K key = null;
        Node current = root;
        while (current.right != null) {
            key = current.key;
            current = current.right;
        }
        return key;
    }

    /**
     * Returns the greatest key strictly less than the given key, or null if no such key exists.
     *
     * @param key key to reference
     * @return greatest prior key
     */
    public K lowerKey(K key) {
        return null;
    }

    @Override
    public V put(K key, V value) {
        V result = insert(root, key, value, null, false, false);
        update(root);
        balance(root);
        return result;
    }

    @Override
    public V putIfAbsent(K key, V value) {
        V result = insert(root, key, value, null, true, false);
        update(root);
        balance(root);
        return result;
    }

    @Override
    public V remove(Object key) {
        // TODO
        return null;
    }

    @Override
    public boolean remove(Object key, Object value) {
        // TODO
        return false;
    }

    @Override
    public V replace(K key, V value) {
        return insert(root, key, value, null, false, true);
    }

    @Override
    public boolean replace(K key, V oldValue, V newValue) {
        return insert(root, key, newValue, oldValue, false, true) != null;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("{");
        MyArrayList<K> keys = keyList();
        MyArrayList<V> values = values();
        int lastIndex = size - 1;
        for (int i = 0; i < size; i++) {
            builder.append(keys.get(i));
            builder.append("=");
            builder.append(values.get(i));
            if (i != lastIndex) {
                builder.append(", ");
            }
        }
        builder.append("}");
        return builder.toString();
    }

    @Override
    public MyArrayList<V> values() {
        MyArrayList<V> values = new MyArrayList<>();
        collectValues(root, values);
        return values;
    }

    /**
     * Performs an in-order traversal of the nodes in this tree map and stores the found keys in a list.
     *
     * @param node current node
     * @param list list to add keys to
     */
    private void collectKeys(Node node, MyArrayList<K> list) {
        while (node.left != null) {
            collectKeys(node.left, list);
        }
        list.add(node.key);
        if (node.right != null) {
            collectKeys(node.right, list);
        }
    }

    /**
     * Performs an in-order traversal of the nodes in this tree map and stores the found values in a list.
     *
     * @param node current node
     * @param list list to add values to
     */
    private void collectValues(Node node, MyArrayList<V> list) {
        while (node.left != null) {
            collectValues(node.left, list);
        }
        list.add(node.value);
        if (node.right != null) {
            collectValues(node.right, list);
        }
    }

    /**
     * Helper method for getOrDefault.
     *
     * @param node current node
     * @param key key to search for
     * @return value associated with key, or null if key was not found
     */
    @SuppressWarnings("unchecked")
    private V findKey(Node node, Object key) {
        if (node == null || key == null) {
            return null;
        }

        if (node.key.equals(key)) {
            return node.value;
        } else if (node.key.compareTo((K) key) > 0) {
            return findKey(node.left, key);
        } else {
            return findKey(node.right, key);
        }
    }

    /**
     * Helper method for containsValue.
     *
     * @param node current node
     * @param value value to search for
     * @return true if value was found, false otherwise
     */
    private boolean findValue(Node node, Object value) {
        if (node == null || value == null) {
            return false;
        }
        if (node.value.equals(value)) {
            return true;
        }
        return findValue(node.left, value) || findValue(node.right, value);
    }

    /**
     * Internal function used to add or modify a key-value pair in this map.
     *
     * @param node current node
     * @param key key to add
     * @param newValue value to be associated with key
     * @param oldValue current value to check for (existing key only), leave as null if not applicable
     * @param addOnlyIfAbsent if false, replace current value with specified new value
     * @param addOnlyIfKeyExists if true, only replace value if key already exists
     * @return previous or current value associated with key, or null if either key was not found, key is null,
     * or newValue is null
     */
    private V insert(Node node, K key, V newValue, V oldValue, boolean addOnlyIfAbsent, boolean addOnlyIfKeyExists) {
        if (key == null || newValue == null) {
            return null;
        }
        if (node == null) {
            if (!addOnlyIfKeyExists) {
                node = new Node();
                node.key = key;
                node.value = newValue;
                ++size;
            }
            return null;
        }
        if (node.key.equals(key)) {
            V previous = node.value;
            if ((oldValue == null || oldValue.equals(previous)) && !addOnlyIfAbsent) {
                node.value = newValue;
            } else if (oldValue != null) {
                return null;
            }
            return previous;
        } else if (node.key.compareTo(key) < 0) {
            return insert(node.left, key, newValue, oldValue, addOnlyIfAbsent, addOnlyIfKeyExists);
        } else {
            return insert(node.right, key, newValue, oldValue, addOnlyIfAbsent, addOnlyIfKeyExists);
        }
    }

    /**
     * Updates balance factor and height values for a node and its children.
     *
     * @param node root of subtree to update
     */
    private void update(Node node) {
        // TODO
    }

    /**
     * Balances the subtree of a given node.
     *
     * @param node root of subtree to update
     */
    private void balance(Node node) {
        // TODO
    }

    /**
     * Internal node object used by this tree map.
     */
    private class Node {
        int balanceFactor = 0;
        int height = 0;
        K key = null;
        V value = null;
        Node left = null;
        Node right = null;
    }
}
