package com.savt.listopia.service;

import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.NotificationDTO;
import com.savt.listopia.payload.dto.UserActivityDTO;
import com.savt.listopia.payload.dto.UserDTO;
import org.springframework.data.domain.Page;
import org.springframework.stereotype.Service;

import java.util.Optional;
import java.util.UUID;

@Service
public interface UserService {
    User createUser(String firstname, String lastName, String email, String username, String hashedPassword);
    UserDTO getUserByUsername(String username);
    UserDTO getUserById(Long id);
    Optional<Long> getCurrentUserId();
    Long getCurrentUserIdOrThrow();
    Long getUserIdFromUUID(UUID uuid);
    void changeUsername(Long userId, String username);
    void changePassword(Long userId, String password);
    void changeBiography(Long userId, String biography);
    void deleteAccount(Long userId);
    void editUser(Long userId, UserDTO user);

    Page<UserActivityDTO> getUserActivities(Long userId, int pageNumber, int pageSize);
    Page<NotificationDTO> getUserNotifications(Long userId, Integer pageNumber, Integer pageSize);
    void userNotifiedBefore(Long userId, Long timestamp);

    Page<UserDTO> searchUsers(String searchText, int pageNumber, int pageSize);
}
