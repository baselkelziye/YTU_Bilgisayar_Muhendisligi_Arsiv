package com.savt.listopia.controller.movie;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.model.user.UserRole;
import com.savt.listopia.payload.dto.movie.MovieDTO;
import com.savt.listopia.payload.response.MovieFrontResponse;
import com.savt.listopia.service.AuthServiceImpl;
import com.savt.listopia.service.movie.MovieService;
import jakarta.validation.constraints.Max;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1")
@Validated
public class MovieController {
    private final MovieService movieService;
    private final AuthServiceImpl authServiceImpl;

    public MovieController(MovieService movieService, AuthServiceImpl authServiceImpl) {
        this.movieService = movieService;
        this.authServiceImpl = authServiceImpl;
    }

    @GetMapping("/movies/{movieId}")
    public ResponseEntity<MovieDTO> getMovie(@PathVariable Integer movieId) {
        MovieDTO movieDTO = movieService.getMovie(movieId);
        return new ResponseEntity<>(movieDTO, HttpStatus.OK);
    }

    @GetMapping("/movies/front")
    public ResponseEntity<MovieFrontResponse> getFrontMovies(
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize,
            @RequestParam(name = "sortBy", defaultValue = AppConstants.SORT_MOVIES_BY, required = false) String sortBy,
            @RequestParam(name = "sortOrder", defaultValue = AppConstants.SORT_DIR, required = false) String sortOrder,
            @RequestParam(name = "genre", required = false) String genre,
            @RequestParam(name = "word", required = false) String word) {
        MovieFrontResponse movieFrontResponse = movieService.getFrontMovies(pageNumber, pageSize, sortBy, sortOrder, genre, word);
        return new ResponseEntity<>(movieFrontResponse, HttpStatus.OK);
    }

    @PutMapping("/admin/movies/{movieId}")
    public ResponseEntity<MovieDTO> updateMovie(@PathVariable Integer movieId,
                                                @RequestBody MovieDTO movieDTO) {
        authServiceImpl.requireRoleOrThrow(UserRole.MODERATOR);
        MovieDTO savedMovieDTO = movieService.updateMovie(movieId, movieDTO);
        return new ResponseEntity<>(savedMovieDTO, HttpStatus.OK);
    }

    @PutMapping("/admin/movies/{movieId}/fetch")
    public ResponseEntity<MovieDTO> fetchFromExternalDb(@PathVariable Integer movieId) {
        authServiceImpl.requireRoleOrThrow(UserRole.ADMIN);
        MovieDTO fetchedMovieDTO = movieService.fetchFromExternalDb(movieId);
        return new ResponseEntity<>(fetchedMovieDTO, HttpStatus.OK);
    }
}
