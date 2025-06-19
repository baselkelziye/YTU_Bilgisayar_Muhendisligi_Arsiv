package com.savt.listopia.repository;

import com.savt.listopia.model.user.PrivateMessage;
import com.savt.listopia.model.user.User;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.Optional;

public interface PrivateMessageRepository extends JpaRepository<PrivateMessage, Long> {
    Page<PrivateMessage> findAllByToUserId(Long toUserId, Pageable page);
    Page<PrivateMessage> findAllByFromUserIdAndToUserId(Long fromId, Long toId, Pageable page);
    Page<PrivateMessage> findAllByFromUserId(Long fromId, Pageable page);
    Page<PrivateMessage> findAllByIsReportedTrue(Pageable page);
    Optional<PrivateMessage> findPrivateMessageById(Long id);

    @Query("""
        SELECT m FROM PrivateMessage m 
        WHERE (m.fromUser.id = :userAId AND m.toUser.id = :userBId) 
           OR (m.fromUser.id = :userBId AND m.toUser.id = :userAId)
    """)
    Page<PrivateMessage> findAllBetweenUsers(@Param("userAId") Long userAId, @Param("userBId") Long userBId, Pageable page);

    @Modifying
    @Query("UPDATE PrivateMessage pm SET pm.isRead = true WHERE pm.fromUser = :fromUser AND pm.toUser = :toUser AND pm.sentAtTimestampSeconds < :timestamp")
    int markMessagesAsReadBefore(
            @Param("fromUser") User fromUser,
            @Param("toUser") User toUser,
            @Param("timestamp") Long timestamp);
}
