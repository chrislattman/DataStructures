import bisect
import heapq
import random

from sortedcontainers import SortedSet # SortedDict available

from dsa.algorithms import Algorithms
from dsa.myarraylist import MyArrayList
from dsa.myhashmap import MyHashMap

NUMS_LENGTH = 10

mylist = MyArrayList[int]()
mylist.add(6, 0)
mylist.add(5)

hashmap = MyHashMap[str, int]()
hashmap.put("hello", 2)

Algorithms[int].binarySearch(mylist, 7)
Algorithms[int].mergesort(mylist)
Algorithms[int].quicksort(mylist)
Algorithms[int].heapsort(mylist)
Algorithms.heapsort(mylist)

# Every print statement should output True

arraylist: list[int] = []
print(str(arraylist) == "[]")
arraylist.append(5)
arraylist.append(10)
arraylist.append(12)
arraylist.insert(2, 17)
print(str(arraylist) == "[5, 10, 17, 12]")
print(5 in arraylist)
print(arraylist[0] == 5)
print(6 not in arraylist)
print(len(arraylist) != 0)
print(arraylist.index(12) == 3)
try:
    arraylist.index(13)
    print(False)
except ValueError:
    print(True)
try:
    arraylist.remove(19)
    print(False)
except ValueError:
    print(True)
arraylist.remove(10)
print(str(arraylist) == "[5, 17, 12]")
arraylist[1] = 13
print(str(arraylist) == "[5, 13, 12]")
print(len(arraylist) == 3)
print(arraylist == arraylist)
del arraylist[1]
print(str(arraylist) == "[5, 12]")

arraylist.clear()
print(len(arraylist) == 0)
arraylist.append(6)
arraylist.append(4)
arraylist.append(19)
arraylist.append(11)
arraylist.append(5)
arraylist.sort()
print(str(arraylist) == "[4, 5, 6, 11, 19]")
print(bisect.bisect_left(arraylist, 11) == 3)
print(bisect.bisect_left(arraylist, 2) == 0 and arraylist[0] != 2)
print(arraylist.count(19) == 1)
arraylist.reverse()
print(str(arraylist) == "[19, 11, 6, 5, 4]")

keys = ["hello", "world", "hi", "bye"]
values = [5, 17, 3, 0]
hashmap: dict[str, int] = {}
print(str(hashmap) == "{}")
for i in range(4):
    hashmap[keys[i]] = values[i]

print(len(hashmap) == 4)
print("hello" in hashmap)
print("hellos" not in hashmap)
print(5 in hashmap.values())
print(6 not in hashmap.values())
print(hashmap["hello"] == 5)
try:
    hashmap["hellos"]
    print(False)
except KeyError:
    print(True)
print(hashmap.get("hellos") == None)
print(hashmap.get("hello", -1) == 5)
print(hashmap.get("hellos", -1) == -1)
print(hashmap.setdefault("pigeon", 7) == 7)
print(hashmap.setdefault("hello", 13) == 5)
hashmap["hello"] = 6
del hashmap["hi"]
print(hashmap.pop("bye") == 0)
try:
    del hashmap["hellos"]
    print(False)
except KeyError:
    print(True)
print(hashmap.pop("hellos", None) == None)
hashmap.clear()
print(len(hashmap) == 0)
print(hashmap == hashmap)

setnums = [12, 15, 10, 3, 13]
hashset: set[int] = set()
print(str(hashset) == "set()")
for elem in setnums:
    hashset.add(elem)

print(len(hashset) == 5)
hashset.add(13)
print(len(hashset) == 5)
try:
    hashset.remove(2)
    print(False)
except KeyError:
    print(True)
print(len(hashset) == 5)
hashset.remove(3)
print(len(hashset) == 4)
print(10 in hashset)
print(4 not in hashset)
hashset.clear()
print(len(hashset) == 0)
print(hashset == hashset)
# set union: hashset.update(other_set)
# set intersection: hashset.intersection_update(other_set)
# set difference: hashset.difference_update(other_set)
# set symmetric difference: hashset.symmetric_difference_update(other_set)
# is subset: hashset.issubset(hashset) == True
# is superset: hashset.issuperset(hashset) == True
# is disjoint: hashset.isdisjoint(hashset) == False

randnums = [0] * NUMS_LENGTH
for i in range(NUMS_LENGTH):
    randnums[i] = random.randint(0, 99)

