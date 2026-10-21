package org.servlet.company.complaint;

import org.db.dao.AnnouncementDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.model.Announcement;
import org.db.model.Company;

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
@WebServlet(name = "ComplaintReportToCompanyServlet", urlPatterns = {"/complaintreporttocompany"})
public class ComplaintReportToCompanyServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        Company company = (Company) session.getAttribute("user");
        AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
        List<Announcement> annList = annDAO.getAvailableForReport(company.getUserName());
        session.setAttribute("annList", annList);

        response.sendRedirect("company/ceza-rapor-al.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
