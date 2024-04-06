import Algorithms from "./dsa/algorithms";
import MyArrayList from "./dsa/myarraylist";

console.log("Hello world!");

const arraylist = new MyArrayList<number>();
arraylist.add(6, 0);
arraylist.add(5);

Algorithms.binarySearch(arraylist, 5);
Algorithms.mergesort(arraylist);
Algorithms.quicksort(arraylist);
Algorithms.heapsort(arraylist);
