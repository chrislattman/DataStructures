package dsa

import "errors"

const defaultCapacityArrayList = 10
const minArrLenThresholdArrayList = 100

// MyArrayList is an array list data structure.
type MyArrayList[T comparable] struct {
	array []T
	size  uint32
}

// NewArrayListDefault returns a new MyArrayList struct pointer with a default
// initial capacity of 10.
func NewArrayListDefault[T comparable]() *MyArrayList[T] {
	return NewArrayList[T](defaultCapacityArrayList)
}

// NewArrayList returns a new MyArrayList struct pointer with initial capacity
// initialCapacity.
func NewArrayList[T comparable](initialCapacity uint32) *MyArrayList[T] {
	newlist := new(MyArrayList[T])
	newlist.array = make([]T, initialCapacity)
	newlist.size = 0
	return newlist
}

// Add inserts element elem at index idx of an array list. Returns an error if
// idx is out of bounds (idx must be between 0 and Size(), inclusive).
func (m *MyArrayList[T]) Add(elem T, idx uint32) error {
	return nil
}

// AddToEnd inserts element elem at the end of an array list.
func (m *MyArrayList[T]) AddToEnd(elem T) {
	m.Add(elem, m.size)
}

// Clear empties an array list of all elements.
func (m *MyArrayList[T]) Clear() {

}

// Contains reports whether element elem is in an array list.
func (m MyArrayList[T]) Contains(elem T) bool {
	return false
}

// Equals reports whether obj is equal to an array list.
func (m MyArrayList[T]) Equals(obj interface{}) bool {
	return false
}

// Get returns, but does not remove, an element from an array list at index idx.
// Returns an error if idx is out of bounds (idx must be between 0 and
// Size() - 1, inclusive).
func (m MyArrayList[T]) Get(idx uint32) (T, error) {
	return make([]T, 1)[0], nil
}

// IndexOf returns the index of the first occurrence of element elem found
// in an array list, or -1 if not found.
func (m MyArrayList[T]) IndexOf(elem T) int64 {
	return -1
}

// IsEmpty reports whether an array list has no elements.
func (m MyArrayList[T]) IsEmpty() bool {
	return true
}

// IndexOf returns the index of the last occurrence of element elem found
// in an array list, or -1 if not found.
func (m MyArrayList[T]) LastIndexOf(elem T) int64 {
	return -1
}

// Remove retrieves and removes an element from an array list at index idx.
// Returns an error if idx is out of bounds (idx must be between 0 and
// Size() - 1, inclusive).
func (m *MyArrayList[T]) Remove(idx uint32) (T, error) {
	return make([]T, 1)[0], nil
}

// RemoveElement attempts to remove element elem from an array list, and reports
// whether the deletion was successful.
func (m *MyArrayList[T]) RemoveElement(elem T) bool {
	return false
}

// Set sets the existing element at index idx of an array list to element elem
// and returns the existing element. Returns an error if idx is out of bounds
// (idx must be between 0 and Size() - 1, inclusive).
func (m *MyArrayList[T]) Set(idx uint32, elem T) (T, error) {
	return make([]T, 1)[0], nil
}

// Size returns the number of elements in an array list.
func (m MyArrayList[T]) Size() uint32 {
	return 0
}

// ToArray returns an array containing all the elements in an array list.
func (m MyArrayList[T]) ToArray() []T {
	return make([]T, 0)
}

// ToString returns a string representation of an array list, e.g.
// "[element1, element2, element3, ..., elementN]".
func (m MyArrayList[T]) ToString() string {
	return "[]"
}

// checkCapacity doubles or halves the size of the internal array of an array
// list depending on size. Used in Add and Remove methods.
func (m *MyArrayList[T]) checkCapacity() {

}

// checkIndex validates that index idx is in bounds. Returns an error if idx is
// greater than or equal to upperBound.
func (m MyArrayList[T]) checkIndex(idx uint32, upperBound uint32) error {
	if idx >= upperBound {
		return errors.New("index is out of bounds")
	}
	return nil
}
