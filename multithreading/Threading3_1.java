import java.util.concurrent.atomic.AtomicInteger;

public class Threading3_1 {
    private static AtomicInteger x = new AtomicInteger(); // _Atomic in C

    private static class Routine extends Thread {
        @Override
        public void run() {
            for (int i = 0; i < 1000000; i++) {
                x.incrementAndGet();
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
    }
}
