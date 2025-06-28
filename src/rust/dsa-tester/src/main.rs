use std::{cmp::Reverse, collections::{BTreeSet, BinaryHeap, HashMap, HashSet, LinkedList, VecDeque}};

use dsa::{
    algorithms::{binary_search_list, heapsort_list, mergesort_list, quicksort_list},
    myarraylist::MyArrayList,
    mylist::MyList,
};

const NUMS_LENGTH: usize = 10;

fn main() {
    let mut myarraylist: MyArrayList<u32> = MyArrayList::new();
    myarraylist.add(Some(0), 6);
    myarraylist.add(None, 5);

    binary_search_list(&mut myarraylist, 5);
    mergesort_list(&mut myarraylist);
    quicksort_list(&mut myarraylist);
    heapsort_list(&mut myarraylist);

    // Every print statement should output true

    let mut arraylist = Vec::new();
    println!("{}", format!("{:?}", arraylist) == "[]");
    arraylist.push(5);
    arraylist.push(10);
    arraylist.push(12);
    arraylist.insert(2, 17);
    println!("{}", format!("{:?}", arraylist) == "[5, 10, 17, 12]");
    println!("{}", arraylist.contains(&5));
    println!("{}", arraylist[0] == 5);
    println!("{}", !arraylist.contains(&6));
    println!("{}", !arraylist.is_empty());
    println!("{}", arraylist.iter().position(|&x| x == 12).unwrap() == 3);
    println!("{}", arraylist.iter().position(|&x| x == 13) == None);
    match arraylist.iter().position(|&x| x == 13) {
        None => println!("{}", true),
        Some(_) => println!("{}", false)
    }
    match arraylist.iter().position(|&x| x == 19) {
        None => println!("true"),
        Some(index) => {
            arraylist.remove(index);
            println!("false");
        }
    }
    arraylist.remove(arraylist.iter().position(|&x| x == 10).unwrap());
    println!("{}", format!("{:?}", arraylist) == "[5, 17, 12]");
    arraylist[1] = 13;
    println!("{}", format!("{:?}", arraylist) == "[5, 13, 12]");
    println!("{}", arraylist.len() == 3);
    println!("{}", arraylist == arraylist);
    arraylist.remove(1);
    println!("{}", format!("{:?}", arraylist) == "[5, 12]");

    arraylist.clear();
    println!("{}", arraylist.len() == 0);
    arraylist.push(6);
    arraylist.push(4);
    arraylist.push(19);
    arraylist.push(11);
    arraylist.push(5);
    arraylist.sort();
    println!("{}", format!("{:?}", arraylist) == "[4, 5, 6, 11, 19]");
    println!("{}", arraylist.binary_search(&11).unwrap() == 3);
    println!("{}", arraylist.binary_search(&2) == Err(0));
    println!("{}", arraylist.iter().filter(|&x| *x == 19).count() == 1);
    arraylist.reverse();
    println!("{}", format!("{:?}", arraylist) == "[19, 11, 6, 5, 4]");

    let keys = ["hello", "world", "hi", "bye"];
    let values = [5, 17, 3, 0];
    let mut hashmap = HashMap::new();
    println!("{}", format!("{:?}", hashmap) == "{}");
    for i in 0..4 {
        hashmap.insert(keys[i], values[i]);
    }

    println!("{}", !hashmap.is_empty());
    println!("{}", hashmap.len() == 4);
    println!("{}", hashmap.contains_key("hello"));
    println!("{}", !hashmap.contains_key("hellos"));
    println!("{}", hashmap.values().any(|&x| x == 5));
    println!("{}", !hashmap.values().any(|&x| x == 6));
    println!("{}", hashmap["hello"] == 5);
    println!("{}", hashmap.get("hellos") == None);
    // no built-in getOrDefault function
    // no built-in putIfAbsent function
    hashmap.insert("hello", 6);
    hashmap.remove("hi");
    println!("{}", hashmap.remove("bye").unwrap() == 0);
    println!("{}", hashmap.remove("hellos") == None);
    hashmap.clear();
    println!("{}", hashmap.len() == 0);
    println!("{}", hashmap == hashmap);

    let setnums = [12, 15, 10, 3, 13];
    let mut hashset = HashSet::new();
    println!("{}", format!("{:?}", hashset) == "{}");
    for elem in setnums {
        hashset.insert(elem);
    }

    println!("{}", !hashset.is_empty());
    println!("{}", hashset.len() == 5);
    hashset.insert(13);
    println!("{}", hashset.len() == 5);
    hashset.remove(&2);
    println!("{}", hashset.len() == 5);
    hashset.remove(&3);
    println!("{}", hashset.len() == 4);
    println!("{}", hashset.contains(&10));
    println!("{}", !hashset.contains(&4));
    hashset.clear();
    println!("{}", hashset.len() == 0);
    println!("{}", hashset == hashset);
    // set union: hashset = hashset.union(&other_set).map(|x| *x).collect();
    // set intersection: hashset = hashset.intersection(&other_set).map(|x| *x).collect();
    // set difference: hashset = hashset.difference(&other_set).map(|x| *x).collect();
    // set symmetric difference: hashset = hashset.symmetric_difference(&other_set).map(|x| *x).collect();
    // is subset: hashset.is_subset(&hashset) == true
    // is superset: hashset.is_superset(&hashset) == true
    // is disjoint: hashset.is_disjoint(&hashset) == false

    let mut randnums = [0; NUMS_LENGTH];
    for i in 0..NUMS_LENGTH {
        randnums[i] = rand::random::<i32>().abs() % 100; // (rand::random::<f64>() * 100.0) as i32;
    }

    let mut linkedlist = LinkedList::new();
    let mut minheap = BinaryHeap::new();
    let mut arrayqueue = VecDeque::new();
    let mut stack = VecDeque::new();
    for elem in randnums {
        linkedlist.push_back(elem);
        minheap.push(Reverse(elem)); // for max heap: maxheap.push(elem);
        arrayqueue.push_back(elem);
        stack.push_back(elem);
    }

    println!("{}", linkedlist.len() == NUMS_LENGTH);
    let _remove = linkedlist.pop_front().unwrap();
    println!("{}", linkedlist.len() == NUMS_LENGTH - 1);
    // can only remove from the front or back of a LinkedList
    linkedlist.pop_back();
    println!("{}", linkedlist.len() == NUMS_LENGTH - 2);
    println!("{}", linkedlist == linkedlist);

    println!("{}", !minheap.is_empty());
    println!("{}", minheap.len() == NUMS_LENGTH);
    // for max heap: maxheap.iter().map(|x| *x).collect::<Vec<_>>()
    let heapstring = format!("{:?}", minheap.iter().map(|x| x.0).collect::<Vec<_>>());
    let nodes: Vec<_> = (&heapstring[1..heapstring.len() - 1]).split(", ").collect();
    let root = nodes[0].parse::<i32>().unwrap();
    println!("{}", minheap.peek().unwrap().0 == root); // for max heap: *maxheap.peek().unwrap() == root
    println!("{}", minheap.pop().unwrap().0 == root); // for max heap: maxheap.pop().unwrap() == root
    println!("{}", minheap.len() == NUMS_LENGTH - 1);
    println!("{}", minheap.as_slice() == minheap.as_slice());

    println!("{}", !arrayqueue.is_empty());
    println!("{}", arrayqueue.len() == NUMS_LENGTH);
    let poll = arrayqueue.pop_front().unwrap();
    println!("{}", poll == randnums[0]);
    println!("{}", *arrayqueue.front().unwrap() == randnums[1]);
    println!("{}", arrayqueue.len() == NUMS_LENGTH - 1);
    println!("{}", arrayqueue == arrayqueue);

    println!("{}", !stack.is_empty());
    println!("{}", stack.len() == NUMS_LENGTH);
    let pop = stack.pop_back().unwrap();
    println!("{}", pop == randnums[randnums.len() - 1]);
    println!("{}", *stack.back().unwrap() == randnums[randnums.len() - 2]);
    println!("{}", stack.len() == NUMS_LENGTH - 1);
    println!("{}", stack == stack);

    let treenums = [6, 4, 8, 3, 5, 7, 9];
    let mut treeset = BTreeSet::new();
    println!("{}", format!("{:?}", treeset) == "{}");
    for elem in treenums {
        treeset.insert(elem);
    }

    println!("{}", !treeset.is_empty());
    println!("{}", treeset.len() == 7);
    treeset.insert(6);
    println!("{}", treeset.len() == 7);
    println!("{}", !treeset.remove(&2));
    println!("{}", treeset.len() == 7);
    treeset.remove(&4);
    println!("{}", treeset.len() == 6);
    println!("{}", treeset.contains(&8));
    println!("{}", !treeset.contains(&10));
    println!("{}", treeset == treeset);

    // right rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(20);
    treeset.insert(10);
    println!("{}", format!("{:?}", treeset) == "{10, 20, 30}");

    treeset.clear();
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(4);
    treeset.insert(7);
    treeset.insert(3);
    println!("{}", format!("{:?}", treeset) == "{3, 4, 6, 7, 8, 9}");

    treeset.clear();
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(4);
    treeset.insert(7);
    treeset.insert(5);
    println!("{}", format!("{:?}", treeset) == "{4, 5, 6, 7, 8, 9}");

    // left-right rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(10);
    treeset.insert(20);
    println!("{}", format!("{:?}", treeset) == "{10, 20, 30}");

    treeset.clear();
    treeset.insert(8);
    treeset.insert(4);
    treeset.insert(9);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(5);
    println!("{}", format!("{:?}", treeset) == "{3, 4, 5, 6, 8, 9}");

    treeset.clear();
    treeset.insert(8);
    treeset.insert(4);
    treeset.insert(9);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(7);
    println!("{}", format!("{:?}", treeset) == "{3, 4, 6, 7, 8, 9}");

    // left rotations

    treeset.clear();
    treeset.insert(10);
    treeset.insert(20);
    treeset.insert(30);
    println!("{}", format!("{:?}", treeset) == "{10, 20, 30}");

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(5);
    treeset.insert(8);
    treeset.insert(7);
    println!("{}", format!("{:?}", treeset) == "{3, 4, 5, 6, 7, 8}");

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(5);
    treeset.insert(8);
    treeset.insert(9);
    println!("{}", format!("{:?}", treeset) == "{3, 4, 5, 6, 8, 9}");

    // right-left rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(10);
    treeset.insert(20);
    println!("{}", format!("{:?}", treeset) == "{10, 20, 30}");

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(5);
    println!("{}", format!("{:?}", treeset) == "{3, 4, 5, 6, 8, 9}");

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(7);
    println!("{}", format!("{:?}", treeset) == "{3, 4, 6, 7, 8, 9}");
}
