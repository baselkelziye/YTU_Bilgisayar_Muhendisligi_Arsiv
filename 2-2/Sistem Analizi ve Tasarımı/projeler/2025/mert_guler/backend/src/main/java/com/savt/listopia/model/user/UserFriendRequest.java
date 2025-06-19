package com.savt.listopia.model.user;

import jakarta.persistence.*;
import lombok.Data;

@Data
@Entity
@Table(name = "user_friend_requests")
public class UserFriendRequest {
    @Column(unique = true)
    @Id
    @GeneratedValue
    private Long id;

    @ManyToOne
    @JoinColumn(name = "user_request_sent")
    private User userRequestSent;

    @ManyToOne
    @JoinColumn(name = "user_request_received")
    private User userRequestReceived;

    private Long timestamp;

    private Boolean active = true;
}