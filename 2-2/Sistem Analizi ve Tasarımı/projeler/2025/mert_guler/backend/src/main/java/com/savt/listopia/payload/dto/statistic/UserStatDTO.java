package com.savt.listopia.payload.dto.statistic;

import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class UserStatDTO {
    private String uuid;

    private String username;

    private String profilePicture;

    private Integer watchedCount;
    private Integer likedCount;
}
