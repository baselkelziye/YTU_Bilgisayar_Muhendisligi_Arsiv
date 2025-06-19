package com.savt.listopia.model.user.auth;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.Data;

@Data
@Entity
@Table(name = "user_verification")
public class UserVerification {
    @Id
    @GeneratedValue
    private Long id;

    private Long sentAt;

    private String token;

    private String mail;

}
