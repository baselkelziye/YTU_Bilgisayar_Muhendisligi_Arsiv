package org.servlet.admin.complaint;

import org.db.dao.ComplaintDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.ComplaintHibernateImpl;
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
 * Created by mgunes on 14.12.2016.
 */
@WebServlet(name = "AcceptComplaintServlet", urlPatterns = {"/acceptcomplaint"})
public class AcceptComplaintServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session  = request.getSession();
        session.setAttribute("ret", 0);
        request.setCharacterEncoding("UTF-8");

        int annId = Integer.parseInt(request.getParameter("annID"));
        String result = "Olumlu";
        String resultReply = request.getParameter("resultReply");

        ComplaintDAO complaintDAO = new ComplaintHibernateImpl();

        if(complaintDAO.punishAnnouncement(annId, result, resultReply)) {
            session.setAttribute("ceza", 1);
            List<Announcement> complaintAnnouncementList = new AnnouncementHibernateImpl().getComplaintAnnouncement();
            session.setAttribute("sikayetilan", complaintAnnouncementList);

            Announcement announcement = new AnnouncementHibernateImpl().getAnnouncement(annId);
            //Bildirim şirket için
            Notification notification = new Notification(
                    "Sistem",
                    new User(announcement.getOwnerCompany().getUserName()),
                    (announcement.getTitle() + " başlıklı ilanınız yayından kaldırıldı Ceza raporlarından detaya erişebilirsiniz."),
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
                        "info"
                );
                new NotificationHibernateImpl().saveNotification(notification);
            }

        } else {
            session.setAttribute("ceza", 2);
        }

        response.sendRedirect("admin/sikayet-edilen-ilanlar.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
