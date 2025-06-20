package com.savt.listopia.repository;

import com.savt.listopia.model.user.Notification;
import jakarta.transaction.Transactional;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.Optional;

public interface NotificationRepository extends JpaRepository<Notification, Long> {
    Page<Notification> findByUserId(Long userId, Pageable pageable);

    Optional<Notification> findByIdAndUserId(Long id, Long userId);

    @Modifying
    @Transactional
    @Query(value = "UPDATE notification n SET n.notified = true WHERE n.time <= :time LIMIT :limit", nativeQuery = true)
    void setLikedTrueBeforeTime(@Param("time") Long time, @Param("limit") int limit);

    Page<Notification> findByUserIdAndTimeBefore(Long userId, Long time, Pageable pageable);
}
