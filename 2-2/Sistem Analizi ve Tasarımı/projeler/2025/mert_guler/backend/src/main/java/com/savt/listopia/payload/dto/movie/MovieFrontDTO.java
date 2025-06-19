package com.savt.listopia.payload.dto.movie;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class MovieFrontDTO {
    private Integer movieId;

    private String title;

    private String poster;

    private Integer watchCount;

    private Integer likeCount;

    private Long clickCount;
}
