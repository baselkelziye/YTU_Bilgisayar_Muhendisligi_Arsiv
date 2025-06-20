package com.savt.listopia.repository.movie;

import com.savt.listopia.model.user.MovieComment;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MovieCommentRepository extends JpaRepository<MovieComment, Long> {
    Page<MovieComment> findByMovie_MovieId(Integer movieId, Pageable pageable);
    Page<MovieComment> findByFromUser_Id(Long userId, Pageable pageable);
    Page<MovieComment> findByFromUser_IdAndMovie_MovieId(Long userId, Integer movieId, Pageable pageable);
    Page<MovieComment> findByIsReported(Boolean isReported, Pageable pageable);
}
