package org.servlet.announcement;

import org.db.dao.AnnouncementPacketDAO;
import org.db.dao.BankAccountDAO;
import org.db.dao.CurrencyDAO;
import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.hibernate.BankAccountHibernateImpl;
import org.db.hibernate.CurrencyHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.AnnouncementPacket;
import org.db.model.BankAccountInfo;
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
 * Created by mgunes on 27.12.2016.
 */
@WebServlet(name = "UpdateInitPacketServlet", urlPatterns = {"/updateinitpacket"})
public class UpdateInitPacketServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        int id = Integer.parseInt(request.getParameter("id"));

        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();
        AnnouncementPacket packet = packetDAO.getPacket(id);
        session.setAttribute("packet", packet);

        CurrencyDAO currencyDAO = new CurrencyHibernateImpl();
        List<Currency> currencyList = currencyDAO.getAllCurrencies();
        session.setAttribute("curr", currencyList);

        BankAccountDAO accountDAO = new BankAccountHibernateImpl();
        List<BankAccountInfo> bankAccountInfos = accountDAO.getSiblingAccounts(packet.getAccountInfo().getIban().trim());
        session.setAttribute("accounts", bankAccountInfos);

        session.setAttribute("duzenle", 0);
        response.sendRedirect("admin/paket-guncelle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
