package org.db.hibernate;

import java.util.List;

import org.db.dao.AnnouncementTypeDAO;
import org.db.model.AnnouncementType;

public class AnnouncementTypeHibernateImpl extends AbstractDAO implements AnnouncementTypeDAO {

	public List<AnnouncementType> getAllAnnouncementTypes() {
		String sql = "SELECT * FROM announcement_type ORDER BY id;";
		return getRowsBySQLQuery(AnnouncementType.class, sql);
	}

}
