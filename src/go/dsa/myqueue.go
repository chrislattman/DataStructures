package dsa

// MyQueue is an interface which defines methods for queues.
type MyQueue[T comparable] interface {
	// Clear empties a queue of all elements.
	Clear()

	// Equals reports whether obj is equal to a queue.
	Equals(obj any) bool

	// IsEmpty reports whether a queue has no elements.
	IsEmpty() bool

	// Offer inserts the given element to a queue.
	Offer(element T)

	// Peek returns, but does not remove, the element at the front of a queue.
	// False is returned if the queue is empty.
	Peek() (T, bool)

	// Poll removes and returns the element at the front of a queue. False is
	// returned if the queue is empty.
	Poll() (T, bool)

	// Size returns the number of elements in a queue.
	Size() uint

	// ToArray returns an array containing all the elements in a queue.
	ToArray() []T

	// ToString returns a string representation of a queue, e.g.
	// "[element1, element2, element3, ..., elementN]".
	ToString() string
}
