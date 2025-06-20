package com.savt.listopia.service.movie;

import com.savt.listopia.model.movie.MovieCast;
import com.savt.listopia.model.movie.MovieCrew;
import com.savt.listopia.payload.dto.movie.MovieCastDTO;
import com.savt.listopia.payload.dto.movie.MovieCrewDTO;
import com.savt.listopia.payload.response.MovieCastResponse;
import com.savt.listopia.payload.response.MovieCrewResponse;
import com.savt.listopia.repository.movie.MovieCastRepository;
import com.savt.listopia.repository.movie.MovieCrewRepository;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MovieCreditServiceImpl implements MovieCreditService {
    private final MovieCastRepository movieCastRepository;

    private final MovieCrewRepository movieCrewRepository;

    private final ModelMapper modelMapper;

    public MovieCreditServiceImpl(MovieCastRepository movieCastRepository, MovieCrewRepository movieCrewRepository, ModelMapper modelMapper) {
        this.movieCastRepository = movieCastRepository;
        this.movieCrewRepository = movieCrewRepository;
        this.modelMapper = modelMapper;
    }

    @Override
    public MovieCastResponse getMovieCasts(Integer movieId, Integer pageNumber, Integer pageSize, String sortBy, String sortOrder) {
        Sort sortByAndOrder = sortOrder.equalsIgnoreCase("asc")
                ? Sort.by(sortBy).ascending()
                : Sort.by(sortBy).descending();

        Pageable pageDetails = PageRequest.of(pageNumber, pageSize, sortByAndOrder);
        Page<MovieCast> pageMovieCasts = movieCastRepository.findAllByMovieMovieId(movieId, pageDetails);

        List<MovieCast> movieCasts = pageMovieCasts.getContent();

        List<MovieCastDTO> movieCastDTOS = movieCasts.stream()
                .map(mc -> modelMapper.map(mc, MovieCastDTO.class))
                .toList();

        MovieCastResponse MovieCastResponse = new MovieCastResponse();
        MovieCastResponse.setContent(movieCastDTOS);
        MovieCastResponse.setPageNumber(pageMovieCasts.getNumber());
        MovieCastResponse.setPageSize(pageMovieCasts.getSize());
        MovieCastResponse.setTotalElements(pageMovieCasts.getTotalElements());
        MovieCastResponse.setTotalPages(pageMovieCasts.getTotalPages());
        MovieCastResponse.setLastPage(pageMovieCasts.isLast());
        return MovieCastResponse;
    }

    @Override
    public MovieCrewResponse getMovieCrews(Integer movieId, Integer pageNumber, Integer pageSize, String sortBy, String sortOrder) {
        Sort sortByAndOrder = sortOrder.equalsIgnoreCase("asc")
                ? Sort.by(sortBy).ascending()
                : Sort.by(sortBy).descending();

        Pageable pageDetails = PageRequest.of(pageNumber, pageSize, sortByAndOrder);
        Page<MovieCrew> pageMovieCrews = movieCrewRepository.findAllByMovieMovieId(movieId, pageDetails);

        List<MovieCrew> movieCrews = pageMovieCrews.getContent();

        List<MovieCrewDTO> movieCrewDTOS = movieCrews.stream()
                .map(mc -> modelMapper.map(mc, MovieCrewDTO.class))
                .toList();

        MovieCrewResponse movieCrewResponse = new MovieCrewResponse();
        movieCrewResponse.setContent(movieCrewDTOS);
        movieCrewResponse.setPageNumber(pageMovieCrews.getNumber());
        movieCrewResponse.setPageSize(pageMovieCrews.getSize());
        movieCrewResponse.setTotalElements(pageMovieCrews.getTotalElements());
        movieCrewResponse.setTotalPages(pageMovieCrews.getTotalPages());
        movieCrewResponse.setLastPage(pageMovieCrews.isLast());
        return movieCrewResponse;
    }
}
