package com.savt.listopia.repository;

import com.savt.listopia.model.user.Session;
import jakarta.transaction.Transactional;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.Optional;
import java.util.UUID;

@Repository
public interface SessionRepository extends JpaRepository<Session, UUID> {
    Optional<Session> findByUuid(UUID uuid);

    @Modifying
    @Transactional
    @Query("DELETE FROM sessions s WHERE s.userId = :userId")
    void deleteUserSessions(@Param("userId") Long userId);

    @Modifying
    @Transactional
    @Query("DELETE FROM sessions s WHERE s.expiresAt < :time")
    void deleteExpiredSessions(@Param("time") Long time);
}
