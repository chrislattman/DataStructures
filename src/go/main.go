package main

import (
	"example.com/dsa"
	"fmt"
)

func main() {
	fmt.Println("Hello world!")

	// verifies that MyArrayList implements MyList
	var _ dsa.MyList[int] = (*dsa.MyArrayList[int])(nil)

	// verifies that MyPriorityQueue implements MyQueue
	var _ dsa.MyQueue[int] = (*dsa.MyPriorityQueue[int])(nil)

	arraylist := dsa.NewArrayListDefault[int]()
	arraylist.Add(6, 0)
	arraylist.AddToEnd(5)

	dsa.BinarySearchList(arraylist, 7)
	dsa.MergesortList(arraylist)
	dsa.QuicksortList(arraylist)
	dsa.HeapsortList(arraylist)
}
