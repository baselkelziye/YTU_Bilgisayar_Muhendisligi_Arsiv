package org.servlet.admin.complaint;

import org.db.dao.AnnouncementDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.model.Announcement;
import org.db.model.Complaint;
import org.db.model.Notification;
import org.db.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 23.01.2017.
 */
@WebServlet(name = "RepunishByAdminServlet", urlPatterns = {"/repunishbyadmin"})
public class RepunishByAdminServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        int annId = Integer.parseInt(request.getParameter("id"));
        String description = request.getParameter("description");

        AnnouncementDAO announcementDAO = new AnnouncementHibernateImpl();

        if(announcementDAO.repunishByAdmin(annId, description)) {
            List<Announcement> rejectedList = announcementDAO.getRejectedComplaintList();
            session.setAttribute("retsikayet", rejectedList);
            session.setAttribute("yayindankaldir", 1);

            Announcement announcement = new AnnouncementHibernateImpl().getAnnouncement(annId);
            //Bildirim şirket için
            Notification notification = new Notification(
                    "Sistem",
                    new User(announcement.getOwnerCompany().getUserName()),
                    (announcement.getTitle() + " başlıklı ilanınız yayından kaldırıldı. Ceza raporlarından detaya erişebilirsiniz."),
                    new Date(),
                    "negative"
            );
            new NotificationHibernateImpl().saveNotification(notification);

            //Bildirim öğrenci için
            for(Complaint complaint: announcement.getComplaintList()) {
                notification = new Notification(
                        "Admin",
                        new User(complaint.getStudent().getUserName()),
                        (complaint.getAnnouncement().getTitle() + " ilanı için yapmış olduğunuz şikayet olumlu sonuçlandı."),
                        new Date(),
                        "positive"
                );
                new NotificationHibernateImpl().saveNotification(notification);
            }
        } else {
            session.setAttribute("yayindankaldir", 2);
        }

        response.sendRedirect("admin/reddedilen-sikayetler.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
