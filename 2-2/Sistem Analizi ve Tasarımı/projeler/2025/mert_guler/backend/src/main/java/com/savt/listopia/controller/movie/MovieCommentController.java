package com.savt.listopia.controller.movie;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.payload.dto.MovieCommentDTO;
import com.savt.listopia.payload.response.APIResponse;
import com.savt.listopia.service.UserService;
import com.savt.listopia.service.user.UserMovieService;
import com.savt.listopia.util.UUIDParser;
import jakarta.validation.constraints.Max;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Page;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1")
@Validated
public class MovieCommentController {
    private static final Logger LOGGER = LoggerFactory.getLogger(MovieCommentController.class);

    private final UserService userService;
    private final UserMovieService userMovieService;

    public MovieCommentController(UserService userService, UserMovieService userMovieService) {
        this.userService = userService;
        this.userMovieService = userMovieService;
    }

    @PostMapping("/movies/{movieId}/comment")
    public ResponseEntity<MovieCommentDTO> commentMovie(
            @PathVariable Integer movieId,
            @RequestParam(name = "message") String message,
            @RequestParam(name = "isSpoiler", required = false) Boolean isSpoiler
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        LOGGER.info("commentMovie: creating movie comment for movieId: {}", movieId);
        MovieCommentDTO dto = userMovieService.createMovieComment(userId, movieId, isSpoiler, message);
        return ResponseEntity.ok(dto);
    }

    @GetMapping("/movies/{movieId}/comment")
    public ResponseEntity<Page<MovieCommentDTO>> getMovieComments(
            @PathVariable Integer movieId,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize,
            @RequestParam(name = "fromUser", defaultValue = "", required = false) String fromUser
    ) {
        Page<MovieCommentDTO> dto;
        if ( fromUser.isEmpty() ) {
            dto = userMovieService.getMovieCommentForMovie(movieId,pageNumber,pageSize);
        } else {
            Long userId = userService.getUserIdFromUUID(UUIDParser.parse(fromUser));
            dto = userMovieService.getMovieCommentForMovieFromUser(movieId, userId, pageNumber, pageSize);
        }
        return ResponseEntity.ok(dto);
    }

    @PostMapping("/movies/comment/{commentId}/report")
    public ResponseEntity<APIResponse> reportMessage(
            @PathVariable Long commentId
    ) {
        LOGGER.info("reportMessage: reporting message with Id: {}", commentId);
        userMovieService.reportMovieComment(commentId);
        return ResponseEntity.ok(APIResponse.builder().success(true).message("movie_comment_reported").build());
    }

    @PutMapping("/movies/comment/{commentId}")
    public ResponseEntity<MovieCommentDTO> changeComment(
            @PathVariable Long commentId,
            @RequestParam(name = "message") String message,
            @RequestParam(name = "isSpoiler", required = false) Boolean isSpoiler
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        LOGGER.info("changeComment: editing movie comment with it: {}", commentId);
        MovieCommentDTO dto = userMovieService.updateMovieComment(userId, commentId, isSpoiler, message);
        return ResponseEntity.ok(dto);
    }

    @DeleteMapping("/movies/comment/{commentId}")
    public ResponseEntity<APIResponse> deleteComment(
            @PathVariable Long commentId
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        LOGGER.info("deleteComment: deleting movie comment with it: {}", commentId);
        userMovieService.deleteMovieComment(userId, commentId);
        return ResponseEntity.ok(APIResponse.builder().success(true).message("movie_comment_deleted").build());
    }

    @GetMapping("/movies/comment/{commentId}")
    public ResponseEntity<MovieCommentDTO> getMovieComment(
            @PathVariable Long commentId
    ) {
        LOGGER.info("getMovieComment: getting movie comment with it: {}", commentId);
        MovieCommentDTO dto = userMovieService.getMovieCommentById(commentId);
        return ResponseEntity.ok(dto);
    }
}
