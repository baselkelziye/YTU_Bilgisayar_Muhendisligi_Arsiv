package com.savt.listopia.payload.dto;

import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class UserFriendRequestDTO {
    private Long id;
    private UserDTO userRequestSent;
    private UserDTO userRequestReceived;
    Long timestamp;
}
