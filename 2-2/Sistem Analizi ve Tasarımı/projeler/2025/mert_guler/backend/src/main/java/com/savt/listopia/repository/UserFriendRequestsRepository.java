package com.savt.listopia.repository;

import com.savt.listopia.model.user.User;
import com.savt.listopia.model.user.UserFriendRequest;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface UserFriendRequestsRepository extends JpaRepository<UserFriendRequest, Long> {
    Optional<UserFriendRequest> findByUserRequestSentAndUserRequestReceived(User id, User id1);

    @Query("SELECT u FROM UserFriendRequest u WHERE u.active = :b AND u.userRequestReceived = :user")
    Page<UserFriendRequest> findByUserRequestReceivedAndActive(User user, boolean b, Pageable pageable);

    @Query("SELECT u FROM UserFriendRequest u WHERE u.active = :b AND u.userRequestSent = :user")
    Page<UserFriendRequest> findByUserRequestSentAndActive(User user, boolean b, Pageable pageable);
}
