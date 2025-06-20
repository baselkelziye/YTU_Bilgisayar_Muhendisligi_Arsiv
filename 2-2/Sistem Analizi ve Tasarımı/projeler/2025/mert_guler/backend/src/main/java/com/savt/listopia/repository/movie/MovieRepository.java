package com.savt.listopia.repository.movie;

import com.savt.listopia.model.movie.Movie;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

@Repository
public interface MovieRepository extends JpaRepository<Movie, Integer> {
    @Query("SELECT m FROM Movie m JOIN m.genres g WHERE g.name = :genre")
    Page<Movie> findAllByGenreName(Pageable pageDetails, String genre);

    Page<Movie> findAllByTitleLikeIgnoreCase(Pageable pageDetails, String word);

    @Query("SELECT m FROM Movie m JOIN m.genres g WHERE g.name = :genre AND lower(m.title) LIKE lower(:word)")
    Page<Movie> findAllByGenreNameAndTitleLikeIgnoreCase(Pageable pageDetails, String genre, String word);
}
