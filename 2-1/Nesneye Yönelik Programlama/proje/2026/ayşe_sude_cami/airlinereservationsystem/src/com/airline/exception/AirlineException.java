package com.airline.exception;

/**
 * Havayolu sistemi için temel exception sınıfı.
 * Tüm custom exception'lar bu sınıftan türetilir.
 */
public class AirlineException extends RuntimeException {
    private static final long serialVersionUID = 1L;

    private final String errorCode;

    public AirlineException(String message) {
        super(message);
        this.errorCode = "AE-000";
    }

    public AirlineException(String message, String errorCode) {
        super(message);
        this.errorCode = errorCode;
    }

    public AirlineException(String message, Throwable cause) {
        super(message, cause);
        this.errorCode = "AE-000";
    }

    public String getErrorCode() {
        return errorCode;
    }
}
