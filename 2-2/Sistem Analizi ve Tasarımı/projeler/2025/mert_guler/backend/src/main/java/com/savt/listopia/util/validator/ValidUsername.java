package com.savt.listopia.util.validator;

import jakarta.validation.Constraint;
import jakarta.validation.Payload;

import java.lang.annotation.*;

@Documented
@Constraint(validatedBy = UsernameValidator.class)
@Target({ ElementType.FIELD, ElementType.PARAMETER })
@Retention(RetentionPolicy.RUNTIME)
public @interface ValidUsername {
    String message() default "Username must be 3-31 characters long and contain only ASCII letters, digits, and underscores";
    Class<?>[] groups() default {};
    Class<? extends Payload>[] payload() default {};
}
