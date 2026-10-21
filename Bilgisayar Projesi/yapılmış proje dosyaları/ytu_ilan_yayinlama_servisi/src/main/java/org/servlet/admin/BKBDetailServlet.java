package org.servlet.admin;

import org.db.dao.CurrencyDAO;
import org.db.hibernate.CurrencyHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.Currency;
import org.db.model.DonationAcceptUnit;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 22.12.2016.
 */
@WebServlet(name = "BKBDetailServlet", urlPatterns = {"/bkbdetail"})
public class BKBDetailServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String unitName = request.getParameter("dauName");

        DauHibernateImpl dauHibernate = new DauHibernateImpl();
        DonationAcceptUnit dau = dauHibernate.getUnit(unitName);

        HttpSession session = request.getSession();
        CurrencyDAO currencyDAO = new CurrencyHibernateImpl();
        List<Currency> currency = currencyDAO.getAllCurrencies();
        session.setAttribute("curr", currency);
        session.setAttribute("dau", dau);

        session.setAttribute("kullanicisil", 0);
        session.setAttribute("hesapeklendi", 0);
        session.setAttribute("kullanicieklendi", 0);
        session.setAttribute("hesapsil", 0);
        session.setAttribute("hesapguncellendi", 0);

        response.sendRedirect("admin/bkb-detay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
