package org.db.dao;

import java.util.List;

import org.db.model.AnnouncementPacket;

public interface AnnouncementPacketDAO {
	boolean savePacket(AnnouncementPacket packet);
	boolean deletePacket(int packetId);
	boolean activePacket(int packetId);
	List<AnnouncementPacket> getAllPackets();
	List<AnnouncementPacket> getAvailablePackets();
    List<AnnouncementPacket> getPacketBySQLQuery(String query);
	AnnouncementPacket getPacket(int packetId);
}
