package com.savt.listopia.model.movie.image;

import com.savt.listopia.model.movie.Movie;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Entity
@Data
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "movie_images")
public class MovieImage {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long imageId;

    private String iso6391;

    private String filePath;

    private Double aspectRatio;

    private Integer height;

    private Integer width;

    private Integer type;

    @ManyToOne()
    @JoinColumn(name = "movie_id")
    private Movie movie;
}
