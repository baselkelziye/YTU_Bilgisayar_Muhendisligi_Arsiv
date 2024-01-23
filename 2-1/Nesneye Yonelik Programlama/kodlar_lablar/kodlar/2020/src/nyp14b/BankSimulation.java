package nyp14b;
import java.util.concurrent.*;
public class BankSimulation {
	public static void main(String[] args) {
		Account anAccount = new Account(0);
		System.out.println("Before: "+anAccount.getBalance());
		ExecutorService executor = Executors.newCachedThreadPool( );
		for( int i = 0; i < 100; i++ ) {
		    AccountDepositer task=new AccountDepositer(anAccount,1);
		    executor.execute(task);
		}
		for( int i = 0; i < 50; i++ ) {
		    AccountWithdrawer task=new AccountWithdrawer(anAccount,1);
		    executor.execute(task);

		}
		executor.shutdown();
		while( !executor.isTerminated() );
		System.out.println("After: "+anAccount.getBalance());
	}
}
