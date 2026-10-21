package org.servlet.dau;

import org.db.dao.UserDAO;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.DauUser;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 08.12.2016.
 */
@WebServlet(name = "UpdateDauPasswordServlet", urlPatterns = {"/updatedaupassword"})
public class UpdateDauPasswordServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        DauUser user = (DauUser) session.getAttribute("user");
        String oldPassword = request.getParameter("oldPassword");
        String newPassword = request.getParameter("newPassword");

        if(!user.getPassword().equals(oldPassword)) {
            session.setAttribute("parolaguncelle", 2);
        } else {
            UserDAO userDAO = new UserHibernateImpl();
            user.setPassword(newPassword);
            userDAO.update(user);
            session.setAttribute("parolaguncelle", 1);
        }

        response.sendRedirect("dau/kisisel-bilgilerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
