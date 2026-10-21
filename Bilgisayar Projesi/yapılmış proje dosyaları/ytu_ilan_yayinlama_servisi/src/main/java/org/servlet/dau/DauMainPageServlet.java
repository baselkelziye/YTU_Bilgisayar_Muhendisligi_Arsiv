package org.servlet.dau;

import org.db.dao.NotificationDAO;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.model.Notification;
import org.db.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 29.01.2017.
 */
@WebServlet(name = "DauMainPageServlet", urlPatterns = {"/daumainpage"})
public class DauMainPageServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        User user = (User) session.getAttribute("user");

        //Bildirimleri getir
        NotificationDAO notificationDAO = new NotificationHibernateImpl();
        List<Notification> notificationList = notificationDAO.getMyNotifications(user.getUserName());
        session.setAttribute("notification", notificationList);

        response.sendRedirect("dau/index.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
