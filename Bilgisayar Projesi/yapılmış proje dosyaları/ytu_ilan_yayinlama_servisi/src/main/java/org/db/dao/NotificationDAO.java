package org.db.dao;

import org.db.model.Notification;

import java.util.List;

/**
 * Created by mgunes on 29.01.2017.
 */
public interface NotificationDAO {
    boolean saveNotification(Notification notification);
    List<Notification> getMyNotifications(String username);
}
