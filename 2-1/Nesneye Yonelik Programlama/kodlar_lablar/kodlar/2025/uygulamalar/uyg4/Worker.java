package Uyg4;

public class Worker implements Runnable {

    private Object[] ops;
    private int start;
    private int end;
    private Account acc;

    public Worker(Object[] ops, int start, int end, Account acc) {
        this.ops = ops;
        this.start = start;
        this.end = end;
        this.acc = acc;
    }

    @Override
    public void run() {
        for (int i = start; i < end; i++) {
            int delta = (int) ops[i];

            acc.addUnsafe(delta);
            // acc.addSafe(delta);
        }
    }
}
