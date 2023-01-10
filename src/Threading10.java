import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class Threading10 {
    private static final int THREAD_NUM = 9;
    private static final CyclicBarrier barrier = new CyclicBarrier(3);

    private static class Routine extends Thread {
        @Override
        public void run() {
            System.out.println("Waiting at the barrier...");
            try {
                barrier.await();
                Thread.sleep(2000);
            } catch (InterruptedException | BrokenBarrierException e) {
                throw new RuntimeException(e);
            }
            System.out.println("We passed the barrier");
        }
    }

    public static void main(String[] args) {
        Routine[] routines = new Routine[THREAD_NUM];
        int i;
        for (i = 0; i < THREAD_NUM; i++) {
            routines[i] = new Routine();
            routines[i].start();
        }
        for (i = 0; i < THREAD_NUM; i++) {
            try {
                routines[i].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
