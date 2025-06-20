package com.savt.listopia.cron;

import com.savt.listopia.config.AppConstants;
import com.savt.listopia.service.SessionService;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import java.time.Instant;

@Component
public class SessionDeleter {

    private final SessionService sessionService;

    public SessionDeleter(SessionService sessionService) {
        this.sessionService = sessionService;
    }

    @Scheduled(cron = "0 0 0 * * *")
    public void deleteOldSessions() {
        Instant deleteBefore = Instant.now().minus(AppConstants.SESSION_EXPIRY_DURATION);
        sessionService.deleteSessionsBefore(deleteBefore.toEpochMilli());
    }

}
