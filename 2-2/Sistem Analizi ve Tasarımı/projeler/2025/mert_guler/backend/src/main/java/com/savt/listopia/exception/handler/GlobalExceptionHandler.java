package com.savt.listopia.exception.handler;

import com.savt.listopia.exception.APIException;
import com.savt.listopia.exception.ResourceAlreadyExistException;
import com.savt.listopia.exception.ResourceNotFoundException;
import com.savt.listopia.exception.userException.UserException;
import com.savt.listopia.exception.userException.UserNotAuthorizedException;
import com.savt.listopia.exception.userException.UserNotFoundException;
import com.savt.listopia.payload.response.APIResponse;
import info.movito.themoviedbapi.tools.TmdbException;
import jakarta.validation.ConstraintViolationException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

@RestControllerAdvice
public class GlobalExceptionHandler {
    private static final Logger LOGGER = LoggerFactory.getLogger(GlobalExceptionHandler.class);

    @ExceptionHandler(MethodArgumentNotValidException.class)
    public ResponseEntity<Map<String, String>> myMethodArgumentNotValidException(
            MethodArgumentNotValidException e) {
        Map<String, String> response = new HashMap<>();
        e.getBindingResult().getAllErrors().forEach((err -> {
            String fieldName = ((FieldError) err).getField();
            String message = err.getDefaultMessage();
            response.put(fieldName, message);
        }));
        return new ResponseEntity<Map<String, String>>(response, HttpStatus.BAD_REQUEST);
    }

    @ExceptionHandler(ResourceNotFoundException.class)
    public ResponseEntity<APIResponse> myResourceNotFoundException(ResourceNotFoundException e) {
        APIResponse apiResponse = new APIResponse(e.getMessage(), false);
        return new ResponseEntity<>(apiResponse, HttpStatus.NOT_FOUND);
    }

    @ExceptionHandler(ResourceAlreadyExistException.class)
    public ResponseEntity<APIResponse> myResourceAlreadyExistException(
            ResourceAlreadyExistException e) {
        APIResponse apiResponse = new APIResponse(e.getMessage(), false);
        return new ResponseEntity<>(apiResponse, HttpStatus.CONFLICT);
    }

    @ExceptionHandler(APIException.class)
    public ResponseEntity<APIResponse> myAPIException(APIException e) {
        APIResponse apiResponse = new APIResponse(e.getMessage(), false);
        return new ResponseEntity<>(apiResponse, HttpStatus.BAD_REQUEST);
    }

    @ExceptionHandler(ConstraintViolationException.class)
    public ResponseEntity<APIResponse> myConstraintViolationException(ConstraintViolationException e) {
        APIResponse apiResponse = new APIResponse(e.getMessage(), false);
        return new ResponseEntity<>(apiResponse, HttpStatus.BAD_REQUEST);
    }

    @ExceptionHandler(TmdbException.class)
    public ResponseEntity<APIResponse> myTmdbException(TmdbException e) {
        APIResponse apiResponse = new APIResponse(e.getMessage(), false);
        return new ResponseEntity<>(apiResponse, HttpStatus.BAD_REQUEST);
    }

    @ExceptionHandler(IOException.class)
    public ResponseEntity<APIResponse> myIoException(IOException e) {
        APIResponse apiResponse = new APIResponse(e.getMessage(), false);
        return new ResponseEntity<>(apiResponse, HttpStatus.BAD_REQUEST);
    }

    @ExceptionHandler(UserException.class)
    public ResponseEntity<APIResponse> myUserException(UserException e) {
        if (e instanceof UserNotFoundException) {
            return ResponseEntity.status(404).body(APIResponse.builder().success(false).message(e.getMessage()).build());
        }
        if (e instanceof UserNotAuthorizedException) {
            return ResponseEntity.status(403).body(APIResponse.builder().success(false).message(e.getMessage()).build());
        }
        return ResponseEntity.status(403).body(APIResponse.builder().success(false).message(e.getMessage()).build());
    }

    @ExceptionHandler(IllegalArgumentException.class)
    public ResponseEntity<APIResponse> IllegalArgumentExceptionHandle(IllegalArgumentException e) {
        return ResponseEntity.status(400).body(APIResponse.builder().success(false).message("illegal_argument: " + e.getMessage()).build());
    }

}
