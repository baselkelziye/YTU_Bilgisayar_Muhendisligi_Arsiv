package com.savt.listopia.model.user.auth;

import jakarta.persistence.*;
import lombok.Data;

import java.util.UUID;

@Data
@Entity
@Table(name = "pending_user")
public class PendingUser {
    @Id
    @GeneratedValue
    private Long id;

    @Column(unique = true)
    UUID uuid = UUID.randomUUID();

    @Column(unique = true)
    private String username;

    @Column(unique = true)
    private String usernameLower;

    private String firstName;
    private String lastName;

    @Column(unique = true)
    private String email;

    private String hashedPassword;

    private Long createdAt;
}
