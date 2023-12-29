from dsa.algorithms import Algorithms
from dsa.myarraylist import MyArrayList
from dsa.myhashmap import MyHashMap

arraylist = MyArrayList[int]()
arraylist.add(5)

hashmap = MyHashMap[str, int]()
hashmap.put("hello", 2)

print("Test")

Algorithms[int].binarySearch(arraylist, 7)
Algorithms[int].mergesort(arraylist)
Algorithms[int].quicksort(arraylist)
Algorithms[int].heapsort(arraylist)
Algorithms.heapsort(arraylist)
