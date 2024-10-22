import java.util.*;

import dsa.Algorithms;
import dsa.MyArrayList;
import dsa.MyArrayQueue;
import dsa.MyHashMap;
import dsa.MyHashSet;
import dsa.MyLinkedList;
import dsa.MyPriorityQueue;
import dsa.MyStack;
import dsa.MyTreeSet;

public class Main {
    private static final int NUMS_LENGTH = 10;

    public static void main(String[] args) {
        // Every print statement should output true

        MyArrayList<Integer> myList = new MyArrayList<>();
        ArrayList<Integer> arrayList = new ArrayList<>();
        myList.add(5);
        myList.add(10);
        myList.add(12);
        myList.add(2, 17);
        arrayList.add(5);
        arrayList.add(10);
        arrayList.add(12);
        arrayList.add(2, 17);
        System.out.println(myList.toString().compareTo("[5, 10, 17, 12]") == 0);
        System.out.println(arrayList.toString().equals(myList.toString()));
        System.out.println(myList.contains(5));
        System.out.println(arrayList.contains(5));
        System.out.println(myList.get(0) == 5);
        System.out.println(arrayList.get(0) == 5);
        System.out.println(!myList.contains(6));
        System.out.println(!arrayList.contains(6));
        System.out.println(!myList.isEmpty());
        System.out.println(!arrayList.isEmpty());
        System.out.println(myList.indexOf(12) == 3);
        System.out.println(arrayList.indexOf(12) == 3);
        System.out.println(myList.lastIndexOf(13) == -1);
        System.out.println(arrayList.lastIndexOf(13) == -1);
        System.out.println(myList.toString().equals(arrayList.toString()));
        System.out.println(!myList.removeElement(19));
        System.out.println(!arrayList.remove(Integer.valueOf(19)));
        myList.removeElement(10);
        arrayList.remove(Integer.valueOf(10));
        System.out.println(myList.toString().equals("[5, 17, 12]"));
        System.out.println(arrayList.toString().equals(myList.toString()));
        myList.set(1, 13);
        arrayList.set(1, 13);
        System.out.println(myList.toString().equals("[5, 13, 12]"));
        System.out.println(arrayList.toString().equals(myList.toString()));
        System.out.println(myList.size() == 3);
        System.out.println(arrayList.size() == 3);
        System.out.println(myList.equals(myList));
        myList.remove(1);
        arrayList.remove(1);
        System.out.println(myList.toString().equals("[5, 12]"));
        System.out.println(arrayList.toString().equals(myList.toString()));

        MyArrayList<Integer> myList2 = new MyArrayList<>();
        myList2.add(5);
        myList2.add(12);
        myList2.remove(0);
        myList2.add(0, 5);
        System.out.println(myList.equals(myList2));
        System.out.println(myList2.equals(myList));

        MyArrayList<Integer> listRef = myList;
        System.out.println(listRef.toString().equals("[5, 12]"));
        System.out.println(listRef.size() == 2);
        System.out.println(listRef.contains(5));
        System.out.println(!listRef.contains(6));
        System.out.println(!listRef.isEmpty());
        System.out.println(listRef.equals(listRef));

        myList.clear();
        arrayList.clear();
        System.out.println(myList.size() == 0);
        System.out.println(myList.toString().equals(arrayList.toString()));
        myList.add(6);
        myList.add(4);
        myList.add(19);
        myList.add(11);
        myList.add(5);
        arrayList.add(6);
        arrayList.add(4);
        arrayList.add(19);
        arrayList.add(11);
        arrayList.add(5);
        Algorithms.quicksort(myList);
        Collections.sort(arrayList);
        System.out.println(myList.toString().equals("[4, 5, 6, 11, 19]"));
        System.out.println(myList.toString().equals(arrayList.toString()));
        System.out.println(Algorithms.binarySearch(myList, 11) == 3);
        System.out.println(Algorithms.binarySearch(myList, 2) == -1);
        System.out.println(Collections.binarySearch(arrayList, 11) == 3);
        System.out.println(Collections.binarySearch(arrayList, 2) == -1);
        System.out.println(Collections.frequency(arrayList, 19) == 1);
        Collections.reverse(arrayList);
        System.out.println(arrayList.toString().equals("[19, 11, 6, 5, 4]"));

        String[] keys = {"hello", "world", "hi", "bye"};
        int[] values = {5, 17, 3, 0};
        HashMap<String, Integer> hashMap = new HashMap<>();
        MyHashMap<String, Integer> myHashMap = new MyHashMap<>();
        for (int i = 0; i < 4; i++) {
            myHashMap.put(keys[i], values[i]);
            hashMap.put(keys[i], values[i]);
        }

        System.out.println(!myHashMap.isEmpty());
        System.out.println(myHashMap.size() == 4);
        System.out.println(myHashMap.containsKey("hello"));
        System.out.println(!myHashMap.containsKey("hellos"));
        System.out.println(myHashMap.containsValue(5));
        System.out.println(!myHashMap.containsValue(6));
        System.out.println(myHashMap.get("hello") == 5);
        System.out.println(myHashMap.get("hellos") == null);
        System.out.println(myHashMap.getOrDefault("hello", -1) == 5);
        System.out.println(myHashMap.getOrDefault("hellos", -1) == -1);
        System.out.println(myHashMap.putIfAbsent("pigeon", 7) == null);
        System.out.println(myHashMap.putIfAbsent("hello", 13) == 5);
        myHashMap.replace("hello", 6);
        myHashMap.remove("hi");
        System.out.println(myHashMap.remove("bye") == 0);
        System.out.println(myHashMap.remove("hellos") == null);
        myHashMap.clear();
        System.out.println(myHashMap.size() == 0);
        System.out.println(myHashMap.equals(myHashMap));

        System.out.println(!hashMap.isEmpty());
        System.out.println(hashMap.size() == 4);
        System.out.println(hashMap.containsKey("hello"));
        System.out.println(!hashMap.containsKey("hellos"));
        System.out.println(hashMap.containsValue(5));
        System.out.println(!hashMap.containsValue(6));
        System.out.println(hashMap.get("hello") == 5);
        System.out.println(hashMap.get("hellos") == null);
        System.out.println(hashMap.getOrDefault("hello", -1) == 5);
        System.out.println(hashMap.getOrDefault("hellos", -1) == -1);
        System.out.println(hashMap.putIfAbsent("pigeon", 7) == null);
        System.out.println(hashMap.putIfAbsent("hello", 13) == 5);
        hashMap.replace("hello", 6);
        hashMap.remove("hi");
        System.out.println(hashMap.remove("bye") == 0);
        System.out.println(hashMap.remove("hellos") == null);
        hashMap.clear();
        System.out.println(hashMap.size() == 0);
        System.out.println(hashMap.equals(hashMap));

        int[] setNums = {12, 15, 10, 3, 13};
        MyHashSet<Integer> myHashSet = new MyHashSet<>();
        HashSet<Integer> hashSet = new HashSet<>();
        for (int setNum : setNums) {
            myHashSet.add(setNum);
            hashSet.add(setNum);
        }

        System.out.println(!myHashSet.isEmpty());
        System.out.println(myHashSet.size() == 5);
        System.out.println(!myHashSet.add(13));
        System.out.println(myHashSet.size() == 5);
        System.out.println(!myHashSet.remove(2));
        System.out.println(myHashSet.size() == 5);
        myHashSet.remove(3);
        System.out.println(myHashSet.size() == 4);
        System.out.println(myHashSet.contains(10));
        System.out.println(!myHashSet.contains(4));
        myHashSet.clear();
        System.out.println(myHashSet.size() == 0);
        System.out.println(myHashSet.equals(myHashSet));

        System.out.println(!hashSet.isEmpty());
        System.out.println(hashSet.size() == 5);
        System.out.println(!hashSet.add(13));
        System.out.println(hashSet.size() == 5);
        System.out.println(!hashSet.remove(2));
        System.out.println(hashSet.size() == 5);
        System.out.println(hashSet.remove(3));
        System.out.println(hashSet.size() == 4);
        System.out.println(hashSet.contains(10));
        System.out.println(!hashSet.contains(4));
        hashSet.clear();
        System.out.println(hashSet.size() == 0);
        System.out.println(hashSet.equals(hashSet));

        Random random = new Random();
        int[] randnums = new int[NUMS_LENGTH];
        for (int i = 0; i < NUMS_LENGTH; i++) {
            randnums[i] = random.nextInt(100);
        }

        MyLinkedList<Integer> myLinkedList = new MyLinkedList<>();
        LinkedList<Integer> linkedList = new LinkedList<>();
        MyPriorityQueue<Integer> myMinHeap = new MyPriorityQueue<>();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        MyArrayQueue<Integer> myArrayQueue = new MyArrayQueue<>();
        ArrayDeque<Integer> arrayQueue = new ArrayDeque<>();
        MyStack<Integer> myStack = new MyStack<>();
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < NUMS_LENGTH; i++) {
            myLinkedList.add(randnums[i]);
            linkedList.add(randnums[i]);
            myMinHeap.offer(randnums[i]);
            minHeap.offer(randnums[i]);
            myArrayQueue.offer(randnums[i]);
            arrayQueue.offer(randnums[i]);
            myStack.push(randnums[i]);
            stack.push(randnums[i]);
        }

