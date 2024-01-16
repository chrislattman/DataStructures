package main

import (
	"example.com/dsa"
	"fmt"
)

func main() {
	fmt.Println("Hello world!")
	var _ dsa.MyList[int] = dsa.MyArrayList[int]{}
	myArrayList := dsa.NewArrayListDefault[int]()
	myArrayList.AddToEnd(5)
}
