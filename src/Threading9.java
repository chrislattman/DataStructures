import java.util.concurrent.Semaphore;

public class Threading9 {
    private static final int THREAD_NUM = 4;
    private static final Semaphore semaphore = new Semaphore(2);

    private static class Routine extends Thread {
        private final int id;

        public Routine(int id) {
            this.id = id;
        }

        @Override
        public void run() {
            try {
                semaphore.acquire();
                Thread.sleep(1000);
                System.out.println("Hello from thread " + id);
                semaphore.release();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) {
        Routine[] routines = new Routine[THREAD_NUM];
        int i;
        for (i = 0; i < THREAD_NUM; i++) {
            routines[i] = new Routine(i);
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
