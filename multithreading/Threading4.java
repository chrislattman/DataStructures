import java.util.concurrent.locks.ReentrantLock;

public class Threading4 {
    private static final ReentrantLock mutex = new ReentrantLock();

    private static class Routine extends Thread {
        @Override
        public void run() {
            if (mutex.tryLock()) {
                System.out.println("Got lock");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                mutex.unlock();
            } else {
                System.out.println("Didn't get lock");
            }
        }
    }

    public static void main(String[] args) {
        Routine[] routines = new Routine[4];
        for (int i = 0; i < 4; i++) {
            routines[i] = new Routine();
            routines[i].start();
        }
        for (int i = 0; i < 4; i++) {
            try {
                routines[i].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
