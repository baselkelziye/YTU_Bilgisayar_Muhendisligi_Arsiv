package hospital;

import java.io.IOException;

public class SurgeryUnsuccessfulException extends IOException {
    public SurgeryUnsuccessfulException(String message) {
        super(message);
    }
}
