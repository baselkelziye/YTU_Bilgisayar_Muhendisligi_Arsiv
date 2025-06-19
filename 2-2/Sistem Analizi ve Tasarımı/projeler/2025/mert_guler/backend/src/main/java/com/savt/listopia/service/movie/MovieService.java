package com.savt.listopia.service.movie;

import com.savt.listopia.payload.dto.movie.MovieDTO;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import com.savt.listopia.payload.response.MovieFrontResponse;
import jakarta.validation.constraints.Max;
import org.springframework.data.domain.Page;

public interface MovieService {
    MovieDTO getMovie(Integer movieId);

    MovieDTO updateMovie(Integer movieId, MovieDTO movieDTO);

    MovieDTO fetchFromExternalDb(Integer movieId);

    MovieFrontResponse getFrontMovies(Integer pageNumber, @Max(50) Integer pageSize, String sortBy, String sortOrder, String genre, String word);

    Page<MovieFrontDTO> searchByTitle(String title, Integer pageNumber, @Max(50) Integer pageSize);
}
