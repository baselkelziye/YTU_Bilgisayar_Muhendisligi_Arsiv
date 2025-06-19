package com.savt.listopia.util.validator;

import jakarta.validation.ConstraintValidator;
import jakarta.validation.ConstraintValidatorContext;

public class PasswordValidator implements ConstraintValidator<ValidPassword, String> {

    private int min;
    private int max;

    @Override
    public void initialize(ValidPassword constraintAnnotation) {
        this.min = constraintAnnotation.min();
        this.max = constraintAnnotation.max();
    }

    @Override
    public boolean isValid(String value, ConstraintValidatorContext context) {
        if (value == null) return false;

        String trimmed = value.trim();

        if (trimmed.length() < min || trimmed.length() > max) return false;

        boolean hasUppercase = trimmed.matches(".*[A-Z].*");
        boolean hasLowercase = trimmed.matches(".*[a-z].*");
        boolean hasDigit = trimmed.matches(".*\\d.*");
        boolean hasSpecial = trimmed.matches(".*[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>/?].*");
        boolean hasNoSpace = !trimmed.contains(" ");

        return hasUppercase && hasLowercase && hasDigit && hasSpecial && hasNoSpace;
    }
}
