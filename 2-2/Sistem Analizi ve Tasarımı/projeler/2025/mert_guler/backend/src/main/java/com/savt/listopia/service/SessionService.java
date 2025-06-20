package com.savt.listopia.service;

import com.savt.listopia.model.user.Session;
import com.savt.listopia.model.user.User;
import org.springframework.http.ResponseCookie;
import org.springframework.stereotype.Service;

@Service
public interface SessionService {
    void deleteSession(Session session);
    void deleteUserSessions(User user);
    void deleteCurrentSession();
    Session createSession(User user);
    ResponseCookie createCookie(Session session);
    Session getAndUpdateSession(String uuidStr);
    Session getCurrentSession();
    void deleteSessionsBefore(Long time);
}
