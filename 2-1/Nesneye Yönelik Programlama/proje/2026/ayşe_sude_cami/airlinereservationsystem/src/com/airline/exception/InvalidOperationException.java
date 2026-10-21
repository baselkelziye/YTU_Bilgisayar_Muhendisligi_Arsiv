package com.airline.exception;

/**
 * Geçersiz bir işlem yapılmaya çalışıldığında fırlatılan exception.
 * Negatif fiyat, geçersiz tarih aralığı vb. durumlarda kullanılır.
 */
public class InvalidOperationException extends AirlineException {
    private static final long serialVersionUID = 1L;

    private final String operation;

    public InvalidOperationException(String message) {
        super(message, "IO-001");
        this.operation = "Bilinmeyen";
    }

    public InvalidOperationException(String operation, String message) {
        super(operation + " işlemi geçersiz: " + message, "IO-001");
        this.operation = operation;
    }

    public String getOperation() {
        return operation;
    }
}
