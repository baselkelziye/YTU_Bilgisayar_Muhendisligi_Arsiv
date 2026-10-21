package org.db.hibernate;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.announcement.SearchCriteria;
import org.db.dao.AnnouncementDAO;
import org.db.model.Announcement;
import org.db.model.AnnouncementType;
import org.db.model.ComplaintReport;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import javax.servlet.http.HttpSession;

public class AnnouncementHibernateImpl extends AbstractDAO implements AnnouncementDAO {
	private Session session;

	public List<AnnouncementType> getAllAnnouncementsTypes() {
		return getAllRows(AnnouncementType.class);
	}

	public boolean saveAnnouncement(Announcement ann) {
		return justSave(ann);
	}

	public List<Announcement> getAllAnnouncements() {
		return getAllRows(Announcement.class);
	}

	public List<Announcement> getAnnouncementsOfCompany(String userName) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.getTransaction().begin();
			String query = " SELECT *  FROM announcement where owner_company = '" + userName + "';";
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(Announcement.class);
			List<Announcement> annList = sqlQuery.list();
			session.getTransaction().commit();
			return annList;
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("Şirket ilanları getirilemedi:" + ex.getMessage());
			return null;
		} finally {
			session.close();
		}
	}

	public Announcement getAnnouncement(int id) {
		return (Announcement) getObject(Announcement.class, id);
	}

	public boolean updateAnnouncement(Announcement ann) {
		return save(ann);
	}

    public boolean deleteAnnouncement(int id) {
        return deleteByQuery(Announcement.class, "Announcement", "id", id);
    }

    public List<Announcement> getSuspendedAnnouncements() {
        String hql = "FROM Announcement WHERE state = 4";
        return getRowsByQuery(Announcement.class, hql, new HashMap<String, Object>());
    }

	public List<Announcement> getSuspendedOrderByName() {
		String hql = "FROM Announcement WHERE state = 4 ORDER BY ownerCompany";
		return getRowsByQuery(Announcement.class, hql, new HashMap<String, Object>());
	}

	public List<Announcement> getSuspendedOrderByDate() {
        String hql = "FROM Announcement WHERE state = 4 ORDER BY ownerCompany";
        return getRowsByQuery(Announcement.class, hql, new HashMap<String, Object>());
	}

    public List<Announcement> getRejectedComplaintList() {
        String sql = "SELECT * FROM announcement where (state = 2 or state = 3) and proper_complaint = false";
        return getRowsBySQLQuery(Announcement.class, sql);
    }

    public List<Announcement> getAvailableForReport() {
        String sql = "select distinct a.* from announcement a, complaint_report c where a.id = c.announcement ";
        return getRowsBySQLQuery(Announcement.class, sql);
    }

    public List<Announcement> getAvailableForReport(String username) {
        String sql = "select distinct a.* " +
                " from announcement a, complaint_report c " +
                " where a.id = c.announcement and a.owner_company = '" + username + "' ";
        return getRowsBySQLQuery(Announcement.class, sql);
    }

    public int republishByAdmin(int annId, String description) {
	    //durumu aktif yap ve kayıp günleri ekle, şikayet edilemez yap
	    String updateExpiredDate = "update announcement a set expired_date = ( " +
                " select (current_timestamp - operation_date)  + a.expired_date " +
                " from complaint_report " +
                " where announcement = " + annId + " and current_state = 'cezalı' " +
                " order by operation_date desc LIMIT 1), state = 2, proper_complaint = FALSE " +
                " where id  = " + annId + ";";

        //now - operation date i döndür
        String operationDate = "select operation_date " +
            " from complaint_report " +
            " where announcement = " + annId + " and current_state = 'cezalı' " +
            " order by operation_date desc LIMIT 1 ";

        //Şikayet eden öğrenciler için son durum
        String complaintStudent = "update complaint " +
            " set result = 'Olumsuz', result_time = now(), result_reply = '" + description + "' " +
            " where announcement = " + annId + "; ";

        //rapora ekleme yap
        ComplaintReport complaintReport = new ComplaintReport();
        complaintReport.setCurrentState("yayında");
        complaintReport.setOperationDate(new Date());
        complaintReport.setAnnouncement(new Announcement(annId));

        //ilan bilgilerini güncelle
        //raporu kaydet
        //kayıp gün sayınısı bul

        //AÇIKLAMAYA xx gün iade edildi diye ekle !!!

        //şikayet listesindeki durumun değiştirilmesi lazım

		try {
            int iadeGun = -1;

            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();
            SQLQuery query1 = session.createSQLQuery(updateExpiredDate);
            query1.executeUpdate();

            SQLQuery query2 = session.createSQLQuery(complaintStudent);
            query2.executeUpdate();

            List list = session.createSQLQuery(operationDate).list();
            Date date = (Date) list.get(0);
            iadeGun = (int) (new Date().getTime() - date.getTime()) / 1000 / 60 / 60 /24;

            complaintReport.setDescription("İlan tekrar yayına alındı. Son yayın tarihine " + iadeGun +
                    " gün eklendi. Yapılan açıklama : " + description);

            session.save(complaintReport);
            session.getTransaction().commit();
            return iadeGun;
		} catch (Exception ex) {
		    session.getTransaction().rollback();
            System.out.println("Yeniden yayına alınırken hata : " + ex.getMessage());
            ex.printStackTrace();
            return -1;
        } finally {
            session.close();
        }
    }

    public boolean repunishByAdmin(int annId, String description) {
        //şikayet eden öğrencilerin durumu güncellenecek
        //rapora kayıt eklenecek

        String q1 = "UPDATE announcement SET state = 4 WHERE id = " + annId + "; ";
        String q2 = "update complaint " +
                " set result = 'Olumlu', result_time = now(), result_reply = '" + description + "' " +
                " where announcement = " + annId + "; ";

        ComplaintReport complaintReport = new ComplaintReport();
        complaintReport.setAnnouncement(new Announcement(annId));
        complaintReport.setOperationDate(new Date());
        complaintReport.setCurrentState("cezalı");
        complaintReport.setDescription("İlan cezalı duruma getirildi. Açıklama: " + description + " ");

        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();
            SQLQuery sqlQuery = session.createSQLQuery(q1);
            SQLQuery sqlQuery1 = session.createSQLQuery(q2);
            sqlQuery.executeUpdate();
            sqlQuery1.executeUpdate();
            session.save(complaintReport);
            session.getTransaction().commit();
            return true;
        } catch (Exception ex) {
            session.getTransaction().rollback();
            System.out.println("Repunish hata : " + ex.getMessage());
            ex.printStackTrace();
            return false;
        } finally {
            session.close();
        }
    }

	public boolean announcementSetNonVisible(int id) {
		String query = "UPDATE announcement SET visibility = false WHERE id = " + id + ";";
		return updateBySQLQuery(Announcement.class, query);
	}

    public boolean announcementSetVisible(int id) {
        String query = "UPDATE announcement SET visibility = true WHERE id = " + id + ";";
        return updateBySQLQuery(Announcement.class, query);
    }

	public List<Announcement> getActiveAnnouncements() {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.getTransaction().begin();
			String query = "SELECT * FROM announcement WHERE now() BETWEEN publish_date AND expired_date";
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(Announcement.class);
			List<Announcement> annList = sqlQuery.list();
			session.getTransaction().commit();
			return annList;
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("Aktif ilanlar getirilemedi:" + ex.getMessage());
			return null;
		} finally {
			session.close();
		}
	}

	public List<Announcement> getActiveAnnouncements(String sql) {
		return  getRowsBySQLQuery(Announcement.class, sql);
	}

	public List<Announcement> getByCriteria(SearchCriteria criteria) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			String query = "SELECT * FROM announcement " +
					"WHERE announcement_type = " + criteria.getTypeId() + " AND announcement_category = " + criteria.getCategoryId() + 
					" AND announcement_language = " + "'" + criteria.getLanguage() + "';";
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(Announcement.class);
			List<Announcement> annList = sqlQuery.list();
			session.getTransaction().commit();
			return annList;
		} catch (Exception e) {
			session.getTransaction().rollback();
			System.out.println("Kritere göre ilan filtreleme işlemi başarısız: " + e.getMessage());
			return null;
		} finally {
			session.close();
		}
	}

	public List<Announcement> getBySQLCriteria(String query) {
		return getRowsBySQLQuery(Announcement.class, query);
	}

	public List<Announcement> getByCriteria(Map<String, Object> parameter) {
	    String sql = "SELECT * from announcement";

	    if(parameter.size() != 0) {
            sql += " WHERE";
            for(String s: parameter.keySet()) {
                sql += " " + s + " = " + parameter.get(s) + " and ";
            }

            sql = sql.substring(0, sql.length() - 4); //son and i sil
        }

		return getRowsBySQLQuery(Announcement.class, sql);
	}

	public List<Announcement> getComplaintAnnouncement() {
		String sql = "SELECT a.id, a.title, a.brief, a.content, a.number_of_page_views, a.state, a.owner_company, a.owner_packet, a.proper_complaint, " +
                "a.announcement_type, a.announcement_language, a.announcement_category, a.announcement_language, a.publish_date, a.visibility, " +
				" proper_complaint, expired_date " +
                "FROM announcement a, complaint c " +
                "WHERE a.state = 2 and c.announcement = a.id and a.proper_complaint = TRUE " +
                "group by a.id;";

		return getRowsBySQLQuery(Announcement.class, sql);
	}

}
