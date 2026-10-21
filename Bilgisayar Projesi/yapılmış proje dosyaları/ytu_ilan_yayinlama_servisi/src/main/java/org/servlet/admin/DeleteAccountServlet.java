package org.servlet.admin;

import org.db.dao.BankAccountDAO;
import org.db.hibernate.BankAccountHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.DonationAcceptUnit;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 22.12.2016.
 */
@WebServlet(name = "DeleteAccountServlet", urlPatterns = {"/deleteaccount"})
public class DeleteAccountServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String iban = request.getParameter("iban");

        BankAccountDAO bankAccountDAO = new BankAccountHibernateImpl();

        if(bankAccountDAO.deleteAccount(iban)) {
            DonationAcceptUnit dau = (DonationAcceptUnit) session.getAttribute("dau");
            dau = new DauHibernateImpl().getUnit(dau.getUnitName());
            session.setAttribute("dau", dau);
            session.setAttribute("hesapsil", 1);
        } else {
            session.setAttribute("hesapsil", 2);
        }

        session.setAttribute("kullanicisil", 0);
        session.setAttribute("hesapeklendi", 0);
        session.setAttribute("kullanicieklendi", 0);
        session.setAttribute("hesapguncellendi", 0);

        response.sendRedirect("admin/bkb-detay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
