package org.servlet.admin.complaint;

import org.db.dao.AnnouncementDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.model.Announcement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 21.01.2017.
 */
@WebServlet(name = "AcceptedComplaintListServlet", urlPatterns = {"/acceptedcomplaintlist"})
public class AcceptedComplaintListServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        AnnouncementDAO announcementDAO = new AnnouncementHibernateImpl();
        List<Announcement> suspendedAnnouncements = announcementDAO.getSuspendedAnnouncements();

        session.setAttribute("yenidenyayin", 0);
        session.setAttribute("cezaliilanlar", suspendedAnnouncements);

        response.sendRedirect("admin/onaylanan-sikayetler.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
