#include "dsa/myarraylist.hpp"
#include "dsa/myarrayqueue.hpp"
#include "dsa/mylinkedlist.hpp"
#include "dsa/mystack.hpp"
// #include "dsa/myhashmap.hpp"
#include <iostream>

using namespace std;

int main(void) {
    MyArrayList<int> myList;
    myList.add(5);
    myList.add(10);
    myList.add(12);
    myList.add(3, 17);
    cout << myList << endl;
    cout << boolalpha << (myList.toString().compare("[5, 10, 12, 17]") == 0) << endl;
    cout << boolalpha << myList.contains(5) << endl;
    cout << boolalpha << !myList.contains(6) << endl;
    cout << boolalpha << !myList.isEmpty() << endl;
    cout << boolalpha << (myList.indexOf(12) == 2) << endl;
    cout << boolalpha << (myList.lastIndexOf(13) == -1) << endl;
    cout << boolalpha << (myList.size() == 4) << endl;
    myList.removeElement(10);
    cout << boolalpha << (myList.toString() == string("[5, 12, 17]")) << endl;
    myList.set(1, 13);
    cout << boolalpha << (myList.toString() == string("[5, 13, 17]")) << endl;
    cout << boolalpha << (myList.size() == 3) << endl;
    cout << boolalpha << (myList == myList) << endl;
    myList.remove(1);
    cout << boolalpha << (myList.toString() == string("[5, 17]")) << endl;

    MyArrayList<int> myList2;
    myList2.add(5);
    myList2.add(17);
    myList2.remove(0);
    myList2.add(0, 5);
    cout << boolalpha << (myList == myList2) << endl;
    cout << boolalpha << (myList2 == myList) << endl;

    MyArrayList<int> *myList3 = new MyArrayList<int>();
    myList3->add(5);
    myList3->add(17);
    myList3->remove(0);
    myList3->add(0, 5);
    cout << boolalpha << (myList == *myList3) << endl;
    cout << boolalpha << (*myList3 == myList) << endl;
    delete myList3;

    MyArrayList<int> listRef = myList;
    cout << listRef << endl;
    cout << boolalpha << (listRef.toString() == string("[5, 17]")) << endl;
    cout << boolalpha << (listRef.size() == 2) << endl;
    cout << boolalpha << listRef.contains(5) << endl;
    cout << boolalpha << !listRef.contains(6) << endl;
    cout << boolalpha << !listRef.isEmpty() << endl;
    cout << boolalpha << (listRef == listRef) << endl;

    MyArrayList<int> *p = &myList;
    cout << *p << endl;
    cout << boolalpha << (p->toString() == string("[5, 17]")) << endl;
    cout << boolalpha << (p->size() == 2) << endl;
    cout << boolalpha << p->contains(5) << endl;
    cout << boolalpha << !p->contains(6) << endl;
    cout << boolalpha << !p->isEmpty() << endl;
    cout << boolalpha << (*p == *p) << endl;

    MyArrayQueue<int> myQueue;
    myQueue.offer(10);
    myQueue.offer(13);
    cout << myQueue << endl;
    cout << boolalpha << (myQueue.toString() == string("[10, 13]")) << endl;
    cout << boolalpha << (myQueue.size() == 2) << endl;
    cout << boolalpha << !myQueue.isEmpty() << endl;
    cout << boolalpha << (myQueue.peek() == 10) << endl;
    myQueue.poll();
    cout << boolalpha << (myQueue.toString() == string("[13]")) << endl;
    cout << boolalpha << (myQueue == myQueue) << endl;

    MyLinkedList<int> myLinkedList;
    myLinkedList.add(5);
    myLinkedList.add(10);
    myLinkedList.add(12);
    myLinkedList.add(3, 17);
    cout << myLinkedList << endl;
    cout << boolalpha << (myLinkedList.toString().compare("[5, 10, 12, 17]") == 0) << endl;
    cout << boolalpha << myLinkedList.contains(5) << endl;
    cout << boolalpha << !myLinkedList.contains(6) << endl;
    cout << boolalpha << !myLinkedList.isEmpty() << endl;
    cout << boolalpha << (myLinkedList.indexOf(12) == 2) << endl;
    cout << boolalpha << (myLinkedList.lastIndexOf(13) == -1) << endl;
    cout << boolalpha << (myLinkedList.size() == 4) << endl;
    myLinkedList.removeElement(10);
    cout << boolalpha << (myLinkedList.toString() == string("[5, 12, 17]")) << endl;
    myLinkedList.set(1, 13);
    cout << boolalpha << (myLinkedList.toString() == string("[5, 13, 17]")) << endl;
    cout << boolalpha << (myLinkedList.size() == 3) << endl;
    cout << boolalpha << (myLinkedList == myLinkedList) << endl;
    myLinkedList.remove(1);
    cout << boolalpha << (myLinkedList.toString() == string("[5, 17]")) << endl;

    MyLinkedList<int> myLinkedList2;
    myLinkedList2.add(5);
    myLinkedList2.add(17);
    myLinkedList2.remove(0);
    myLinkedList2.add(0, 5);
    cout << boolalpha << (myLinkedList == myLinkedList2) << endl;
    cout << boolalpha << (myLinkedList2 == myLinkedList) << endl;

    MyLinkedList<int> *myLinkedList3 = new MyLinkedList<int>();
    myLinkedList3->add(5);
    myLinkedList3->add(17);
    myLinkedList3->remove(0);
    myLinkedList3->add(0, 5);
    cout << boolalpha << (myLinkedList == *myLinkedList3) << endl;
    cout << boolalpha << (*myLinkedList3 == myLinkedList) << endl;
    delete myLinkedList3;

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

    MyLinkedList<int> *linkedp = &myLinkedList;
    cout << *linkedp << endl;
    cout << boolalpha << (linkedp->toString() == string("[5, 17]")) << endl;
    cout << boolalpha << (linkedp->size() == 2) << endl;
    cout << boolalpha << linkedp->contains(5) << endl;
    cout << boolalpha << !linkedp->contains(6) << endl;
    cout << boolalpha << !linkedp->isEmpty() << endl;
    cout << boolalpha << (*linkedp == *linkedp) << endl;

    MyStack<int> myStack;
    myStack.push(10);
    myStack.push(13);
    cout << myStack << endl;
    cout << boolalpha << (myStack.toString() == string("[10, 13]")) << endl;
    cout << boolalpha << (myStack.size() == 2) << endl;
    cout << boolalpha << !myStack.isEmpty() << endl;
    cout << boolalpha << (myStack.peek() == 13) << endl;
    myStack.pop();
    cout << boolalpha << (myStack.toString() == string("[10]")) << endl;
    cout << boolalpha << (myStack == myStack) << endl;

    // MyHashMap (and therefore MyHashSet) doesn't work
    // MyHashMap<string, int> myHashMap;
    // myHashMap.put("hello", 1);
    // myHashMap.put("world", 4);
    // cout << myHashMap.size() << endl;
}
