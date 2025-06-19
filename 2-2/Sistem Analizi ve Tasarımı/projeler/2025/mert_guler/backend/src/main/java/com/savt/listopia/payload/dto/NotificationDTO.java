package com.savt.listopia.payload.dto;

import com.savt.listopia.model.user.NotificationType;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class NotificationDTO {
    private Long id;
    private NotificationType type;
    private String content;
    private Boolean notified;
    private Long time;
}
