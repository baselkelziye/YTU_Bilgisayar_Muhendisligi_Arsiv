package com.savt.listopia.service.user;

import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.model.user.MovieComment;
import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.UserActivityDTO;
import org.springframework.data.domain.Page;
import org.springframework.stereotype.Service;

@Service
public interface UserActivityService {
    void activityBecomeFriends(User user, User friend);
    void activityMovieComment(User user, MovieComment comment);
    void activityMovieLike(User user, Movie movie);
    void activityMovieAddWatchlist(User user, Movie movie);
    void activityMovieAddWatched(User user, Movie movie);

    Page<UserActivityDTO> getUserActivities(User user, int pageNumber, int pageSize);
}
