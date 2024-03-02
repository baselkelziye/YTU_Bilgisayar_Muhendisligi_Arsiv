package nyp14y;
public class AccountWithdrawer implements Runnable {
	private Account account;
	private double amount;
	public AccountWithdrawer(Account account, double amount) {
		this.account = account; this.amount = amount;
	}
	public void run() {
		account.withdraw(amount);
	}
}
