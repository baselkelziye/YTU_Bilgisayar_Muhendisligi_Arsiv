package org.servlet.admin.companyapproval;

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
import java.util.List;

/**
 * Created by mgunes on 28.01.2017.
 */
@WebServlet(name = "RejectCompanyServlet", urlPatterns = {"/rejectcompany"})
public class RejectCompanyServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String username = request.getParameter("username");

        CompanyDAO companyDAO = new CompanyHibernateImpl();

        if(companyDAO.deleteCompany(username)) {
            List<Company> companyList = companyDAO.getWaitingApproval();
            session.setAttribute("companyList", companyList);
            session.setAttribute("istek", 1);
        } else {
            session.setAttribute("istek", 2);
        }

        response.sendRedirect("admin/sirket-kayit-onay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
