package dsa

// MyList is an interface which defines methods for lists.
type MyList[T comparable] interface {
	// Add inserts element elem at index idx of a list. Returns an error if idx
	// is out of bounds (idx must be between 0 and Size(), inclusive).
	Add(elem T, idx uint32) error

	// AddToEnd inserts element elem at the end of a list.
	AddToEnd(elem T)

	// Clear empties a list of all elements.
	Clear()

	// Contains reports whether element elem is in a list.
	Contains(elem T) bool

	// Equals reports whether obj is equal to a list.
	Equals(obj any) bool

	// Get returns, but does not remove, an element from a list at index idx.
	// Returns an error if idx is out of bounds (idx must be between 0 and
	// Size() - 1, inclusive).
	Get(idx uint32) (T, error)

	// IndexOf returns the index of the first occurrence of element elem found
	// in a list, or -1 if not found.
	IndexOf(elem T) int64

	// IsEmpty reports whether a list has no elements.
	IsEmpty() bool

	// IndexOf returns the index of the last occurrence of element elem found
	// in a list, or -1 if not found.
	LastIndexOf(elem T) int64

	// Remove retrieves and removes an element from a list at index idx.
	// Returns an error if idx is out of bounds (idx must be between 0 and
	// Size() - 1, inclusive).
	Remove(idx uint32) (T, error)

	// RemoveElement attempts to remove element elem from a list, and reports
	// whether the deletion was successful.
	RemoveElement(elem T) bool

	// Set sets the existing element at index idx of a list to element elem and
	// returns the existing element. Returns an error if idx is out of bounds
	// (idx must be between 0 and Size() - 1, inclusive).
	Set(idx uint32, elem T) (T, error)

	// Size returns the number of elements in a list.
	Size() uint32

	// ToArray returns an array containing all the elements in a list.
	ToArray() []T

	// ToString returns a string representation of a list, e.g.
	// "[element1, element2, element3, ..., elementN]".
	ToString() string
}
