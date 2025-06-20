package com.savt.listopia.controller;


import com.savt.listopia.config.AppConstants;
import com.savt.listopia.exception.userException.UserNotAuthorizedException;
import com.savt.listopia.payload.dto.UserActivityDTO;
import com.savt.listopia.payload.dto.UserDTO;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import com.savt.listopia.payload.request.ChangeBiography;
import com.savt.listopia.payload.request.ChangePassword;
import com.savt.listopia.payload.response.APIResponse;
import com.savt.listopia.repository.movie.MovieRepository;
import com.savt.listopia.security.request.ChangeUsernameRequest;
import com.savt.listopia.service.UserService;
import com.savt.listopia.service.user.UserFriendService;
import com.savt.listopia.service.user.UserMovieService;
import com.savt.listopia.util.UUIDParser;
import jakarta.validation.Valid;
import jakarta.validation.constraints.Max;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Page;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.UUID;

@RestController
@RequestMapping("/api/v1/user")
public class UserController {
    private static final Logger LOGGER = LoggerFactory.getLogger(UserController.class);
    private final UserService userService;
    private final UserFriendService userFriendService;
    private final UserMovieService userMovieService;

    public UserController(UserService userService, MovieRepository movieRepository, UserFriendService userFriendService, UserMovieService userMovieService) {
        this.userService = userService;
        this.userFriendService = userFriendService;
        this.userMovieService = userMovieService;
    }

    @GetMapping("/username/{username}")
    public ResponseEntity<UserDTO> getUser(@PathVariable String username) {
        LOGGER.info("getUser: {}", username);
        UserDTO dto = userService.getUserByUsername(username);
        return ResponseEntity.ok(dto);
    }

    @PutMapping("/username")
    public ResponseEntity<APIResponse> ChangeUsername(@Valid @RequestBody ChangeUsernameRequest changeUsernameRequest) {
        Long userId = userService.getCurrentUserIdOrThrow();
        LOGGER.trace("change_username:id: {}", userId);
        userService.changeUsername(userId, changeUsernameRequest.getNewUsername());
        return ResponseEntity.ok( APIResponse.builder().success(true).message("username_changed").build() );
    }

    @PutMapping("/password")
    public ResponseEntity<APIResponse> changePassword(@Valid @RequestBody ChangePassword req) {
        Long userId = userService.getCurrentUserId().orElseThrow(UserNotAuthorizedException::new);
        LOGGER.info("changePassword: request from userId {}", userId);
        userService.changePassword(userId, req.getPassword());
        return ResponseEntity.ok( APIResponse.success("password_changed") );
    }

    @PutMapping("/biography")
    public ResponseEntity<APIResponse> changeBiography(@Valid @RequestBody ChangeBiography req) {
        Long userId = userService.getCurrentUserId().orElseThrow(UserNotAuthorizedException::new);
        LOGGER.info("changeBiography: request from userId {}", userId);
        userService.changeBiography(userId, req.getBiography());
        return ResponseEntity.ok( APIResponse.success("biography_changed") );
    }

    @GetMapping("/me")
    public ResponseEntity<UserDTO> Me() {
        Long userId = userService.getCurrentUserId().orElseThrow(UserNotAuthorizedException::new);
        UserDTO userDTO = userService.getUserById(userId);
        return ResponseEntity.ok(userDTO);
    }

    @DeleteMapping("/me")
    public ResponseEntity<APIResponse> deleteMe() {
        Long userId = userService.getCurrentUserId().orElseThrow(UserNotAuthorizedException::new);
        LOGGER.info("deleteMe: request from userId {}", userId);
        userService.deleteAccount(userId);
        return ResponseEntity.ok( APIResponse.success("me_deleted") );
    }

    @GetMapping("/uuid/{uuid}/friends")
    public ResponseEntity<Page<UserDTO>> Friends(
            @PathVariable String uuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        return ResponseEntity.ok(
                userFriendService.getUserFriends(userService.getUserIdFromUUID(UUIDParser.parse(uuid)),
                pageNumber, pageSize)
        );
    }

    @GetMapping("/uuid/{uuid}/liked_movies")
    public ResponseEntity<Page<MovieFrontDTO>> getUserLikedMovies(
            @PathVariable UUID uuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getUserIdFromUUID(uuid);
        Page<MovieFrontDTO> likedMovies = userMovieService.getUserLikedMovies(userId, pageNumber, pageSize);
        return ResponseEntity.ok(likedMovies);
    }

    @GetMapping("/uuid/{uuid}/watchlist")
    public ResponseEntity<Page<MovieFrontDTO>> getUserWatchlist(
            @PathVariable String uuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getUserIdFromUUID(UUIDParser.parse(uuid));
        Page<MovieFrontDTO> movieFrontDTOPage = userMovieService.getUserWatchlist(userId, pageNumber, pageSize);
        return ResponseEntity.ok(movieFrontDTOPage);
    }

    @GetMapping("/uuid/{uuid}/watched")
    public ResponseEntity<Page<MovieFrontDTO>> getUserWatched(
            @PathVariable String uuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getUserIdFromUUID(UUIDParser.parse(uuid));
        Page<MovieFrontDTO> movieFrontDTOPage = userMovieService.getUserWatched(userId, pageNumber, pageSize);
        return ResponseEntity.ok(movieFrontDTOPage);
    }

    @GetMapping("/uuid/{uuid}/activity")
    public ResponseEntity<Page<UserActivityDTO>> getUserActivity(
            @PathVariable String uuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getUserIdFromUUID(UUIDParser.parse(uuid));
        Page<UserActivityDTO> activityDTOS = userService.getUserActivities(userId, pageNumber, pageSize);
        return ResponseEntity.ok(activityDTOS);
    }

}
