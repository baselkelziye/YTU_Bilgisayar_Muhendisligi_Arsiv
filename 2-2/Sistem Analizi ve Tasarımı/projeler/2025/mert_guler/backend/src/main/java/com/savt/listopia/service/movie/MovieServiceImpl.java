package com.savt.listopia.service.movie;

import com.savt.listopia.exception.APIException;
import com.savt.listopia.exception.ResourceNotFoundException;
import com.savt.listopia.mapper.MovieFrontMapper;
import com.savt.listopia.model.movie.Genre;
import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.payload.dto.movie.MovieDTO;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import com.savt.listopia.payload.response.MovieFrontResponse;
import com.savt.listopia.repository.movie.GenreRepository;
import com.savt.listopia.repository.movie.MovieImageRepository;
import com.savt.listopia.repository.movie.MovieRepository;
import info.movito.themoviedbapi.TmdbApi;
import info.movito.themoviedbapi.TmdbMovies;
import info.movito.themoviedbapi.model.movies.ExternalIds;
import info.movito.themoviedbapi.model.movies.MovieDb;
import info.movito.themoviedbapi.tools.TmdbException;
import info.movito.themoviedbapi.tools.appendtoresponse.MovieAppendToResponse;
import jakarta.transaction.Transactional;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.domain.*;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MovieServiceImpl implements MovieService {
    private final ModelMapper modelMapper;

    private final MovieRepository movieRepository;

    private final MovieImageRepository movieImageRepository;
    private final GenreRepository genreRepository;
    private final MovieFrontMapper movieFrontMapper;

    @Value("${tmdb.apiKey}")
    private String tmdbKey;

    public MovieServiceImpl(ModelMapper modelMapper, MovieRepository movieRepository, MovieImageRepository movieImageRepository, GenreRepository genreRepository, MovieFrontMapper movieFrontMapper) {
        this.modelMapper = modelMapper;
        this.movieRepository = movieRepository;
        this.movieImageRepository = movieImageRepository;
        this.genreRepository = genreRepository;
        this.movieFrontMapper = movieFrontMapper;
    }

    @Override
    public MovieFrontResponse getFrontMovies(Integer pageNumber, Integer pageSize, String sortBy, String sortOrder, String genre, String word) {
        Sort sortByAndOrder = sortOrder.equalsIgnoreCase("asc")
                ? Sort.by(sortBy).ascending()
                : Sort.by(sortBy).descending();

        Pageable pageDetails = PageRequest.of(pageNumber, pageSize, sortByAndOrder);
        Page<Movie> pageMovies;

        if (genre != null) {
            if (word != null){
                pageMovies = movieRepository.findAllByGenreNameAndTitleLikeIgnoreCase(pageDetails, genre, '%' + word + '%');
            } else {
                pageMovies = movieRepository.findAllByGenreName(pageDetails, genre);
            }
        } else {
            if (word != null){
                pageMovies = movieRepository.findAllByTitleLikeIgnoreCase(pageDetails, '%' + word + '%');
            } else {
                pageMovies = movieRepository.findAll(pageDetails);
            }
        }

        List<Movie> movies = pageMovies.getContent();

        List<MovieFrontDTO> movieFrontDTOS = movies.stream()
                .map(product -> modelMapper.map(product, MovieFrontDTO.class))
                .toList();

        movieFrontDTOS.forEach(movieFrontDTO -> movieFrontDTO
                .setPoster(
                        movieImageRepository.findMovieImageByMovieId(movieFrontDTO.getMovieId(), Limit.of(1))
                ));

        MovieFrontResponse movieFrontResponse = new MovieFrontResponse();
        movieFrontResponse.setContent(movieFrontDTOS);
        movieFrontResponse.setPageNumber(pageMovies.getNumber());
        movieFrontResponse.setPageSize(pageMovies.getSize());
        movieFrontResponse.setTotalElements(pageMovies.getTotalElements());
        movieFrontResponse.setTotalPages(pageMovies.getTotalPages());
        movieFrontResponse.setLastPage(pageMovies.isLast());
        return movieFrontResponse;
    }

    @Override
    public Page<MovieFrontDTO> searchByTitle(String title, Integer pageNumber, Integer pageSize) {
        Pageable pageDetails = PageRequest.of(pageNumber, pageSize);
        String searchQuery = "%" + title + "%";
        Page<Movie> movies = movieRepository.findAllByTitleLikeIgnoreCase(pageDetails, searchQuery);
        return movieFrontMapper.toDTOPage(movies, movieImageRepository);
    }

    @Override
    @Transactional
    public MovieDTO getMovie(Integer movieId) {
        Movie movie = movieRepository.findById(movieId)
                .orElseThrow(() -> new ResourceNotFoundException("Movie", "movieId", movieId));

        movie.setClickCount(movie.getClickCount() + 1);
        for (Genre genre: movie.getGenres()){
            genre.setClickCount(genre.getClickCount() + 1);
            genreRepository.save(genre);
        }
        movieRepository.save(movie);

        MovieDTO movieDTO = modelMapper.map(movie, MovieDTO.class);
        movieDTO.setBackdrop(movieImageRepository.findMovieImageByMovieIdAndType(movieId, Limit.of(1), 1));
        movieDTO.setPoster(movieImageRepository.findMovieImageByMovieIdAndType(movieId, Limit.of(1), 2));
        movieDTO.setLogo(movieImageRepository.findMovieImageByMovieIdAndType(movieId, Limit.of(1), 3));
        return movieDTO;
    }

    @Override
    public MovieDTO updateMovie(Integer movieId, MovieDTO movieDTO) {
        Movie movieFromDb = movieRepository.findById(movieId)
                .orElseThrow(() -> new ResourceNotFoundException("Movie", "movieId", movieId));

        Movie movie = modelMapper.map(movieDTO, Movie.class);
movie.setMovieId(movieId);
        movie.setGenres(movieFromDb.getGenres());
        movie.setPosters(movieFromDb.getPosters());
        movie.setBackdrops(movieFromDb.getBackdrops());
        movie.setLogos(movieFromDb.getLogos());
        movie.setMovieCasts(movieFromDb.getMovieCasts());
        movie.setMovieCrews(movieFromDb.getMovieCrews());
        movie.setPopularity(movieFromDb.getPopularity());
        movie.setWatchCount(movieFromDb.getWatchCount());
        movie.setLikeCount(movieFromDb.getLikeCount());
        return modelMapper.map(movieRepository.save(movie), MovieDTO.class);
    }

    @Override
    public MovieDTO fetchFromExternalDb(Integer movieId) {
        Movie movieFromDb = movieRepository.findById(movieId)
                .orElseThrow(() -> new ResourceNotFoundException("Movie", "movieId", movieId));

        TmdbApi tmdbApi = new TmdbApi(tmdbKey);
        TmdbMovies movies = tmdbApi.getMovies();

        modelMapper.typeMap(MovieDb.class, Movie.class).addMappings(mapper -> {
            mapper.skip(Movie::setGenres);
        });


        MovieDb movieDb;

        try {
            movieDb = movies.getDetails(movieId, "en"
                    , MovieAppendToResponse.IMAGES
                    , MovieAppendToResponse.CREDITS
                    , MovieAppendToResponse.VIDEOS
                    , MovieAppendToResponse.EXTERNAL_IDS);
        } catch (TmdbException e) {
            throw new APIException("Movie with Id: " + movieId + ", is not found in the TMDB Database");
        }

        Movie movie = modelMapper.map(movieDb, Movie.class);
        movie.setMovieId(movieId);
        movie.setGenres(movieFromDb.getGenres());
        movie.setPosters(movieFromDb.getPosters());
        movie.setBackdrops(movieFromDb.getBackdrops());
        movie.setLogos(movieFromDb.getLogos());
        movie.setPopularity(movieFromDb.getPopularity());
        movie.setWatchCount(movieFromDb.getWatchCount());
        movie.setLikeCount(movieFromDb.getLikeCount());

        ExternalIds externalIds = movieDb.getExternalIds();
        movie.setFacebookId(externalIds.getFacebookId());
        movie.setInstagramId(externalIds.getInstagramId());
        movie.setWikidataId(externalIds.getWikidataId());
        movie.setTwitterId(externalIds.getTwitterId());

        try {
            String trailerKey = movieDb.getVideos().getResults().getFirst().getKey();
            movie.setTrailerKey(trailerKey);
            movie.setTrailerLink("https://www.youtube.com/watch?v=" + trailerKey);
        } catch (Exception e) {
            System.out.println("Error happened while fetching movie trailer link");
        }

        MovieDTO movieDTO = modelMapper.map(movie, MovieDTO.class);

        movieDTO.setBackdrop(movieImageRepository.findMovieImageByMovieIdAndType(movieId, Limit.of(1), 1));
        movieDTO.setPoster(movieImageRepository.findMovieImageByMovieIdAndType(movieId, Limit.of(1), 2));
        movieDTO.setLogo(movieImageRepository.findMovieImageByMovieIdAndType(movieId, Limit.of(1), 3));
        return movieDTO;
    }

}
