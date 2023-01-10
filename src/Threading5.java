import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;

public class Threading5 {
    private static final ReentrantLock mutex = new ReentrantLock();

    private static class Routine extends Thread {
        @Override
        public void run() {
            try {
                if (mutex.tryLock(100, TimeUnit.MILLISECONDS)) {
                    System.out.println("Got lock");
                    Thread.sleep(1000);
                    mutex.unlock();
                } else {
                    System.out.println("Gave up on waiting");
                }
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
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
