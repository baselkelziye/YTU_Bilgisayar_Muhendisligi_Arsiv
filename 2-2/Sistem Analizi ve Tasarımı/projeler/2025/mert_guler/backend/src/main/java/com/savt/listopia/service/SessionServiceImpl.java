package com.savt.listopia.service;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.exception.userException.UserNotAuthorizedException;
import com.savt.listopia.model.user.Session;
import com.savt.listopia.model.user.User;
import com.savt.listopia.repository.SessionRepository;
import com.savt.listopia.security.auth.AuthenticationToken;
import com.savt.listopia.util.UUIDParser;
import org.springframework.http.ResponseCookie;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

import java.util.UUID;

@Service
public class SessionServiceImpl implements SessionService {

    private final SessionRepository sessionRepository;

    public SessionServiceImpl(SessionRepository sessionRepository) {
        this.sessionRepository = sessionRepository;
    }

    @Override
    public Session createSession(User user) {
        Session session = new Session();

        long now = System.currentTimeMillis();
        long end = now + AppConstants.SESSION_EXPIRY_TIME;

        session.setCreatedAt(now);
        session.setUserId(user.getId());
        session.setExpiresAt(end);

        sessionRepository.save(session);

        return session;
    }

    @Override
    public ResponseCookie createCookie(Session session) {
        return ResponseCookie.from("_SESSION", session.getUuid().toString())
                .secure(true)
                .httpOnly(true)
                .path("/")
                .sameSite("None")
                .maxAge(AppConstants.SESSION_EXPIRY_TIME)
                .build();
    }

    @Override
    public void deleteSession(Session session) {
        sessionRepository.delete(session);
    }

    @Override
    public void deleteUserSessions(User user) {
        sessionRepository.deleteUserSessions(user.getId());
    }

    @Override
    public void deleteCurrentSession() {
        Session session_ctx = getCurrentSession();
        if ( session_ctx == null )
            return;

        Session sessionRepo = sessionRepository.findByUuid(session_ctx.getUuid()).orElseThrow(UserNotAuthorizedException::new);
        sessionRepository.delete(sessionRepo);
    }

    @Override
    public Session getAndUpdateSession(String uuidStr) {
        UUID uuid = UUIDParser.parseOrNull(uuidStr);

        if ( uuid == null )
            return null;

        Session session = sessionRepository.findByUuid(uuid).orElse(null);

        if ( session == null )
            return null;

        // check if session expired
        long end = session.getExpiresAt();
        long now = System.currentTimeMillis();

        if ( now < end ) {
            // update expire date
            session.setExpiresAt(now + AppConstants.SESSION_EXPIRY_TIME);
            sessionRepository.save(session);
            return session;
        } else {
            // session expired
            sessionRepository.delete(session);
            return null;
        }

    }

    @Override
    public Session getCurrentSession() {
        Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
        if (authentication == null)
            return null;

        if (authentication instanceof AuthenticationToken authenticationToken) {
            return authenticationToken.getPrincipal();
        }

        return null;
    }

    @Override
    public void deleteSessionsBefore(Long time) {
        sessionRepository.deleteExpiredSessions(time);
    }
}
