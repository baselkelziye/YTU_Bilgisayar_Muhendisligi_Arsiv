package org.db.hibernate;

import org.db.dao.AnnouncementDAO;
import org.db.model.Announcement;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;

/**
 * Created by mgunes on 01.01.2017.
 */
public class AnnouncementTest {
    private List<Announcement> announcementList;
    private AnnouncementDAO announcementDAO;

    @Before
    public void initialize() {
        announcementList = new ArrayList<Announcement>();
        announcementDAO = new AnnouncementHibernateImpl();
    }

    @Test
    public void getAnnouncementsOfCompany() {
        announcementList = announcementDAO.getAnnouncementsOfCompany("sirket1");
        assertEquals(5, announcementList.size());
    }

    @Test
    public void getAnnouncement() {
        Announcement ann = new Announcement();
        ann = announcementDAO.getAnnouncement(11);
        assertEquals(12, ann.getOwnerPacket().getId());
    }

    @Test
    public void getBySQLCriteria() {
        String query = "SELECT * FROM announcement ORDER BY announcement_category;";
        announcementList = announcementDAO.getBySQLCriteria(query);
        assertEquals(2, announcementList.get(0).getCategory().getId());
    }
}
