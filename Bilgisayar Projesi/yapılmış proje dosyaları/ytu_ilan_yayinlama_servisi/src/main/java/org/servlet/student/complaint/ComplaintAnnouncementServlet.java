package org.servlet.student.complaint;

import org.db.dao.ComplaintDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.ComplaintHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Date;

/**
 * Created by mgunes on 11.12.2016.
 */
@WebServlet(name = "ComplaintAnnouncementServlet", urlPatterns = {"/complaintannouncement"})
public class ComplaintAnnouncementServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("basvuruldu", 0);

        int announcementID = Integer.parseInt(request.getParameter("announcementId"));
        Announcement announcement = new AnnouncementHibernateImpl().getAnnouncement(announcementID);
        Student student = (Student) session.getAttribute("user");
        String description = request.getParameter("complaintDescription");

        Complaint complaint = new Complaint();
        complaint.setStudent(student);
        complaint.setAnnouncement(announcement);
        complaint.setDescription(description);
        complaint.setComplaintTime(new Date());

        ComplaintDAO complaintDAO = new ComplaintHibernateImpl();

        if(complaintDAO.saveComplaint(complaint)) {
            session.setAttribute("sikayetedildi", 1);
            session.setAttribute("sikayetvar", 1);
            student = (Student) new UserHibernateImpl().getUser(student.getUserName());
            session.setAttribute("user", student);

            //Bildirim
            Notification notification = new Notification(
                    student.getUserName(),
                    new User("admin"),
                    (announcement.getTitle() + " başlıklı ilan şikayet edildi."),
                    new Date(),
                    "info"
            );
            new NotificationHibernateImpl().saveNotification(notification);

        } else {
            session.setAttribute("sikayetedildi", 2);
        }

        response.sendRedirect("student/ilan-detay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
