package com.savt.listopia.payload.dto;

import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class MovieCommentDTO {
    private Long commentId;
    private Integer movieId;
    private UserDTO user;
    private Long sentAt;
    private Boolean isSpoiler;
    private Boolean isUpdated;
    private String message;
}
