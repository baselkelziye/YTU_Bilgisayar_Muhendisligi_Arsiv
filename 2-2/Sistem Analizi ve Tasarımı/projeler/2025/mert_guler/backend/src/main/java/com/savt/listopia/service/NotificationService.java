package com.savt.listopia.service;

import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.NotificationDTO;
import org.springframework.data.domain.Page;
import org.springframework.stereotype.Service;

@Service
public interface NotificationService {
    void notifyBecomeFriends(User user, User friend);
    void notifyNewMessage(User user, User from, String message);
    void notifyFriendRequest(User user, User from);

    Page<NotificationDTO> getUserNotifications(User user, int pageNumber, int pageSize);
    void markAsRead(User user, Long timestamp);
}
