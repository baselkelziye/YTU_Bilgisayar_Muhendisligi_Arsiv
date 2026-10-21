package nasrullahtoprak;

import java.io.IOException;

public class ItemAlreadyInCartException extends IOException {
    public ItemAlreadyInCartException(String message){
        super(message);
    }
}
