package org.servlet.company;

import org.db.dao.CompanyDAO;
import org.db.dao.UserDAO;
import org.db.hibernate.CompanyHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.Company;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 09.12.2016.
 */
@WebServlet(name = "UpdateCompanyPasswordServlet", urlPatterns = {"/updatecompanypassword"})
public class UpdateCompanyPasswordServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("guncelle", 0);
        session.setAttribute("parolaguncelle", 0);
        session.setAttribute("iletisimeklendi", 0);
        session.setAttribute("iletisimsil", 0);
        session.setAttribute("sirketguncelle", 0);

        Company user = (Company) session.getAttribute("user");

        String oldPassword = request.getParameter("oldPassword");
        String newPassword = request.getParameter("newPassword");

        if(!user.getPassword().equals(oldPassword)) {
            session.setAttribute("parolaguncelle", 2);
        } else {
            CompanyDAO userDAO = new CompanyHibernateImpl();
            user.setPassword(newPassword);
            userDAO.updateCompanyPassword(user);
            session.setAttribute("parolaguncelle", 1);
        }

        response.sendRedirect("company/profil-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
