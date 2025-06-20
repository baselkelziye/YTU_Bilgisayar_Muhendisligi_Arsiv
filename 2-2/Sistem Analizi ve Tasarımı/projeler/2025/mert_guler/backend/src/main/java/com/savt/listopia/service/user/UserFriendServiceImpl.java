package com.savt.listopia.service.user;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.savt.listopia.exception.ResourceNotFoundException;
import com.savt.listopia.exception.userException.UserNotFoundException;
import com.savt.listopia.mapper.UserFriendRequestMapper;
import com.savt.listopia.mapper.UserMapper;
import com.savt.listopia.model.user.User;
import com.savt.listopia.model.user.UserFriendRequest;
import com.savt.listopia.payload.dto.UserDTO;
import com.savt.listopia.payload.dto.UserFriendRequestDTO;
import com.savt.listopia.repository.UserFriendRequestsRepository;
import com.savt.listopia.repository.UserRepository;
import com.savt.listopia.service.NotificationService;
import jakarta.transaction.Transactional;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;

import java.util.Objects;
import java.util.Optional;
import java.util.UUID;

@Service
public class UserFriendServiceImpl implements UserFriendService {
    private static final Logger LOGGER = LoggerFactory.getLogger(UserFriendServiceImpl.class);

    private final UserRepository userRepository;
    private final UserFriendRequestsRepository userFriendRequestsRepository;
    private final UserMapper userMapper;
    private final ObjectMapper objectMapper;
    private final NotificationService notificationService;
    private final UserActivityService userActivityService;
    private final UserFriendRequestMapper userFriendRequestMapper;

    public UserFriendServiceImpl(UserRepository userRepository, UserFriendRequestsRepository userFriendRequestsRepository, UserMapper userMapper, ObjectMapper objectMapper, NotificationService notificationService, UserActivityService userActivityService, UserFriendRequestMapper userFriendRequestMapper) {
        this.userRepository = userRepository;
        this.userFriendRequestsRepository = userFriendRequestsRepository;
        this.userMapper = userMapper;
        this.objectMapper = objectMapper;
        this.notificationService = notificationService;
        this.userActivityService = userActivityService;
        this.userFriendRequestMapper = userFriendRequestMapper;
    }

    @Transactional
    public void makeFriends(Long receiverId, Long senderId) {
        User userReceiver = userRepository.findById(receiverId).orElseThrow(ResourceNotFoundException::new);
        User userSender = userRepository.findById(senderId).orElseThrow(ResourceNotFoundException::new);

        userReceiver.getFriends().add(userSender);
        userSender.getFriends().add(userReceiver);

        userRepository.save(userReceiver);
        userRepository.save(userSender);

        // Delete the requests from repo
        Optional<UserFriendRequest> optReq1 = userFriendRequestsRepository.findByUserRequestSentAndUserRequestReceived(userReceiver, userSender);
        optReq1.ifPresent(userFriendRequestsRepository::delete);

        Optional<UserFriendRequest> optReq2 = userFriendRequestsRepository.findByUserRequestSentAndUserRequestReceived(userSender, userReceiver);
        optReq2.ifPresent(userFriendRequestsRepository::delete);

        try {
            String json = objectMapper.writeValueAsString( userMapper.toDTO(userReceiver) );
            notificationService.notifyBecomeFriends(userSender, userReceiver);
            // createNotification(userSender.getId(), NotificationType.BECOME_FRIENDS, json);
        } catch (JsonProcessingException e) {
            LOGGER.error("error creating json object for UserDTO commentId: {}", userReceiver.getUuid());
        }

        try {
            String json = objectMapper.writeValueAsString( userMapper.toDTO(userSender) );
            userActivityService.activityBecomeFriends(userReceiver, userSender);
            // createUserActivity(userReceiver.getId(), UserActivityType.BECOME_FRIENDS, json);
        } catch (JsonProcessingException e) {
            LOGGER.error("error creating json object for UserDTO commentId: {}", userSender.getUuid());
        }

        try {
            String json = objectMapper.writeValueAsString( userMapper.toDTO(userReceiver) );
            // createUserActivity(userSender.getId(), UserActivityType.BECOME_FRIENDS, json);
            userActivityService.activityBecomeFriends(userSender, userReceiver);
        } catch (JsonProcessingException e) {
            LOGGER.error("error creating json object for UserDTO commentId: {}", userReceiver.getUuid());
        }

        LOGGER.info("users become friends: {} - {}", userReceiver.getUuid(), userSender.getUuid());
    }

