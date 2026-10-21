package org.servlet.admin.complaint;

import org.db.dao.AnnouncementDAO;
import org.db.dao.ComplaintDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.ComplaintHibernateImpl;
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
 * Created by mgunes on 12.12.2016.
 */
@WebServlet(name = "ComplaintlListToAdminServlet", urlPatterns = {"/complaintlisttoadmin"})
public class ComplaintlListToAdminServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
        List<Announcement> complaintAnnouncementList = annDAO.getComplaintAnnouncement();
        session.setAttribute("sikayetilan", complaintAnnouncementList);

        session.setAttribute("ceza", 0);
        response.sendRedirect("admin/sikayet-edilen-ilanlar.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
