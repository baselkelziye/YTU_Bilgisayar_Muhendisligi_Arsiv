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
 * Created by mgunes on 20.12.2016.
 */
@WebServlet(name = "SuspendedOrderByNameServlet", urlPatterns = {"/suspendedorderbyname"})
public class SuspendedOrderByNameServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
        HttpSession session = request.getSession();
        List<Announcement> suspendedOrdered = annDAO.getSuspendedOrderByName();
        session.setAttribute("suspendedAnnList", suspendedOrdered);

        response.sendRedirect("admin/ilanlar.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
