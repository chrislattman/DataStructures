use dsa::{
    algorithms::{binary_search_list, heapsort_list, mergesort_list, quicksort_list},
    myarraylist::{new_array_list_default, MyArrayList},
    mylist::MyList,
};

fn main() {
    println!("Hello world!");

    let mut arraylist: MyArrayList<u32> = new_array_list_default();
    arraylist.add(Some(0), 6);
    arraylist.add(None, 5);

    binary_search_list(&mut arraylist, 5);
    mergesort_list(&mut arraylist);
    quicksort_list(&mut arraylist);
    heapsort_list(&mut arraylist);
}
