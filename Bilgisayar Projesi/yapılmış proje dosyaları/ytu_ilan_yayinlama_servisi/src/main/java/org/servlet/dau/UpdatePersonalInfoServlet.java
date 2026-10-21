package org.servlet.dau;

import org.db.dao.DauUserDAO;
import org.db.dao.DonationAcceptUnitDAO;
import org.db.dao.UserDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.DauUserHibernateImpl;
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
@WebServlet(name = "UpdatePersonalInfoServlet", urlPatterns = {"/updatedaupersonalinfo"})
public class UpdatePersonalInfoServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        DauUser dauUser = (DauUser) session.getAttribute("user");
        dauUser.setName(request.getParameter("name").trim());
        dauUser.setSurname(request.getParameter("surname").trim());
        dauUser.setContactMail(request.getParameter("contactMail").trim());
        dauUser.setContactTel(request.getParameter("contactTel").trim());

        UserDAO dauDAO = new UserHibernateImpl();

        if(dauDAO.update(dauUser)) {
            session.setAttribute("guncelle", 1);
            session.setAttribute("user", dauUser);
        } else {
            session.setAttribute("guncelle", 2);
        }

        response.sendRedirect("dau/kisisel-bilgilerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
