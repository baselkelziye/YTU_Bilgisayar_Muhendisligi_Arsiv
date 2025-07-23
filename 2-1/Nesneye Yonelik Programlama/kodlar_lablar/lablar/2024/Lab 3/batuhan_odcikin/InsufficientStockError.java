package batuhanodcikin;

public class InsufficientStockError extends Exception {
	public InsufficientStockError(String message) {
		System.out.println(message);
	}
}
