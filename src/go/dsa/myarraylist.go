package dsa

import (
	"errors"
	"fmt"
	"strings"
)

const defaultCapacityArrayList = 10
const minArrLenThresholdArrayList = 100

// MyArrayList is an array list data structure.
type MyArrayList[T comparable] struct {
	array []T
	size  uint
}

// NewArrayListDefault returns a new MyArrayList struct pointer with a default
// initial capacity of 10.
func NewArrayListDefault[T comparable]() *MyArrayList[T] {
	return NewArrayList[T](defaultCapacityArrayList)
}

// NewArrayList returns a new MyArrayList struct pointer with initial capacity
// initialCapacity.
func NewArrayList[T comparable](initialCapacity uint) *MyArrayList[T] {
	newlist := new(MyArrayList[T])
	newlist.array = make([]T, initialCapacity)
	newlist.size = 0
	return newlist
}

// Add inserts the given element at the given index of an array list. Returns an error if
// index is out of bounds (index must be between 0 and Size(), inclusive).
func (m *MyArrayList[T]) Add(index uint, element T) error {
	err := m.checkIndex(index, m.size+1)
	if err != nil {
		return err
	}
	m.checkCapacity()
	if index < m.size {
		copy(m.array[index+1:m.size+1], m.array[index:m.size])
	}
	m.array[index] = element
	m.size++
	return nil
}

// AddToEnd inserts the given element at the end of an array list.
func (m *MyArrayList[T]) AddToEnd(element T) {
	m.Add(m.size, element)
}

// Clear empties an array list of all elements.
func (m *MyArrayList[T]) Clear() {
	m.array = make([]T, defaultCapacityArrayList)
	m.size = 0
}

// Contains reports whether the given element is in an array list.
func (m MyArrayList[T]) Contains(element T) bool {
	for i := 0; i < int(m.size); i++ {
		if element == m.array[i] {
			return true
		}
	}
	return false
}

// Equals reports whether obj is equal to an array list.
func (m MyArrayList[T]) Equals(obj any) bool {
	return false
}

// Get returns, but does not remove, an element from an array list at the given index.
// Returns an error if index is out of bounds (index must be between 0 and
// Size() - 1, inclusive).
func (m MyArrayList[T]) Get(index uint) (T, error) {
	err := m.checkIndex(index, m.size)
	if err != nil {
		return make([]T, 1)[0], err
	}
	return m.array[index], nil
}

// IndexOf returns the index of the first occurrence of the given element found
// in an array list, or -1 if not found.
func (m MyArrayList[T]) IndexOf(element T) int {
	for i := 0; i < int(m.size); i++ {
		if element == m.array[i] {
			return i
		}
	}
	return -1
}

// IsEmpty reports whether an array list has no elements.
func (m MyArrayList[T]) IsEmpty() bool {
	return m.size == 0
}

// IndexOf returns the index of the last occurrence of the given element found
// in an array list, or -1 if not found.
func (m MyArrayList[T]) LastIndexOf(element T) int {
	for i := int(m.size - 1); i >= 0; i-- {
		if element == m.array[i] {
			return i
		}
	}
	return -1
}

// Remove retrieves and removes an element from an array list at the given index.
// Returns an error if index is out of bounds (index must be between 0 and
// Size() - 1, inclusive).
func (m *MyArrayList[T]) Remove(index uint) (T, error) {
	err := m.checkIndex(index, m.size)
	if err != nil {
		return make([]T, 1)[0], err
	}
	element := m.array[index]
	m.size--
	if index+1 < m.size {
		copy(m.array[index:m.size-1], m.array[index+1:m.size])
	}
	m.checkCapacity()
	return element, nil
}

// RemoveElement attempts to remove the given element from an array list, and reports
// whether the deletion was successful.
func (m *MyArrayList[T]) RemoveElement(element T) bool {
	for i := 0; i < int(m.size); i++ {
		if element == m.array[i] {
			m.size--
			if i+1 < int(m.size) {
				copy(m.array[i:m.size-1], m.array[i+1:m.size])
			}
			m.checkCapacity()
			return true
		}
	}
	return false
}

// Set sets the existing element at the given index of an array list to the given element
// and returns the existing element. Returns an error if index is out of bounds
// (index must be between 0 and Size() - 1, inclusive).
func (m *MyArrayList[T]) Set(index uint, element T) (T, error) {
	err := m.checkIndex(index, m.size)
	if err != nil {
		return make([]T, 1)[0], err
	}
	oldValue := m.array[index]
	m.array[index] = element
	return oldValue, nil
}

// Size returns the number of elements in an array list.
func (m MyArrayList[T]) Size() uint {
	return m.size
}

// String overrides String() in the Stringer interface. Calls toString().
func (m MyArrayList[T]) String() string {
	return m.ToString()
}

// ToArray returns an array containing all the elements in an array list.
func (m MyArrayList[T]) ToArray() []T {
	return make([]T, 0)
}

// ToString returns a string representation of an array list, e.g.
// "[element1, element2, element3, ..., elementN]".
func (m MyArrayList[T]) ToString() string {
	var builder strings.Builder
	builder.WriteString("[")
	lastIndex := int(m.size) - 1
	for i := 0; i < int(m.size); i++ {
		builder.WriteString(fmt.Sprint(m.array[i]))
		if i != lastIndex {
			builder.WriteString(", ")
		}
	}
	builder.WriteString("]")
	return builder.String()
}

// checkCapacity doubles or halves the size of the internal array of an array
// list depending on size. Used in Add and Remove methods.
func (m *MyArrayList[T]) checkCapacity() {
	if len(m.array) == 0 {
		m.array = make([]T, defaultCapacityArrayList)
	} else if m.size == uint(len(m.array)) {
		newArray := make([]T, m.size*2)
		copy(newArray[:m.size], m.array[:m.size])
		m.array = newArray
	} else if len(m.array) > minArrLenThresholdArrayList && m.size*2 < uint(len(m.array)) {
		newArray := make([]T, len(m.array)/2)
		copy(newArray[:m.size], m.array[:m.size])
		m.array = newArray
	}
}

// checkIndex validates that the given index is in bounds. Returns an error if index is
// greater than or equal to upperBound.
func (m MyArrayList[T]) checkIndex(index, upperBound uint) error {
	if index >= upperBound {
		return errors.New("index is out of bounds")
	}
	return nil
}
