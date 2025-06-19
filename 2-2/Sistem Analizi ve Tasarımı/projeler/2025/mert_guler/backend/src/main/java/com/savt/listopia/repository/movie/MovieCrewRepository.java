package com.savt.listopia.repository.movie;

import com.savt.listopia.model.movie.MovieCrew;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface MovieCrewRepository extends JpaRepository<MovieCrew, Integer> {
    Page<MovieCrew> findAllByMovieMovieId(Integer movieId, Pageable pageDetails);
}
