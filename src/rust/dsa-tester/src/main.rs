use dsa::{
    myarraylist::{new_array_list_default, MyArrayList},
    mylinkedlist::{new_linked_list, MyLinkedList},
    mylist::MyList,
};

fn main() {
    println!("Hello, world!");
    let mut x: MyArrayList<u32> = new_array_list_default();
    x.add(Some(2), 5);
    let mut y: MyLinkedList<u32> = new_linked_list();
    y.add(Some(2), 5);
}
