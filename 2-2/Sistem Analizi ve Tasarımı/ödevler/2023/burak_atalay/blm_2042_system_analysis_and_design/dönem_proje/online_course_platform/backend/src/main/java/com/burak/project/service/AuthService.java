package com.burak.project.service;

import com.burak.project.model.Instructor;
import com.burak.project.model.Student;
import com.burak.project.model.Token;
import com.burak.project.repository.ITokenRepository;
import com.burak.project.request.InstructorRequest;
import com.burak.project.request.LoginRequest;
import com.burak.project.request.RefreshTokenRequest;
import com.burak.project.request.StudentRequest;
import com.burak.project.response.AuthResponse;
import com.burak.project.security.JwtTokenProvider;
import com.burak.project.security.JwtUserDetails;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

@Service
public class AuthService {
    private final StudentService studentService;
    private final InstructorService instructorService;
    private final JwtTokenProvider jwtTokenProvider;
    private final AuthenticationManager authenticationManager;
    private final ITokenRepository tokenRepository;
    private final UserDetailsServiceImpl userDetailsService;
    private static final Logger logger = LogManager.getLogger(AuthService.class);

    public AuthService(StudentService studentService,
                       InstructorService instructorService,
                       JwtTokenProvider jwtTokenProvider,
                       AuthenticationManager authenticationManager,
                       ITokenRepository tokenRepository,
                       UserDetailsServiceImpl userDetailsService) {
        this.studentService = studentService;
        this.instructorService = instructorService;
        this.jwtTokenProvider = jwtTokenProvider;
        this.authenticationManager = authenticationManager;
        this.tokenRepository = tokenRepository;
        this.userDetailsService = userDetailsService;
    }

    public ResponseEntity<AuthResponse> login(LoginRequest loginRequest) {
        if(doAuthenticate(loginRequest)){
            return createToken("user is successfully logged in.", loginRequest.getUsername());
        }
        return new ResponseEntity<>(AuthResponse.builder().
                message("Invalid username or password!!!").build(), HttpStatus.UNAUTHORIZED);
    }

    public ResponseEntity<AuthResponse> registerStudent(StudentRequest studentRequest) {
        Student student = studentService.createStudent(studentRequest);
        LoginRequest loginRequest = LoginRequest.builder()
                .username(studentRequest.getUsername())
                .password(studentRequest.getPassword())
                .build();

        if(doAuthenticate(loginRequest)){
            return createToken("student is successfully registered.", student.getUsername());
        }
        else{
            return new ResponseEntity<>(AuthResponse.builder().
                    message("authentication is failed after registration").build(), HttpStatus.UNAUTHORIZED);
        }
    }

    public ResponseEntity<AuthResponse> registerInstructor(InstructorRequest instructorRequest) {
        Instructor instructor = instructorService.createInstructor(instructorRequest);
        LoginRequest loginRequest = LoginRequest.builder()
                .username(instructorRequest.getUsername())
                .password(instructorRequest.getPassword())
                .build();

        if(doAuthenticate(loginRequest)){
            return createToken("instructor is successfully registered.", instructor.getUsername());
        }
        else{
            return new ResponseEntity<>(AuthResponse.builder().
                    message("authentication is failed after registration").build(), HttpStatus.UNAUTHORIZED);
        }
    }

    public ResponseEntity<AuthResponse> refresh(RefreshTokenRequest refreshTokenRequest) {
        if(refreshTokenRequest.getUserId() == null) new ResponseEntity<>(AuthResponse.builder().
                message("userId cannot be null.").build(), HttpStatus.BAD_REQUEST);

        Token token = tokenRepository.findByUserId(refreshTokenRequest.getUserId());
        if(token == null){
            return new ResponseEntity<>(AuthResponse.builder().
                    message("there is not a refresh token of this user.").build(), HttpStatus.BAD_REQUEST);
        }

        JwtUserDetails userDetails = userDetailsService.loadUserByUserId(refreshTokenRequest.getUserId());

        if(token.getRefreshToken().equals(refreshTokenRequest.getRefreshToken()) &&
                jwtTokenProvider.validateToken(token.getRefreshToken(), userDetails)){
            return createToken("Token is successfully refreshed.", userDetails.getUsername());
        }
        else{
            return new ResponseEntity<>(AuthResponse.builder().
                    message("Refresh token is not valid.").build(), HttpStatus.UNAUTHORIZED);
        }
    }

    private ResponseEntity<AuthResponse> createToken(String message, String username){

        JwtUserDetails userDetails = userDetailsService.loadUserByUsername(username);

        String accessToken = jwtTokenProvider.generateToken(userDetails.getUsername());
        String refreshToken = jwtTokenProvider.generateRefreshToken(userDetails.getUsername());

        Token token = tokenRepository.findByUserId(userDetails.getId());

        if(token == null){
            token = Token.builder()
                    .refreshToken(refreshToken)
                    .userId(userDetails.getId()).
                    build();
        }
        else{
            token.setRefreshToken(refreshToken);
        }

        tokenRepository.save(token);
        return new ResponseEntity<>(AuthResponse.builder().
                accessToken("Bearer " + accessToken).
                refreshToken(token.getRefreshToken()).
                userId(userDetails.getId()).
                role(userDetails.getRole()).
                message(message).build(), HttpStatus.CREATED);
    }

    private Boolean doAuthenticate(LoginRequest loginRequest) {
        try {
            Authentication authentication = authenticationManager.authenticate(
                    new UsernamePasswordAuthenticationToken(loginRequest.getUsername(), loginRequest.getPassword()));
            SecurityContextHolder.getContext().setAuthentication(authentication);
            return true;
        } catch (AuthenticationException e) {
            logger.error("Exception during authentication: ", e);
            return false;
        }
    }
}
