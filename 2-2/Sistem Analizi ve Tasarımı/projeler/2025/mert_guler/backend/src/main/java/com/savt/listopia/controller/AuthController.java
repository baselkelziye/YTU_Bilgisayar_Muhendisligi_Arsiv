package com.savt.listopia.controller;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.model.user.Session;
import com.savt.listopia.payload.response.APIResponse;
import com.savt.listopia.payload.request.SignInRequest;
import com.savt.listopia.payload.request.SignUpRequest;
import com.savt.listopia.service.AuthService;
import com.savt.listopia.service.CaptchaService;
import com.savt.listopia.service.SessionService;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.validation.Valid;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpHeaders;
import org.springframework.http.ResponseCookie;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.view.RedirectView;

@RestController
@RequestMapping("/api/v1/auth")
public class AuthController {
    private static final Logger LOGGER = LoggerFactory.getLogger(AuthController.class);
    private final SessionService sessionService;
    private final AuthService authService;
    private final CaptchaService captchaService;

    public AuthController(SessionService sessionService, AuthService authService, CaptchaService captchaService) {
        this.sessionService = sessionService;
        this.authService = authService;
        this.captchaService = captchaService;
    }

    @PostMapping("/signup")
    public ResponseEntity<APIResponse> signUp(@Valid @RequestBody SignUpRequest signUpRequest, HttpServletRequest request) {
        String token = signUpRequest.getRecaptchaToken();
        String clientIp = request.getRemoteAddr();
        captchaService.validateCaptcha(token, "register", clientIp);

        LOGGER.info("signUp: signUp request arrived with mail: {}", signUpRequest.getEmail());
        authService.handleSignUp(signUpRequest);
        return ResponseEntity.ok(APIResponse.success("signup_success_verify_email"));
    }

    @PostMapping("/signin")
    public ResponseEntity<APIResponse> signIn(@Valid @RequestBody SignInRequest signInRequest, HttpServletResponse response, HttpServletRequest request) {
        String token = signInRequest.getRecaptchaToken();
        String clientIp = request.getRemoteAddr();
        captchaService.validateCaptcha(token, "login", clientIp);

        LOGGER.info("signIn: signIn request arrived with username: {}", signInRequest.getUsername());
        ResponseCookie sessionCookie = authService.handleSignIn(signInRequest.getUsername(), signInRequest.getPassword());
        response.setHeader(HttpHeaders.SET_COOKIE, sessionCookie.toString());
        return ResponseEntity.ok(APIResponse.builder().success(true).message("logged_in").build());
    }

    @PostMapping("/signout")
    public ResponseEntity<APIResponse> signOut(HttpServletResponse response) {
        sessionService.deleteCurrentSession();

        ResponseCookie deleteCookie = ResponseCookie.from("_SESSION", "")
            .secure(true)
            .httpOnly(true)
            .path("/")
            .sameSite("None")
            .maxAge(AppConstants.SESSION_EXPIRY_TIME)
            .build();

        response.setHeader(HttpHeaders.SET_COOKIE, deleteCookie.toString());
        return ResponseEntity.ok(APIResponse.builder().success(true).message("logged_out").build());
    }

    @GetMapping("/verify")
    public RedirectView verify(
            @RequestParam String email,
            @RequestParam String token
    ) {
        LOGGER.info("verify: verify request arrived with mail & token: {} - {}", email, token);
        String message = authService.handleAccountVerification(email, token);
        // TODO: fix main pls
        String redirectTo = "https://ensargok.com/login?message=" + message;
        return new RedirectView(redirectTo);
    }

}
