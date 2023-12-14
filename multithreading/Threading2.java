public class Threading2 {
    private static int x = 0;

    private static class Routine extends Thread {
        @Override
        public void run() {
            for (int i = 0; i < 1000000; i++) {
                x = x + 1;
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

//        r1 = new Routine();
//        r2 = new Routine();
//
//        x = 0;
//        r1.start();
//        r2.start();
//        try {
//            r1.join();
//            r2.join();
//        } catch (InterruptedException e) {
//            throw new RuntimeException(e);
//        }
//        System.out.println("Value of x = " + x);
    }
}
