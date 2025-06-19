package com.savt.listopia.security.request;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;
import lombok.Data;

import java.util.UUID;

@Data
public class MessageUserRequest {
    UUID to;

    @Size(max = 1024)
    @NotBlank(message = "message cannot be blank.")
    String message;
}
