package org.servlet.admin;

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
 * Created by mgunes on 18.12.2016.
 */
@WebServlet(name = "ListAnnouncementsToAdminServlet", urlPatterns = {"/listannouncementstoadmin"})
public class ListAnnouncementsToAdminServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //Aktif ve cezalı ilanları admin için listele
        AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
        List<Announcement> activeAnn = annDAO.getActiveAnnouncements();
        List<Announcement> suspendedAnn = annDAO.getSuspendedAnnouncements();

        HttpSession session = request.getSession();
        session.setAttribute("activeAnnList", activeAnn);
        session.setAttribute("suspendedAnnList", suspendedAnn);

        response.sendRedirect("admin/ilanlar.jsp");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
