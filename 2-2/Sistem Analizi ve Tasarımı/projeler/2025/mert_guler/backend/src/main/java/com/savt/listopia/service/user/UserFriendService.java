package com.savt.listopia.service.user;

import com.savt.listopia.payload.dto.UserDTO;
import com.savt.listopia.payload.dto.UserFriendRequestDTO;
import org.springframework.data.domain.Page;
import org.springframework.stereotype.Service;

import java.util.UUID;

@Service
public interface UserFriendService {
    void makeFriends(Long receiverId, Long senderId);
    void userSentOrAcceptFriendRequest(Long requestOwnerUserId, UUID requestedUserUuid);
    void userCancelFriendRequest(Long userId, UUID cancelledUserUuid);
    void userRejectedFriend(Long userId, UUID friendUUID);
    void userRemovedFriend(Long userId, UUID friendUUID);
    Page<UserFriendRequestDTO> getUserFriendRequestsReceived(Long userId, int page, int size);
    Page<UserFriendRequestDTO> getUserFriendRequestsSent(Long userId, int page, int size);
    Page<UserDTO> getUserFriends(Long userId, int page, int size);
}
