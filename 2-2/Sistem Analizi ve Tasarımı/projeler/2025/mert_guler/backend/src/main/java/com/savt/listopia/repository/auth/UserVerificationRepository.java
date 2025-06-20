package com.savt.listopia.repository.auth;

import com.savt.listopia.model.user.auth.UserVerification;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface UserVerificationRepository extends JpaRepository<UserVerification, Long> {
    Optional<UserVerification> findByMail(String mail);
}
