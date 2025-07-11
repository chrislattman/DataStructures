package dsa

// MySet is an interface which defines methods for sets.
type MySet[T comparable] interface {
	// Add inserts the given element to a set only if it was not already there, and
	// reports whether insertion was successful.
	Add(element T) bool

	// Clear empties a set of all elements.
	Clear()

	// Contains reports whether the given element is in a set.
	Contains(element T) bool

	// Equals reports whether obj is equal to a set.
	Equals(obj any) bool

	// IsEmpty reports whether a set has no elements.
	IsEmpty() bool

	// Remove attempts to delete the given element from a set, and reports whether
	// element was found.
	Remove(element T) bool

	// Size returns the number of elements in a set.
	Size() uint

	// ToArray returns an array containing all the elements in a set.
	ToArray() []T

	// ToString returns a string representation of a set, e.g.
	// "[element1, element2, element3, ..., elementN]".
	ToString() string
}
