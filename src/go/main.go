package main

import (
	"container/heap"
	"container/list"
	"fmt"
	"maps"
	"math/rand"
	"slices"
	"strconv"
	"strings"

	"example.com/dsa"
)

type PriorityQueue []int

func (h PriorityQueue) Len() int           { return len(h) }
func (h PriorityQueue) Less(i, j int) bool { return h[i] < h[j] }
func (h PriorityQueue) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *PriorityQueue) Push(x any)        { *h = append(*h, x.(int)) }
func (h *PriorityQueue) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

const NUMS_LENGTH = 10

func main() {
	// verifies that MyArrayList implements MyList
	var _ dsa.MyList[int] = (*dsa.MyArrayList[int])(nil)

	// verifies that MyPriorityQueue implements MyQueue
	var _ dsa.MyQueue[int] = (*dsa.MyPriorityQueue[int])(nil)

	myarraylist := dsa.NewArrayListDefault[int]()
	myarraylist.Add(6, 0)
	myarraylist.AddToEnd(5)
	fmt.Println(fmt.Sprint(myarraylist) == "[]")

	dsa.BinarySearchList(myarraylist, 7)
	dsa.MergesortList(myarraylist)
	dsa.QuicksortList(myarraylist)
	dsa.HeapsortList(myarraylist)

	// Every print statement should output true

	var arraylist []int
	fmt.Println(fmt.Sprint(arraylist) == "[]")
	arraylist = append(arraylist, 5)
	arraylist = append(arraylist, 10)
	arraylist = append(arraylist, 12)
	arraylist = slices.Insert(arraylist, 2, 17)
	fmt.Println(fmt.Sprint(arraylist) == "[5 10 17 12]")
	fmt.Println(slices.Contains(arraylist, 5))
	fmt.Println(arraylist[0] == 5)
	fmt.Println(!slices.Contains(arraylist, 6))
	fmt.Println(len(arraylist) != 0)
	fmt.Println(slices.Index(arraylist, 12) == 3)
	fmt.Println(slices.Index(arraylist, 13) == -1)
	// this will panic:
	// arraylist = append(arraylist[:slices.Index(arraylist, 19)], arraylist[slices.Index(arraylist, 19) + 1:]...)
	// old style:
	// arraylist = append(arraylist[:slices.Index(arraylist, 10)], arraylist[slices.Index(arraylist, 10) + 1:]...)
	arraylist = slices.Delete(arraylist, slices.Index(arraylist, 10), slices.Index(arraylist, 10)+1)
	fmt.Println(fmt.Sprint(arraylist) == "[5 17 12]")
	arraylist[1] = 13
	fmt.Println(fmt.Sprint(arraylist) == "[5 13 12]")
	fmt.Println(len(arraylist) == 3)
	fmt.Println(slices.Equal(arraylist, arraylist))
	arraylist = append(arraylist[:1], arraylist[2:]...)
	fmt.Println(fmt.Sprint(arraylist) == "[5 12]")

	arraylist = nil // slices.Clear(arraylist) available in future release
	fmt.Println(len(arraylist) == 0)
	arraylist = append(arraylist, 6)
	arraylist = append(arraylist, 4)
	arraylist = append(arraylist, 19)
	arraylist = append(arraylist, 11)
	arraylist = append(arraylist, 5)
	slices.Sort(arraylist)
	fmt.Println(fmt.Sprint(arraylist) == "[4 5 6 11 19]")
	index, found := slices.BinarySearch(arraylist, 11)
	fmt.Println(found && index == 3)
	index, found = slices.BinarySearch(arraylist, 2)
	fmt.Println(!found && index == 0)
	// no built-in frequency/count function for slices
	slices.Reverse(arraylist)
	fmt.Println(fmt.Sprint(arraylist) == "[19 11 6 5 4]")

	keys := [4]string{"hello", "world", "hi", "bye"} // both allocated
	values := [4]int{5, 17, 3, 0}                    // on the stack
	hashmap := make(map[string]int)
	fmt.Println(fmt.Sprint(hashmap) == "map[]")
	for i := 0; i < 4; i++ {
		hashmap[keys[i]] = values[i]
	}

	fmt.Println(len(hashmap) == 4)
	if _, ok := hashmap["hello"]; ok {
		fmt.Println(true)
	} else {
		fmt.Println(false)
	}
	if _, ok := hashmap["hellos"]; ok {
		fmt.Println(false)
	} else {
		fmt.Println(true)
	}
	// no built-in containsValue/values function
	for val := range maps.Values(hashmap) {
		if val == 5 {
			fmt.Println(true)
			break
		}
	}
	for val := range maps.Values(hashmap) {
		if val == 6 {
			fmt.Println(false)
			break
		}
	}
	fmt.Println(hashmap["hello"] == 5)
	// no built-in getOrDefault/get function
	// no built-in putIfAbsent/setdefault function
	hashmap["hello"] = 6
	delete(hashmap, "hi")
	// no remove/pop method
	for key := range hashmap {
		delete(hashmap, key)
	}
	fmt.Println(len(hashmap) == 0)
	fmt.Println(maps.Equal(hashmap, hashmap))

	setnums := []int{12, 15, 10, 3, 13} // allocated on the heap
	hashset := make(map[int]bool)
	for _, elem := range setnums {
		hashset[elem] = true
	}

	fmt.Println(len(hashset) == 5)
	hashset[13] = true
	fmt.Println(len(hashset) == 5)
	delete(hashset, 2) // doesn't return anything
	fmt.Println(len(hashset) == 5)
	delete(hashset, 3)
	fmt.Println(len(hashset) == 4)
	if _, ok := hashset[10]; ok {
		fmt.Println(true)
	} else {
		fmt.Println(false)
	}
	if _, ok := hashset[4]; ok {
		fmt.Println(false)
	} else {
		fmt.Println(true)
	}
	for elem := range hashset {
		delete(hashset, elem)
	}
	fmt.Println(len(hashset) == 0)
	fmt.Println(maps.Equal(hashset, hashset))
	// no built-in methods for set union, intersection, difference, symmetric difference, is subset/superset, or is disjoint

	var randnums [NUMS_LENGTH]int
	for i := 0; i < NUMS_LENGTH; i++ {
		randnums[i] = rand.Intn(100)
	}

	linkedlist := list.New()
	// for max heap: multiply numbers by -1
	var minheap PriorityQueue
	var arrayqueue []int
	var stack []int
	fmt.Println(fmt.Sprint(minheap) == "[]")
	for _, elem := range randnums {
		linkedlist.PushBack(elem)
		heap.Push(&minheap, elem)
		arrayqueue = append(arrayqueue, elem)
		stack = append(stack, elem)
	}

	fmt.Println(linkedlist.Len() == NUMS_LENGTH)
	// can only get front or back of a list
	linkedlist.Remove(linkedlist.Front()) // Remove returns removed element (but it's unused here)
	fmt.Println(linkedlist.Len() == NUMS_LENGTH-1)
	linkedlist.Remove(linkedlist.Back())
	fmt.Println(linkedlist.Len() == NUMS_LENGTH-2)
	fmt.Println(linkedlist == linkedlist)

	fmt.Println(minheap.Len() == NUMS_LENGTH)
	heapstring := fmt.Sprint(minheap)
	nodes := strings.Split(heapstring[1:len(heapstring)-1], " ")
	root, _ := strconv.Atoi(nodes[0])
	fmt.Println(minheap[0] == root)
	fmt.Println(heap.Pop(&minheap) == root)
	fmt.Println(minheap.Len() == NUMS_LENGTH-1)
	fmt.Println(slices.Equal(minheap, minheap))

	fmt.Println(len(arrayqueue) == NUMS_LENGTH)
	poll := arrayqueue[0]
	arrayqueue = arrayqueue[1:]
	fmt.Println(poll == randnums[0])
	fmt.Println(arrayqueue[0] == randnums[1])
	fmt.Println(len(arrayqueue) == NUMS_LENGTH-1)
	fmt.Println(slices.Equal(arrayqueue, arrayqueue))

	fmt.Println(len(stack) == NUMS_LENGTH)
	pop := stack[len(stack)-1]
	stack = stack[:len(stack)-1]
	fmt.Println(pop == randnums[len(randnums)-1])
	fmt.Println(stack[len(stack)-1] == randnums[len(randnums)-2])
	fmt.Println(len(stack) == NUMS_LENGTH-1)
	fmt.Println(slices.Equal(stack, stack))
}
