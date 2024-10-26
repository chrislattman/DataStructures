import Algorithms from "./dsa/algorithms";
import MyArrayList from "./dsa/myarraylist";

const NUMS_LENGTH = 10;

const myArrayList = new MyArrayList<number>();
myArrayList.add(6, 0);
myArrayList.add(5);

Algorithms.binarySearch(myArrayList, 5);
Algorithms.mergesort(myArrayList);
Algorithms.quicksort(myArrayList);
Algorithms.heapsort(myArrayList);

// Every print statement should output true

const arraylist = [];
console.log(arraylist.toString() === "");
arraylist.push(5);
arraylist.push(10);
arraylist.push(12);
arraylist.splice(2, 0, 17);
console.log(arraylist.toString() === "5,10,17,12");
console.log(arraylist.includes(5));
console.log(arraylist[0] === 5);
console.log(!arraylist.includes(6));
console.log(arraylist.length != 0);
console.log(arraylist.indexOf(12) === 3);
console.log(arraylist.lastIndexOf(13) === -1);
console.log(arraylist.splice(arraylist.indexOf(19), arraylist.indexOf(19) > -1 ? 1 : 0).length === 0);
arraylist.splice(arraylist.indexOf(10), arraylist.indexOf(10) > -1 ? 1 : 0);
console.log(arraylist.toString() === "5,17,12");
arraylist[1] = 13;
console.log(arraylist.toString() === "5,13,12");
console.log(arraylist.length === 3);
console.log(arraylist === arraylist);
arraylist.splice(1, 1);
console.log(arraylist.toString() === "5,12");

arraylist.splice(0, arraylist.length);
console.log(arraylist.length === 0);
arraylist.push(6);
arraylist.push(4);
arraylist.push(19);
arraylist.push(11);
arraylist.push(5);
arraylist.sort((a, b) => a - b);
console.log(arraylist.toString() === "4,5,6,11,19");
console.log(arraylist.indexOf(11) === 3); // no built-in binary search
console.log(arraylist.indexOf(2) === -1); // no built-in binary search
console.log(arraylist.filter((a) => a === 19).length === 1);
arraylist.reverse();
console.log(arraylist.toString() === "19,11,6,5,4");

const keys = ["hello", "world", "hi", "bye"];
const values = [5, 17, 3, 0];
const hashmap = new Map();
for (let i = 0; i < 4; i++) {
    hashmap.set(keys[i], values[i]);
}

console.log(hashmap.size === 4);
console.log(hashmap.has("hello"));
console.log(!hashmap.has("hellos"));
console.log(Array.from(hashmap.values()).includes(5));
console.log(!Array.from(hashmap.values()).includes(6));
console.log(hashmap.get("hello") === 5);
console.log(hashmap.get("hellos") === undefined);
console.log((hashmap.get("hello") === undefined ? undefined : hashmap.get("hello")) === 5);
console.log((hashmap.get("hellos") === undefined ? undefined : hashmap.get("hellos")) === undefined);
console.log((hashmap.has("pigeon") ? hashmap.get("pigeon") : hashmap.set("pigeon", 7).get("pigeon")) === 7);
console.log((hashmap.has("hello") ? hashmap.get("hello") : hashmap.set("hello", 13).get("hello")) === 5);
hashmap.set("hello", 6);
hashmap.delete("hi");
// delete only returns true or false
console.log(!hashmap.delete("hellos"));
hashmap.clear();
console.log(hashmap.size === 0);
console.log(hashmap === hashmap);

const setnums = [12, 15, 10, 3, 13];
const hashset = new Set();
setnums.forEach((elem) => hashset.add(elem));

console.log(hashset.size === 5);
hashset.add(13);
console.log(hashset.size === 5);
console.log(!hashset.delete(2));
console.log(hashset.size === 5);
hashset.delete(3);
console.log(hashset.size === 4);
console.log(hashset.has(10));
console.log(!hashset.has(4));
hashset.clear();
console.log(hashset.size === 0);
console.log(hashset === hashset);
// no built-in methods for set union, intersection, difference, symmetric difference, is subset/superset, or is disjoint

const randnums = new Array(NUMS_LENGTH);
for (let i = 0; i < NUMS_LENGTH; i++) {
    randnums[i] = Math.floor(Math.random() * 100);
}

const arrayqueue = [];
const stack = [];
randnums.forEach((elem) => {
    arrayqueue.push(elem);
    stack.push(elem);
});

console.log(arrayqueue.length === NUMS_LENGTH);
const poll = arrayqueue.shift();
console.log(poll === randnums[0]);
console.log(arrayqueue[0] === randnums[1]);
console.log(arrayqueue.length === NUMS_LENGTH - 1);
console.log(arrayqueue === arrayqueue);

console.log(stack.length === NUMS_LENGTH);
const pop = stack.pop();
console.log(pop === randnums[randnums.length - 1]);
console.log(stack.at(-1) === randnums.at(-2));
console.log(stack.length === NUMS_LENGTH - 1);
console.log(stack === stack);
