package org.db.dao;

import org.db.model.Application;

public interface ApplicationDAO {
	boolean application(Application app);
	boolean deleteApplication(String userName, int announcementID);
}
