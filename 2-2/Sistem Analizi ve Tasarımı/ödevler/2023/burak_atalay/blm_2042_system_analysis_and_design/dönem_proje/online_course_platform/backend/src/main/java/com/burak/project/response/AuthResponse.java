package com.burak.project.response;

import com.burak.project.enumeration.Role;
import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class AuthResponse {
    private String message;
    private Long userId;
    private Role role;
    private String accessToken;
    private String refreshToken;
}
