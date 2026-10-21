package org.db.dao;

import java.util.List;
import java.util.Map;

import org.announcement.SearchCriteria;
import org.db.model.Announcement;

public interface AnnouncementDAO {
	boolean saveAnnouncement(Announcement ann);
    boolean updateAnnouncement(Announcement ann);
    boolean deleteAnnouncement(int id);
	List<Announcement> getAllAnnouncements();
	List<Announcement> getAnnouncementsOfCompany(String userName);
	List<Announcement> getActiveAnnouncements();
	List<Announcement> getByCriteria(SearchCriteria criteria);
	List<Announcement> getBySQLCriteria(String query);
    List<Announcement> getByCriteria(Map<String, Object> parameter);
	List<Announcement> getComplaintAnnouncement();
	Announcement getAnnouncement(int id);
	List<Announcement> getSuspendedAnnouncements();
	List<Announcement> getSuspendedOrderByName();
    List<Announcement> getSuspendedOrderByDate();
    List<Announcement> getRejectedComplaintList();
    List<Announcement> getAvailableForReport();
    List<Announcement> getAvailableForReport(String username);
    int republishByAdmin(int annId, String description);
    boolean repunishByAdmin(int annId, String description);
	boolean announcementSetNonVisible(int id);
    boolean announcementSetVisible(int id);

}
