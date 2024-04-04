use crate::mylist::MyList;

pub fn binary_search_list<T: PartialOrd>(list: &mut dyn MyList<T>, key: T) -> i64 {
    -1
}

pub fn binary_search_list_indices<T: PartialOrd>(
    list: &mut dyn MyList<T>,
    start_index: u32,
    end_index: u32,
    key: T,
) -> i64 {
    -1
}

pub fn binary_search_array<T: PartialOrd>(list: &mut [T], key: T) -> i64 {
    -1
}

pub fn binary_search_array_indices<T: PartialOrd>(
    list: &mut [T],
    start_index: u32,
    end_index: u32,
    key: T,
) -> i64 {
    -1
}

pub fn mergesort_list<T: PartialOrd>(list: &mut dyn MyList<T>) {}

pub fn mergesort_array<T: PartialOrd>(list: &mut [T]) {}

pub fn quicksort_list<T: PartialOrd>(list: &mut dyn MyList<T>) {}

pub fn quicksort_array<T: PartialOrd>(list: &mut [T]) {}

pub fn heapsort_list<T: PartialOrd>(list: &mut dyn MyList<T>) {}

pub fn heapsort_array<T: PartialOrd>(list: &mut [T]) {}
