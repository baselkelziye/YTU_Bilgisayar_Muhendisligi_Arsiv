package com.savt.listopia.model.user;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import lombok.Data;

import java.util.UUID;

@Data
@Entity(name = "sessions")
public class Session {
    @Id
    private UUID uuid = UUID.randomUUID();

    private Long userId;
    private String ipAddress;

    private long createdAt;
    private long expiresAt;
}
