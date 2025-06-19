package com.savt.listopia.model.movie;


import com.fasterxml.jackson.annotation.JsonManagedReference;
import com.savt.listopia.model.movie.image.MovieImage;
import jakarta.annotation.Nullable;
import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.List;

@Entity
@Data
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "movies")
public class Movie {
    @Id
    private Integer movieId;

    private String originalLanguage;

    private String originalTitle;

    private String title;

    @Column(columnDefinition = "TEXT", length = 2048)
    private String overview;

    @Column(columnDefinition = "TEXT", length = 2048)
    private String tagline;

    private Double popularity;

    private String releaseDate;

    private String trailerKey;

    private String trailerLink;

    private Integer runtime;

    private Integer watchCount = 0;

    private Integer likeCount = 0;

    private Long clickCount = 0L;

    @NotNull
    private String imdbId;

    @Nullable
    private String wikidataId;

    @Nullable
    private String facebookId;

    @Nullable
    private String instagramId;

    @Nullable
    private String twitterId;

    @OneToMany(mappedBy = "movie", cascade = {CascadeType.MERGE, CascadeType.PERSIST}, orphanRemoval = true)
    @JsonManagedReference
    private List<MovieImage> backdrops;

    @JsonManagedReference
    @OneToMany(mappedBy = "movie", cascade = {CascadeType.MERGE, CascadeType.PERSIST}, orphanRemoval = true)
    private List<MovieImage> logos;

    @JsonManagedReference
    @OneToMany(mappedBy = "movie", cascade = {CascadeType.MERGE, CascadeType.PERSIST}, orphanRemoval = true)
    private List<MovieImage> posters;

    @JsonManagedReference
    @OneToMany(mappedBy = "movie", cascade = {CascadeType.MERGE, CascadeType.PERSIST}, orphanRemoval = true)
    private List<MovieCast> movieCasts = new ArrayList<>();

    @JsonManagedReference
    @OneToMany(mappedBy = "movie", cascade = {CascadeType.MERGE, CascadeType.PERSIST}, orphanRemoval = true)
    private List<MovieCrew> movieCrews = new ArrayList<>();

    @ManyToMany
    @JoinTable(name = "movie_genres",
            joinColumns = @JoinColumn(name = "movie_id"),
            inverseJoinColumns = @JoinColumn(name = "genre_id"))
    private List<Genre> genres;
}
