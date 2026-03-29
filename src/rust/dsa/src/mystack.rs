use std::fmt::{self, Debug, Display};

const DEFAULT_CAPACITY_STACK: usize = 10;
const MIN_ARR_LEN_THRESHOLD_STACK: usize = 100;

/// A stack data structure (LIFO).
pub struct MyStack<T> {
    array: Vec<T>,
    size: usize,
}

impl<T: PartialEq + Copy> MyStack<T> {
    fn check_capacity(&mut self) {
        if self.array.capacity() == 0 {
            self.array = Vec::with_capacity(DEFAULT_CAPACITY_STACK);
        } else if self.size == self.array.capacity() {
            let mut new_array = Vec::with_capacity(self.size * 2);
            new_array[..self.size].copy_from_slice(&self.array);
            self.array = new_array;
        } else if self.array.capacity() > MIN_ARR_LEN_THRESHOLD_STACK
            && self.size * 2 < self.array.capacity()
        {
            let mut new_array = Vec::with_capacity(self.array.capacity() / 2);
            new_array[..self.size].copy_from_slice(&self.array[..self.size]);
            self.array = new_array;
        }
    }
}

impl<T: PartialEq + Copy + Display> MyStack<T> {
    /// Returns a new `MyStack` struct with a default initial capacity of 10.
    pub fn new() -> Self {
        Self {
            array: Vec::with_capacity(DEFAULT_CAPACITY_STACK),
            size: 0,
        }
    }

    /// Empties this stack of all elements.
    pub fn clear(&mut self) {
        self.array = Vec::with_capacity(DEFAULT_CAPACITY_STACK);
        self.size = 0;
    }

    /// Compares an object with this stack for equality.
    pub fn equals(&self, object: &Self) -> bool {
        if object == self {
            return true;
        }
        false
    }

    /// Checks if this stack has no elements.
    pub fn is_empty(&self) -> bool {
        self.size == 0
    }

    /// Retrieves, but does not remove, the element at the top of this stack.
    pub fn peek(&self) -> Option<T> {
        if self.is_empty() {
            return None;
        }
        Some(self.array[self.size - 1])
    }

    /// Retrieves and removes the element at the top of this stack.
    pub fn pop(&mut self) -> Option<T> {
        if self.is_empty() {
            return None;
        }
        let element = self.array[self.size - 1];
        self.size -= 1;
        self.check_capacity();
        Some(element)
    }

    /// Inserts an element at the top of this stack.
    pub fn push(&mut self, element: T) {
        self.check_capacity();
        self.array[self.size] = element;
        self.size += 1;
    }

    /// Returns the number of elements in this stack.
    pub fn size(&self) -> usize {
        self.size
    }

    /// Returns a string representation of this stack, e.g. "[element1, element2, element3, ..., elementN]".
    pub fn to_string(&self) -> String {
        let mut sb = String::from('[');
        let last_index = self.size as i64 - 1;
        for i in 0..self.size {
            sb.push_str(self.array[i].to_string().as_str());
            if i as i64 != last_index {
                sb.push_str(", ");
            }
        }
        sb.push(']');
        sb
    }
}

impl<T: PartialEq> PartialEq for MyStack<T> {
    fn eq(&self, other: &Self) -> bool {
        if self.size != other.size {
            return false;
        }
        for i in 0..self.size {
            if other.array[i] != self.array[i] {
                return false;
            }
        }
        true
    }
}

impl<T> Debug for MyStack<T>
where
    T: PartialEq + Copy + Display + Debug,
{
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.to_string())
    }
}
