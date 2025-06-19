package com.savt.listopia.payload.response;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class APIResponse {
    private String message;
    private boolean success;

    public static APIResponse success(String message) {
        return APIResponse.builder().success(true).message(message).build();
    }

    public static APIResponse failure(String message) {
        return APIResponse.builder().success(false).message(message).build();
    }

}