        System.out.println(myLinkedList.size() == NUMS_LENGTH);
        System.out.println(myLinkedList.toString().equals(linkedList.toString()));
        int remove1 = myLinkedList.remove(0);
        int remove2 = linkedList.remove(0);
        System.out.println(remove1 == remove2);
        System.out.println(myLinkedList.size() == NUMS_LENGTH - 1);
        System.out.println(myLinkedList.toString().equals(linkedList.toString()));
        myLinkedList.remove(4);
        linkedList.remove(4);
        System.out.println(myLinkedList.size() == NUMS_LENGTH - 2);
        System.out.println(myLinkedList.toString().equals(linkedList.toString()));
        myLinkedList.remove(myLinkedList.size() - 1);
        linkedList.remove(linkedList.size() - 1);
        System.out.println(myLinkedList.size() == NUMS_LENGTH - 3);
        System.out.println(myLinkedList.toString().equals(linkedList.toString()));

        System.out.println(!myMinHeap.isEmpty());
        System.out.println(!minHeap.isEmpty());
        System.out.println(myMinHeap.toString().equals(minHeap.toString()));
        String heapString = myMinHeap.toString();
        String[] nodes = heapString.substring(1, heapString.length() - 1).split(", ");
        int root = Integer.parseInt(nodes[0]);
        System.out.println(myMinHeap.peek() == root);
        System.out.println(myMinHeap.size() == NUMS_LENGTH);
        System.out.println(myMinHeap.poll() == root);
        System.out.println(myMinHeap.size() == NUMS_LENGTH - 1);
        System.out.println(minHeap.peek() == root);
        System.out.println(minHeap.size() == NUMS_LENGTH);
        System.out.println(minHeap.poll() == root);
        System.out.println(minHeap.size() == NUMS_LENGTH - 1);
        System.out.println(myMinHeap.toString().equals(minHeap.toString()));
        System.out.println(myMinHeap.equals(myMinHeap));

