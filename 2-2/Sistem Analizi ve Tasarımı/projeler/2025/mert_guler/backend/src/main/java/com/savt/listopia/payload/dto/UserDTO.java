package com.savt.listopia.payload.dto;

import com.savt.listopia.model.user.UserRole;
import io.swagger.v3.oas.annotations.media.Schema;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class UserDTO {
    private String uuid;

    private String username;
    private String firstName;
    private String lastName;

    @Schema(nullable = true, description = "User biography can be null")
    private String biography;

    @Schema(nullable = true, description = "User Role can be null. User role in the system. Possible values: ADMIN, MODERATOR, USER")
    private UserRole role;

    private Long lastOnline;
    private Long createdAt;

    private String profilePicture; // will be null for now.
}
