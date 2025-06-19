package com.savt.listopia.model.movie;

import jakarta.annotation.Nullable;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Entity
@Data
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "movie_crews")
public class MovieCrew {
    @Id
    @JoinColumn(name = "crew_id")
    private Integer crewId;

    private String originalName;

    private Double popularity;

    @Nullable
    private String profilePath;

    private String department;

    private String job;

    @ManyToOne
    @JoinColumn(name = "movie_id")
    private Movie movie;
}
