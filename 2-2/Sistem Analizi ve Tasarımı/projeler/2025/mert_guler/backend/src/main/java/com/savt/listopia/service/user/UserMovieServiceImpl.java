package com.savt.listopia.service.user;

import com.savt.listopia.exception.APIException;
import com.savt.listopia.exception.ResourceNotFoundException;
import com.savt.listopia.exception.userException.UserNotAuthorizedException;
import com.savt.listopia.exception.userException.UserNotFoundException;
import com.savt.listopia.mapper.MovieCommentMapper;
import com.savt.listopia.mapper.MovieFrontMapper;
import com.savt.listopia.model.movie.Genre;
import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.model.user.MovieComment;
import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.MovieCommentDTO;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import com.savt.listopia.repository.UserRepository;
import com.savt.listopia.repository.movie.GenreRepository;
import com.savt.listopia.repository.movie.MovieCommentRepository;
import com.savt.listopia.repository.movie.MovieImageRepository;
import com.savt.listopia.repository.movie.MovieRepository;
import jakarta.transaction.Transactional;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;

import java.time.Instant;
import java.util.Optional;

@Service
public class UserMovieServiceImpl implements UserMovieService {
    private static final Logger LOGGER = LoggerFactory.getLogger(UserMovieServiceImpl.class);

    private final UserRepository userRepository;
    private final MovieRepository movieRepository;
    private final MovieCommentRepository movieCommentRepository;
    private final UserActivityService userActivityService;
    private final MovieCommentMapper movieCommentMapper;
    private final MovieFrontMapper movieFrontMapper;
    private final MovieImageRepository movieImageRepository;
    private final GenreRepository genreRepository;

    public UserMovieServiceImpl(UserRepository userRepository, MovieRepository movieRepository, MovieCommentRepository movieCommentRepository, UserActivityService userActivityService, MovieCommentMapper movieCommentMapper, MovieFrontMapper movieFrontMapper, MovieImageRepository movieImageRepository, GenreRepository genreRepository) {
        this.userRepository = userRepository;
        this.movieRepository = movieRepository;
        this.movieCommentRepository = movieCommentRepository;
        this.userActivityService = userActivityService;
        this.movieCommentMapper = movieCommentMapper;
        this.movieFrontMapper = movieFrontMapper;
        this.movieImageRepository = movieImageRepository;
        this.genreRepository = genreRepository;
    }

