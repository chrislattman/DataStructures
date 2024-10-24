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
    cout << boolalpha << (mylist.toString().compare("[5, 10, 17, 12]") == 0) << endl;
    cout << boolalpha << (mylist.toString().compare(oss.str()) == 0) << endl;
    cout << boolalpha << (oss.str().compare(mylist.toString()) == 0) << endl;
    cout << boolalpha << mylist.contains(5) << endl;
    cout << boolalpha << (find(arraylist.begin(), arraylist.end(), 5) != arraylist.end()) << endl;
    cout << boolalpha << (mylist[0] == 5) << endl; // mylist.get(0) == 5
    cout << boolalpha << (arraylist[0] == 5) << endl;
    cout << boolalpha << !mylist.contains(6) << endl;
    cout << boolalpha << (find(arraylist.begin(), arraylist.end(), 6) == arraylist.end()) << endl;
    cout << boolalpha << !mylist.isEmpty() << endl;
    cout << boolalpha << !arraylist.empty() << endl;
    cout << boolalpha << (mylist.indexOf(12) == 3) << endl;
    cout << boolalpha << (find(arraylist.begin(), arraylist.end(), 12) - arraylist.begin() == 3) << endl;
    cout << boolalpha << (mylist.lastIndexOf(13) == -1) << endl;
    cout << boolalpha << ((unsigned long) (find(arraylist.begin(), arraylist.end(), 13) - arraylist.begin()) >= arraylist.size()) << endl;
    cout << boolalpha << !mylist.removeElement(19) << endl;
    cout << boolalpha << (find(arraylist.begin(), arraylist.end(), 19) != arraylist.end() ? arraylist.erase(find(arraylist.begin(), arraylist.end(), 19)) == arraylist.end() : true) << endl;
    mylist.removeElement(10);
    arraylist.erase(find(arraylist.begin(), arraylist.end(), 10));
    cout << boolalpha << (mylist.toString() == string("[5, 17, 12]")) << endl;
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << boolalpha << (oss.str().compare(mylist.toString()) == 0) << endl;
    mylist[1] = 13; // mylist.set(1, 13)
    arraylist[1] = 13; // arraylist.at(1) = 13
    cout << boolalpha << (mylist.toString() == string("[5, 13, 12]")) << endl;
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << boolalpha << (oss.str().compare(mylist.toString()) == 0) << endl;
    cout << boolalpha << (mylist.size() == 3) << endl;
    cout << boolalpha << (arraylist.size() == 3) << endl;
    cout << boolalpha << (mylist == mylist) << endl;
    cout << boolalpha << (arraylist == arraylist) << endl;
    mylist.remove(1);
    arraylist.erase(arraylist.begin() + 1);
    cout << boolalpha << (mylist.toString() == string("[5, 12]")) << endl;
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << boolalpha << (oss.str().compare(mylist.toString()) == 0) << endl;

    MyArrayList<int> myList2;
    myList2.add(5);
    myList2.add(12);
    myList2.remove(0);
    myList2.add(0, 5);
    cout << boolalpha << (mylist == myList2) << endl;
    cout << boolalpha << (myList2 == mylist) << endl;

    MyArrayList<int> *myList3 = new MyArrayList<int>();
    myList3->add(5);
    myList3->add(12);
    myList3->remove(0);
    myList3->add(0, 5);
    cout << boolalpha << (mylist == *myList3) << endl;
    cout << boolalpha << (*myList3 == mylist) << endl;
    delete myList3;

    MyArrayList<int> listRef = mylist;
    cout << boolalpha << (listRef.toString() == string("[5, 12]")) << endl;
    cout << boolalpha << (listRef.size() == 2) << endl;
    cout << boolalpha << listRef.contains(5) << endl;
    cout << boolalpha << !listRef.contains(6) << endl;
    cout << boolalpha << !listRef.isEmpty() << endl;
    cout << boolalpha << (listRef == listRef) << endl;

    MyArrayList<int> *p = &mylist;
    // cout << *p << endl;
    cout << boolalpha << (p->toString() == string("[5, 12]")) << endl;
    cout << boolalpha << (p->size() == 2) << endl;
    cout << boolalpha << p->contains(5) << endl;
    cout << boolalpha << !p->contains(6) << endl;
    cout << boolalpha << !p->isEmpty() << endl;
    cout << boolalpha << (*p == *p) << endl;

    mylist.clear();
    arraylist.clear();
    cout << boolalpha << (mylist.size() == 0) << endl;
    cout << boolalpha << (arraylist.size() == 0) << endl;
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
    cout << boolalpha << (oss.str().compare("[4, 5, 6, 11, 19]") == 0) << endl;
    cout << boolalpha << binary_search(arraylist.begin(), arraylist.end(), 11) << endl;
    cout << boolalpha << !binary_search(arraylist.begin(), arraylist.end(), 2) << endl;
    cout << boolalpha << (count(arraylist.begin(), arraylist.end(), 19) == 1) << endl;
    reverse(arraylist.begin(), arraylist.end());
    oss.str("");
    oss << "[";
    copy(arraylist.begin(), arraylist.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arraylist.back() << "]";
    cout << boolalpha << (oss.str().compare("[19, 11, 6, 5, 4]") == 0) << endl;

    string keys[] = {"hello", "world", "hi", "bye"}; // string is preferable to char * in C++
    int values[] = {5, 17, 3, 0};
    unordered_map<string, int> hashmap;
    for (int i = 0; i < 4; i++) {
        hashmap[keys[i]] = values[i]; // hashmap.insert({keys[i], values[i]})
    }

    cout << boolalpha << !hashmap.empty() << endl;
    cout << boolalpha << (hashmap.size() == 4) << endl;
    cout << boolalpha << (hashmap.find("hello") != hashmap.end()) << endl; // hashmap.count("hello") == 1 or with C++20: hashmap.contains("hello")
    cout << boolalpha << (hashmap.find("hellos") == hashmap.end()) << endl;
    // no built-in containsValue method
    cout << boolalpha << (hashmap["hello"] == 5) << endl; // hashmap.at("hello") == 5
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
    hashmap.clear();
    cout << boolalpha << (hashmap.size() == 0) << endl;
    cout << boolalpha << (hashmap == hashmap) << endl;

    int setnums[] = {12, 15, 10, 3, 13};
    unordered_set<int> hashset;
    for (int elem : setnums) {
        hashset.insert(elem);
    }

    cout << boolalpha << !hashset.empty() << endl;
    cout << boolalpha << (hashset.size() == 5) << endl;
    hashset.insert(13);
    cout << boolalpha << (hashset.size() == 5) << endl;
    cout << boolalpha << !hashset.erase(2) << endl; // erase technically returns 0 or 1
    cout << boolalpha << (hashset.size() == 5) << endl;
    hashset.erase(3);
    cout << boolalpha << (hashset.size() == 4) << endl;
    cout << boolalpha << (hashset.find(10) != hashset.end()) << endl; // hashset.count(10) == 1 or with C++20: hashset.contains(10)
    cout << boolalpha << (hashset.find(4) == hashset.end()) << endl;
    hashset.clear();
    cout << boolalpha << (hashset.size() == 0) << endl;
    cout << boolalpha << (hashset == hashset) << endl;

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

    cout << boolalpha << (mylinkedlist.size() == NUMS_LENGTH) << endl;
    list<int>::iterator range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    oss.str("");
    oss << "[";
    copy(linkedlist.begin(), range_end, ostream_iterator<int>(oss, ", "));
    oss << linkedlist.back() << "]";
    cout << boolalpha << (mylinkedlist.toString().compare(oss.str()) == 0) << endl;
    // no built-in remove method that returns element removed at index
    mylinkedlist.remove(4);
    range_end = linkedlist.begin();
    advance(range_end, 4);
    linkedlist.erase(range_end);
    cout << boolalpha << (mylinkedlist.size() == NUMS_LENGTH - 1) << endl;
    range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    oss.str("");
    oss << "[";
    copy(linkedlist.begin(), range_end, ostream_iterator<int>(oss, ", "));
    oss << linkedlist.back() << "]";
    cout << boolalpha << (mylinkedlist.toString().compare(oss.str()) == 0) << endl;
    mylinkedlist.remove(mylinkedlist.size() - 1);
    range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    linkedlist.erase(range_end);
    cout << boolalpha << (mylinkedlist.size() == NUMS_LENGTH - 2) << endl;
    range_end = linkedlist.begin();
    advance(range_end, linkedlist.size() - 1);
    oss.str("");
    oss << "[";
    copy(linkedlist.begin(), range_end, ostream_iterator<int>(oss, ", "));
    oss << linkedlist.back() << "]";
    cout << boolalpha << (mylinkedlist.toString().compare(oss.str()) == 0) << endl;
    cout << boolalpha << (mylinkedlist == mylinkedlist) << endl;
    cout << boolalpha << (linkedlist == linkedlist) << endl;

    cout << !minheap.empty() << endl;
    // no immutable way of getting a string representation of a priority_queue
    int min_elem = *min_element(begin(randnums), end(randnums));
    int root = minheap.top();
    cout << boolalpha << (min_elem == root) << endl;
    cout << boolalpha << (minheap.size() == NUMS_LENGTH) << endl;
    // pop doesn't return the removed element
    minheap.pop();
    cout << boolalpha << (minheap.size() == NUMS_LENGTH - 1) << endl;
    // no == operator for priority_queue

    cout << boolalpha << !myarrayqueue.isEmpty() << endl;
    cout << boolalpha << !arrayqueue.empty() << endl;
    cout << boolalpha << (myarrayqueue.size() == NUMS_LENGTH) << endl;
    oss.str("");
    oss << "[";
    copy(arrayqueue.begin(), arrayqueue.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arrayqueue.back() << "]";
    cout << boolalpha << (myarrayqueue.toString().compare(oss.str()) == 0) << endl;
    int poll1 = myarrayqueue.poll();
    int poll2 = arrayqueue.front();
    // pop_front doesn't return the removed element
    arrayqueue.pop_front();
    cout << boolalpha << (poll1 == randnums[0]) << endl;
    cout << boolalpha << (poll1 == poll2) << endl;
    cout << boolalpha << (myarrayqueue.peek() == randnums[1]) << endl;
    cout << boolalpha << (myarrayqueue.peek() == arrayqueue.front()) << endl;
    cout << boolalpha << (myarrayqueue.size() == NUMS_LENGTH - 1) << endl;
    oss.str("");
    oss << "[";
    copy(arrayqueue.begin(), arrayqueue.end() - 1, ostream_iterator<int>(oss, ", "));
    oss << arrayqueue.back() << "]";
    cout << boolalpha << (myarrayqueue.toString().compare(oss.str()) == 0) << endl;
    cout << boolalpha << (myarrayqueue == myarrayqueue) << endl;
    cout << boolalpha << (arrayqueue == arrayqueue) << endl;

    cout << boolalpha << !mystack.isEmpty() << endl;
    cout << boolalpha << !stack1.empty() << endl;
    cout << boolalpha << (mystack.size() == NUMS_LENGTH) << endl;
    // no immutable way of getting a string representation of a stack
    int pop1 = mystack.pop();
    int pop2 = stack1.top();
    // pop doesn't return the removed element
    stack1.pop();
    cout << boolalpha << (pop1 == randnums[NUMS_LENGTH - 1]) << endl;
    cout << boolalpha << (pop1 == pop2) << endl;
    cout << boolalpha << (mystack.peek() == randnums[NUMS_LENGTH - 2]) << endl;
    cout << boolalpha << (mystack.peek() == stack1.top()) << endl;
    cout << boolalpha << (mystack.size() == NUMS_LENGTH - 1) << endl;
    cout << boolalpha << (mystack == mystack) << endl;
    cout << boolalpha << (stack1 == stack1) << endl;

    int treenums[] = {6, 4, 8, 3, 5, 7, 9};
    set<int> treeset;
    for (int elem : treenums) {
        treeset.insert(elem);
    }

    cout << boolalpha << !treeset.empty() << endl;
    cout << boolalpha << (treeset.size() == 7) << endl;
    treeset.insert(6);
    cout << boolalpha << (treeset.size() == 7) << endl;
    cout << boolalpha << !treeset.erase(2) << endl; // erase technically returns 0 or 1
    cout << boolalpha << (treeset.size() == 7) << endl;
    treeset.erase(4);
    cout << boolalpha << (treeset.size() == 6) << endl;
    cout << boolalpha << (treeset.find(8) != treeset.end()) << endl; // treeset.count(8) == 1 or with C++20: treeset.contains(8)
    cout << boolalpha << (treeset.find(10) == treeset.end()) << endl;
    cout << boolalpha << (treeset == treeset) << endl;

    // right rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(20);
    treeset.insert(10);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 6, 7, 8, 9]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[4, 5, 6, 7, 8, 9]") == 0) << endl;

    // left-right rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(10);
    treeset.insert(20);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 8, 9]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 6, 7, 8, 9]") == 0) << endl;

    // left rotations

    treeset.clear();
    treeset.insert(10);
    treeset.insert(20);
    treeset.insert(30);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 7, 8]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 8, 9]") == 0) << endl;

    // right-left rotations

    treeset.clear();
    treeset.insert(30);
    treeset.insert(10);
    treeset.insert(20);
    oss.str("");
    oss << "[";
    copy(treeset.begin(), treeset.end(), ostream_iterator<int>(oss, ", "));
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[10, 20, 30]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 5, 6, 8, 9]") == 0) << endl;

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
    cout << boolalpha << (oss.str().substr(0, oss.str().length() - 2).append("]").compare("[3, 4, 6, 7, 8, 9]") == 0) << endl;

    /**
     * Commenting out because I'm not following the C++ Rule of 3
     * and MyLinkedList has a non-trivial destructor
     */
    // MyLinkedList<int> linkedListRef = myLinkedList;
    // cout << linkedListRef << endl;
    // cout << boolalpha << (linkedListRef.toString() == string("[5, 17]")) << endl;
    // cout << boolalpha << (linkedListRef.size() == 2) << endl;
    // cout << boolalpha << linkedListRef.contains(5) << endl;
    // cout << boolalpha << !linkedListRef.contains(6) << endl;
    // cout << boolalpha << !linkedListRef.isEmpty() << endl;
    // cout << boolalpha << (linkedListRef == linkedListRef) << endl;
}
