package org.servlet.company;

import com.sun.org.apache.regexp.internal.RE;
import org.db.dao.CompanyDAO;
import org.db.dao.UserDAO;
import org.db.hibernate.CompanyHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.Company;
import org.db.model.User;

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
@WebServlet(name = "UpdateCompanyUserServlet", urlPatterns = {"/updatecompanyuser"})
public class UpdateCompanyUserServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();
        session.setAttribute("guncelle", 0);
        session.setAttribute("parolaguncelle", 0);
        session.setAttribute("iletisimeklendi", 0);
        session.setAttribute("iletisimsil", 0);
        session.setAttribute("sirketguncelle", 0);

        Company company = (Company) session.getAttribute("user");
        company.setContactMail(request.getParameter("contactMail"));
        company.setContactTel(request.getParameter("contactTel"));
        company.setName(request.getParameter("name"));
        company.setSurname(request.getParameter("surname"));

        CompanyDAO userDAO = new CompanyHibernateImpl();

        if(userDAO.updateCompanyUser(company)) {
            session.setAttribute("guncelle", 1);
            session.setAttribute("user", company);
        } else {
            session.setAttribute("guncelle", 2);
        }

        response.sendRedirect("company/profil-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
