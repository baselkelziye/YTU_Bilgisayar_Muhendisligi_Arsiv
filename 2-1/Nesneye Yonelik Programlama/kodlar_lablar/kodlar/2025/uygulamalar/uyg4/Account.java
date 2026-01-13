package Uyg4;

public class Account {
	private int id;
    private int balance;
    

    public Account(int id, int balance) {
        this.id = id;
        this.balance = balance;
    }

    public int getBalance() {
        return balance;
    }
    
    public int getId() {
        return id;
    }
    
    public void addUnsafe(int delta) {
        int temp = balance;
        temp += delta;
        balance = temp;
    }

    public synchronized void addSafe(int delta) {
        int temp = balance;
        temp += delta;
        balance = temp;
    }
}






















