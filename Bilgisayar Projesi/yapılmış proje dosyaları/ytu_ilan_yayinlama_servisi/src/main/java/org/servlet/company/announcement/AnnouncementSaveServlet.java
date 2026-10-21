package org.servlet.company.announcement;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.dao.AnnouncementStateDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.AnnouncementStateHibernateImpl;
import org.db.model.Announcement;
import org.db.model.AnnouncementState;
import org.db.model.AnnouncementType;
import org.db.model.Company;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 28.01.2017.
 */
@WebServlet(name = "AnnouncementSaveServlet", urlPatterns = {"/announcementsave"})
public class AnnouncementSaveServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();

        int id = Integer.parseInt(request.getParameter("id"));
        Announcement announcement = new AnnouncementHibernateImpl().getAnnouncement(id);

        announcement.setTitle(request.getParameter("title"));
        announcement.setBrief(request.getParameter("brief"));
        announcement.setContent(request.getParameter("content"));
        announcement.setAnnouncementLanguage(request.getParameter("language"));

        AnnouncementType annType = new AnnouncementType();
        annType.setId(Integer.parseInt(request.getParameter("type")));
        announcement.setAnnouncementType(annType);

        AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
        announcement.setCategory(categoryDAO.getCategory(Integer.parseInt(request.getParameter("category"))));
        announcement.setOwnerCompany((Company)session.getAttribute("user"));
        announcement.setProperComplaint(true);

        if(new AnnouncementHibernateImpl().updateAnnouncement(announcement)) {
            session.setAttribute("guncellendi", 1);
            announcement = new AnnouncementHibernateImpl().getAnnouncement(id);
            session.setAttribute("announcement", announcement);
        }
        else {
            session.setAttribute("guncellendi", 2);
        }

        response.sendRedirect("company/ilan-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }

}
