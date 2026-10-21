package org.db.hibernate;

import org.db.dao.CompanyDAO;
import org.db.dao.ComplaintDAO;
import org.db.model.Announcement;
import org.db.model.Complaint;
import org.db.model.ComplaintReport;
import org.hibernate.Query;
import org.hibernate.Session;

import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 11.12.2016.
 */
public class ComplaintHibernateImpl extends AbstractDAO implements ComplaintDAO {
    private Session session;

    public boolean saveComplaint(Complaint complaint) {
        return save(complaint);
    }

    public boolean deleteComplaint(String username, int announcementID) {
        String query = "DELETE FROM complaint WHERE student = '" + username + "' and announcement = " + announcementID;
        return updateBySQLQuery(Complaint.class, query);
    }

    public boolean punishAnnouncement(int annID, String result, String resultReply) {
        session = HibernateSessionFactory.getSessionFactory().openSession();
        String annHql = "UPDATE Announcement SET state = 4 WHERE id = " + annID;
        String complaintHQL = "UPDATE Complaint SET result = '" + result + "', resultReply = '" + resultReply + "', " +
                " resultTime = '" + new Date() + "' WHERE announcement = " + annID;

        ComplaintReport report = new ComplaintReport();
        report.setAnnouncement(new Announcement(annID));
        report.setOperationDate(new Date());
        report.setDescription("İlan -" + resultReply + "- sebebi ile yayından kaldırıldı.");
        report.setCurrentState("cezalı");

        try {
            session.getTransaction().begin();
            Query query1 = session.createQuery(annHql);
            Query query2 = session.createQuery(complaintHQL);

            query1.executeUpdate();
            query2.executeUpdate();

            session.save(report);

            session.getTransaction().commit();

            return  true;
        } catch (Exception ex) {
            session.getTransaction().commit();
            System.out.println("Şikayet güncellenemedi:" + ex.getMessage());
            return false;
        } finally {
            session.close();
        }
    }

    public boolean rejectComplaint(int annID, String result, String resultReply) {
        session = HibernateSessionFactory.getSessionFactory().openSession();

        //şikayet tablosunu düzenle
        String complaintHQL = " UPDATE Complaint SET result = '" + result + "', resultReply = '" + resultReply + "', " +
                " resultTime = '" + new Date() + "' WHERE announcement = " + annID;

        //öğrencilere ceza puanı ekle
        String penaltyPoint = " UPDATE Student s SET s.penaltyPoint = s.penaltyPoint + 5 " +
                " WHERE s.userName in (SELECT s1.userName FROM Complaint c, Student s1 WHERE c.student = s1.userName and c.announcement = " + annID + ")";

        //ilanı şikayet edilemez yap
        String proper = "UPDATE Announcement SET properComplaint = false WHERE id = " + annID;

        try {
            session.getTransaction().begin();
            Query query1 = session.createQuery(complaintHQL);
            Query query2 = session.createQuery(penaltyPoint);
            Query query3 = session.createQuery(proper);
            query1.executeUpdate();
            query2.executeUpdate();
            query3.executeUpdate();
            session.getTransaction().commit();
            return  true;
        } catch (Exception ex) {
            session.getTransaction().commit();
            System.out.println("Şikayet güncellenemedi(ret):" + ex.getMessage());
            return false;
        } finally {
            session.close();
        }
    }

    public List<Complaint> getComplaintBySQLQuery(String sql) {
        return getRowsBySQLQuery(Complaint.class, sql);
    }
}
