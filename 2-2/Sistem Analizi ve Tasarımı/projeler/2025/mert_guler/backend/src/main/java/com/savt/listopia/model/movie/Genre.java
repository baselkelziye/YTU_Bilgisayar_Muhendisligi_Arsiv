package com.savt.listopia.model.movie;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Entity
@Data
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "genres")
public class Genre {
    @Id
    private Integer genreId;

    private String name;

    private Long clickCount = 0L;
    private Long watchCount = 0L;
    private Long likeCount = 0L;
}
