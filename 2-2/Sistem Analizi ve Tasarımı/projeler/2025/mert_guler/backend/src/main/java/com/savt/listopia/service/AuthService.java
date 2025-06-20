package com.savt.listopia.service;

import com.savt.listopia.model.user.UserRole;
import com.savt.listopia.payload.request.SignUpRequest;
import org.springframework.http.ResponseCookie;

public interface AuthService {
    void requireRoleOrThrow(UserRole role);

    void handleSignUp(SignUpRequest signUpRequest);
    ResponseCookie handleSignIn(String username, String password);
    String handleAccountVerification(String email, String token);
}
