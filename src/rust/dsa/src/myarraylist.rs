use std::fmt::{self, Display};

use crate::mylist::{MyList, MyListError};

const DEFAULT_CAPACITY_ARRAY_LIST: usize = 10;
const MIN_ARR_LEN_THRESHOLD_ARRAY_LIST: usize = 100;

/// An array list data structure.
pub struct MyArrayList<T> {
    // It is not straightforward to try to dynamically allocate a fixed size
    // generic array of size n of type Box<[T]>
    // Several crates address similar issues: arrayvec, heapless, generic_array
    array: Vec<T>,
    size: usize,
}

impl<T: PartialEq> MyArrayList<T> { // <T: PartialEq> is an alternative to where
    /// Returns a new `MyArrayList` struct with a default initial capacity of 10.
    pub fn new() -> Self {
        Self::with_capacity(DEFAULT_CAPACITY_ARRAY_LIST)
    }

    /// Returns a new `MyArrayList` struct with the specified initial capacity.
    pub fn with_capacity(initial_capacity: usize) -> Self {
        Self {
            array: Vec::with_capacity(initial_capacity),
            size: 0,
        }
    }
}

// MyArrayList trait item that implements MyList.
impl<T> MyList<T> for MyArrayList<T>
where
    T: PartialEq + Copy + Display
{
    fn add(&mut self, index: Option<usize>, element: T) -> Result<(), MyListError> {
        // Just to ensure there are elements in the array
        if self.array.len() == 0 {
            for _ in 0..self.array.capacity() {
                self.array.push(element);
            }
        }

        if let Some(idx) = index {
            check_index(idx, self.size + 1)?;
            check_capacity(self);
            if idx < self.size {
                self.array.copy_within(idx..self.size, idx + 1);
            }
            self.array[idx] = element;
            Ok(self.size += 1)
        } else {
            self.add(Some(self.size), element)
        }
    }

    fn clear(&mut self) {}

    fn contains(&self, element: T) -> bool {
        false
    }

    fn equals(&self, object: &dyn MyList<T>) -> bool {
        false
    }

    fn get(&self, index: usize) -> Result<T, MyListError> {
        check_index(index, self.size)?;
        Ok(self.array[index])
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
        check_index(index, self.size)?;
        let element = self.array[index];
        self.size -= 1;
        self.array.copy_within((index + 1)..self.size, index);
        check_capacity(self);
        Ok(element)
    }

    fn remove_element(&mut self, element: T) -> bool {
        false
    }

    fn set(&mut self, index: usize, element: T) -> Result<T, MyListError> {
        check_index(index, self.size)?;
        let old_value = self.array[index];
        self.array[index] = element;
        Ok(old_value)
    }

    fn size(&self) -> usize {
        0
    }

    fn to_array(&self) -> Box<[T]> {
        todo!()
    }

    fn to_string(&self) -> String {
        let mut sb = String::from("[");
        let last_index = self.size as i64 - 1;
        for i in 0..self.size {
            sb.push_str(self.array[i].to_string().as_str());
            if i as i64 != last_index {
                sb.push_str(", ");
            }
        }
        sb.push_str("]");
        sb
    }
}

fn check_capacity<T: PartialEq>(list: &mut MyArrayList<T>) {}

fn check_index(index: usize, upper_bound: usize) -> Result<(), MyListError> {
    if index >= upper_bound {
        Err(MyListError::IndexError)
    } else {
        Ok(())
    }
}

impl<T> fmt::Debug for MyArrayList<T>
where
    T: PartialEq + Copy + Display + fmt::Debug
{
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.to_string())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_add() {
        let mut myarraylist: MyArrayList<u32> = MyArrayList::new();
        myarraylist.clear();
        myarraylist.add(Some(0), 5).unwrap();
        myarraylist.add(None, 6).unwrap();
        assert_eq!(0, myarraylist.size());
    }

    #[test]
    fn test_contains() {
        let mut myarraylist: MyArrayList<u32> = MyArrayList::new();
        myarraylist.add(None, 5).unwrap();
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
