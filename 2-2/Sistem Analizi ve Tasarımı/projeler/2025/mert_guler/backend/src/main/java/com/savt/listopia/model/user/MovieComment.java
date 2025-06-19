package com.savt.listopia.model.user;

import com.savt.listopia.model.movie.Movie;
import jakarta.persistence.*;
import lombok.Data;

@Data
@Entity
@Table(name = "movie_comments")
public class MovieComment {
    @Id
    @GeneratedValue
    private Long id;

    @ManyToOne
    @JoinColumn(name = "from_user", nullable = false)
    private User fromUser;

    @ManyToOne
    @JoinColumn(name = "movie_id", nullable = false)
    private Movie movie;

    private Long sentAtTimestampSeconds;

    private Boolean isReported = false;
    private Boolean isSpoiler;
    private Boolean isUpdated = false;

    @Column(columnDefinition = "TEXT", length = 4096)
    private String message;
}
