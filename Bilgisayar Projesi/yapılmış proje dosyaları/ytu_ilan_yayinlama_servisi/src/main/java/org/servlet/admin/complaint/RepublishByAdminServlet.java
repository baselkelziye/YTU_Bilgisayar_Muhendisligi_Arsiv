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
@WebServlet(name = "RepublishByAdminServlet", urlPatterns = {"/republishbyadmin"})
public class RepublishByAdminServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        int annId = Integer.parseInt(request.getParameter("id"));
        String description = request.getParameter("description");

        AnnouncementDAO announcementDAO = new AnnouncementHibernateImpl();
        int iadeGun = announcementDAO.republishByAdmin(annId, description);

        if(iadeGun != -1) {
            session.setAttribute("yenidenyayin", 1);
            List<Announcement> suspendedAnnouncements = announcementDAO.getSuspendedAnnouncements();
            session.setAttribute("cezaliilanlar", suspendedAnnouncements);
            session.setAttribute("iadegun", iadeGun);

            Announcement announcement = new AnnouncementHibernateImpl().getAnnouncement(annId);
            //Bildirim şirket için
            Notification notification = new Notification(
                    "Sistem",
                    new User(announcement.getOwnerCompany().getUserName()),
                    (announcement.getTitle() + " başlıklı ilanınız yeniden yayına alındı. Ceza raporlarından detaya erişebilirsiniz."),
                    new Date(),
                    "positive"
            );
            new NotificationHibernateImpl().saveNotification(notification);

            //Bildirim öğrenci için
            for(Complaint complaint: announcement.getComplaintList()) {
                notification = new Notification(
                        "Admin",
                        new User(complaint.getStudent().getUserName()),
                        (complaint.getAnnouncement().getTitle() + " ilanı için yapmış olduğunuz şikayet olumsuz sonuçlandı."),
                        new Date(),
                        "negative"
                );
                new NotificationHibernateImpl().saveNotification(notification);
            }
        } else {
            session.setAttribute("yenidenyayin", 2);
        }

        response.sendRedirect("admin/onaylanan-sikayetler.jsp");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
