use std::fmt::{self, Display};

use crate::mylist::{MyList, MyListError};

/// Internal struct used by this linked list.
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
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

impl<T> MyList<T> for MyLinkedList<T>
where
    T: PartialEq + Copy + Display,
{
    fn add(&mut self, index: Option<usize>, element: T) -> Result<(), MyListError> {
        if let Some(idx) = index {
            check_index(idx, self.size + 1)?;
            if self.is_empty() {
                self.head = Some(Box::new(Node {
                    data: element,
                    next: None,
                }));
            } else {
                let mut new_node = Box::new(Node {
                    data: element,
                    next: None,
                });
                if idx == 0 {
                    new_node.next = self.head.take();
                    self.head = Some(new_node);
                } else {
                    let mut current = &mut self.head;
                    let stop = idx - 1;
                    for _ in 0..stop {
                        if let Some(curr) = current {
                            current = &mut curr.next;
                        }
                    }
                    if let Some(curr) = current {
                        new_node.next = curr.next.take();
                        curr.next = Some(new_node);
                    }
                }
            }
            self.size += 1;
            Ok(())
        } else {
            self.add(Some(self.size), element)
        }
    }

    fn clear(&mut self) {
        self.head = None;
        self.size = 0;
    }

    fn contains(&self, element: T) -> bool {
        let mut current = &self.head;
        while let Some(curr) = current {
            if element == curr.data {
                return true;
            }
            current = &curr.next;
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
        let mut current = &self.head;
        for _ in 0..index {
            if let Some(curr) = current {
                current = &curr.next;
            }
        }
        if let Some(curr) = current {
            return Ok(curr.data);
        }
        Err(MyListError::IndexError)
    }

    fn index_of(&self, element: T) -> i64 {
        let mut current = &self.head;
        for i in 0..self.size {
            if let Some(curr) = current {
                if element == curr.data {
                    return i as i64;
                }
                current = &curr.next;
            }
        }
        -1
    }

    fn is_empty(&self) -> bool {
        self.size == 0
    }

    fn last_index_of(&self, element: T) -> i64 {
        let mut index = -1;
        let mut current = &self.head;
        for i in 0..self.size {
            if let Some(curr) = current {
                if element == curr.data {
                    index = i as i64;
                }
                current = &curr.next;
            }
        }
        index
    }

    fn remove(&mut self, index: usize) -> Result<T, MyListError> {
        if index == 0 {
            if let Some(mut old) = self.head.take() {
                self.head = old.next.take();
                self.size -= 1;
                return Ok(old.data);
            }
        } else {
            let mut current = &mut self.head;
            let stop = index - 1;
            for _ in 0..stop {
                if let Some(curr) = current {
                    current = &mut curr.next;
                }
            }
            if let Some(curr) = current {
                if let Some(mut old) = curr.next.take() {
                    curr.next = old.next.take();
                    self.size -= 1;
                    return Ok(old.data);
                }
            }
        }
        Err(MyListError::IndexError)
    }

    fn remove_element(&mut self, element: T) -> bool {
        let mut current = &mut self.head;
        if let Some(old) = current {
            if element == old.data {
                self.head = old.next.take();
                self.size -= 1;
                return true;
            }
        }
        while let Some(curr) = current {
            if let Some(ref mut next_node) = curr.next {
                if element == next_node.data {
                    curr.next = next_node.next.take();
                    self.size -= 1;
                    return true;
                }
            }
            current = &mut curr.next;
        }
        false
    }

    fn set(&mut self, index: usize, element: T) -> Result<T, MyListError> {
        let mut current = &mut self.head;
        for _ in 0..index {
            if let Some(curr) = current {
                current = &mut curr.next;
            }
        }
        if let Some(curr) = current {
            let old_value = curr.data;
            curr.data = element;
            return Ok(old_value);
        }
        Err(MyListError::IndexError)
    }

    fn size(&self) -> usize {
        self.size
    }

    fn to_array(&self) -> Box<[T]> {
        todo!()
    }

    fn to_string(&self) -> String {
        let mut sb = String::from('[');
        let mut current = &self.head;
        while let Some(curr) = current {
            sb.push_str(curr.data.to_string().as_str());
            if curr.next.is_some() {
                sb.push_str(", ");
            }
            current = &curr.next;
        }
        sb.push(']');
        sb
    }
}

fn check_index(index: usize, upper_bound: usize) -> Result<(), MyListError> {
    if index >= upper_bound {
        Err(MyListError::IndexError)
    } else {
        Ok(())
    }
}

impl<T: PartialEq> PartialEq for MyLinkedList<T> {
    fn eq(&self, other: &Self) -> bool {
        if self.size != other.size {
            return false;
        }
        let mut current_self = &self.head;
        let mut current_other = &other.head;
        while let (Some(curr_self), Some(curr_other)) = (current_self, current_other) {
            if curr_self.data != curr_other.data {
                return false;
            }
            current_self = &curr_self.next;
            current_other = &curr_other.next;
        }
        current_self.is_none() && current_other.is_none()
    }
}

impl<T> fmt::Debug for MyLinkedList<T>
where
    T: PartialEq + Copy + Display + fmt::Debug,
{
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.to_string())
    }
}
