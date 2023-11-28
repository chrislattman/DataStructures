import java.util.concurrent.locks.ReentrantLock;

public class Threading3 {
    private static int x = 0;
    private static final ReentrantLock mutex = new ReentrantLock();

    private static class Routine extends Thread {
        @Override
        public void run() {
            for (int i = 0; i < 1000000; i++) {
                synchronized (Routine.class) {
                    x = x + 1;
                }
            }
        }
    }

    private static class Routine2 extends Thread {
        @Override
        public void run() {
            for (int i = 0; i < 1000000; i++) {
                increment();
            }
        }

        private static synchronized void increment() {
            x = x + 1;
        }
    }

    private static class Routine3 extends Thread {
        @Override
        public void run() {
            for (int i = 0; i < 1000000; i++) {
                mutex.lock();
                x = x + 1;
                mutex.unlock();
            }
        }
    }

    public static void main(String[] args) {
        Routine r1 = new Routine();
        Routine r2 = new Routine();
        r1.start();
        r2.start();
        try {
            r1.join();
            r2.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Value of x = " + x);

        Routine2 r3 = new Routine2();
        Routine2 r4 = new Routine2();
        r3.start();
        r4.start();
        try {
            r3.join();
            r4.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Value of x = " + x);

        Routine3 r5 = new Routine3();
        Routine3 r6 = new Routine3();
        r5.start();
        r6.start();
        try {
            r5.join();
            r6.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Value of x = " + x);
    }
}
