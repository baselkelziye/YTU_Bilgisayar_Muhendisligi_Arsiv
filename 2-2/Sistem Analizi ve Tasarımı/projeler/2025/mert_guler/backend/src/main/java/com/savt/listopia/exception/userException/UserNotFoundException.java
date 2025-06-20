package com.savt.listopia.exception.userException;

public class UserNotFoundException extends UserException {
    public UserNotFoundException() {super("user_not_found");}
    public UserNotFoundException(String message) {
        super(message);
    }
}
