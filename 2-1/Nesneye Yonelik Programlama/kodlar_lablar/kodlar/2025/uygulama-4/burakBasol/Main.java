public class Main {

    public static void main(String[] args) throws Exception {

        Bank bank = new Bank("Yildiz Bank");
        Object[] ops = bank.loadData("data.txt");

        Account acc = new Account(1, 0);
        bank.addAccount(acc);

        int mid = ops.length / 2;

        Worker w1 = new Worker(ops, 0, mid, acc);
        Worker w2 = new Worker(ops, mid, ops.length, acc);

        Thread t1 = new Thread(w1);
        Thread t2 = new Thread(w2);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Banka: " + bank.getName());
        System.out.println("Hesap ID: " + acc.getId());
        System.out.println("Sonuç: " + acc.getBalance());
        System.out.println("Beklenen (SAFE): 10");
    }
}
