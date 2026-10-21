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
 * Created by mgunes on 23.01.2017.
 */
@WebServlet(name = "ComplaintReportToAdminServlet", urlPatterns = {"/complaintreporttoadmin"})
public class ComplaintReportToAdminServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
        List<Announcement> annList = annDAO.getAvailableForReport();
        session.setAttribute("annList", annList);

        response.sendRedirect("admin/ceza-rapor-al.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
