package org.servlet.company;

import org.db.dao.CompanyDAO;
import org.db.hibernate.CompanyHibernateImpl;
import org.db.model.Company;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 24.12.2016.
 */
@WebServlet(name = "UpdateCompanyInfoServlet", urlPatterns = {"/updatecompanyinfo"})
public class UpdateCompanyInfoServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("guncelle", 0);
        session.setAttribute("parolaguncelle", 0);
        session.setAttribute("iletisimeklendi", 0);
        session.setAttribute("iletisimsil", 0);
        session.setAttribute("iletisimguncelle", 0);
        session.setAttribute("sirketguncelle", 0);

        String companyName = request.getParameter("companyName");
        String location = request.getParameter("location");

        Company company = (Company) session.getAttribute("user");
        company.setCompanyName(companyName);
        company.setLocation(location);

        CompanyDAO userDAO = new CompanyHibernateImpl();

        if(userDAO.updateCompanyUser(company)) {
            session.setAttribute("sirketguncelle", 1);
            session.setAttribute("user", company);
        } else {
            session.setAttribute("sirketguncelle", 2);
        }

        response.sendRedirect("company/profil-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
