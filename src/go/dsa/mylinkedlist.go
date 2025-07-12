package dsa

import (
	"errors"
	"fmt"
	"strings"
)

// node is an internal struct used by this linked list.
type node[T comparable] struct {
	data T
	next *node[T]
}

// MyLinkedList is a singly linked list data structure.
type MyLinkedList[T comparable] struct {
	head *node[T]
	size uint
}

// NewMyLinkedList returns a new MyLinkedList struct pointer.
func NewMyLinkedList[T comparable]() *MyLinkedList[T] {
	newlist := new(MyLinkedList[T])
	newlist.head = nil
	newlist.size = 0
	return newlist
}

// Add inserts the given element at the given index of a linked list. Returns an error if
// index is out of bounds (index must be between 0 and Size(), inclusive).
func (m *MyLinkedList[T]) Add(index uint, element T) error {
	err := m.checkIndex(index, m.size+1)
	if err != nil {
		return err
	}
	if m.IsEmpty() {
		m.head = &node[T]{data: element}
	} else {
		newNode := &node[T]{data: element}
		if index == 0 {
			newNode.next = m.head
			m.head = newNode
		} else {
			current := m.head
			stop := int(index) - 1
			for range stop {
				current = current.next
			}
			newNode.next = current.next
			current.next = newNode
		}
	}
	m.size++
	return nil
}

// AddToEnd inserts the given element at the end of a linked list.
func (m *MyLinkedList[T]) AddToEnd(element T) {
	m.Add(m.size, element)
}

// Clear empties a linked list of all elements.
func (m *MyLinkedList[T]) Clear() {
	m.head = nil
	m.size = 0
}

// Contains reports whether the given element is in a linked list.
func (m MyLinkedList[T]) Contains(element T) bool {
	for current := m.head; current != nil; current = current.next {
		if element == current.data {
			return true
		}
	}
	return false
}

// Equals reports whether obj is equal to a linked list.
func (m MyLinkedList[T]) Equals(obj any) bool {
	return false
}

// Get returns, but does not remove, an element from a linked list at the given index.
// Returns an error if index is out of bounds (index must be between 0 and
// Size() - 1, inclusive).
func (m MyLinkedList[T]) Get(index uint) (T, error) {
	err := m.checkIndex(index, m.size)
	if err != nil {
		return make([]T, 1)[0], err
	}
	current := m.head
	for i := 0; i < int(index); i++ {
		current = current.next
	}
	return current.data, nil
}

// IndexOf returns the index of the first occurrence of the given element found
// in a linked list, or -1 if not found.
func (m MyLinkedList[T]) IndexOf(element T) int {
	current := m.head
	for i := 0; i < int(m.size); i++ {
		if element == current.data {
			return i
		}
		current = current.next
	}
	return -1
}

// IsEmpty reports whether a linked list has no elements.
func (m MyLinkedList[T]) IsEmpty() bool {
	return m.size == 0
}

// IndexOf returns the index of the last occurrence of the given element found
// in a linked list, or -1 if not found.
func (m MyLinkedList[T]) LastIndexOf(element T) int {
	index := -1
	current := m.head
	for i := 0; i < int(m.size); i++ {
		if element == current.data {
			index = i
		}
		current = current.next
	}
	return index
}

// Remove retrieves and removes an element from a linked list at the given index.
// Returns an error if index is out of bounds (index must be between 0 and
// Size() - 1, inclusive).
func (m *MyLinkedList[T]) Remove(index uint) (T, error) {
	err := m.checkIndex(index, m.size)
	if err != nil {
		return make([]T, 1)[0], err
	}
	if index == 0 {
		oldValue := m.head.data
		m.head = m.head.next
		m.size--
		return oldValue, nil
	}
	current := m.head
	stop := index - 1
	for range stop {
		current = current.next
	}
	oldValue := current.next.data
	current.next = current.next.next
	m.size--
	return oldValue, nil
}

// RemoveElement attempts to remove the given element from a linked list, and reports
// whether the deletion was successful.
func (m *MyLinkedList[T]) RemoveElement(element T) bool {
	if m.head != nil && element == m.head.data {
		m.head = m.head.next
		m.size--
		return true
	}
	for current := m.head; current != nil; current = current.next {
		nextNode := current.next
		if nextNode != nil && element == nextNode.data {
			current.next = nextNode.next
			m.size--
			return true
		}
	}
	return false
}

// Set sets the existing element at the given index of a linked list to the given element
// and returns the existing element. Returns an error if index is out of bounds
// (index must be between 0 and Size() - 1, inclusive).
func (m *MyLinkedList[T]) Set(index uint, element T) (T, error) {
	err := m.checkIndex(index, m.size)
	if err != nil {
		return make([]T, 1)[0], err
	}
	current := m.head
	for i := 0; i < int(index); i++ {
		current = current.next
	}
	oldValue := current.data
	current.data = element
	return oldValue, nil
}

// Size returns the number of elements in a linked list.
func (m MyLinkedList[T]) Size() uint {
	return m.size
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
	var builder strings.Builder
	builder.WriteString("[")
	for current := m.head; current != nil; current = current.next {
		builder.WriteString(fmt.Sprint(current.data))
		if current.next != nil {
			builder.WriteString(", ")
		}
	}
	builder.WriteString("]")
	return builder.String()
}

// checkIndex validates that the given index is in bounds. Returns an error if index is
// greater than or equal to upperBound.
func (m MyLinkedList[T]) checkIndex(index, upperBound uint) error {
	if index >= upperBound {
		return errors.New("index is out of bounds")
	}
	return nil
}
