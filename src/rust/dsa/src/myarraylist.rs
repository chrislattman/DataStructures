use std::error::Error;

use crate::mylist::MyList;

const DEFAULT_CAPACITY_ARRAY_LIST: usize = 10;
const MIN_ARR_LEN_THRESHOLD_ARRAY_LIST: usize = 100;

/// An array list data structure.
pub struct MyArrayList<T> {
    // It is not straightforward to try to dynamically allocate a fixed size
    // generic array of size n of type Box<[T]>
    // Several crates address similar issues: arrayvec, heapless, generic_array
    array: Vec<T>,
    size: u32,
}

impl<T: PartialEq> MyArrayList<T> {
    /// Returns a new MyArrayList struct with a default initial capacity of 10.
    pub fn new() -> Self {
        Self::with_capacity(DEFAULT_CAPACITY_ARRAY_LIST)
    }

    /// Returns a new MyArrayList struct with the specified initial capacity.
    pub fn with_capacity(initial_capacity: usize) -> Self {
        Self {
            array: Vec::with_capacity(initial_capacity),
            size: 0,
        }
    }
}

// MyArrayList trait item that implements MyList.
impl<T: PartialEq> MyList<T> for MyArrayList<T> {
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

fn check_capacity<T: PartialEq>(list: &mut MyArrayList<T>) {}

fn check_index<T: PartialEq>(
    list: &MyArrayList<T>,
    index: u32,
    upper_bound: u32,
) -> Result<(), Box<dyn Error>> {
    if index >= upper_bound {
        Err(From::from("index is out of bounds"))
    } else {
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_add() {
        let mut myarraylist: MyArrayList<u32> = MyArrayList::new();
        myarraylist.clear();
        myarraylist.add(Some(0), 5);
        myarraylist.add(None, 6);
        assert_eq!(0, myarraylist.size());
    }

    #[test]
    fn test_contains() {
        let mut myarraylist: MyArrayList<u32> = MyArrayList::new();
        myarraylist.add(None, 5);
        assert!(!myarraylist.contains(5));
    }

    #[test]
    fn test_equals() {
        let myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert!(!myarraylist.equals(&myarraylist));
    }

    #[test]
    fn test_index_of() {
        let myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert_eq!(-1, myarraylist.index_of(0));
    }

    #[test]
    fn test_is_empty() {
        let myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert!(myarraylist.is_empty());
    }

    #[test]
    fn test_last_index_of() {
        let myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert_eq!(-1, myarraylist.last_index_of(0));
    }

    #[test]
    fn test_remove_element() {
        let mut myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert!(!myarraylist.remove_element(0));
    }

    #[test]
    fn test_size() {
        let myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert_eq!(0, myarraylist.size());
    }

    #[test]
    fn test_to_string() {
        let myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert_eq!("[]", myarraylist.to_string());
    }
}
