package com.savt.listopia.service.admin;

import com.savt.listopia.model.movie.Genre;
import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import com.savt.listopia.payload.dto.statistic.StatisticDTO;
import com.savt.listopia.payload.dto.statistic.UserStatDTO;
import com.savt.listopia.repository.UserRepository;
import com.savt.listopia.repository.movie.GenreRepository;
import com.savt.listopia.repository.movie.MovieRepository;
import org.modelmapper.ModelMapper;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class StatServiceImpl implements StatService{
    private final MovieRepository movieRepository;
    private final GenreRepository genreRepository;
    private final UserRepository userRepository;
    private final ModelMapper modelMapper;

    public StatServiceImpl(MovieRepository movieRepository, GenreRepository genreRepository, UserRepository userRepository, ModelMapper modelMapper) {
        this.movieRepository = movieRepository;
        this.genreRepository = genreRepository;
        this.userRepository = userRepository;
        this.modelMapper = modelMapper;
    }

    @Override
    public StatisticDTO getStatistics() {
        modelMapper.typeMap(User.class, UserStatDTO.class).addMappings(mapper -> {
            mapper.map(User::getLikedCount, UserStatDTO::setLikedCount);
            mapper.map(User::getWatchedCount, UserStatDTO::setWatchedCount);
        });

        Sort sortBy = Sort.by("watchCount").descending();
        Pageable pageDetails = PageRequest.of(0, 10, sortBy);
        List<Movie> mostWatchedMovies = movieRepository.findAll(pageDetails).getContent();
        List<Genre> mostWatchedGenres = genreRepository.findAll(pageDetails).getContent();

        sortBy = Sort.by("likeCount").descending();
        pageDetails = PageRequest.of(0, 10, sortBy);
        List<Movie> mostLikedMovies = movieRepository.findAll(pageDetails).getContent();
        List<Genre> mostLikedGenres = genreRepository.findAll(pageDetails).getContent();

        sortBy = Sort.by("clickCount").descending();
        pageDetails = PageRequest.of(0, 10, sortBy);
        List<Movie> mostVisitedMovies = movieRepository.findAll(pageDetails).getContent();
        List<Genre> mostVisitedGenres = genreRepository.findAll(pageDetails).getContent();

        Integer movieCount = (int) movieRepository.count();
        Integer userCount = (int) userRepository.count();

        pageDetails = PageRequest.of(0, 10);
        List<User> usersWithLargestLikedList = userRepository.findUsersByLikedMoviesCount(pageDetails).getContent();
        List<User> usersWithLargestWatchedList = userRepository.findUsersByWatchedMoviesCount(pageDetails).getContent();

        List<MovieFrontDTO> mostWatchedMovieDTOS = mostWatchedMovies.stream()
                .map(product -> modelMapper.map(product, MovieFrontDTO.class))
                .toList();

        List<MovieFrontDTO> mostLikedMovieDTOS = mostLikedMovies.stream()
                .map(product -> modelMapper.map(product, MovieFrontDTO.class))
                .toList();

        List<MovieFrontDTO> mostVisitedMovieDTOS = mostVisitedMovies.stream()
                .map(product -> modelMapper.map(product, MovieFrontDTO.class))
                .toList();

        List<UserStatDTO> userDTOSbyLikedMovieCount = usersWithLargestLikedList.stream()
                .map(product -> modelMapper.map(product, UserStatDTO.class))
                .toList();

        List<UserStatDTO> userDTOSbyWatchedMovieCount = usersWithLargestWatchedList.stream()
                .map(product -> modelMapper.map(product, UserStatDTO.class))
                .toList();

        StatisticDTO statisticDTO = new StatisticDTO();
        statisticDTO.setMovieCount(movieCount);
        statisticDTO.setUserCount(userCount);
        statisticDTO.setMostWatchedMovies(mostWatchedMovieDTOS);
        statisticDTO.setMostLikedMovies(mostLikedMovieDTOS);
        statisticDTO.setMostVisitedMovies(mostVisitedMovieDTOS);
        statisticDTO.setMostLikedGenres(mostLikedGenres);
        statisticDTO.setMostWatchedGenres(mostWatchedGenres);
        statisticDTO.setMostVisitedGenres(mostVisitedGenres);
        statisticDTO.setUsersByLikedListSize(userDTOSbyLikedMovieCount);
        statisticDTO.setUsersByWatchedListSize(userDTOSbyWatchedMovieCount);
        return statisticDTO;
    }
}
