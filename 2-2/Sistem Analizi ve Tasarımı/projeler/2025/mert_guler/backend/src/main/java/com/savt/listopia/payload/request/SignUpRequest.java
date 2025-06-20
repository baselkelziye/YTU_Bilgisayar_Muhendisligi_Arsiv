package com.savt.listopia.payload.request;

import com.savt.listopia.util.validator.ValidPassword;
import com.savt.listopia.util.validator.ValidUsername;
import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.NotBlank;
import lombok.Data;

@Data
public class SignUpRequest {
    @NotBlank
    @Email
    private String email;

    @ValidPassword
    private String password;

    @NotBlank
    private String firstName;

    @NotBlank
    private String lastName;

    @ValidUsername
    private String username;

    @NotBlank
    private String recaptchaToken;
}
