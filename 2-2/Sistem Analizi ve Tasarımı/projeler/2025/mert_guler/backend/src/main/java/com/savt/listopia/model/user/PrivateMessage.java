package com.savt.listopia.model.user;

import jakarta.persistence.*;
import lombok.Data;

@Data
@Entity
@Table(name = "private_messages")
public class PrivateMessage {
    @Id
    @GeneratedValue
    Long id;

    @ManyToOne
    @JoinColumn(name = "from_user_id", nullable = false)
    User fromUser;

    @ManyToOne
    @JoinColumn(name = "to_user_id", nullable = false)
    User toUser;

    Long sentAtTimestampSeconds;

    Boolean isReported = false;
    Boolean isRead = false;

    @Column(columnDefinition = "TEXT", length = 1024)
    String message;
}
