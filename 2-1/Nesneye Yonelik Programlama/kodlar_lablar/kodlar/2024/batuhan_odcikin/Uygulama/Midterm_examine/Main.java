package batu;

public class Main{
	public static void main(String [] args) {
		Product hmd_su = new Product("su",4.5);
		VendingMachine vendingMachine = new VendingMachine(hmd_su, 21);
		vendingMachine.enterCoin(0.10);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(0.50);
		vendingMachine.enterCoin(2);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		vendingMachine.enterCoin(1);
		
		System.out.println(vendingMachine.buyProduct());
	}
}