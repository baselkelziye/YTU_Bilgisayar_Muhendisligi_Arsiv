package org.servlet.admin.complaint;

import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.model.Announcement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 23.01.2017.
 */
@WebServlet(name = "ReportAnnouncementServlet", urlPatterns = {"/reportannouncement"})
public class ReportAnnouncementServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        int id = Integer.parseInt(request.getParameter("id"));
        Announcement announcement = new AnnouncementHibernateImpl().getAnnouncement(id);
        session.setAttribute("reportList", announcement.getReports());
        session.setAttribute("announcement", announcement);
        response.sendRedirect("admin/report-detail.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
