package dsa

// MyMap is an interface which defines methods for maps.
type MyMap[K, V comparable] interface {
	// Clear empties a map of all elements.
	Clear()

	// ContainsKey reports whether key is in a map.
	ContainsKey(key K) bool

	// ContainsValue reports whether value is in a map.
	ContainsValue(value V) bool

	// Equals reports whether obj is equal to a map.
	Equals(obj any) bool

	// GetValue returns the value associated with key. False is returned if key
	// was not found.
	GetValue(key K) (V, bool)

	// GetOrDefault returns the value associated with key, or defaultValue if
	// key was not found.
	GetOrDefault(key K, defaultValue V) V

	// IsEmpty reports whether a map has no key-value pairs.
	IsEmpty() bool

	// KeyList returns a copy of the keys in a map.
	KeyList() MyList[K]

	// Put inserts a key-value pair into a map, and returns the previous value
	// associated with key. False is returned if key was not found.
	Put(key K, value V) (V, bool)

	// PutIfAbsent inserts a key-value pair into a map only if key was not
	// found, and returns either value if key was found or false if key was not
	// found.
	PutIfAbsent(key K, value V) (V, bool)

	// Remove deletes a key-value pair from a map and returns either the value
	// previously associated with key, or false if key was not found.
	Remove(key K) (V, bool)

	// RemoveIfPresent deletes a key-value pair from a map only if key maps to
	// value, and reports whether the pair was found.
	RemoveIfPresent(key K, value V) bool

	// Replace maps key to newValue and returns the previous value associated
	// with key. False is returned if key was not found.
	Replace(key K, newValue V) (V, bool)

	// ReplaceIfPresent maps key to newValue only if key already maps to
	// oldValue, and reports whether this replacement was successful.
	ReplaceIfPresent(key K, oldValue, newValue V) bool

	// Size returns the number of key-value pairs in a map.
	Size() uint

	// ToString returns a string representation of a map, e.g.
	// "{key1=value1, key2=value2, key3=value3, ..., keyN=valueN}".
	ToString() string

	// Values returns a copy of the values in a map.
	Values() MyList[V]
}
