package org.db.hibernate;

import org.db.dao.NotificationDAO;
import org.db.model.Notification;

import java.util.List;

/**
 * Created by mgunes on 29.01.2017.
 */
public class NotificationHibernateImpl extends AbstractDAO implements NotificationDAO {
    public boolean saveNotification(Notification notification) {
        return save(notification);
    }

    public List<Notification> getMyNotifications(String username) {
        String query = "SELECT * FROM notification WHERE trigger_target = '" + username + "' ORDER BY trigger_date desc;";
        return getRowsBySQLQuery(Notification.class, query);
    }
}
