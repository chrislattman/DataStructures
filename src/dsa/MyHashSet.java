package dsa;

/**
 * A hash set data structure built upon a hash map.
 *
 * @param <T> data type
 */
public class MyHashSet<T> implements MySet<T> {
    private final MyHashMap<T, Object> map;
    private static final int defaultCapacity = 16;
    private static final float defaultLoadFactor = 0.75f;

    /**
     * Constructs a hash set instance with a default initial capacity of 16 and a default load factor of 0.75.
     */
    public MyHashSet() {
        this(defaultCapacity, defaultLoadFactor);
    }

    /**
     * Constructs a hash set instance with the specified initial capacity and a default load factor of 0.75.
     *
     * @param initialCapacity initial capacity of this hash set
     * @throws IllegalArgumentException if initialCapacity is negative
     */
    public MyHashSet(int initialCapacity) throws IllegalArgumentException {
        this(initialCapacity, defaultLoadFactor);
    }

    /**
     * Constructs a hash set instance with the specified initial capacity and load factor.
     *
     * @param initialCapacity initial capacity of this hash set
     * @param loadFactor maximum value of (number of elements / number of total slots in hash set) before rehashing
     *                   occurs
     * @throws IllegalArgumentException if initialCapacity is negative or loadFactor is nonpositive
     */
    public MyHashSet(int initialCapacity, float loadFactor) throws IllegalArgumentException {
        map = new MyHashMap<>(initialCapacity, loadFactor);
    }

    @Override
    public boolean add(T element) {
        int currentSize = map.size();
        map.putIfAbsent(element, new Object());
        int newSize = map.size();
        return currentSize != newSize;
    }

    @Override
    public void clear() {
        map.clear();
    }

    @Override
    public boolean contains(Object element) {
        return map.containsKey(element);
    }

    @Override
    @SuppressWarnings("unchecked")
    public boolean equals(Object object) {
        if (object == this) {
            return true;
        }
        if (object == null) {
            return false;
        }
        if (!(object instanceof MyHashSet<?> obj)) {
            return false;
        }
        if (obj.size() != size()) {
            return false;
        }
        T[] elements = (T[]) obj.toArray();
        T[] array = (T[]) toArray();
        for (int i = 0; i < array.length; i++) {
            if (!elements[i].equals(array[i])) {
                return false;
            }
        }
        return true;
    }

    @Override
    public boolean isEmpty() {
        return map.isEmpty();
    }

    @Override
    public boolean remove(Object element) {
        return map.remove(element) != null;
    }

    @Override
    public int size() {
        return map.size();
    }

    @Override
    public Object[] toArray() {
        MyArrayList<T> keys = map.keyList();
        Object[] array = new Object[map.size()];
        for (int i = 0; i < array.length; i++) {
            array[i] = keys.get(i);
        }
        return array;
    }

    @Override
    public String toString() {
        MyArrayList<T> keys = map.keyList();
        StringBuilder builder = new StringBuilder("[");
        int length = map.size();
        int lastIndex = length - 1;
        for (int i = 0; i < length; i++) {
            builder.append(keys.get(i));
            if (i != lastIndex) {
                builder.append(", ");
            }
        }
        builder.append("]");
        return builder.toString();
    }
}
