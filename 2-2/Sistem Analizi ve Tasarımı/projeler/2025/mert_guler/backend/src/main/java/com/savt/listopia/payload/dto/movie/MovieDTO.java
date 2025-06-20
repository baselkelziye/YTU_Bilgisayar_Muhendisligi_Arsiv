package com.savt.listopia.payload.dto.movie;

import com.savt.listopia.model.movie.Genre;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class MovieDTO {
    private Integer movieId;

    private String originalLanguage;

    private String originalTitle;

    private String title;

    private String overview;

    private String tagline;

    private String releaseDate;

    private String trailerLink;

    private Integer runtime;

    private String backdrop;

    private String poster;

    private String logo;

    @ToString.Exclude
    private List<Genre> genres;

    private Integer watchCount;

    private Integer likeCount;

    private Long clickCount;

    private String imdbId;

    private String wikidataId;

    private String facebookId;

    private String instagramId;

    private String twitterId;

}
