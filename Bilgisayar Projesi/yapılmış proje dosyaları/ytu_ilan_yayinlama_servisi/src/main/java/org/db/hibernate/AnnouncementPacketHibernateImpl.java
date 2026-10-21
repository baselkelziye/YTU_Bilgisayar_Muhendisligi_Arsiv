package org.db.hibernate;

import java.util.List;

import org.db.dao.AnnouncementPacketDAO;
import org.db.model.AnnouncementPacket;

public class AnnouncementPacketHibernateImpl extends AbstractDAO implements AnnouncementPacketDAO {
	
	public boolean savePacket(AnnouncementPacket packet) {
		return save(packet);
	}

	public List<AnnouncementPacket> getAllPackets() {
		List<AnnouncementPacket> packetList = (List<AnnouncementPacket>) getAllRows(AnnouncementPacket.class);
		return packetList;
	}

	public List<AnnouncementPacket> getAvailablePackets() {
		String query = "SELECT * FROM announcement_packet where visible = true and last_date_used > now()";
        return getRowsBySQLQuery(AnnouncementPacket.class, query);
	}

    public List<AnnouncementPacket> getPacketBySQLQuery(String query) {
        return getRowsBySQLQuery(AnnouncementPacket.class, query);
    }

    public boolean deletePacket(int packetId) {
    	return deleteByQuery(AnnouncementPacket.class, "AnnouncementPacket", "packetId", packetId);
	}

    public boolean activePacket(int packetId) {
        String query = "UPDATE announcement_packet SET visible = TRUE WHERE packet_id = " + packetId;
        return updateBySQLQuery(AnnouncementPacket.class, query);
    }

    public AnnouncementPacket getPacket(int packetId) { //abstract dao içinde?
		return (AnnouncementPacket) getObject(AnnouncementPacket.class, packetId);
	}

}
