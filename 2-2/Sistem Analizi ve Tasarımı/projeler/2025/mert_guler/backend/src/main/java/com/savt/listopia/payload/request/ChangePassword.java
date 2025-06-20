package com.savt.listopia.payload.request;

import com.savt.listopia.util.validator.ValidPassword;
import lombok.Data;

@Data
public class ChangePassword {
    @ValidPassword
    private String password;
}
