import java.util.*;

import dsa.MyArrayList;
import dsa.MyArrayQueue;
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
        myList.add(5);
        myList.add(10);
        myList.add(12);
        myList.add(3, 17);
        System.out.println(myList.toString().compareTo("[5, 10, 12, 17]") == 0);
        System.out.println(myList.contains(5));
        System.out.println(!myList.contains(6));
        System.out.println(!myList.isEmpty());
        System.out.println(myList.indexOf(12) == 2);
        System.out.println(myList.lastIndexOf(13) == -1);
        myList.removeElement(10);
        System.out.println(myList.toString().equals("[5, 12, 17]"));
        myList.set(1, 13);
        System.out.println(myList.toString().equals("[5, 13, 17]"));
        System.out.println(myList.size() == 3);
        System.out.println(myList.equals(myList));
        myList.remove(1);
        System.out.println(myList.toString().equals("[5, 17]"));

        MyArrayList<Integer> myList2 = new MyArrayList<>();
        myList2.add(5);
        myList2.add(17);
        myList2.remove(0);
        myList2.add(0, 5);
        System.out.println(myList.equals(myList2));
        System.out.println(myList2.equals(myList));

        MyArrayList<Integer> listRef = myList;
        System.out.println(listRef.toString().equals("[5, 17]"));
        System.out.println(listRef.size() == 2);
        System.out.println(listRef.contains(5));
        System.out.println(!listRef.contains(6));
        System.out.println(!listRef.isEmpty());
        System.out.println(listRef.equals(listRef));

        int[] setNums = {12, 15, 10, 3, 13};
        MyHashSet<Integer> myHashSet = new MyHashSet<>();
        HashSet<Integer> hashSet = new HashSet<>();
        for (int setNum : setNums) {
            myHashSet.add(setNum);
            hashSet.add(setNum);
        }

        System.out.println(myHashSet.size() == 5);
        System.out.println(!myHashSet.add(13));
        System.out.println(myHashSet.size() == 5);
        System.out.println(!myHashSet.remove(2));
        System.out.println(myHashSet.size() == 5);
        System.out.println(myHashSet.remove(3));
        System.out.println(myHashSet.size() == 4);
        System.out.println(myHashSet.contains(10));
        System.out.println(!myHashSet.contains(4));

        System.out.println(hashSet.size() == 5);
        System.out.println(!hashSet.add(13));
        System.out.println(hashSet.size() == 5);
        System.out.println(!hashSet.remove(2));
        System.out.println(hashSet.size() == 5);
        System.out.println(hashSet.remove(3));
        System.out.println(hashSet.size() == 4);
        System.out.println(hashSet.contains(10));
        System.out.println(!hashSet.contains(4));

        Random random = new Random();
        int[] randomNums = new int[NUMS_LENGTH];
        for (int i = 0; i < NUMS_LENGTH; i++) {
            randomNums[i] = random.nextInt(100);
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
            myLinkedList.add(randomNums[i]);
            linkedList.add(randomNums[i]);
            myMinHeap.offer(randomNums[i]);
            minHeap.offer(randomNums[i]);
            myArrayQueue.offer(randomNums[i]);
            arrayQueue.offer(randomNums[i]);
            myStack.push(randomNums[i]);
            stack.push(randomNums[i]);
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

        System.out.println(myArrayQueue.size() == NUMS_LENGTH);
        System.out.println(myArrayQueue.toString().equals(arrayQueue.toString()));
        int poll1 = myArrayQueue.poll();
        int poll2 = arrayQueue.poll();
        System.out.println(poll1 == poll2);
        System.out.println(myArrayQueue.size() == NUMS_LENGTH - 1);
        System.out.println(myArrayQueue.toString().equals(arrayQueue.toString()));
        
        System.out.println(myStack.size() == NUMS_LENGTH);
        System.out.println(myStack.toString().equals(stack.toString()));
        int pop1 = myStack.pop();
        int pop2 = stack.pop();
        System.out.println(pop1 == pop2);
        System.out.println(myStack.size() == NUMS_LENGTH - 1);
        System.out.println(myStack.toString().equals(stack.toString()));

        int[] treeNums = {6, 4, 8, 3, 5, 7, 9};
        MyTreeSet<Integer> myTreeSet = new MyTreeSet<>();
        TreeSet<Integer> treeSet = new TreeSet<>();
        for (int treeNum : treeNums) {
            myTreeSet.add(treeNum);
            treeSet.add(treeNum);
        }
        System.out.println(myTreeSet.toString().equals(treeSet.toString()));

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
