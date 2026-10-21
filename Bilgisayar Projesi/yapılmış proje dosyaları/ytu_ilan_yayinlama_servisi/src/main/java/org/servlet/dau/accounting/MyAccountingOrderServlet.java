package org.servlet.dau.accounting;

import org.db.dao.AccountingDAO;
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
 * Created by mgunes on 12.01.2017.
 */
@WebServlet(name = "MyAccountingOrderServlet", urlPatterns = {"/myaccountingorder"})
public class MyAccountingOrderServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String query = (String) session.getAttribute("searchaccountingquery");

        String condition = request.getParameter("condition");
        String type = request.getParameter("type");

        query += " order by " + condition + " " + type + " ";

        AccountingDAO accountingDAO = new AccountingHibernateImpl();
        List<Accounting> accountingList = accountingDAO.getAccountingByQuery(query.toString());
        session.setAttribute("accounting", accountingList);

        response.sendRedirect("dau/muhasebe-kayitlari.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
