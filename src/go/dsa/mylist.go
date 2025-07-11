package dsa

//go:generate mockgen -source=mylist.go -destination=mock_mylist.go -package=dsa

// MyList is an interface which defines methods for lists.
type MyList[T comparable] interface {
	// Add inserts the given element at the given index of a list. Returns an error if index
	// is out of bounds (index must be between 0 and Size(), inclusive).
	Add(index uint, element T) error

	// AddToEnd inserts the given element at the end of a list.
	AddToEnd(element T)

	// Clear empties a list of all elements.
	Clear()

	// Contains reports whether the given element is in a list.
	Contains(element T) bool

	// Equals reports whether obj is equal to a list.
	Equals(obj any) bool

	// Get returns, but does not remove, an element from a list at the given index.
	// Returns an error if index is out of bounds (index must be between 0 and
	// Size() - 1, inclusive).
	Get(index uint) (T, error)

	// IndexOf returns the index of the first occurrence of the given element found
	// in a list, or -1 if not found.
	IndexOf(element T) int

	// IsEmpty reports whether a list has no elements.
	IsEmpty() bool

	// IndexOf returns the index of the last occurrence of the given element found
	// in a list, or -1 if not found.
	LastIndexOf(element T) int

	// Remove retrieves and removes an element from a list at the given index.
	// Returns an error if index is out of bounds (index must be between 0 and
	// Size() - 1, inclusive).
	Remove(index uint) (T, error)

	// RemoveElement attempts to remove the given element from a list, and reports
	// whether the deletion was successful.
	RemoveElement(element T) bool

	// Set sets the existing element at the given index of a list to the given element and
	// returns the existing element. Returns an error if index is out of bounds
	// (index must be between 0 and Size() - 1, inclusive).
	Set(index uint, element T) (T, error)

	// Size returns the number of elements in a list.
	Size() uint

	// ToArray returns an array containing all the elements in a list.
	ToArray() []T

	// ToString returns a string representation of a list, e.g.
	// "[element1, element2, element3, ..., elementN]".
	ToString() string
}
