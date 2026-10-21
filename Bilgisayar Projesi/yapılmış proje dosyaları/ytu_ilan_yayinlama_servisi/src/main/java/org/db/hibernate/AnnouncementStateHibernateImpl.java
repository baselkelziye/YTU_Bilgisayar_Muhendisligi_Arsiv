package org.db.hibernate;

import org.db.dao.AnnouncementStateDAO;
import org.db.model.AnnouncementState;

public class AnnouncementStateHibernateImpl extends AbstractDAO implements AnnouncementStateDAO {

	public AnnouncementState getState(int id) {
		return (AnnouncementState) getObject(AnnouncementState.class, id);
	}

}
