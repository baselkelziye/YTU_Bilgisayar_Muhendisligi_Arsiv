package com.savt.listopia.controller.movie;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.payload.response.MovieCastResponse;
import com.savt.listopia.payload.response.MovieCrewResponse;
import com.savt.listopia.service.movie.MovieCreditService;
import jakarta.validation.constraints.Max;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1")
@Validated
public class MovieCreditController {
    private final MovieCreditService movieCreditService;

    public MovieCreditController(MovieCreditService movieCreditService) {
        this.movieCreditService = movieCreditService;
    }

    @GetMapping("/movies/{movieId}/casts")
    public ResponseEntity<MovieCastResponse> getMovieCast(@PathVariable Integer movieId,
                                                          @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
                                                          @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize,
                                                          @RequestParam(name = "sortBy", defaultValue = AppConstants.SORT_MOVIES_BY, required = false) String sortBy,
                                                          @RequestParam(name = "sortOrder", defaultValue = AppConstants.SORT_DIR, required = false) String sortOrder) {
        MovieCastResponse movieCastResponse = movieCreditService.getMovieCasts(movieId, pageNumber, pageSize, sortBy, sortOrder);
        return new ResponseEntity<>(movieCastResponse, HttpStatus.OK);
    }

    @GetMapping("/movies/{movieId}/crews")
    public ResponseEntity<MovieCrewResponse> getMovieCrew(@PathVariable Integer movieId,
                                                          @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
                                                          @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize,
                                                          @RequestParam(name = "sortBy", defaultValue = AppConstants.SORT_MOVIES_BY, required = false) String sortBy,
                                                          @RequestParam(name = "sortOrder", defaultValue = AppConstants.SORT_DIR, required = false) String sortOrder) {
        MovieCrewResponse movieCrewResponse = movieCreditService.getMovieCrews(movieId, pageNumber, pageSize, sortBy, sortOrder);
        return new ResponseEntity<>(movieCrewResponse, HttpStatus.OK);
    }
}
