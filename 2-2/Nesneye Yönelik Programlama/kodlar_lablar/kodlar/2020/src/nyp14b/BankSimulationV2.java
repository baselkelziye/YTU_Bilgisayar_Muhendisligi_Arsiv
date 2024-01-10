package nyp14b;
import java.util.concurrent.*;
public class BankSimulationV2 {
	public static void main(String[] args) {
		Account anAccount = new Account(1000);
		System.out.println("Before: "+anAccount.getBalance());
		ExecutorService executor = Executors.newCachedThreadPool( );
		AccountWithdrawer task=new AccountWithdrawer(anAccount,100);
		executor.execute(task);
		AccountWithdrawer task2=new AccountWithdrawer(anAccount,50);
		executor.execute(task2);
		executor.shutdown();
		while( !executor.isTerminated() );
			System.out.println("After: "+anAccount.getBalance());
	}
}
