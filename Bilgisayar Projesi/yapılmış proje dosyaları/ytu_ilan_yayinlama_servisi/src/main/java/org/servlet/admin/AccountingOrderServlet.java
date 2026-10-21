package org.servlet.admin;

import org.db.hibernate.AccountingHibernateImpl;
import org.db.model.Accounting;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 25.12.2016.
 */
@WebServlet(name = "AccountingOrderServlet", urlPatterns = {"/accountingorder"})
public class AccountingOrderServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        StringBuilder query = new StringBuilder();
        query.append((String) session.getAttribute("accountingquery"));
        String order = request.getParameter("condition");
        String type = request.getParameter("type");

        query.append(" ORDER BY " + order + " " + type);
        List<Accounting> acc = new AccountingHibernateImpl().getAccountingByQuery(query.toString());
        session.setAttribute("accounting", acc);

        response.sendRedirect("admin/muhasebe-kayitlari.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
