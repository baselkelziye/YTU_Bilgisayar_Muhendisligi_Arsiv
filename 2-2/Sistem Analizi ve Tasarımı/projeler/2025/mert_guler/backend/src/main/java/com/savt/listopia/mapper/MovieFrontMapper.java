package com.savt.listopia.mapper;

import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.payload.dto.movie.MovieFrontDTO;
import com.savt.listopia.repository.movie.MovieImageRepository;
import org.mapstruct.AfterMapping;
import org.mapstruct.Context;
import org.mapstruct.Mapper;
import org.mapstruct.MappingTarget;
import org.springframework.data.domain.Limit;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;

import java.util.List;

@Mapper(componentModel = "spring")
public interface MovieFrontMapper {
    MovieFrontDTO toDTO(Movie movie, @Context MovieImageRepository movieImageRepository);

    @AfterMapping
    default void afterMapping(@MappingTarget MovieFrontDTO dto, Movie movie, @Context MovieImageRepository movieImageRepository) {
        dto.setPoster(
                movieImageRepository.findMovieImageByMovieId(movie.getMovieId(), Limit.of(1))
        );
    }

    default Page<MovieFrontDTO> toDTOPage(Page<Movie> page, @Context MovieImageRepository repository) {
        List<MovieFrontDTO> dtoList = page.getContent().stream()
                .map((movie -> toDTO(movie, repository)))
                .toList();
        return new PageImpl<>(dtoList, page.getPageable(), page.getTotalElements());
    }
}
