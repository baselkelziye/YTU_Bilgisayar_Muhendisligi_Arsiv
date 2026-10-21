package org.servlet.company.announcement;

import org.db.dao.AnnouncementDAO;
import org.db.hibernate.AnnouncementHibernateImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 25.01.2017.
 */
@WebServlet(name = "DeleteAnnouncementServlet", urlPatterns = {"/deleteannouncement"})
public class DeleteAnnouncementServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("ilanaktif", 0);
        int id = Integer.parseInt(request.getParameter("annId"));

        AnnouncementDAO announcementDAO = new AnnouncementHibernateImpl();

        if(announcementDAO.deleteAnnouncement(id)) {
            session.setAttribute("ilansil", 1);
        } else {
            session.setAttribute("ilansil", 2);
        }

        response.sendRedirect("mypassiveannouncements");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
