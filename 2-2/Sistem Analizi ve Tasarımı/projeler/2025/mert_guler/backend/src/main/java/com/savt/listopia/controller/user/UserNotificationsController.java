package com.savt.listopia.controller.user;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.payload.dto.NotificationDTO;
import com.savt.listopia.payload.response.APIResponse;
import com.savt.listopia.service.UserService;
import jakarta.validation.constraints.Max;
import org.springframework.data.domain.Page;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1/user/notifications")
public class UserNotificationsController {
    private final UserService userService;

    public UserNotificationsController(UserService userService) {
        this.userService = userService;
    }

    @GetMapping("/")
    public ResponseEntity<Page<NotificationDTO>> getNotifications(
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        Page<NotificationDTO> dto = userService.getUserNotifications(
                userId,
                pageNumber,
                pageSize
        );
        return ResponseEntity.ok(dto);
    }

    @PostMapping("/notified")
    public ResponseEntity<APIResponse> notifiedUser(
            @RequestParam(name = "timestamp") Long timestamp
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        userService.userNotifiedBefore(userId, timestamp);
        return ResponseEntity.ok(APIResponse.success("user_notified"));
    }
}
