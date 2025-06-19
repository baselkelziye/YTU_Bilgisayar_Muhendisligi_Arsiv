package com.savt.listopia.controller.user;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.exception.userException.UserNotFoundException;
import com.savt.listopia.payload.dto.PrivateMessageDTO;
import com.savt.listopia.payload.response.APIResponse;
import com.savt.listopia.security.request.MessageUserRequest;
import com.savt.listopia.service.UserService;
import com.savt.listopia.service.user.UserMessageService;
import com.savt.listopia.util.UUIDParser;
import jakarta.validation.Valid;
import jakarta.validation.constraints.Max;
import org.springframework.data.domain.Page;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.UUID;

@RestController
@RequestMapping("/api/v1/user/message")
public class UserMessageController {
    private final UserService userService;
    private final UserMessageService userMessageService;

    public UserMessageController(UserService userService, UserMessageService userMessageService) {
        this.userService = userService;
        this.userMessageService = userMessageService;
    }

    @PostMapping("/")
    public ResponseEntity<PrivateMessageDTO> Message(@Valid @RequestBody MessageUserRequest request) {
        PrivateMessageDTO dto = userMessageService.sendMessage(
                userService.getCurrentUserId().orElseThrow(() -> new UserNotFoundException("user_does_not_exists")),
                userService.getUserIdFromUUID(request.getTo()),
                request.getMessage()
        );
        return ResponseEntity.ok( dto );
    }

    @PostMapping("/{id}/report")
    public ResponseEntity<APIResponse> MessageReport(@PathVariable Long id) {
        userMessageService.userReportMessage(
                userService.getCurrentUserIdOrThrow(),
                id
        );
        return ResponseEntity.ok(APIResponse.builder().success(true).message("message_reported").build());
    }

    @GetMapping("/received")
    public ResponseEntity<Page<PrivateMessageDTO>> Received(
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        Page<PrivateMessageDTO> messages = userMessageService.getAllMessagesOfUserReceived(userId, pageNumber, pageSize);
        return ResponseEntity.ok(messages);
    }

    @GetMapping("/sent")
    public ResponseEntity<Page<PrivateMessageDTO>> Sent(
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        Page<PrivateMessageDTO> messages = userMessageService.getAllMessagesUserSent(userId, pageNumber, pageSize);
        return ResponseEntity.ok(messages);
    }

    @GetMapping("/received/{userUuid}")
    public ResponseEntity<Page<PrivateMessageDTO>> MessagesFromUser(
            @PathVariable String userUuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        Page<PrivateMessageDTO> messageDTOS = userMessageService.getAllMessagesReceivedFrom(
                userId,
                userService.getUserIdFromUUID(UUIDParser.parse(userUuid)),
                pageNumber,
                pageSize
        );
        return ResponseEntity.ok(messageDTOS);
    }

    @GetMapping("/sent/{userUuid}")
    public ResponseEntity<Page<PrivateMessageDTO>> MessagesToUser(
            @PathVariable String userUuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ){
        Long userId = userService.getCurrentUserIdOrThrow();
        Page<PrivateMessageDTO> messageDTOS = userMessageService.getAllMessagesSentTo(
                userId,
                userService.getUserIdFromUUID(UUIDParser.parse(userUuid)),
                pageNumber,
                pageSize
        );
        return ResponseEntity.ok(messageDTOS);
    }

    @GetMapping("/with/{uuid}")
    public ResponseEntity<Page<PrivateMessageDTO>> getMessagesWith(
            @PathVariable String uuid,
            @RequestParam(name = "pageNumber", defaultValue = AppConstants.PAGE_NUMBER, required = false) Integer pageNumber,
            @Max(50) @RequestParam(name = "pageSize", defaultValue = AppConstants.PAGE_SIZE, required = false) Integer pageSize
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        UUID friendUuid = UUIDParser.parse(uuid);
        Page<PrivateMessageDTO> messageDTOS = userMessageService.getAllMessagesWith(userId, friendUuid, pageNumber, pageSize);
        return ResponseEntity.ok(messageDTOS);
    }

    @PostMapping("/read")
    public ResponseEntity<APIResponse> markAsRead(
            @RequestParam(name = "userUuid") String userUuid,
            @RequestParam(name = "time") Long time
    ) {
        Long userId = userService.getCurrentUserIdOrThrow();
        UUID uuid = UUIDParser.parse(userUuid);
        Long friendId = userService.getUserIdFromUUID(uuid);
        userMessageService.markAsRead(userId, friendId, time);
        return ResponseEntity.ok(APIResponse.success("messages_mark_as_read"));
    }

}
