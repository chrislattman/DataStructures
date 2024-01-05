import { Algorithms } from "./dsa/algorithms";
import { MyArrayList } from "./dsa/myarraylist";

console.log("Hello world!");
const myarraylist = new MyArrayList<number>(10);
myarraylist.add(5);
const arr = [1, 2, 3];
const found = Algorithms.binarySearch(arr, 3);
const found2 = Algorithms.binarySearch(myarraylist, 3);
