public class Main {
    public static void main(String[] args) {
        MyHashSet<Integer> set = new MyHashSet<>();
        set.add(12);
        set.add(15);
        set.add(10);
        set.add(3);
        set.add(13);
        System.out.println(set);
        MyPriorityQueue<Integer> minHeap = new MyPriorityQueue<>();
        minHeap.offer(10);
        minHeap.offer(2);
        minHeap.offer(12);
        System.out.println(minHeap);
    }
}
