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

	myArrayList := dsa.NewArrayListDefault[int]()
	myArrayList.AddToEnd(5)
}
