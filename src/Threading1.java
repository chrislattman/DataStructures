public class Threading1 {
    private static int x = 2;

    private static class Routine extends Thread {
        @Override
        public void run() {
            x += 5;
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("Routine: Value of x = " + x);
        }
    }

    private static class Routine2 extends Thread {
        @Override
        public void run() {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("Routine2: Value of x = " + x);
        }
    }

    public static void main(String[] args) {
        Routine r1 = new Routine();
        Routine2 r2 = new Routine2();
        r1.start();
        r2.start();
        try {
            r1.join();
            r2.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
