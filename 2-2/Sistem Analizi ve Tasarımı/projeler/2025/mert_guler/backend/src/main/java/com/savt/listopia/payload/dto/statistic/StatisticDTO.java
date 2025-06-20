package com.savt.listopia.payload.dto.statistic;

import com.savt.listopia.model.movie.Genre;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import lombok.Data;

import java.util.ArrayList;
import java.util.List;

@Data
public class StatisticDTO {
    private List<MovieFrontDTO> mostWatchedMovies;
    private List<MovieFrontDTO> mostLikedMovies;
    private List<MovieFrontDTO> mostVisitedMovies;
    private Integer movieCount;

    private List<Genre> mostWatchedGenres;
    private List<Genre> mostLikedGenres;
    private List<Genre> mostVisitedGenres;

    private List<UserStatDTO> usersByLikedListSize;
    private List<UserStatDTO> usersByWatchedListSize;

    private Integer userCount;

}
