use std::{
    cell::UnsafeCell,
    sync::atomic::{AtomicUsize, Ordering},
};

/// A lock-free SPSC (single producer, single consumer) queue (ring buffer/FIFO)
/// built on top of an array. SPSC queues are used in HFT pipelines, audio/video
/// processing, real-time control, and GPU/CPU communication.
pub struct MySPSCArrayQueue<T> {
    mask: usize,
    buffer: Vec<UnsafeCell<Option<T>>>,
    // _pad0: [u8; 64],                                         // padding to avoid false sharing on same 64 byte cache line
    head: AtomicUsize,
    // _pad1: [u8; 64 - std::mem::size_of::<AtomicUsize>()],    // padding to avoid false sharing on same 64 byte cache line
    tail: AtomicUsize,
    // _pad2: [u8; 64 - std::mem::size_of::<AtomicUsize>()],    // padding to avoid false sharing on same 64 byte cache line
}

// Safety: SPSC means only one producer and one consumer exist
unsafe impl<T: Send> Send for MySPSCArrayQueue<T> {}
unsafe impl<T: Send> Sync for MySPSCArrayQueue<T> {}

impl<T: Copy> MySPSCArrayQueue<T> {
    /// Returns a lock-free SPSC queue with a usable capacity of 2^k - 1.
    pub fn new(k: usize) -> Self {
        let capacity = 1 << k;
        Self {
            mask: capacity - 1,
            buffer: (0..capacity)
                .map(|_| UnsafeCell::new(None))
                .collect::<Vec<_>>(),
            head: AtomicUsize::new(0),
            tail: AtomicUsize::new(0),
        }
    }

    /// Checks if this lock-free SPSC queue has no elements.
    pub fn is_empty(&self) -> bool {
        self.head.load(Ordering::Acquire) == self.tail.load(Ordering::Acquire)
    }

    /// Inserts an element to this lock-free SPSC queue.
    pub fn offer(&self, element: T) -> bool {
        // self.tail.load(Ordering::Relaxed) technically works for SPSC
        let current_tail = self.tail.load(Ordering::Acquire);
        let next_tail = (current_tail + 1) & self.mask;
        if next_tail == self.head.load(Ordering::Acquire) {
            return false;
        }
        unsafe {
            *self.buffer[current_tail].get() = Some(element);
        }
        self.tail.store(next_tail, Ordering::Release);
        true
    }

    /// Retrieves, but does not remove, the element at the front of this lock-free SPSC queue.
    pub fn peek(&self) -> Option<T> {
        let current_head = self.head.load(Ordering::Acquire);
        let current_tail = self.tail.load(Ordering::Acquire);
        if current_head == current_tail {
            return None;
        }
        unsafe { *self.buffer[current_head].get() }
    }

    /// Retrieves and removes the element at the front of this lock-free SPSC queue.
    pub fn poll(&self) -> Option<T> {
        // self.head.load(Ordering::Relaxed) technically works for SPSC
        let current_head = self.head.load(Ordering::Acquire);
        if current_head == self.tail.load(Ordering::Acquire) {
            return None;
        }
        let value = unsafe { (*self.buffer[current_head].get()).take() };
        unsafe {
            *self.buffer[current_head].get() = None;
        }
        self.head
            .store((current_head + 1) & self.mask, Ordering::Release);
        value
    }
}
