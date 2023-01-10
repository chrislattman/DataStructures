public class Threading0 {
    private static class Routine extends Thread {
        @Override
        public void run() {
            System.out.println("Test from threads");
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("Ending thread");
        }
    }

    public static void main(String[] args) {
        Routine r1 = new Routine();
        Routine r2 = new Routine();
//        r1.run();
//        r2.run();
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
