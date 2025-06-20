package com.savt.listopia.service.user;

import com.savt.listopia.exception.ResourceNotFoundException;
import com.savt.listopia.exception.userException.UserNotFoundException;
import com.savt.listopia.mapper.PrivateMessageMapper;
import com.savt.listopia.model.user.PrivateMessage;
import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.PrivateMessageDTO;
import com.savt.listopia.repository.PrivateMessageRepository;
import com.savt.listopia.repository.UserRepository;
import com.savt.listopia.service.NotificationService;
import jakarta.transaction.Transactional;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;

import java.time.Instant;
import java.util.UUID;

@Service
public class UserMessageServiceImpl implements UserMessageService {
    private final UserRepository userRepository;
    private final PrivateMessageRepository privateMessageRepository;
    private final NotificationService notificationService;
    private final PrivateMessageMapper privateMessageMapper;

    public UserMessageServiceImpl(UserRepository userRepository, PrivateMessageRepository privateMessageRepository, NotificationService notificationService, PrivateMessageMapper privateMessageMapper) {
        this.userRepository = userRepository;
        this.privateMessageRepository = privateMessageRepository;
        this.notificationService = notificationService;
        this.privateMessageMapper = privateMessageMapper;
    }

    @Override
    @Transactional
    public void userReportMessage(Long userId, Long messageId) {
        PrivateMessage msg = privateMessageRepository.findById(messageId).orElseThrow(() -> new UserNotFoundException("message_does_not_exists"));
        if (msg.getToUser().getId().equals(userId)) {
            markPrivateMessageReported(messageId);
        }
    }

    @Transactional
    public PrivateMessageDTO sendMessage(Long fromId, Long toId, String messageStr) {
        User sender = userRepository.findById(fromId).orElseThrow(UserNotFoundException::new);
        User receiver = userRepository.findById(toId).orElseThrow(UserNotFoundException::new);
        PrivateMessage message = new PrivateMessage();
        message.setFromUser( sender );
        message.setToUser( receiver );
        message.setSentAtTimestampSeconds(Instant.now().getEpochSecond());
        message.setMessage(messageStr);
        notificationService.notifyNewMessage(sender, receiver, messageStr);
        PrivateMessage sent = privateMessageRepository.save(message);
        return privateMessageMapper.toDTO(sent);
    }

    @Transactional
    public void markPrivateMessageReported(Long messageId) {
        PrivateMessage msg = privateMessageRepository.findById(messageId).orElseThrow(ResourceNotFoundException::new);
        msg.setIsReported(true);
        privateMessageRepository.save(msg);
    }

    public Boolean isPrivateMessageReported(Long messageId) {
        return privateMessageRepository.findPrivateMessageById(messageId).orElseThrow(ResourceNotFoundException::new).getIsReported();
    }

    public Page<PrivateMessageDTO> getAllReportedMessages(int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return privateMessageMapper.toDTOPage(privateMessageRepository.findAllByIsReportedTrue(pageable));
    }

    public Page<PrivateMessageDTO> getAllMessagesOfUserReceived(Long userId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return privateMessageMapper.toDTOPage(privateMessageRepository.findAllByToUserId(userId, pageable));
    }

    public Page<PrivateMessageDTO> getAllMessagesUserSent(Long userId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return privateMessageMapper.toDTOPage(privateMessageRepository.findAllByFromUserId(userId, pageable));
    }

    public Page<PrivateMessageDTO> getAllMessagesSentTo(Long userId, Long toId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return privateMessageMapper.toDTOPage(privateMessageRepository.findAllByFromUserIdAndToUserId(userId, toId, pageable));
    }

    public Page<PrivateMessageDTO> getAllMessagesReceivedFrom(Long userId, Long fromId, int page, int size) {
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        return privateMessageMapper.toDTOPage(privateMessageRepository.findAllByFromUserIdAndToUserId(fromId, userId, pageable));
    }

    @Override
    public Page<PrivateMessageDTO> getAllMessagesWith(Long userId, UUID friendUUid, int page, int size) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        User receiver = userRepository.findByUuid(friendUUid).orElseThrow(UserNotFoundException::new);
        Pageable pageable = PageRequest.of(page, size, Sort.by("sentAtTimestampSeconds").descending());
        Page<PrivateMessage> messages = privateMessageRepository.findAllBetweenUsers(user.getId(), receiver.getId(), pageable);
        return privateMessageMapper.toDTOPage(messages);
    }

    @Override
    public void markAsRead(Long userId, Long receiverId, Long messageId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        User receiver = userRepository.findById(receiverId).orElseThrow(UserNotFoundException::new);
        privateMessageRepository.markMessagesAsReadBefore(user, receiver, messageId);
    }
}