# Python 3 currently has no linked list data structure
# for max heap: multiply numbers by -1
minheap: list[int] = []
arrayqueue: list[int] = []
stack: list[int] = []
for elem in randnums:
    heapq.heappush(minheap, elem)
    arrayqueue.append(elem)
    stack.append(elem)

print(len(minheap) == NUMS_LENGTH)
heapstring = str(minheap)
nodes = heapstring[1:-1].split(",")
root = int(nodes[0])
print(minheap[0] == root)
print(heapq.heappop(minheap) == root)
print(len(minheap) == NUMS_LENGTH - 1)
print(minheap == minheap)

print(len(arrayqueue) == NUMS_LENGTH)
poll = arrayqueue.pop(0)
print(poll == randnums[0])
print(arrayqueue[0] == randnums[1])
print(len(arrayqueue) == NUMS_LENGTH - 1)
print(arrayqueue == arrayqueue)

print(len(stack) == NUMS_LENGTH)
pop = stack.pop()
print(pop == randnums[-1])
print(stack[-1] == randnums[-2])
print(len(stack) == NUMS_LENGTH - 1)
print(stack == stack)

treenums = [6, 4, 8, 3, 5, 7, 9]
treeset: SortedSet[int] = SortedSet()
print(str(treeset) == "SortedSet([])")
for elem in treenums:
    treeset.add(elem)

print(len(treeset) == 7)
treeset.add(6)
print(len(treeset) == 7)
try:
    treeset.remove(2)
    print(False)
except KeyError:
    print(True)
treeset.remove(4)
print(len(treeset) == 6)
print(8 in treeset)
print(10 not in treeset)
print(treeset == treeset)

# right rotations

treeset.clear()
treeset.add(30)
treeset.add(20)
treeset.add(10)
print(str(treeset)[10:-1] == "[10, 20, 30]")
print(str(treeset) == "SortedSet([10, 20, 30])")

treeset.clear()
treeset.add(8)
treeset.add(6)
treeset.add(9)
treeset.add(4)
treeset.add(7)
treeset.add(3)
print(str(treeset) == "SortedSet([3, 4, 6, 7, 8, 9])")

treeset.clear()
treeset.add(8)
treeset.add(6)
treeset.add(9)
treeset.add(4)
treeset.add(7)
treeset.add(5)
print(str(treeset) == "SortedSet([4, 5, 6, 7, 8, 9])")

# left-right rotations

treeset.clear()
treeset.add(30)
treeset.add(10)
treeset.add(20)
print(str(treeset) == "SortedSet([10, 20, 30])")

treeset.clear()
treeset.add(8)
treeset.add(4)
treeset.add(9)
treeset.add(3)
treeset.add(6)
treeset.add(5)
print(str(treeset) == "SortedSet([3, 4, 5, 6, 8, 9])")

treeset.clear()
treeset.add(8)
treeset.add(4)
treeset.add(9)
treeset.add(3)
treeset.add(6)
treeset.add(7)
print(str(treeset) == "SortedSet([3, 4, 6, 7, 8, 9])")

# left rotations

treeset.clear()
treeset.add(10)
treeset.add(20)
treeset.add(30)
print(str(treeset) == "SortedSet([10, 20, 30])")

treeset.clear()
treeset.add(4)
treeset.add(3)
treeset.add(6)
treeset.add(5)
treeset.add(8)
treeset.add(7)
print(str(treeset) == "SortedSet([3, 4, 5, 6, 7, 8])")

treeset.clear()
treeset.add(4)
treeset.add(3)
treeset.add(6)
treeset.add(5)
treeset.add(8)
treeset.add(9)
print(str(treeset) == "SortedSet([3, 4, 5, 6, 8, 9])")

# right-left rotations

treeset.clear()
treeset.add(30)
treeset.add(10)
treeset.add(20)
print(str(treeset) == "SortedSet([10, 20, 30])")

treeset.clear()
treeset.add(4)
treeset.add(3)
treeset.add(8)
treeset.add(6)
treeset.add(9)
treeset.add(5)
print(str(treeset) == "SortedSet([3, 4, 5, 6, 8, 9])")

treeset.clear()
treeset.add(4)
treeset.add(3)
treeset.add(8)
treeset.add(6)
treeset.add(9)
treeset.add(7)
print(str(treeset) == "SortedSet([3, 4, 6, 7, 8, 9])")
