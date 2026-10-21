package com.burak.project.controller;

import com.burak.project.request.InstructorRequest;
import com.burak.project.request.LoginRequest;
import com.burak.project.request.RefreshTokenRequest;
import com.burak.project.request.StudentRequest;
import com.burak.project.response.AuthResponse;
import com.burak.project.service.AuthService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/auth")

public class AuthController {
    private final AuthService authService;

    public AuthController(AuthService authService) {
        this.authService = authService;
    }

    @PostMapping("/login")
    public ResponseEntity<AuthResponse> login(@RequestBody LoginRequest loginRequest){
        return authService.login(loginRequest);
    }

    @PostMapping("/register/student")
    public ResponseEntity<AuthResponse> register(@RequestBody StudentRequest studentRequest){
        return authService.registerStudent(studentRequest);
    }

    @PostMapping("/register/instructor")
    public ResponseEntity<AuthResponse> register(@RequestBody InstructorRequest instructorRequest){
        return authService.registerInstructor(instructorRequest);
    }

    @PostMapping("/refresh")
    public ResponseEntity<AuthResponse> refresh(@RequestBody RefreshTokenRequest refreshTokenRequest){
        return authService.refresh(refreshTokenRequest);
    }
}
