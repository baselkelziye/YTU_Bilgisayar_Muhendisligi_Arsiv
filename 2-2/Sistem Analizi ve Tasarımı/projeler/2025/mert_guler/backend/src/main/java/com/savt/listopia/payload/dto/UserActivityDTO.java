package com.savt.listopia.payload.dto;

import com.savt.listopia.model.user.UserActivityType;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class UserActivityDTO {
    private Long id;
    private UserActivityType type;
    private String content;
    private Long time;
}
