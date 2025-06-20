package com.savt.listopia.util.validator;

import jakarta.validation.ConstraintValidator;
import jakarta.validation.ConstraintValidatorContext;

public class UsernameValidator implements ConstraintValidator<ValidUsername, String> {

    private static final String USERNAME_REGEX = "^[a-zA-Z0-9_]+$";
    private static final int MIN_LENGTH = 3;
    private static final int MAX_LENGTH = 31;

    @Override
    public boolean isValid(String value, ConstraintValidatorContext context) {
        if (value == null) return false;

        String trimmed = value.trim();
        return trimmed.length() >= MIN_LENGTH &&
                trimmed.length() <= MAX_LENGTH &&
                trimmed.matches(USERNAME_REGEX);
    }
}
