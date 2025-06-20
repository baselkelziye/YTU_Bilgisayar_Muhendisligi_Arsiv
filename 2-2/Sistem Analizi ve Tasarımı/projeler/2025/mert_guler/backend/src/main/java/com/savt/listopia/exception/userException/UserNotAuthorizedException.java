package com.savt.listopia.exception.userException;

public class UserNotAuthorizedException extends UserException {
    public UserNotAuthorizedException() { super("user_not_authorized"); }
    public UserNotAuthorizedException(String message) {
        super(message);
    }
}
