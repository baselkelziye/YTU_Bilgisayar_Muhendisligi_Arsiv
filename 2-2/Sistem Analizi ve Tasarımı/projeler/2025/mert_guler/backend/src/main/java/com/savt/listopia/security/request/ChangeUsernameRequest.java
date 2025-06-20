package com.savt.listopia.security.request;

import com.savt.listopia.util.validator.ValidUsername;
import lombok.Data;

@Data
public class ChangeUsernameRequest {
    @ValidUsername
    String newUsername;
}
