package lab3_2023;

import java.io.IOException;

public class ApartmentException extends IOException {
    public ApartmentException(String message) {
        super(message);
    }
}