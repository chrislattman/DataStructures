from dsa.algorithms import Algorithms
from dsa.myarraylist import MyArrayList
from dsa.myhashmap import MyHashMap

print("Hello world!")

arraylist = MyArrayList[int]()
arraylist.add(6, 0)
arraylist.add(5)

hashmap = MyHashMap[str, int]()
hashmap.put("hello", 2)

Algorithms[int].binarySearch(arraylist, 7)
Algorithms[int].mergesort(arraylist)
Algorithms[int].quicksort(arraylist)
Algorithms[int].heapsort(arraylist)
Algorithms.heapsort(arraylist)
