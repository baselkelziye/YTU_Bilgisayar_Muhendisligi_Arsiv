package com.savt.listopia.payload.request;

import jakarta.validation.constraints.NotBlank;
import lombok.Data;

@Data
public class SignInRequest {
    @NotBlank
    private String username;

    @NotBlank
    private String password;

    @NotBlank
    private String recaptchaToken;
}
