use std::fmt::{self, Display};

use crate::mylist::{MyList, MyListError};

/// Internal struct used by this linked list.
struct Node<T> {
    data: T,
    next: Box<Node<T>>,
}

/// A linked list data structure.
pub struct MyLinkedList<T> {
    head: Option<Box<Node<T>>>,
    size: usize,
}

impl<T: PartialEq> MyLinkedList<T> {
    /// Returns a new `MyLinkedList` struct.
    pub fn new() -> Self {
        Self {
            head: None,
            size: 0,
        }
    }
}

// MyArrayList trait item that implements MyList.
impl<T> MyList<T> for MyLinkedList<T>
where
    T: PartialEq + Copy + Display
{
    fn add(&mut self, index: Option<usize>, element: T) -> Result<(), MyListError> {
        todo!()
    }

    fn clear(&mut self) {}

    fn contains(&self, element: T) -> bool {
        false
    }

    fn equals(&self, object: &dyn MyList<T>) -> bool {
        false
    }

    fn get(&self, index: usize) -> Result<T, MyListError> {
        todo!()
    }

    fn index_of(&self, element: T) -> i64 {
        -1
    }

    fn is_empty(&self) -> bool {
        true
    }

    fn last_index_of(&self, element: T) -> i64 {
        -1
    }

    fn remove(&mut self, index: usize) -> Result<T, MyListError> {
        todo!()
    }

    fn remove_element(&mut self, element: T) -> bool {
        false
    }

    fn set(&mut self, index: usize, element: T) -> Result<T, MyListError> {
        todo!()
    }

    fn size(&self) -> usize {
        0
    }

    fn to_array(&self) -> Box<[T]> {
        todo!()
    }

    fn to_string(&self) -> String {
        "[]".to_string()
    }
}

fn check_index(index: usize, upper_bound: usize) -> Result<(), MyListError> {
    if index >= upper_bound {
        Err(MyListError::IndexError)
    } else {
        Ok(())
    }
}

impl<T> fmt::Debug for MyLinkedList<T>
where
    T: PartialEq + Copy + Display + fmt::Debug
{
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.to_string())
    }
}
