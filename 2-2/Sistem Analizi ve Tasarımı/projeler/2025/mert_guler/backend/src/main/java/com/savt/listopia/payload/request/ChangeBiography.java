package com.savt.listopia.payload.request;

import jakarta.validation.constraints.Size;
import lombok.Data;

@Data
public class ChangeBiography {
    @Size(max = 128, message = "Biography must be less than 128 characters.")
    private String biography;
}
