package org.db.dao;

import org.db.model.Complaint;

import java.util.List;

/**
 * Created by mgunes on 11.12.2016.
 */
public interface ComplaintDAO {
    boolean saveComplaint(Complaint complaint);
    boolean deleteComplaint(String username, int announcementID);
    boolean punishAnnouncement(int annID, String result, String resultReply);
    boolean rejectComplaint(int annID, String result, String resultReply);
    List<Complaint> getComplaintBySQLQuery(String sql);
}
