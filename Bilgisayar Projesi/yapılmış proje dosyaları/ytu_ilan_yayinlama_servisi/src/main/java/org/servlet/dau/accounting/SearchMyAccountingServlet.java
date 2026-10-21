package org.servlet.dau.accounting;

import org.db.dao.AccountingDAO;
import org.db.hibernate.AccountingHibernateImpl;
import org.db.model.Accounting;
import org.db.model.DauUser;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 12.01.2017.
 */
@WebServlet(name = "SearchMyAccountingServlet", urlPatterns = {"/searchmyaccounting"})
public class SearchMyAccountingServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String userName = request.getParameter("username");
        String type = request.getParameter("type");
        String start = request.getParameter("from");
        String end = request.getParameter("to");

        StringBuilder query = new StringBuilder();
        query.append("SELECT * FROM accounting WHERE 1 = 1 ");

        if(!userName.equals("all")) {
            query.append(" AND user_name = '" + userName + "' ");
        } else {
            DauUser dauUser = (DauUser) session.getAttribute("user");
            query.append(" AND unit_name = '" + dauUser.getDau().getUnitName() + "' ");
        }

        if(type.equals("spent")) {
            query.append(" AND amount < 0 ");
        } else if(type.equals("accept")) {
            query.append(" AND amount > 0 ");
        }

        if(start != null) {
            try {
                Date startDate = new SimpleDateFormat("dd/MM/yyyy").parse(start);
                query.append(" AND date_time > '" + startDate + "' ");
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }

        if(end != null) {
            try {
                Date endDate = new SimpleDateFormat("dd/MM/yyyy").parse(start);
                query.append(" AND date_time > '" + endDate + "' ");
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }

        session.setAttribute("searchaccountingquery", query.toString());

        AccountingDAO accountingDAO = new AccountingHibernateImpl();
        List<Accounting> accountingList = accountingDAO.getAccountingByQuery(query.toString());
        session.setAttribute("accounting", accountingList);

        response.sendRedirect("dau/muhasebe-kayitlari.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
