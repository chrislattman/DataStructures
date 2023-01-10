import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class Threading7 {
    private static int fuel = 0;
    private static final ReentrantLock mutex = new ReentrantLock();
    private static final Condition condition = mutex.newCondition();

    private static class Tanker implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {
                mutex.lock();
                fuel += 60;
                System.out.println("Filled fuel... " + fuel);
                condition.signalAll();
                mutex.unlock();
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }

    private static class Car implements Runnable {
        @Override
        public void run() {
            mutex.lock();
            while (fuel < 40) {
                System.out.println("No fuel. Waiting...");
                try {
                    condition.await();
                    // Equivalent to
                    // mutex.unlock();
                    // waits for signal on condition, then
                    // mutex.lock();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
            fuel -= 40;
            System.out.println("Got fuel. Now left: " + fuel);
            mutex.unlock();
        }
    }

    public static void main(String[] args) {
        Thread[] th = new Thread[5];
        for (int i = 0; i < 5; i++) {
            if (i == 4) {
                th[i] = new Thread(new Tanker());
            } else {
                th[i] = new Thread(new Car());
            }
            th[i].start();
        }
        for (int i = 0; i < 5; i++) {
            try {
                th[i].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
