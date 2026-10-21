package org.servlet.company.announcement;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.dao.AnnouncementTypeDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.AnnouncementTypeHibernateImpl;
import org.db.model.Announcement;
import org.db.model.AnnouncementCategory;
import org.db.model.AnnouncementType;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by mgunes on 28.01.2017.
 */
@WebServlet(name = "UpdateAnnouncementServlet", urlPatterns = {"/updateannouncement"})
public class UpdateAnnouncementServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        int id = Integer.parseInt(request.getParameter("annId"));
        Announcement announcement = new AnnouncementHibernateImpl().getAnnouncement(id);
        session.setAttribute("announcement", announcement);

        List<AnnouncementType> annType = new ArrayList<AnnouncementType>();
        AnnouncementTypeDAO annTypeDAO = new AnnouncementTypeHibernateImpl();
        AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
        List<AnnouncementCategory> categoryList = categoryDAO.getParentCategories();

        annType = annTypeDAO.getAllAnnouncementTypes();
        session.setAttribute("categoryList", categoryList);
        session.setAttribute("annType", annType);
        session.setAttribute("guncellendi", 0);

        response.sendRedirect("company/ilan-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
