/// Trait which defines methods for lists.
pub trait MyList<T> {
    /// Inserts an element at the specified index or at the end of this list.
    fn add(&mut self, index: Option<u32>, element: T);

    /// Empties this list of all elements.
    fn clear(&mut self);

    /// Checks if an element is in this list.
    fn contains(&self, element: T) -> bool;

    /// Compares an object with this list for equality.
    fn equals(&self, object: &dyn MyList<T>) -> bool;

    /// Retrieves, but does not remove, an element from this list at the
    /// specified index.
    fn get(&self, index: u32) -> T;

    /// Returns the index of the first occurrence of an element found in this
    /// list.
    fn index_of(&self, element: T) -> i64;

    /// Checks if this list has no elements.
    fn is_empty(&self) -> bool;

    /// Returns the index of the last occurrence of an element found in this
    /// list.
    fn last_index_of(&self, element: T) -> i64;

    /// Retrieves and removes an element from this list at a specified index.
    fn remove(&mut self, index: u32) -> T;

    /// Removes the first occurrence of an element from this list.
    fn remove_element(&mut self, element: T) -> bool;

    /// Sets the existing element at a specified index to a new value.
    fn set(&mut self, index: u32, element: T) -> T;

    /// Returns the number of elements in this list.
    fn size(&self) -> u32;

    /// Returns an array containing all the elements in this list.
    fn to_array(&self) -> Vec<T>;

    /// Returns a string representation of this list, e.g.
    /// "\[element1, element2, element3, ..., elementN\]".
    fn to_string(&self) -> String;
}
