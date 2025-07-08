package dsa

import "errors"

// node is an internal struct used by this linked list.
type node[T comparable] struct {
	data T
	next *node[T]
}

// MyLinkedList is a singly linked list data structure.
type MyLinkedList[T comparable] struct {
	head *node[T]
	size uint32
}

// NewMyLinkedList returns a new MyLinkedList struct pointer.
func NewMyLinkedList[T comparable]() *MyLinkedList[T] {
	newlist := new(MyLinkedList[T])
	newlist.head = nil
	newlist.size = 0
	return newlist
}

// Add inserts element elem at index idx of a linked list. Returns an error if
// idx is out of bounds (idx must be between 0 and Size(), inclusive).
func (m *MyLinkedList[T]) Add(elem T, idx uint32) error {
	return nil
}

// AddToEnd inserts element elem at the end of a linked list.
func (m *MyLinkedList[T]) AddToEnd(elem T) {
	m.Add(elem, m.size)
}

// Clear empties a linked list of all elements.
func (m *MyLinkedList[T]) Clear() {

}

// Contains reports whether element elem is in a linked list.
func (m MyLinkedList[T]) Contains(elem T) bool {
	return false
}

// Equals reports whether obj is equal to a linked list.
func (m MyLinkedList[T]) Equals(obj interface{}) bool {
	return false
}

// Get returns, but does not remove, an element from a linked list at index idx.
// Returns an error if idx is out of bounds (idx must be between 0 and
// Size() - 1, inclusive).
func (m MyLinkedList[T]) Get(idx uint32) (T, error) {
	return make([]T, 1)[0], nil
}

// IndexOf returns the index of the first occurrence of element elem found
// in a linked list, or -1 if not found.
func (m MyLinkedList[T]) IndexOf(elem T) int64 {
	return -1
}

// IsEmpty reports whether a linked list has no elements.
func (m MyLinkedList[T]) IsEmpty() bool {
	return true
}

// IndexOf returns the index of the last occurrence of element elem found
// in a linked list, or -1 if not found.
func (m MyLinkedList[T]) LastIndexOf(elem T) int64 {
	return -1
}

// Remove retrieves and removes an element from a linked list at index idx.
// Returns an error if idx is out of bounds (idx must be between 0 and
// Size() - 1, inclusive).
func (m *MyLinkedList[T]) Remove(idx uint32) (T, error) {
	return make([]T, 1)[0], nil
}

// RemoveElement attempts to remove element elem from a linked list, and reports
// whether the deletion was successful.
func (m *MyLinkedList[T]) RemoveElement(elem T) bool {
	return false
}

// Set sets the existing element at index idx of a linked list to element elem
// and returns the existing element. Returns an error if idx is out of bounds
// (idx must be between 0 and Size() - 1, inclusive).
func (m *MyLinkedList[T]) Set(idx uint32, elem T) (T, error) {
	return make([]T, 1)[0], nil
}

// Size returns the number of elements in a linked list.
func (m MyLinkedList[T]) Size() uint32 {
	return 0
}

// String overrides String() in the Stringer interface. Calls toString().
func (m MyLinkedList[T]) String() string {
	return m.ToString()
}

// ToArray returns an array containing all the elements in a linked list.
func (m MyLinkedList[T]) ToArray() []T {
	return make([]T, 0)
}

// ToString returns a string representation of a linked list, e.g.
// "[element1, element2, element3, ..., elementN]".
func (m MyLinkedList[T]) ToString() string {
	return "[]"
}

// checkIndex validates that index idx is in bounds. Returns an error if idx is
// greater than or equal to upperBound.
func (m MyLinkedList[T]) checkIndex(idx uint32, upperBound uint32) error {
	if idx >= upperBound {
		return errors.New("index is out of bounds")
	}
	return nil
}
