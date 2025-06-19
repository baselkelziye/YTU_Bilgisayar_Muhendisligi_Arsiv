package com.savt.listopia.service.user;

import com.savt.listopia.payload.dto.PrivateMessageDTO;
import org.springframework.data.domain.Page;
import org.springframework.stereotype.Service;

import java.util.UUID;

@Service
public interface UserMessageService {
    void userReportMessage(Long userId, Long messageId);
    PrivateMessageDTO sendMessage(Long fromId, Long toId, String messageUnsafe);
    void markPrivateMessageReported(Long messageId);
    Boolean isPrivateMessageReported(Long messageId);
    Page<PrivateMessageDTO> getAllReportedMessages(int page, int size);
    Page<PrivateMessageDTO> getAllMessagesOfUserReceived(Long userId, int page, int size);
    Page<PrivateMessageDTO> getAllMessagesUserSent(Long userId, int page, int size);
    Page<PrivateMessageDTO> getAllMessagesSentTo(Long userId, Long toId, int page, int size);
    Page<PrivateMessageDTO> getAllMessagesReceivedFrom(Long userId, Long fromId, int page, int size);
    Page<PrivateMessageDTO> getAllMessagesWith(Long userId, UUID friendUUid, int page, int size);

    void markAsRead(Long userId, Long receiverId, Long messageId);
}
