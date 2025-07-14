use crate::mylist::MyList;

// In C++ std::span(T[]) is the equivalent of &[T]

pub fn binary_search_list<T: PartialOrd>(_list: &impl MyList<T>, _key: T) -> i64 {
    -1
}

pub fn binary_search_list_indices<T: PartialOrd>(
    _list: &impl MyList<T>,
    _start_index: u32,
    _end_index: u32,
    _key: T,
) -> i64 {
    -1
}

pub fn binary_search_array<T: PartialOrd>(_list: &[T], _key: T) -> i64 {
    -1
}

pub fn binary_search_array_indices<T: PartialOrd>(
    _list: &[T],
    _start_index: u32,
    _end_index: u32,
    _key: T,
) -> i64 {
    -1
}

pub fn mergesort_list<T: PartialOrd>(_list: &mut impl MyList<T>) {}

pub fn mergesort_array<T: PartialOrd>(_list: &mut [T]) {}

pub fn quicksort_list<T: PartialOrd>(_list: &mut impl MyList<T>) {}

pub fn quicksort_array<T: PartialOrd>(_list: &mut [T]) {}

pub fn heapsort_list<T: PartialOrd>(_list: &mut impl MyList<T>) {}

pub fn heapsort_array<T: PartialOrd>(_list: &mut [T]) {}
