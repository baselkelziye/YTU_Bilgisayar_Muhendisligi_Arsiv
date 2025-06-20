package com.savt.listopia.controller.admin;

import com.savt.listopia.exception.userException.UserNotFoundException;
import com.savt.listopia.model.user.User;
import com.savt.listopia.model.user.UserRole;
import com.savt.listopia.payload.dto.UserDTO;
import com.savt.listopia.payload.response.APIResponse;
import com.savt.listopia.repository.UserRepository;
import com.savt.listopia.service.AuthService;
import com.savt.listopia.service.UserService;
import com.savt.listopia.util.UUIDParser;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1/admin/user")
public class AdminUserController {
    private static final Logger LOGGER = LoggerFactory.getLogger(AdminUserController.class);

    private final AuthService authService;
    private final UserService userService;
    private final UserRepository userRepository;

    public AdminUserController(AuthService authService, UserService userService, UserRepository userRepository) {
        this.authService = authService;
        this.userService = userService;
        this.userRepository = userRepository;
    }

    @DeleteMapping("/uuid/{uuid}")
    public ResponseEntity<APIResponse> deleteAccount(@PathVariable("uuid") String uuid) {
        authService.requireRoleOrThrow(UserRole.ADMIN);

        Long userId = userService.getUserIdFromUUID(UUIDParser.parse(uuid));
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);

        LOGGER.info("deleteAccount: deleting account with uuid: {}", uuid);
        userService.deleteAccount(user.getId());
        return ResponseEntity.ok(APIResponse.success("user_deleted"));
    }

    @PutMapping("/uuid/{uuid}")
    public ResponseEntity<APIResponse> editAccount(
            @PathVariable("uuid") String uuid,
            @RequestBody UserDTO user
        ) {
        authService.requireRoleOrThrow(UserRole.ADMIN);
        Long userId = userService.getUserIdFromUUID(UUIDParser.parse(uuid));

        LOGGER.info("deleteAccount: editing account with uuid: {}", uuid);
        userService.editUser(userId, user);
        return ResponseEntity.ok(APIResponse.success("user_edited"));
    }

}
