package mertguler;

public class InsufficentStockError extends RuntimeException {
    public InsufficentStockError(String message) {
        super(message);
    }
}
