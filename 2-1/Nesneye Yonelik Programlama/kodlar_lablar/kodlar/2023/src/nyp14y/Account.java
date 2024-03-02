package nyp14y;
public class Account {
	private double balance;
	public Account(double balance) { this.balance = balance; }
	public double getBalance() { return balance; }
	public void withdraw( double amt ){  
		balance -= amt;
	}
	public void deposit( double amt ){  
		balance += amt;
	}
	private void possibleDelay( ) {
		try { Thread.sleep(5); } 
		catch (InterruptedException e) { e.printStackTrace(); }
	}
}
