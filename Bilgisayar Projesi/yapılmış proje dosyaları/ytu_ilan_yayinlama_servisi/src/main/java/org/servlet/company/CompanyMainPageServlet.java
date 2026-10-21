package org.servlet.company;

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
@WebServlet(name = "CompanyMainPageServlet", urlPatterns = {"/companymainpage"})
public class CompanyMainPageServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        User user = (User) session.getAttribute("user");

        //Bildirimleri getir
        NotificationDAO notificationDAO = new NotificationHibernateImpl();
        List<Notification> notificationList = notificationDAO.getMyNotifications(user.getUserName());
        session.setAttribute("notification", notificationList);

        response.sendRedirect("company/index.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
