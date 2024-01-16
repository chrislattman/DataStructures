package dsa

import "cmp"

const defaultCapacityPriorityQueue = 11
const minArrLenThresholdPriorityQueue = 100

// MyPriorityQueue is a priority queue data structure. Also called a (binary)
// heap.
type MyPriorityQueue[CT cmp.Ordered] struct {
	array     []CT
	size      uint32
	isMinHeap bool
}

// NewMyPriorityQueueDefault returns a min heap with a default initial capacity
// of 11.
func NewMyPriorityQueueDefault[CT cmp.Ordered]() *MyPriorityQueue[CT] {
	return NewMyPriorityQueue[CT](defaultCapacityPriorityQueue, true)
}

// NewMyPriorityQueueDefaultHeap returns a min heap with initial capacity
// initialCapacity.
func NewMyPriorityQueueDefaultHeap[CT cmp.Ordered](
	initialCapacity uint32) *MyPriorityQueue[CT] {
	return NewMyPriorityQueue[CT](initialCapacity, true)
}

// NewMyPriorityQueueDefaultCapacity returns either a min heap or max heap with
// a default initial capacity of 11.
func NewMyPriorityQueueDefaultCapacity[CT cmp.Ordered](
	isMinHeap bool) *MyPriorityQueue[CT] {
	return NewMyPriorityQueue[CT](defaultCapacityPriorityQueue, isMinHeap)
}

// NewMyPriorityQueue returns either a min heap or a max heap with initial
// capacity initialCapacity.
func NewMyPriorityQueue[CT cmp.Ordered](
	initialCapacity uint32, isMinHeap bool) *MyPriorityQueue[CT] {
	newqueue := new(MyPriorityQueue[CT])
	newqueue.array = make([]CT, initialCapacity)
	newqueue.size = 0
	newqueue.isMinHeap = isMinHeap
	return newqueue
}

// Clear empties a priority queue of all elements.
func (m *MyPriorityQueue[CT]) Clear() {

}

// Equals reports whether obj is equal to a priority queue.
func (m *MyPriorityQueue[CT]) Equals(obj any) bool {
	return false
}

// IsEmpty reports whether a priority queue has no elements.
func (m *MyPriorityQueue[CT]) IsEmpty() bool {
	return true
}

// Offer inserts element elem to a priority queue.
func (m *MyPriorityQueue[CT]) Offer(elem CT) {

}

// Peek returns, but does not remove, the element at the front of a priority
// queue. False is returned if the queue is empty.
func (m *MyPriorityQueue[CT]) Peek() (CT, bool) {
	return make([]CT, 1)[0], false
}

// Poll removes and returns the element at the front of a priority queue.
// False is returned if the queue is empty.
func (m *MyPriorityQueue[CT]) Poll() (CT, bool) {
	return make([]CT, 1)[0], false
}

// Size returns the number of elements in a priority queue.
func (m *MyPriorityQueue[CT]) Size() uint32 {
	return 0
}

// ToArray returns an array containing all the elements in a priority queue.
func (m *MyPriorityQueue[CT]) ToArray() []CT {
	return make([]CT, 0)
}

// ToString returns a string representation of a priority queue, e.g.
// "[element1, element2, element3, ..., elementN]".
func (m *MyPriorityQueue[CT]) ToString() string {
	return "[]"
}

// checkCapacity doubles or halves the size of the internal array of a priority
// queue depending on size. Used in Offer and Poll methods.
func (m *MyPriorityQueue[CT]) checkCapacity() {

}

// getBestIndex returns the index of the lesser element of the internal array
// of a priority queue if it is a min heap. Otherwise, returns the index of the
// greater element, or -1. Indices should be distinct and increasing.
func (m *MyPriorityQueue[CT]) getBestIndex(leftIndex uint32) int64 {
	return -1
}
