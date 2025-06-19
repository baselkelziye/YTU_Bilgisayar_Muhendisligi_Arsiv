package com.savt.listopia.payload.dto;

import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class PrivateMessageDTO {
    Long id;

    UserDTO from;

    UserDTO recipient;

    Long sentAt;

    String message;

    Boolean isRead;
}
