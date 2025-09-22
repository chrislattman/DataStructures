package dsa

import "sync/atomic"

// A lock-free SPSC (single producer, single consumer) queue (ring buffer/FIFO)
// built on top of an array. SPSC queues are used in HFT pipelines, audio/video
// processing, real-time control, and GPU/CPU communication.
// Go encourages the use of channels instead.
type MySPSCArrayQueue[T comparable] struct {
	mask   int32
	buffer []T
	// _pad0  [16]int32 // padding to avoid false sharing on same 64 byte cache line
	head   int32
	// _pad1  [15]int32	// padding to avoid false sharing on same 64 byte cache line
	tail   int32
	// _pad2  [15]int32	// padding to avoid false sharing on same 64 byte cache line
}

// Returns a lock-free SPSC queue with a usable capacity of 2^k - 1.
func NewMySPSCArrayQueue[T comparable](k int) *MySPSCArrayQueue[T] {
    capacity := 1 << k
    return &MySPSCArrayQueue[T]{
        mask:   int32(capacity - 1),
        buffer: make([]T, capacity),
    }
}

// Checks if this lock-free SPSC queue has no elements.
func (m *MySPSCArrayQueue[T]) IsEmpty() bool {
	return atomic.LoadInt32(&m.head) == atomic.LoadInt32(&m.tail)
}

// Inserts an element to this lock-free SPSC queue.
func (m *MySPSCArrayQueue[T]) Offer(element T) bool {
	currentTail := atomic.LoadInt32(&m.tail)
	nextTail := (currentTail + 1) & m.mask
	if nextTail == atomic.LoadInt32(&m.head) {
		return false
	}
	m.buffer[currentTail] = element
	atomic.StoreInt32(&m.tail, nextTail)
	return true
}

// Retrieves, but does not remove, the element at the front of this lock-free SPSC queue.
func (m *MySPSCArrayQueue[T]) Peek() T {
	currentHead := atomic.LoadInt32(&m.head)
	currentTail := atomic.LoadInt32(&m.tail)
	if currentHead == currentTail {
		var zero T
		return zero
	}
	return m.buffer[currentHead]
}

// Retrieves and removes the element at the front of this lock-free SPSC queue.
func (m *MySPSCArrayQueue[T]) Poll() T {
	currentHead := atomic.LoadInt32(&m.head)
	if currentHead == atomic.LoadInt32(&m.tail) {
		var zero T
		return zero
	}
	value := m.buffer[currentHead]
	atomic.StoreInt32(&m.head, (currentHead + 1) & m.mask)
	return value
}