        System.out.println(!myArrayQueue.isEmpty());
        System.out.println(!arrayQueue.isEmpty());
        System.out.println(myArrayQueue.size() == NUMS_LENGTH);
        System.out.println(myArrayQueue.toString().equals(arrayQueue.toString()));
        int poll1 = myArrayQueue.poll();
        int poll2 = arrayQueue.poll();
        System.out.println(poll1 == randnums[0]);
        System.out.println(poll1 == poll2);
        System.out.println(myArrayQueue.peek() == randnums[1]);
        System.out.println(myArrayQueue.peek() == arrayQueue.peek());
        System.out.println(myArrayQueue.size() == NUMS_LENGTH - 1);
        System.out.println(myArrayQueue.toString().equals(arrayQueue.toString()));
        System.out.println(myArrayQueue.equals(myArrayQueue));

        System.out.println(!myStack.isEmpty());
        System.out.println(!stack.isEmpty());
        System.out.println(myStack.size() == NUMS_LENGTH);
        System.out.println(myStack.toString().equals(stack.toString()));
        int pop1 = myStack.pop();
        int pop2 = stack.pop();
        System.out.println(pop1 == randnums[randnums.length - 1]);
        System.out.println(pop1 == pop2);
        System.out.println(myStack.peek() == randnums[randnums.length - 2]);
        System.out.println(myStack.peek() == stack.peek());
        System.out.println(myStack.size() == NUMS_LENGTH - 1);
        System.out.println(myStack.toString().equals(stack.toString()));
        System.out.println(myStack.equals(myStack));

        int[] treeNums = {6, 4, 8, 3, 5, 7, 9};
        MyTreeSet<Integer> myTreeSet = new MyTreeSet<>();
        TreeSet<Integer> treeSet = new TreeSet<>();
        for (int treeNum : treeNums) {
            myTreeSet.add(treeNum);
            treeSet.add(treeNum);
        }
        System.out.println(myTreeSet.toString().equals(treeSet.toString()));
        System.out.println(!myTreeSet.isEmpty());
        System.out.println(!treeSet.isEmpty());
        System.out.println(myTreeSet.equals(myTreeSet));

