package com.savt.listopia.util;

import com.savt.listopia.exception.APIException;
import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.model.movie.MovieCast;
import com.savt.listopia.model.movie.MovieCrew;
import com.savt.listopia.model.movie.image.MovieImage;
import com.savt.listopia.model.movie.image.MovieImageType;
import com.savt.listopia.repository.movie.*;
import info.movito.themoviedbapi.TmdbApi;
import info.movito.themoviedbapi.TmdbGenre;
import info.movito.themoviedbapi.TmdbMovies;
import info.movito.themoviedbapi.model.core.Genre;
import info.movito.themoviedbapi.model.core.image.Artwork;
import info.movito.themoviedbapi.model.movies.ExternalIds;
import info.movito.themoviedbapi.model.movies.Images;
import info.movito.themoviedbapi.model.movies.MovieDb;
import info.movito.themoviedbapi.model.movies.Translation;
import info.movito.themoviedbapi.tools.TmdbException;
import info.movito.themoviedbapi.tools.appendtoresponse.MovieAppendToResponse;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class FetchUtil {
    private final GenreRepository genreRepository;
    private final MovieRepository movieRepository;
    private final MovieCrewRepository movieCrewRepository;
    private final MovieCastRepository movieCastRepository;
    private final MovieImageRepository movieImageRepository;
    private final ModelMapper modelMapper;

    @Value("${tmdb.apiKey}")
    private String tmdbKey;

    @Value("${backdrops.path}")
    private String backdropsPath;

    @Value("${posters.path}")
    private String postersPath;

    @Value("${logos.path}")
    private String logosPath;

    public FetchUtil(GenreRepository genreRepository, MovieRepository movieRepository, MovieCrewRepository movieCrewRepository, MovieCastRepository movieCastRepository, ModelMapper modelMapper, MovieImageRepository movieImageRepository) {
        this.genreRepository = genreRepository;
        this.movieRepository = movieRepository;
        this.movieCrewRepository = movieCrewRepository;
        this.movieCastRepository = movieCastRepository;
        this.modelMapper = modelMapper;
        this.movieImageRepository = movieImageRepository;
    }

    public void fetchGenres() throws TmdbException {
        TmdbApi tmdbApi = new TmdbApi(tmdbKey);

        TmdbGenre tmdbGenre = tmdbApi.getGenre();
        List<Genre> genresFromTmdb;

        try {
            genresFromTmdb = tmdbGenre.getMovieList("en");
        } catch (TmdbException e) {
            throw new TmdbException(e.getMessage());
        }

        List<com.savt.listopia.model.movie.Genre> genres = genresFromTmdb.stream()
                .map(g -> modelMapper.map(g, com.savt.listopia.model.movie.Genre.class))
                .toList();

        genreRepository.saveAll(genres);
    }

    public void fetchMovies(Integer startId, Integer endId, Integer minPopularity, Boolean fetchAllImages, Boolean fetchKeywords) {
        TmdbApi tmdbApi = new TmdbApi(tmdbKey);

        modelMapper.typeMap(MovieDb.class, Movie.class).addMappings(mapper -> {
            mapper.skip(Movie::setGenres);
        });

        TmdbMovies movies = tmdbApi.getMovies();
        MovieDb movieDb;

        for (int i = startId; i <= endId; i++) {
            try {
                movieDb = movies.getDetails(i, "en"
                        , MovieAppendToResponse.IMAGES
                        , MovieAppendToResponse.CREDITS
                        , MovieAppendToResponse.VIDEOS
                        , MovieAppendToResponse.EXTERNAL_IDS);
            } catch (TmdbException e) {
                continue;
            }

            if (movieDb.getPopularity() < minPopularity) {
                continue;
            }

            Movie movie = modelMapper.map(movieDb, Movie.class);
            movie.setMovieId(movieDb.getId());
            movie.setWatchCount(0);
            movie.setLikeCount(0);

            Images images = movieDb.getImages();

            List<Artwork> backdropsArtwork;
            List<Artwork> logosArtwork;
            List<Artwork> postersArtwork;

            if (fetchAllImages) {
                backdropsArtwork = images.getBackdrops();
                logosArtwork = images.getLogos();
                postersArtwork = images.getPosters();
            } else {
                backdropsArtwork = new ArrayList<>();
                if (!(images.getBackdrops().isEmpty())) {
                    backdropsArtwork.add(images.getBackdrops().getFirst());
                }

                postersArtwork = new ArrayList<>();
                if (!(images.getPosters().isEmpty())) {
                    postersArtwork.add(images.getPosters().getFirst());
                }

                logosArtwork = new ArrayList<>();
                if (!(images.getLogos().isEmpty())) {
                    logosArtwork.add(images.getLogos().getFirst());
                }
            }

            List<MovieImage> backdrops = backdropsArtwork.stream()
                    .map(a -> modelMapper.map(a, MovieImage.class))
                    .toList();

            backdrops.forEach(b -> b.setMovie(movie));
            backdrops.forEach(b -> b.setType(MovieImageType.BACKDROP.getId()));

            List<MovieImage> posters = postersArtwork.stream()
                    .map(a -> modelMapper.map(a, MovieImage.class))
                    .toList();

            posters.forEach(b -> b.setMovie(movie));
            posters.forEach(b -> b.setType(MovieImageType.POSTER.getId()));

            List<MovieImage> logos = logosArtwork.stream()
                    .map(a -> modelMapper.map(a, MovieImage.class))
                    .toList();

            logos.forEach(b -> b.setMovie(movie));
            logos.forEach(b -> b.setType(MovieImageType.LOGO.getId()));

            movie.setBackdrops(backdrops);
            movie.setPosters(posters);
            movie.setLogos(logos);
            List<Genre> genresFromDb = movieDb.getGenres();
            List<com.savt.listopia.model.movie.Genre> genresOfMovie = genresFromDb.stream()
                    .map(g -> modelMapper.map(g, com.savt.listopia.model.movie.Genre.class))
                    .toList();

            movie.setGenres(genresOfMovie);

            List<MovieCast> movieCast = movieDb.getCredits().getCast().stream()
                    .map(c -> modelMapper.map(c, MovieCast.class))
                    .toList();

            movieCast.forEach(c -> c.setMovie(movie));

            List<MovieCrew> movieCrew = movieDb.getCredits().getCrew().stream()
                    .map(c -> modelMapper.map(c, MovieCrew.class))
                    .toList();

            movieCrew.forEach(c -> c.setMovie(movie));

            ExternalIds externalIds = movieDb.getExternalIds();
            movie.setFacebookId(externalIds.getFacebookId());
            movie.setInstagramId(externalIds.getInstagramId());
            movie.setWikidataId(externalIds.getWikidataId());
            movie.setTwitterId(externalIds.getTwitterId());

            String trailerKey = movieDb.getVideos().getResults().getFirst().getKey();
            if (trailerKey != null){
                movie.setTrailerKey(trailerKey);
                movie.setTrailerLink("https://www.youtube.com/watch?v=" + trailerKey);
            }

            try {
                movieRepository.save(movie);
            } catch (Exception e) {
                throw new APIException("Fetch genres first!");
            }

            movieCrewRepository.saveAll(movieCrew);
            movieCastRepository.saveAll(movieCast);
        }
    }
}
