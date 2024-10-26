#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dsa/myarraylist.hpp"
#include "dsa/myarrayqueue.hpp"
// #include "dsa/myhashmap.hpp"
// #include "dsa/myhashset.hpp"
#include "dsa/mylinkedlist.hpp"
#include "dsa/mystack.hpp"

#define NUMS_LENGTH 10

using namespace std;

int main(void) {
    // Every print statement should output true

    MyArrayList<int> mylist;
    vector<int> arraylist;
    cout << boolalpha << (mylist.toString().compare("[]") == 0) << endl;
    mylist.add(5);
    mylist.add(10);
    mylist.add(12);
    mylist.add(2, 17);
    arraylist.push_back(5);
    arraylist.push_back(10);
    arraylist.push_back(12);
    arraylist.insert(arraylist.begin() + 2, 17);
    // cout << mylist << endl;
    ostringstream oss;
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << (mylist.toString().compare("[5, 10, 17, 12]") == 0) << endl;
    cout << (mylist.toString().compare(oss.str()) == 0) << endl;
    cout << (oss.str().compare(mylist.toString()) == 0) << endl;
    cout << mylist.contains(5) << endl;
    cout << (find(arraylist.begin(), arraylist.end(), 5) != arraylist.end()) << endl;
    cout << (mylist[0] == 5) << endl; // mylist.get(0) == 5
    cout << (arraylist[0] == 5) << endl;
    cout << !mylist.contains(6) << endl;
    cout << (find(arraylist.begin(), arraylist.end(), 6) == arraylist.end()) << endl;
    cout << !mylist.isEmpty() << endl;
    cout << !arraylist.empty() << endl;
    cout << (mylist.indexOf(12) == 3) << endl;
    cout << (find(arraylist.begin(), arraylist.end(), 12) - arraylist.begin() == 3) << endl;
    cout << (mylist.lastIndexOf(13) == -1) << endl;
    cout << ((unsigned long) (find(arraylist.begin(), arraylist.end(), 13) - arraylist.begin()) >= arraylist.size()) << endl;
    cout << !mylist.removeElement(19) << endl;
    cout << (find(arraylist.begin(), arraylist.end(), 19) != arraylist.end() ? arraylist.erase(find(arraylist.begin(), arraylist.end(), 19)) == arraylist.end() : true) << endl;
    mylist.removeElement(10);
    arraylist.erase(find(arraylist.begin(), arraylist.end(), 10));
    cout << (mylist.toString() == string("[5, 17, 12]")) << endl;
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << (oss.str().compare(mylist.toString()) == 0) << endl;
    mylist[1] = 13; // mylist.set(1, 13)
    arraylist[1] = 13; // arraylist.at(1) = 13
    cout << (mylist.toString() == string("[5, 13, 12]")) << endl;
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << (oss.str().compare(mylist.toString()) == 0) << endl;
    cout << (mylist.size() == 3) << endl;
    cout << (arraylist.size() == 3) << endl;
    cout << (mylist == mylist) << endl;
    cout << (arraylist == arraylist) << endl;
    mylist.remove(1);
    arraylist.erase(arraylist.begin() + 1);
    cout << (mylist.toString() == string("[5, 12]")) << endl;
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << (oss.str().compare(mylist.toString()) == 0) << endl;

    MyArrayList<int> myList2;
    myList2.add(5);
    myList2.add(12);
    myList2.remove(0);
    myList2.add(0, 5);
    cout << (mylist == myList2) << endl;
    cout << (myList2 == mylist) << endl;

    MyArrayList<int> listRef = mylist;
    cout << (listRef.toString() == string("[5, 12]")) << endl;
    cout << (listRef.size() == 2) << endl;
    cout << listRef.contains(5) << endl;
    cout << !listRef.contains(6) << endl;
    cout << !listRef.isEmpty() << endl;
    cout << (listRef == listRef) << endl;

    MyArrayList<int> *myList3 = new MyArrayList<int>();
    myList3->add(5);
    myList3->add(12);
    myList3->remove(0);
    myList3->add(0, 5);
    cout << (mylist == *myList3) << endl;
    cout << (*myList3 == mylist) << endl;
    delete myList3;

    MyArrayList<int> *p = &mylist;
    // cout << *p << endl;
    cout << (p->toString() == string("[5, 12]")) << endl;
    cout << (p->size() == 2) << endl;
    cout << p->contains(5) << endl;
    cout << !p->contains(6) << endl;
    cout << !p->isEmpty() << endl;
    cout << (*p == *p) << endl;

    mylist.clear();
    arraylist.clear();
    cout << (mylist.size() == 0) << endl;
    cout << (arraylist.size() == 0) << endl;
    arraylist.push_back(6);
    arraylist.push_back(4);
    arraylist.push_back(19);
    arraylist.push_back(11);
    arraylist.push_back(5);
    sort(arraylist.begin(), arraylist.end());
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << (oss.str().compare("[4, 5, 6, 11, 19]") == 0) << endl;
    cout << binary_search(arraylist.begin(), arraylist.end(), 11) << endl;
    cout << !binary_search(arraylist.begin(), arraylist.end(), 2) << endl;
    cout << (count(arraylist.begin(), arraylist.end(), 19) == 1) << endl;
    reverse(arraylist.begin(), arraylist.end());
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << (oss.str().compare("[19, 11, 6, 5, 4]") == 0) << endl;

    string keys[] = {"hello", "world", "hi", "bye"}; // string is preferable to char * in C++
    int values[] = {5, 17, 3, 0};
    unordered_map<string, int> hashmap;
    for (int i = 0; i < 4; i++) {
        hashmap[keys[i]] = values[i]; // hashmap.insert({keys[i], values[i]})
    }

    cout << !hashmap.empty() << endl;
    cout << (hashmap.size() == 4) << endl;
    cout << (hashmap.find("hello") != hashmap.end()) << endl; // hashmap.count("hello") == 1 or with C++20: hashmap.contains("hello")
    cout << (hashmap.find("hellos") == hashmap.end()) << endl;
    // no built-in containsValue method
    cout << (hashmap["hello"] == 5) << endl; // hashmap.at("hello") == 5
    try {
        hashmap.at("hellos");
        cout << false << endl;
    } catch (const out_of_range& e) {
        cout << true << endl;
    }
    // no built-in getOrDefault method
    // no built-in putIfAbsent method
    hashmap["hello"] = 6; // hashmap.at("hello") = 6
    hashmap.erase("hi");
    // erase only returns 0 or 1
    cout << !hashmap.erase("hellos") << endl;
    hashmap.clear();
    cout << (hashmap.size() == 0) << endl;
    cout << (hashmap == hashmap) << endl;

    int setnums[] = {12, 15, 10, 3, 13};
    unordered_set<int> hashset;
    for (int elem : setnums) {
        hashset.insert(elem);
    }

    cout << !hashset.empty() << endl;
    cout << (hashset.size() == 5) << endl;
    hashset.insert(13);
    cout << (hashset.size() == 5) << endl;
    cout << !hashset.erase(2) << endl; // erase technically returns 0 or 1
    cout << (hashset.size() == 5) << endl;
    hashset.erase(3);
    cout << (hashset.size() == 4) << endl;
    cout << (hashset.find(10) != hashset.end()) << endl; // hashset.count(10) == 1 or with C++20: hashset.contains(10)
    cout << (hashset.find(4) == hashset.end()) << endl;
    hashset.clear();
    cout << (hashset.size() == 0) << endl;
    cout << (hashset == hashset) << endl;
    // For the following operations, you must sort the sets first and initialize a temporary vector:
    // vector<int> hashset_vec(hashset.begin(), hashset.end());
    // vector<int> otherset_vec(otherset.begin(), otherset.end());
    // sort(hashset_vec.begin(), hashset_vec.end());
    // sort(otherset_vec.begin(), otherset_vec.end());
    // vector<int> temp;

    // set union:
    // set_union(hashset_vec.begin(), hashset_vec.end(), otherset_vec.begin(), otherset_vec.end(), back_inserter(temp));
    // hashset = unordered_set<int>(temp.begin(), temp.end());
    // set intersection:
    // set_intersection(hashset_vec.begin(), hashset_vec.end(), otherset_vec.begin(), otherset_vec.end(), back_inserter(temp));
    // hashset = unordered_set<int>(temp.begin(), temp.end());
    // set difference:
    // set_difference(hashset_vec.begin(), hashset_vec.end(), otherset_vec.begin(), otherset_vec.end(), back_inserter(temp));
    // hashset = unordered_set<int>(temp.begin(), temp.end());
    // set symmetric difference:
    // set_symmetric_difference(hashset_vec.begin(), hashset_vec.end(), otherset_vec.begin(), otherset_vec.end(), back_inserter(temp));
    // hashset = unordered_set<int>(temp.begin(), temp.end());

    int randnums[NUMS_LENGTH];
    srand(time(0));
    for (int i = 0; i < NUMS_LENGTH; i++) {
        randnums[i] = rand() % 100;
    }

    MyLinkedList<int> mylinkedlist;
    list<int> linkedlist;
    // for max heap: priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MyArrayQueue<int> myarrayqueue;
    deque<int> arrayqueue;
    MyStack<int> mystack;
    stack<int> stack1;
    for (int elem : randnums) {
        mylinkedlist.add(elem);
        linkedlist.push_back(elem);
        minheap.push(elem);
        myarrayqueue.offer(elem);
        arrayqueue.push_back(elem);
        mystack.push(elem);
        stack1.push(elem);
    }

    cout << (mylinkedlist.size() == NUMS_LENGTH) << endl;
    list<int>::iterator range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    oss.str("");
    oss << "[";
    copy(linkedlist.begin(), range_end, ostream_iterator<int>(oss, ", "));
    oss << linkedlist.back() << "]";
    cout << (mylinkedlist.toString().compare(oss.str()) == 0) << endl;
    // no built-in remove method that returns element removed at index
    mylinkedlist.remove(4);
    range_end = linkedlist.begin();
    advance(range_end, 4);
    linkedlist.erase(range_end);
    cout << (mylinkedlist.size() == NUMS_LENGTH - 1) << endl;
    range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    oss.str("");
    oss << "[";
    copy(linkedlist.begin(), range_end, ostream_iterator<int>(oss, ", "));
    oss << linkedlist.back() << "]";
    cout << (mylinkedlist.toString().compare(oss.str()) == 0) << endl;
    mylinkedlist.remove(mylinkedlist.size() - 1);
    range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    linkedlist.erase(range_end);
    cout << (mylinkedlist.size() == NUMS_LENGTH - 2) << endl;
    range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    oss.str("");
    oss << "[";
    copy(linkedlist.begin(), range_end, ostream_iterator<int>(oss, ", "));
    oss << linkedlist.back() << "]";
    cout << (mylinkedlist.toString().compare(oss.str()) == 0) << endl;
    cout << (mylinkedlist == mylinkedlist) << endl;
    cout << (linkedlist == linkedlist) << endl;

    cout << !minheap.empty() << endl;
    cout << (minheap.size() == NUMS_LENGTH) << endl;
    // no immutable way of getting a string representation of a priority_queue
    int min_elem = *min_element(begin(randnums), end(randnums));
    int root = minheap.top();
    cout << (min_elem == root) << endl;
    // pop doesn't return the removed element
    minheap.pop();
    cout << (minheap.size() == NUMS_LENGTH - 1) << endl;
    // no == operator for priority_queue

    cout << !myarrayqueue.isEmpty() << endl;
    cout << !arrayqueue.empty() << endl;
    cout << (myarrayqueue.size() == NUMS_LENGTH) << endl;
    oss.str("");
    oss << "[";
    copy(arrayqueue.begin(), arrayqueue.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arrayqueue.back() << "]";
    cout << (myarrayqueue.toString().compare(oss.str()) == 0) << endl;
    int poll1 = myarrayqueue.poll();
    int poll2 = arrayqueue.front();
    // pop_front doesn't return the removed element
    arrayqueue.pop_front();
    cout << (poll1 == randnums[0]) << endl;
    cout << (poll1 == poll2) << endl;
    cout << (myarrayqueue.peek() == randnums[1]) << endl;
    cout << (myarrayqueue.peek() == arrayqueue.front()) << endl;
    cout << (myarrayqueue.size() == NUMS_LENGTH - 1) << endl;
    oss.str("");
    oss << "[";
    copy(arrayqueue.begin(), arrayqueue.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arrayqueue.back() << "]";
    cout << (myarrayqueue.toString().compare(oss.str()) == 0) << endl;
    cout << (myarrayqueue == myarrayqueue) << endl;
    cout << (arrayqueue == arrayqueue) << endl;

    cout << !mystack.isEmpty() << endl;
    cout << !stack1.empty() << endl;
    cout << (mystack.size() == NUMS_LENGTH) << endl;
    // no immutable way of getting a string representation of a stack
    int pop1 = mystack.pop();
    int pop2 = stack1.top();
    // pop doesn't return the removed element
    stack1.pop();
    cout << (pop1 == randnums[NUMS_LENGTH - 1]) << endl;
    cout << (pop1 == pop2) << endl;
    cout << (mystack.peek() == randnums[NUMS_LENGTH - 2]) << endl;
    cout << (mystack.peek() == stack1.top()) << endl;
    cout << (mystack.size() == NUMS_LENGTH - 1) << endl;
    cout << (mystack == mystack) << endl;
    cout << (stack1 == stack1) << endl;

    int treenums[] = {6, 4, 8, 3, 5, 7, 9};
    set<int> treeset;
    for (int elem : treenums) {
        treeset.insert(elem);
    }

    cout << !treeset.empty() << endl;
    cout << (treeset.size() == 7) << endl;
    treeset.insert(6);
    cout << (treeset.size() == 7) << endl;
    cout << !treeset.erase(2) << endl; // erase technically returns 0 or 1
    cout << (treeset.size() == 7) << endl;
    treeset.erase(4);
    cout << (treeset.size() == 6) << endl;
    cout << (treeset.find(8) != treeset.end()) << endl; // treeset.count(8) == 1 or with C++20: treeset.contains(8)
    cout << (treeset.find(10) == treeset.end()) << endl;
    cout << (treeset == treeset) << endl;

    // right rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(20);
    treeset.insert(10);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

    treeset.clear();
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(4);
    treeset.insert(7);
    treeset.insert(3);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 6, 7, 8, 9]") == 0) << endl;

    treeset.clear();
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(4);
    treeset.insert(7);
    treeset.insert(5);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[4, 5, 6, 7, 8, 9]") == 0) << endl;

    // left-right rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(10);
    treeset.insert(20);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

    treeset.clear();
    treeset.insert(8);
    treeset.insert(4);
    treeset.insert(9);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(5);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 8, 9]") == 0) << endl;

    treeset.clear();
    treeset.insert(8);
    treeset.insert(4);
    treeset.insert(9);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(7);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 6, 7, 8, 9]") == 0) << endl;

    // left rotations

    treeset.clear();
    treeset.insert(10);
    treeset.insert(20);
    treeset.insert(30);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(5);
    treeset.insert(8);
    treeset.insert(7);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 7, 8]") == 0) << endl;

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(6);
    treeset.insert(5);
    treeset.insert(8);
    treeset.insert(9);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 8, 9]") == 0) << endl;

    // right-left rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(10);
    treeset.insert(20);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(5);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 8, 9]") == 0) << endl;

    treeset.clear();
    treeset.insert(4);
    treeset.insert(3);
    treeset.insert(8);
    treeset.insert(6);
    treeset.insert(9);
    treeset.insert(7);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 6, 7, 8, 9]") == 0) << endl;

    /**
     * Commenting out because I'm not following the C++ Rule of 3
     * and MyLinkedList has a non-trivial destructor
     */
    // MyLinkedList<int> linkedListRef = myLinkedList;
    // cout << linkedListRef << endl;
    // cout << (linkedListRef.toString() == string("[5, 17]")) << endl;
    // cout << (linkedListRef.size() == 2) << endl;
    // cout << linkedListRef.contains(5) << endl;
    // cout << !linkedListRef.contains(6) << endl;
    // cout << !linkedListRef.isEmpty() << endl;
    // cout << (linkedListRef == linkedListRef) << endl;
}