    @Transactional
    public Page<MovieFrontDTO> getUserLikedMovies(Long userId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size);
        Page<Movie> movies = userRepository.findLikedMoviesByUserId(userId, pageable);
        return movieFrontMapper.toDTOPage(movies, movieImageRepository);
    }

    @Transactional
    public void likeMovie(Long userId, Movie movie, Boolean liked) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);

        if (movie == null || !movieRepository.existsById(movie.getMovieId())) {
            throw new APIException("movie_not_found");
        }

        if (liked) {
            if (!user.getLikedMovies().contains(movie)) {
                user.getLikedMovies().add(movie);
                userRepository.save(user);
                movie.setLikeCount(movie.getLikeCount() + 1);
                for (Genre genre: movie.getGenres()){
                    genre.setLikeCount(genre.getLikeCount() + 1);
                    genreRepository.save(genre);
                }
                movieRepository.save(movie);

                userActivityService.activityMovieLike(user, movie);
            }
        } else {
            user.getLikedMovies().remove(movie);
            userRepository.save(user);
            movie.setLikeCount(movie.getLikeCount() - 1);
            for (Genre genre: movie.getGenres()){
                if (genre.getLikeCount() != 0){
                    genre.setLikeCount(genre.getLikeCount() - 1);
                    genreRepository.save(genre);
                }
            }
            movieRepository.save(movie);
        }
    }

    @Override
    public void userAddToLiked(Long userId, Integer movieId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Movie movie = movieRepository.findById(movieId).orElseThrow(ResourceNotFoundException::new);

        if (user.getLikedMovies().contains(movie))
            return;

        movie.setLikeCount(movie.getLikeCount() + 1);
        for (Genre genre: movie.getGenres()){
            genre.setLikeCount(genre.getLikeCount() + 1);
            genreRepository.save(genre);
        }
        movieRepository.save(movie);

        user.getLikedMovies().add(movie);
        userRepository.save(user);

        userActivityService.activityMovieLike(user, movie);
    }

    @Override
    public void userRemoveFromLiked(Long userId, Integer movieId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Movie movie = movieRepository.findById(movieId).orElseThrow(ResourceNotFoundException::new);

        if (!user.getLikedMovies().contains(movie))
            return;

        movie.setLikeCount(movie.getLikeCount() - 1);
        for (Genre genre: movie.getGenres()){
            if (genre.getLikeCount() != 0){
                genre.setLikeCount(genre.getLikeCount() - 1);
                genreRepository.save(genre);
            }
        }
        movieRepository.save(movie);

        user.getLikedMovies().remove(movie);
        userRepository.save(user);
    }

    @Override
    public Page<MovieFrontDTO> getUserWatchlist(Long userId, int pageNumber, int pageSize) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Pageable pageable = PageRequest.of(pageNumber, pageSize);
        Page<Movie> movies = userRepository.findWatchlistByUserId(user.getId(), pageable);
        return movieFrontMapper.toDTOPage(movies, movieImageRepository);
    }

    @Override
    public void userAddToWatchlist(Long userId, Integer movieId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Movie movie = movieRepository.findById(movieId).orElseThrow(ResourceNotFoundException::new);

        if (user.getWatchlist().contains(movie))
            return;

        user.getWatchlist().add(movie);
        userRepository.save(user);

        userActivityService.activityMovieAddWatchlist(user, movie);
    }

    @Override
    public void userDeleteFromWatchlist(Long userId, Integer movieId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Movie movie = movieRepository.findById(movieId).orElseThrow(ResourceNotFoundException::new);

        if (!user.getWatchlist().contains(movie))
            return;

        user.getWatchlist().remove(movie);
        userRepository.save(user);
    }

    @Override
    public Page<MovieFrontDTO> getUserWatched(Long userId, int pageNumber, int pageSize) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Pageable pageable = PageRequest.of(pageNumber, pageSize);
        Page<Movie> movies = userRepository.findWatchedListByUserId(user.getId(), pageable);
        return movieFrontMapper.toDTOPage(movies, movieImageRepository);
    }

    @Override
    public void userAddToWatched(Long userId, Integer movieId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Movie movie = movieRepository.findById(movieId).orElseThrow(ResourceNotFoundException::new);

        if (user.getWatchedList().contains(movie))
            return;

        movie.setWatchCount(movie.getWatchCount() + 1);
        for (Genre genre: movie.getGenres()){
            genre.setWatchCount(genre.getWatchCount() + 1);
            genreRepository.save(genre);
        }
        movieRepository.save(movie);

        user.getWatchedList().add(movie);
        userRepository.save(user);
        userActivityService.activityMovieAddWatched(user, movie);
    }

    @Override
    public void userDeleteFromWatched(Long userId, Integer movieId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Movie movie = movieRepository.findById(movieId).orElseThrow(ResourceNotFoundException::new);

        if (!user.getWatchedList().contains(movie))
            return;

        if (movie.getWatchCount() != 0){
            movie.setWatchCount(movie.getWatchCount() - 1);
            for (Genre genre: movie.getGenres()){
                if (genre.getWatchCount() != 0){
                    genre.setWatchCount(genre.getWatchCount() - 1);
                    genreRepository.save(genre);
                }
            }
            movieRepository.save(movie);
        }

        user.getWatchedList().remove(movie);
        userRepository.save(user);
    }

    @Transactional
    public MovieCommentDTO createMovieComment(Long userId, Integer movieId, Boolean isSpoiler, String messageU) {
        User commented = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Movie movie = movieRepository.findById(movieId).orElseThrow(ResourceNotFoundException::new);

        String message = messageU.trim();

        if (message.isEmpty())
            throw new APIException("message_cannot_be_null");

        MovieComment comment = new MovieComment();
        comment.setMovie(movie);
        comment.setFromUser(commented);
        comment.setIsSpoiler(isSpoiler);
        comment.setSentAtTimestampSeconds(Instant.now().getEpochSecond());
        comment.setMessage(message);

        movieCommentRepository.save(comment);

        // try {
            // String json = objectMapper.writeValueAsString(dto);
            // createUserActivity(commented.getId(), UserActivityType.MOVIE_COMMENT, json);
            userActivityService.activityMovieComment(commented, comment);
        // } catch (JsonProcessingException e) {
        //     LOGGER.error("error creating json object for MovieCommentDTO commentId: {}", dto.getCommentId());
        // }

        return movieCommentMapper.toDTO(comment);
    }

    @Transactional
    public void deleteMovieComment(Long requestedId, Long commentId) {
        User user = userRepository.findById(requestedId).orElseThrow(UserNotAuthorizedException::new);
        MovieComment comment = movieCommentRepository.findById(commentId).orElseThrow(ResourceNotFoundException::new);
        if ( comment.getFromUser().equals(user) )
            movieCommentRepository.deleteById(commentId);
        else
            throw new UserNotAuthorizedException();
    }

    @Override
    public void reportMovieComment(Long commentId) {
        Optional<MovieComment> commentOpt = movieCommentRepository.findById(commentId);
        if ( commentOpt.isPresent() ) {
            MovieComment comment = commentOpt.get();
            comment.setIsReported(true);
            movieCommentRepository.save(comment);
        }
    }

    @Override
    public MovieCommentDTO updateMovieComment(Long userId, Long commentId, Boolean isSpoiler, String messageU) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        MovieComment comment = movieCommentRepository.findById(commentId).orElseThrow(ResourceNotFoundException::new);

        if (!comment.getFromUser().equals(user))
            throw new UserNotAuthorizedException();

        String message = messageU.trim();

        if (message.isEmpty())
            throw new APIException("message_cannot_be_null");

        comment.setIsSpoiler(isSpoiler);
        comment.setMessage(message);
        comment.setIsUpdated(true);
        movieCommentRepository.save(comment);
        return movieCommentMapper.toDTO(comment);
    }

    public MovieCommentDTO getMovieCommentById(Long commentId) {
        return movieCommentMapper.toDTO(movieCommentRepository.findById(commentId).orElseThrow(ResourceNotFoundException::new));
    }

    public Page<MovieCommentDTO> getMovieCommentForMovie(Integer movieId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        Page<MovieComment> dto = movieCommentRepository.findByMovie_MovieId(movieId, pageable);
        return movieCommentMapper.toDTOPage(dto);
    }

    public Page<MovieCommentDTO> getMovieCommentFromUser(Long userId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return movieCommentMapper.toDTOPage(movieCommentRepository.findByFromUser_Id(userId, pageable));
    }

    public Page<MovieCommentDTO> getMovieCommentForMovieFromUser(Integer movieId, Long userId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return movieCommentMapper.toDTOPage(movieCommentRepository.findByFromUser_IdAndMovie_MovieId(userId, movieId, pageable));
    }

    public Page<MovieCommentDTO> getMovieCommentReported(Boolean isReported, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return movieCommentMapper.toDTOPage( movieCommentRepository.findByIsReported(isReported, pageable));
    }
}
