use std::error::Error;

use crate::mylist::MyList;

/// Internal struct used by this linked list.
struct Node<T> {
    data: T,
    next: Box<Node<T>>,
}

/// A linked list data structure.
pub struct MyLinkedList<T> {
    head: Option<Box<Node<T>>>,
    size: u32,
}

impl<T: PartialEq> MyLinkedList<T> {
    /// Returns a new MyLinkedList struct.
    pub fn new() -> Self {
        Self {
            head: None,
            size: 0,
        }
    }
}

// MyArrayList trait item that implements MyList.
impl<T: PartialEq> MyList<T> for MyLinkedList<T> {
    fn add(&mut self, index: Option<u32>, element: T) {}

    fn clear(&mut self) {}

    fn contains(&self, element: T) -> bool {
        false
    }

    fn equals(&self, object: &dyn MyList<T>) -> bool {
        false
    }

    fn get(&self, index: u32) -> T {
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

    fn remove(&mut self, index: u32) -> T {
        todo!()
    }

    fn remove_element(&mut self, element: T) -> bool {
        false
    }

    fn set(&mut self, index: u32, element: T) -> T {
        todo!()
    }

    fn size(&self) -> u32 {
        0
    }

    fn to_array(&self) -> Box<[T]> {
        todo!()
    }

    fn to_string(&self) -> String {
        "[]".to_string()
    }
}

fn check_index<T: PartialEq>(
    list: &MyLinkedList<T>,
    index: u32,
    upper_bound: u32,
) -> Result<(), Box<dyn Error>> {
    if index >= upper_bound {
        Err(From::from("index is out of bounds"))
    } else {
        Ok(())
    }
}
