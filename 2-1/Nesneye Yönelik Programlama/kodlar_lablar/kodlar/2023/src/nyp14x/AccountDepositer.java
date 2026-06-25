package nyp14x;
public class AccountDepositer implements Runnable {
	private Account account;
	private double amount;
	public AccountDepositer(Account account, double amount) {
		this.account = account; this.amount = amount;
	}
	public void run() {
		account.deposit(amount);
	}
}
