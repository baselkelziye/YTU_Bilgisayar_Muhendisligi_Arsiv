package org.db.hibernate;

import org.db.dao.AnnouncementPacketStateDAO;
import org.db.model.AnnouncementPacketState;

import java.util.List;

public class PacketStateHibernateImpl extends AbstractDAO implements AnnouncementPacketStateDAO {

	public AnnouncementPacketState getPacketState(int id) {
		return (AnnouncementPacketState) getObject(AnnouncementPacketState.class, id);
	}

	public List<AnnouncementPacketState> getAllStates() {
		String query = "SELECT * FROM announcement_packet_state ORDER BY id;";
		return getRowsBySQLQuery(AnnouncementPacketState.class, query);
	}

}
