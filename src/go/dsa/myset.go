package dsa

// MySet is an interface which defines methods for sets.
type MySet[T comparable] interface {
	// Add inserts element elem to a set only if it was not already there, and
	// reports whether insertion was successful.
	Add(elem T) bool

	// Clear empties a set of all elements.
	Clear()

	// Contains reports whether element elem is in a set.
	Contains(elem T) bool

	// Equals reports whether obj is equal to a set.
	Equals(obj any) bool

	// IsEmpty reports whether a set has no elements.
	IsEmpty() bool

	// Remove attempts to delete element elem from a set, and reports whether
	// elem was found.
	Remove(elem T) bool

	// Size returns the number of elements in a set.
	Size() uint32

	// ToArray returns an array containing all the elements in a set.
	ToArray() []T

	// ToString returns a string representation of a set, e.g.
	// "[element1, element2, element3, ..., elementN]".
	ToString() string
}