        System.out.println(myTreeSet.size() == 7);
        System.out.println(!myTreeSet.add(6));
        System.out.println(myTreeSet.size() == 7);
        System.out.println(!myTreeSet.remove(2));
        System.out.println(myTreeSet.size() == 7);
        System.out.println(myTreeSet.remove(4));
        System.out.println(myTreeSet.size() == 6);
        System.out.println(myTreeSet.contains(8));
        System.out.println(!myTreeSet.contains(10));
        System.out.println(myTreeSet.remove(7));

        System.out.println(treeSet.size() == 7);
        System.out.println(!treeSet.add(6));
        System.out.println(treeSet.size() == 7);
        System.out.println(!treeSet.remove(2));
        System.out.println(treeSet.size() == 7);
        System.out.println(treeSet.remove(4));
        System.out.println(treeSet.size() == 6);
        System.out.println(treeSet.contains(8));
        System.out.println(!treeSet.contains(10));
        System.out.println(treeSet.remove(7));

        System.out.println(myTreeSet.toString().equals(treeSet.toString()));

        // right rotations

        myTreeSet.clear();
        myTreeSet.add(30);
        myTreeSet.add(20);
        myTreeSet.add(10);
        System.out.println(myTreeSet.toString().equals("[10, 20, 30]"));

        myTreeSet.clear();
        myTreeSet.add(8);
        myTreeSet.add(6);
        myTreeSet.add(9);
        myTreeSet.add(4);
        myTreeSet.add(7);
        myTreeSet.add(3);
        System.out.println(myTreeSet.toString().equals("[3, 4, 6, 7, 8, 9]"));

        myTreeSet.clear();
        myTreeSet.add(8);
        myTreeSet.add(6);
        myTreeSet.add(9);
        myTreeSet.add(4);
        myTreeSet.add(7);
        myTreeSet.add(5);
        System.out.println(myTreeSet.toString().equals("[4, 5, 6, 7, 8, 9]"));

        // left-right rotations

        myTreeSet.clear();
        myTreeSet.add(30);
        myTreeSet.add(10);
        myTreeSet.add(20);
        System.out.println(myTreeSet.toString().equals("[10, 20, 30]"));

        myTreeSet.clear();
        myTreeSet.add(8);
        myTreeSet.add(4);
        myTreeSet.add(9);
        myTreeSet.add(3);
        myTreeSet.add(6);
        myTreeSet.add(5);
        System.out.println(myTreeSet.toString().equals("[3, 4, 5, 6, 8, 9]"));

        myTreeSet.clear();
        myTreeSet.add(8);
        myTreeSet.add(4);
        myTreeSet.add(9);
        myTreeSet.add(3);
        myTreeSet.add(6);
        myTreeSet.add(7);
        System.out.println(myTreeSet.toString().equals("[3, 4, 6, 7, 8, 9]"));

        // left rotations

        myTreeSet.clear();
        myTreeSet.add(10);
        myTreeSet.add(20);
        myTreeSet.add(30);
        System.out.println(myTreeSet.toString().equals("[10, 20, 30]"));

        myTreeSet.clear();
        myTreeSet.add(4);
        myTreeSet.add(3);
        myTreeSet.add(6);
        myTreeSet.add(5);
        myTreeSet.add(8);
        myTreeSet.add(7);
        System.out.println(myTreeSet.toString().equals("[3, 4, 5, 6, 7, 8]"));

        myTreeSet.clear();
        myTreeSet.add(4);
        myTreeSet.add(3);
        myTreeSet.add(6);
        myTreeSet.add(5);
        myTreeSet.add(8);
        myTreeSet.add(9);
        System.out.println(myTreeSet.toString().equals("[3, 4, 5, 6, 8, 9]"));

        // right-left rotations

        myTreeSet.clear();
        myTreeSet.add(30);
        myTreeSet.add(10);
        myTreeSet.add(20);
        System.out.println(myTreeSet.toString().equals("[10, 20, 30]"));

        myTreeSet.clear();
        myTreeSet.add(4);
        myTreeSet.add(3);
        myTreeSet.add(8);
        myTreeSet.add(6);
        myTreeSet.add(9);
        myTreeSet.add(5);
        System.out.println(myTreeSet.toString().equals("[3, 4, 5, 6, 8, 9]"));

        myTreeSet.clear();
        myTreeSet.add(4);
        myTreeSet.add(3);
        myTreeSet.add(8);
        myTreeSet.add(6);
        myTreeSet.add(9);
        myTreeSet.add(7);
        System.out.println(myTreeSet.toString().equals("[3, 4, 6, 7, 8, 9]"));
    }
}
