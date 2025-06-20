package com.savt.listopia.repository.auth;

import com.savt.listopia.model.user.auth.PendingUser;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface PendingUserRepository extends JpaRepository<PendingUser, Long> {
    boolean existsByUsernameLower(String usernameLower);

    boolean existsByEmail(String email);

    Optional<PendingUser> findByEmail(String email);

    Optional<PendingUser> findByUsernameLower(String usernameLower);

    Optional<PendingUser> findByUsername(String username);
}
