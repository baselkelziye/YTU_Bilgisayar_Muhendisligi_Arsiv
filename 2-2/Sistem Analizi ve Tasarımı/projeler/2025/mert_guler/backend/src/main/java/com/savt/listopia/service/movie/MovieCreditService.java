package com.savt.listopia.service.movie;

import com.savt.listopia.payload.response.MovieCastResponse;
import com.savt.listopia.payload.response.MovieCrewResponse;
import jakarta.validation.constraints.Max;

public interface MovieCreditService {
    MovieCastResponse getMovieCasts(Integer movieId, Integer pageNumber, @Max(50) Integer pageSize, String sortBy, String sortOrder);

    MovieCrewResponse getMovieCrews(Integer movieId, Integer pageNumber, @Max(50) Integer pageSize, String sortBy, String sortOrder);
}
