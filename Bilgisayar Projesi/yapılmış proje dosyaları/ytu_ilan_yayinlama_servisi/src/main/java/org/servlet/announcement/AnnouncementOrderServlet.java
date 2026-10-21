package org.servlet.announcement;

import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.model.Announcement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 10.12.2016.
 */
@WebServlet(name = "AnnouncementOrderServlet", urlPatterns = {"/announcementorder"})
public class AnnouncementOrderServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String order = request.getParameter("condition");
        String type = request.getParameter("type");
        StringBuilder query = new StringBuilder();
        query.append(session.getAttribute("searchannouncementquery"));
        query.append(" ORDER BY " + order + " " + type);
        List<Announcement> annList = new AnnouncementHibernateImpl().getActiveAnnouncements(query.toString());

        session.setAttribute("announcements", annList);
        response.sendRedirect("student/ilan-ara.jsp");
    }

    public static class AnnouncementComparator implements Comparator<Announcement> {
        public int compare(Announcement a1, Announcement a2) {
            return a1.compareTo(a2);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
