package org.db.hibernate;

import org.db.dao.AnnouncementPacketDAO;
import org.db.model.Announcement;
import org.db.model.AnnouncementPacket;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;

/**
 * Created by mgunes on 01.01.2017.
 */
public class AnnouncementPacketTest {
    private AnnouncementPacketDAO packetDAO;
    private List<org.db.model.AnnouncementPacket> packetList;

    @Before
    public void initialize() {
        packetDAO = new AnnouncementPacketHibernateImpl();
        packetList = new ArrayList<org.db.model.AnnouncementPacket>();
    }

    @Test
    public void getAvailablePacket() {
        packetList = packetDAO.getAvailablePackets();
        assertEquals(2, packetList.size());
    }

    @Test
    public void getPacketBySqlQuery() {
        String sql = "SELECT * FROM announcement_packet ORDER BY packet_id ASC; ";
        packetList = packetDAO.getPacketBySQLQuery(sql);
        assertEquals(5, packetList.get(0).getPacketId());
    }

    @Test
    public void getPacket() {
        AnnouncementPacket packet = packetDAO.getPacket(34);
        assertEquals(100, packet.getPrice());
    }
}
