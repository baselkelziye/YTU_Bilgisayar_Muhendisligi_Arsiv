package com.savt.listopia.service.user;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.savt.listopia.mapper.MovieCommentMapper;
import com.savt.listopia.mapper.MovieFrontMapper;
import com.savt.listopia.mapper.UserActivityMapper;
import com.savt.listopia.mapper.UserMapper;
import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.model.user.MovieComment;
import com.savt.listopia.model.user.User;
import com.savt.listopia.model.user.UserActivity;
import com.savt.listopia.model.user.UserActivityType;
import com.savt.listopia.payload.dto.MovieCommentDTO;
import com.savt.listopia.payload.dto.UserActivityDTO;
import com.savt.listopia.payload.dto.UserDTO;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import com.savt.listopia.repository.UserActivityRepository;
import com.savt.listopia.repository.movie.MovieImageRepository;
import jakarta.transaction.Transactional;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;

@Service
public class UserActivityServiceImpl implements UserActivityService {
    private static final Logger LOGGER = LoggerFactory.getLogger(UserActivityServiceImpl.class);

    private final UserActivityRepository userActivityRepository;
    private final UserActivityMapper userActivityMapper;
    private final ObjectMapper objectMapper;
    private final UserMapper userMapper;
    private final MovieCommentMapper movieCommentMapper;
    private final MovieFrontMapper movieFrontMapper;
    private final MovieImageRepository movieImageRepository;

    public UserActivityServiceImpl(UserActivityRepository userActivityRepository, UserActivityMapper userActivityMapper, ObjectMapper objectMapper, UserMapper userMapper, MovieCommentMapper movieCommentMapper, MovieFrontMapper movieFrontMapper, MovieImageRepository movieImageRepository) {
        this.userActivityRepository = userActivityRepository;
        this.userActivityMapper = userActivityMapper;
        this.objectMapper = objectMapper;
        this.userMapper = userMapper;
        this.movieCommentMapper = movieCommentMapper;
        this.movieFrontMapper = movieFrontMapper;
        this.movieImageRepository = movieImageRepository;
    }

    @Transactional
    protected void createAndSaveActivity(User user, UserActivityType type, String content) {
        try {
            UserActivity userActivity = new UserActivity();
            userActivity.setUser(user);
            userActivity.setType(type);
            userActivity.setContent(content);
            userActivityRepository.save(userActivity);
        } catch (Exception e) {
            LOGGER.error(e.getMessage(), e);
        }
    }

    private String dtoToJson(Object object) {
        try {
            return objectMapper.writeValueAsString(object);
        } catch (JsonProcessingException e) {
            return "";
        }
    }

    @Override
    @Transactional
    public void activityBecomeFriends(User user, User friend) {
        UserDTO dto = userMapper.toDTO(friend);
        String json = dtoToJson(dto);
        if (json.isEmpty()) {
            LOGGER.error("UserActivityServiceImpl: activityBecomeFriends: json is empty");
            return;
        }
        createAndSaveActivity(user, UserActivityType.BECOME_FRIENDS, json);
    }

    @Override
    @Transactional
    public void activityMovieComment(User user, MovieComment comment) {
        MovieCommentDTO dto = movieCommentMapper.toDTO(comment);
        String json = dtoToJson(dto);
        if (json.isEmpty()) {
            LOGGER.error("UserActivityServiceImpl: activityMovieComment: json is empty");
            return;
        }
        createAndSaveActivity(user, UserActivityType.MOVIE_COMMENT, json);
    }

    @Override
    @Transactional
    public void activityMovieLike(User user, Movie movie) {
        MovieFrontDTO dto = movieFrontMapper.toDTO(movie, movieImageRepository);
        String json = dtoToJson(dto);
        if (json.isEmpty()) {
            LOGGER.error("UserActivityServiceImpl: activityMovieLike: json is empty");
            return;
        }
        createAndSaveActivity(user, UserActivityType.MOVIE_LIKED, json);
    }

    @Override
    @Transactional
    public void activityMovieAddWatchlist(User user, Movie movie) {
        MovieFrontDTO dto = movieFrontMapper.toDTO(movie, movieImageRepository);
        String json = dtoToJson(dto);
        if (json.isEmpty()) {
            LOGGER.error("UserActivityServiceImpl: activityMovieAddWatchlist: json is empty");
            return;
        }
        createAndSaveActivity(user, UserActivityType.MOVIE_ADD_WATCHLIST, json);
    }

    @Override
    @Transactional
    public void activityMovieAddWatched(User user, Movie movie) {
        MovieFrontDTO dto = movieFrontMapper.toDTO(movie, movieImageRepository);
        String json = dtoToJson(dto);
        if (json.isEmpty()) {
            LOGGER.error("UserActivityServiceImpl: activityMovieAddWatched: json is empty");
            return;
        }
        createAndSaveActivity(user, UserActivityType.MOVIE_ADD_WATCHED, json);
    }

    @Override
    @Transactional
    public Page<UserActivityDTO> getUserActivities(User user, int pageNumber, int pageSize) {
        Pageable pageable = PageRequest.of(pageNumber, pageSize, Sort.by(Sort.Direction.DESC, "time"));
        Page<UserActivity> page = userActivityRepository.findByUserId(user.getId(), pageable);
        return userActivityMapper.toDTOPage(page);
    }
}
