package com.savt.listopia.controller.user;

import com.savt.listopia.exception.APIException;
import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.payload.response.APIResponse;
import com.savt.listopia.repository.movie.MovieRepository;
import com.savt.listopia.service.UserService;
import com.savt.listopia.service.user.UserMovieService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1/user/movie")
public class UserMovieController {
    private final UserService userService;
    private final MovieRepository movieRepository;
    private final UserMovieService userMovieService;

    public UserMovieController(UserService userService, MovieRepository movieRepository, UserMovieService userMovieService) {
        this.userService = userService;
        this.movieRepository = movieRepository;
        this.userMovieService = userMovieService;
    }

    @PutMapping("/{movieId}/like")
    public ResponseEntity<APIResponse> likeMovie(
            @PathVariable Integer movieId,
            @RequestParam Boolean liked
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();

        Movie movie = movieRepository.findById(movieId)
                .orElseThrow(() -> new APIException("movie_not_found"));

        userMovieService.likeMovie(userId, movie, liked);

        return ResponseEntity.ok(APIResponse.builder().message("movie_like_updated").success(true).build());
    }

    @PostMapping("/{movieId}/like")
    public ResponseEntity<APIResponse> addToLiked(
            @PathVariable(name = "movieId") Integer movieId
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        userMovieService.userAddToLiked(userId, movieId);
        return ResponseEntity.ok(APIResponse.success("added_to_watchlist"));
    }

    @DeleteMapping("/{movieId}/like")
    public ResponseEntity<APIResponse> removeFromLiked(
            @PathVariable(name = "movieId") Integer movieId
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        userMovieService.userRemoveFromLiked(userId, movieId);
        return ResponseEntity.ok(APIResponse.success("deleted_from_watchlist"));
    }
    
    @PostMapping("/{movieId}/watchlist")
    public ResponseEntity<APIResponse> addToWatchlist(
            @PathVariable(name = "movieId") Integer movieId
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        userMovieService.userAddToWatchlist(userId, movieId);
        return ResponseEntity.ok(APIResponse.success("added_to_watchlist"));
    }

    @DeleteMapping("/{movieId}/watchlist")
    public ResponseEntity<APIResponse> removeFromWatchlist(
            @PathVariable(name = "movieId") Integer movieId
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        userMovieService.userDeleteFromWatchlist(userId, movieId);
        return ResponseEntity.ok(APIResponse.success("deleted_from_watchlist"));
    }
    
    @PostMapping("/{movieId}/watched")
    public ResponseEntity<APIResponse> addToWatched(
            @PathVariable(name = "movieId") Integer movieId
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        userMovieService.userAddToWatched(userId, movieId);
        return ResponseEntity.ok(APIResponse.success("added_to_watched"));
    }

    @DeleteMapping("/{movieId}/watched")
    public ResponseEntity<APIResponse> removeFromWatched(
            @PathVariable(name = "movieId") Integer movieId
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        userMovieService.userDeleteFromWatched(userId, movieId);
        return ResponseEntity.ok(APIResponse.success("deleted_from_watched"));
    }

}

