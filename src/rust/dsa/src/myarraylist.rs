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

impl<T: PartialEq> MyArrayList<T> { // replace <T: PartialEQ> with <T: Ord> for a priority queue
    // <T: PartialEq> is an alternative to where
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

impl<T> MyList<T> for MyArrayList<T>
where
    T: PartialEq + Copy + Display,
{
    fn add(&mut self, index: Option<usize>, element: T) -> Result<(), MyListError> {
        // Just to ensure there are elements in the array
        if self.array.is_empty() {
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
            self.size += 1;
            Ok(())
        } else {
            self.add(Some(self.size), element)
        }
    }

    fn clear(&mut self) {
        self.array = Vec::with_capacity(DEFAULT_CAPACITY_ARRAY_LIST);
        self.size = 0;
    }

    fn contains(&self, element: T) -> bool {
        for i in 0..self.size {
            if element == self.array[i] {
                return true;
            }
        }
        false
    }

    fn equals(&self, object: &Self) -> bool {
        if object == self {
            return true;
        }
        false
    }

    fn get(&self, index: usize) -> Result<T, MyListError> {
        check_index(index, self.size)?;
        Ok(self.array[index])
    }

    fn index_of(&self, element: T) -> i64 {
        for i in 0..self.size {
            if element == self.array[i] {
                return i as i64;
            }
        }
        -1
    }

    fn is_empty(&self) -> bool {
        self.size == 0
    }

    fn last_index_of(&self, element: T) -> i64 {
        for i in (0..self.size).rev() {
            if element == self.array[i] {
                return i as i64;
            }
        }
        -1
    }

    fn remove(&mut self, index: usize) -> Result<T, MyListError> {
        check_index(index, self.size)?;
        let element = self.array[index];
        self.size -= 1;
        if index < self.size {
            self.array.copy_within((index + 1)..=self.size, index);
        }
        check_capacity(self);
        Ok(element)
    }

    fn remove_element(&mut self, element: T) -> bool {
        for i in 0..self.size {
            if element == self.array[i] {
                self.size -= 1;
                if i < self.size {
                    self.array.copy_within((i + 1)..=self.size, i);
                }
                check_capacity(self);
                return true;
            }
        }
        false
    }

    fn set(&mut self, index: usize, element: T) -> Result<T, MyListError> {
        check_index(index, self.size)?;
        let old_value = self.array[index];
        self.array[index] = element;
        Ok(old_value)
    }

    fn size(&self) -> usize {
        self.size
    }

    fn to_array(&self) -> Box<[T]> {
        todo!()
    }

    fn to_string(&self) -> String {
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

fn check_capacity<T: PartialEq + Copy>(list: &mut MyArrayList<T>) {
    if list.array.capacity() == 0 {
        list.array = Vec::with_capacity(DEFAULT_CAPACITY_ARRAY_LIST);
    } else if list.size == list.array.capacity() {
        let mut new_array = Vec::with_capacity(list.size * 2);
        new_array[..list.size].copy_from_slice(&list.array);
        list.array = new_array;
    } else if list.array.capacity() > MIN_ARR_LEN_THRESHOLD_ARRAY_LIST
        && list.size * 2 < list.array.capacity()
    {
        let mut new_array = Vec::with_capacity(list.array.capacity() / 2);
        new_array[..list.size].copy_from_slice(&list.array[..list.size]);
        list.array = new_array;
    }
}

fn check_index(index: usize, upper_bound: usize) -> Result<(), MyListError> {
    if index >= upper_bound {
        Err(MyListError::IndexError)
    } else {
        Ok(())
    }
}

impl<T: PartialEq> PartialEq for MyArrayList<T> {
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

impl<T> fmt::Debug for MyArrayList<T>
where
    T: PartialEq + Copy + Display + fmt::Debug,
{
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.to_string())
    }
}

#[cfg(test)]
mod tests {
    use mockall::predicate::eq;

    use super::*;
    use crate::mylist::MockMyList;

    #[test]
    fn test_add() {
        let mut myarraylist = MyArrayList::new();
        assert_eq!(0, myarraylist.size());
        myarraylist.clear();
        assert_eq!(0, myarraylist.size());
        myarraylist.add(Some(0), 5).unwrap();
        assert_eq!(1, myarraylist.size());
        myarraylist.add(None, 6).unwrap();
        assert_eq!(2, myarraylist.size());
    }

    #[test]
    fn test_contains() {
        let mut myarraylist = MyArrayList::new();
        myarraylist.add(None, 5).unwrap();
        assert!(myarraylist.contains(5));
        assert!(!myarraylist.contains(6));
    }

    #[test]
    fn test_equals() {
        let mut myarraylist = MyArrayList::new();
        let mut otherlist = MyArrayList::new();
        otherlist.add(None, 5).unwrap();
        assert!(myarraylist.equals(&myarraylist));
        assert!(!myarraylist.equals(&otherlist));
        myarraylist.add(None, 5).unwrap();
        assert!(myarraylist.equals(&otherlist));
    }

    #[test]
    fn test_get() {
        let mut myarraylist = MyArrayList::new();
        let result = myarraylist.get(0);
        assert!(matches!(result, Err(MyListError::IndexError)));
        myarraylist.add(None, 5).unwrap();
        assert_eq!(5, myarraylist.get(0).unwrap());
    }

    #[test]
    fn test_index_of() {
        let mut myarraylist = MyArrayList::new();
        assert_eq!(-1, myarraylist.index_of(5));
        myarraylist.add(None, 5).unwrap();
        assert_eq!(0, myarraylist.index_of(5));
    }

    #[test]
    fn test_is_empty() {
        let myarraylist: MyArrayList<u32> = MyArrayList::new();
        assert!(myarraylist.is_empty());
    }

    #[test]
    fn test_last_index_of() {
        let mut myarraylist = MyArrayList::new();
        assert_eq!(-1, myarraylist.last_index_of(5));
        myarraylist.add(None, 5).unwrap();
        assert_eq!(0, myarraylist.last_index_of(5));
    }

    #[test]
    fn test_remove() {
        let mut myarraylist = MyArrayList::new();
        let result = myarraylist.remove(0);
        assert!(matches!(result, Err(MyListError::IndexError)));
        myarraylist.add(None, 5).unwrap();
        assert_eq!(5, myarraylist.remove(0).unwrap());
        assert!(myarraylist.is_empty());
    }

    #[test]
    fn test_remove_element() {
        let mut myarraylist = MyArrayList::new();
        assert!(!myarraylist.remove_element(5));
        myarraylist.add(None, 5).unwrap();
        assert!(myarraylist.remove_element(5));
        assert!(myarraylist.is_empty());
    }

    #[test]
    fn test_set() {
        let mut myarraylist = MyArrayList::new();
        let result = myarraylist.set(1, 5);
        assert!(matches!(result, Err(MyListError::IndexError)));
        myarraylist.add(None, 5).unwrap();
        assert_eq!(5, myarraylist.set(0, 6).unwrap());
        assert_eq!(6, myarraylist.get(0).unwrap());
    }

    #[test]
    fn test_size() {
        let myarraylist: MyArrayList<i32> = MyArrayList::new();
        assert_eq!(0, myarraylist.size());
    }

    #[test]
    fn test_to_string() {
        let mut myarraylist = MyArrayList::new();
        assert_eq!("[]", myarraylist.to_string());
        myarraylist.add(None, 5).unwrap();
        assert_eq!("[5]", myarraylist.to_string());
        myarraylist.add(None, 6).unwrap();
        assert_eq!("[5, 6]", myarraylist.to_string());
    }

    #[test]
    fn test_mock() {
        let mut mock_list = MockMyList::<i32>::new();
        mock_list.expect_size().returning(|| 10);
        assert_eq!(10, mock_list.size());

        mock_list.expect_contains().with(eq(3)).returning(|_| true);
        mock_list
            .expect_contains()
            .withf(|v| *v != 3)
            .returning(|_| false);
        assert!(mock_list.contains(3));
        assert!(!mock_list.contains(4));
        // No spying/wrapping mocks in mockall currently
    }
}
