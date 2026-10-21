package org.db.dao;

import org.db.model.AnnouncementPacket;
import org.db.model.AnnouncementPacketState;

import java.util.List;

public interface AnnouncementPacketStateDAO {
	AnnouncementPacketState getPacketState(int id);
	List<AnnouncementPacketState> getAllStates();
}
