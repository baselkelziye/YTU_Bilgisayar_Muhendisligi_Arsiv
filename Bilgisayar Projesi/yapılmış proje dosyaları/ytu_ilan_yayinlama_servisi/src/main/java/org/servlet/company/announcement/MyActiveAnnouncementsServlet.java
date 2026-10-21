package org.servlet.company.announcement;

import org.db.dao.CompanyDAO;
import org.db.hibernate.CompanyHibernateImpl;
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
 * Created by mgunes on 25.01.2017.
 */
@WebServlet(name = "MyActiveAnnouncementsServlet", urlPatterns = {"/myactiveannouncements"})
public class MyActiveAnnouncementsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("gorunur", 0);
        session.setAttribute("gorunmez", 0);
        Company company = (Company) session.getAttribute("user");

        CompanyDAO companyDAO = new CompanyHibernateImpl();
        List<Announcement> announcementList = companyDAO.getMyActiveAnnouncements(company.getUserName());
        session.setAttribute("announcements", announcementList);

        response.sendRedirect("company/aktif-ilanlarim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