    @Transactional
    public void userSentOrAcceptFriendRequest(Long requestOwnerUserId, UUID requestedUserUuid) {
        User requester = userRepository.findById(requestOwnerUserId).orElseThrow(UserNotFoundException::new);
        User requested = userRepository.findByUuid(requestedUserUuid).orElseThrow(UserNotFoundException::new);

        if (Objects.equals(requester.getId(), requested.getId()))
            return;

        if (Objects.equals(requested.getId(), requester.getId()))
            return;

        if ( requester.getFriends().contains(requested) )
            return;

        if ( requested.getFriends().contains(requester) )
            return;

        Optional<UserFriendRequest> requestOptional = userFriendRequestsRepository.findByUserRequestSentAndUserRequestReceived(requester, requested);
        Optional<UserFriendRequest> reverseRequestOptional = userFriendRequestsRepository.findByUserRequestSentAndUserRequestReceived(requested, requester);

        // Check if other made request before
        if ( reverseRequestOptional.isPresent() ) {
            UserFriendRequest reverseUserFriendRequest = reverseRequestOptional.get();
            if ( reverseUserFriendRequest.getActive() ) {
                makeFriends(requester.getId(), requested.getId());
                return;
            }
        }

        // Check if already made request before.
        if ( requestOptional.isPresent() ) {
            UserFriendRequest userFriendRequest = requestOptional.get();
            if ( userFriendRequest.getActive() )
                return;

            userFriendRequest.setActive(true);
            userFriendRequest.setTimestamp(System.currentTimeMillis());
            userFriendRequestsRepository.save(userFriendRequest);
            return;
        }

        UserFriendRequest userFriendRequest = new UserFriendRequest();
        userFriendRequest.setActive(true);
        userFriendRequest.setTimestamp(System.currentTimeMillis());
        userFriendRequest.setUserRequestSent(requester);
        userFriendRequest.setUserRequestReceived(requested);

        userFriendRequestsRepository.save(userFriendRequest);
    }

    private void deactivateFriendRequest(Long senderId, UUID receiverUuid) {
        User user = userRepository.findById(senderId).orElseThrow(UserNotFoundException::new);
        User cancelled = userRepository.findByUuid(receiverUuid).orElseThrow(UserNotFoundException::new);

        Optional<UserFriendRequest> requestOptional = userFriendRequestsRepository.findByUserRequestSentAndUserRequestReceived(user, cancelled);
        if (requestOptional.isEmpty() )
            return;

        UserFriendRequest request = requestOptional.get();
        if ( !request.getActive() )
            return;

        request.setActive(false);
        userFriendRequestsRepository.save(request);
    }

    @Override
    public void userCancelFriendRequest(Long userId, UUID cancelledUserUuid) {
        deactivateFriendRequest(userId, cancelledUserUuid);
    }

    @Override
    @Transactional
    public void userRejectedFriend(Long rejecterId, UUID rejectedUUID) {
        User receiver = userRepository.findById(rejecterId).orElseThrow(UserNotFoundException::new);
        User sender = userRepository.findByUuid(rejectedUUID).orElseThrow(UserNotFoundException::new);

        Optional<UserFriendRequest> requestOptional = userFriendRequestsRepository.findByUserRequestSentAndUserRequestReceived(sender, receiver);
        if (requestOptional.isEmpty() )
            return;

        UserFriendRequest request = requestOptional.get();
        if ( !request.getActive() )
            return;

        request.setActive(false);
        userFriendRequestsRepository.save(request);
    }

    @Override
    @Transactional
    public void userRemovedFriend(Long userId, UUID friendUUID) {
        User remover = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        User lonely = userRepository.findByUuid(friendUUID).orElseThrow(UserNotFoundException::new);
        if ( remover.getFriends().contains(lonely) ) {
            remover.getFriends().remove(lonely);
            userRepository.save(remover);
        }
        if ( lonely.getFriends().contains(remover) ) {
            lonely.getFriends().remove(remover);
            userRepository.save(lonely);
        }
    }

    @Transactional
    public Page<UserFriendRequestDTO> getUserFriendRequestsReceived(Long userId, int page, int size) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Pageable pageable = PageRequest.of(page, size);
        Page<UserFriendRequest> usersRequested = userFriendRequestsRepository.findByUserRequestReceivedAndActive(user, true, pageable);
        return userFriendRequestMapper.toDTOPage(usersRequested);
    }

    @Override
    public Page<UserFriendRequestDTO> getUserFriendRequestsSent(Long userId, int page, int size) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        Pageable pageable = PageRequest.of(page, size);
        Page<UserFriendRequest> requests = userFriendRequestsRepository.findByUserRequestSentAndActive(user, true, pageable);
        return userFriendRequestMapper.toDTOPage(requests);
    }

    @Transactional
    public Page<UserDTO> getUserFriends(Long userId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size);
        Page<User> userPage = userRepository.findFriendsByUserId(userId, pageable);
        return userMapper.toDTOPage(userPage);
    }

}
