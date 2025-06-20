package com.savt.listopia.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.savt.listopia.mapper.NotificationMapper;
import com.savt.listopia.mapper.UserMapper;
import com.savt.listopia.model.user.Notification;
import com.savt.listopia.model.user.NotificationType;
import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.NotificationDTO;
import com.savt.listopia.payload.dto.UserDTO;
import com.savt.listopia.repository.NotificationRepository;
import jakarta.transaction.Transactional;
import lombok.Builder;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;

@Builder
class NewMessageNotificationDTO {
    UserDTO from;
    String message;
}

@Service
public class NotificationServiceImpl implements NotificationService {
    private static final Logger LOGGER = LoggerFactory.getLogger(NotificationServiceImpl.class);

    private final NotificationRepository notificationRepository;
    private final UserMapper userMapper;
    private final ObjectMapper objectMapper;
    private final NotificationMapper notificationMapper;

    public NotificationServiceImpl(NotificationRepository notificationRepository, UserMapper userMapper, ObjectMapper objectMapper, NotificationMapper notificationMapper) {
        this.notificationRepository = notificationRepository;
        this.userMapper = userMapper;
        this.objectMapper = objectMapper;
        this.notificationMapper = notificationMapper;
    }

    @Transactional
    protected void createAndSaveNotification(User user, NotificationType type, String content) {
        try {
            Notification notification = new Notification();
            notification.setUser(user);
            notification.setType(type);
            notification.setContent(content);
            notificationRepository.save(notification);
        } catch (Exception e) {
            LOGGER.error(e.getMessage(), e);
        }
    }

    private String dtoToJson(Object object) {
        try {
            return objectMapper.writeValueAsString(object);
        } catch (JsonProcessingException e) {
            return "";
        }
    }

    @Override
    @Transactional
    public void notifyBecomeFriends(User user, User friend) {
        UserDTO friendDTO = userMapper.toDTO(friend);
        String json = dtoToJson(friendDTO);
        if (json.isEmpty()) {
            LOGGER.error("JSON object is null or empty: notifyBecomeFriends(): userId: {}, friendId: {}", user.getId(), friend.getId());
            return;
        }
        createAndSaveNotification(user, NotificationType.BECOME_FRIENDS, json);
    }

    @Override
    @Transactional
    public void notifyNewMessage(User user, User from, String message) {
        UserDTO fromDTO = userMapper.toDTO(from);
        NewMessageNotificationDTO newMessageNotificationDTO = NewMessageNotificationDTO.builder()
                .message(message)
                .from(fromDTO)
                .build();
        String json = dtoToJson(newMessageNotificationDTO);
        if (json.isEmpty()) {
            LOGGER.error("JSON object is null or empty: notifyNewMessage(): userId: {}, fromId: {}", user.getId(), from.getId());
            return;
        }
        createAndSaveNotification(user, NotificationType.NEW_MESSAGE, json);
    }

    @Override
    @Transactional
    public void notifyFriendRequest(User user, User from) {
        UserDTO fromDTO = userMapper.toDTO(from);
        String json = dtoToJson(fromDTO);
        if (json.isEmpty()) {
            LOGGER.error("JSON object is null or empty: notifyFriendRequest(): userId: {}, fromId: {}", user.getId(), from.getId());
            return;
        }
        createAndSaveNotification(user, NotificationType.FRIEND_REQUEST, json);
    }

    @Override
    @Transactional
    public Page<NotificationDTO> getUserNotifications(User user, int pageNumber, int pageSize) {
        Pageable pageable = PageRequest.of(pageNumber, pageSize, Sort.by(Sort.Direction.DESC, "time"));
        Page<Notification> dto = notificationRepository.findByUserId(user.getId(), pageable);
        return notificationMapper.toDTOPage(dto);
    }

    @Override
    @Transactional
    public void markAsRead(User user, Long timestamp) {
        int page = 0;
        int size = 500;
        Pageable pageable = PageRequest.of(page, size);
        Page<Notification> notificationsPage;

        // Loop through the pages and apply the update
        do {
            notificationsPage = notificationRepository.findByUserIdAndTimeBefore(user.getId(), timestamp, pageable);

            if (!notificationsPage.isEmpty()) {
                notificationRepository.setLikedTrueBeforeTime(timestamp, pageable.getPageSize());
            }

            page++;
            pageable = PageRequest.of(page, size);

        } while (notificationsPage.hasNext());
    }
}
