package com.savt.listopia.service.user;

import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.payload.dto.MovieCommentDTO;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import org.springframework.data.domain.Page;
import org.springframework.stereotype.Service;

@Service
public interface UserMovieService {
    Page<MovieFrontDTO> getUserLikedMovies(Long userId, int page, int size);
    void likeMovie(Long userId, Movie movie, Boolean liked);
    void userAddToLiked(Long userId, Integer movieId);
    void userRemoveFromLiked(Long userId, Integer movieId);

    Page<MovieFrontDTO> getUserWatchlist(Long userId, int pageNumber, int pageSize);
    void userAddToWatchlist(Long userId, Integer movieId);
    void userDeleteFromWatchlist(Long userId, Integer movieId);

    Page<MovieFrontDTO> getUserWatched(Long userId, int pageNumber, int pageSize);
    void userAddToWatched(Long userId, Integer movieId);
    void userDeleteFromWatched(Long userId, Integer movieId);

    MovieCommentDTO createMovieComment(Long userId, Integer movieId, Boolean isSpoiler, String messageUnsafe);
    void deleteMovieComment(Long requestedId, Long commentId);
    void reportMovieComment(Long commentId);
    MovieCommentDTO updateMovieComment(Long userId, Long commentId, Boolean isSpoiler, String messageUnsafe);
    MovieCommentDTO getMovieCommentById(Long commentId);
    Page<MovieCommentDTO> getMovieCommentForMovie(Integer movieId, int page, int size);
    Page<MovieCommentDTO> getMovieCommentFromUser(Long userId, int page, int size);
    Page<MovieCommentDTO> getMovieCommentForMovieFromUser(Integer movieId, Long userId, int page, int size);
    Page<MovieCommentDTO> getMovieCommentReported(Boolean isReported, int page, int size);
}
