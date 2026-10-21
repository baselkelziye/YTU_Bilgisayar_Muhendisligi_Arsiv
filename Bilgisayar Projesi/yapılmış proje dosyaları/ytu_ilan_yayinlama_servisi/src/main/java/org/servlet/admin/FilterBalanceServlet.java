package org.servlet.admin;

import org.db.dao.AccountingDAO;
import org.db.hibernate.AccountingHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.Accounting;
import org.db.model.DonationAcceptUnit;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 04.12.2016.
 */
@WebServlet("/filterbalance")
public class FilterBalanceServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        AccountingDAO accDAO = new AccountingHibernateImpl();
        StringBuilder query = new StringBuilder();
        //query.append("SELECT * FROM accounting WHERE date_time BETWEEN ");
        query.append("SELECT * FROM accounting WHERE 1 = 1 ");

        List<DonationAcceptUnit> dauList = new ArrayList<DonationAcceptUnit>();

        try {
            //Date startDate = new SimpleDateFormat("dd/mm/yyyy").parse(request.getParameter("from"));
            //Date endDate = new SimpleDateFormat("dd/mm/yyyy").parse(request.getParameter("to"));
            String start = request.getParameter("from");
            String end = request.getParameter("to");

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
                    Date endDate = new SimpleDateFormat("dd/MM/yyyy").parse(end);
                    query.append(" AND date_time < '" + endDate + "' ");
                } catch (ParseException e) {
                    e.printStackTrace();
                }
            }

            String unitName = request.getParameter("department");

            if(!unitName.equals("Tüm Birimler")) {
                query.append(" AND unit_name = '" + unitName + "'");
                DonationAcceptUnit dau = new DauHibernateImpl().getUnit(unitName);
                dauList.add(dau);
            } else {
                dauList = new DauHibernateImpl().getAllUnits();
            }

            List<Accounting> acc = new AccountingHibernateImpl().getAccountingByQuery(query.toString());

            session.setAttribute("accountingquery", query.toString());
            session.setAttribute("dau", dauList);
            session.setAttribute("accounting", acc);
        } catch (Exception e) {
            e.printStackTrace();
        }

        response.sendRedirect("admin/muhasebe-kayitlari.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
