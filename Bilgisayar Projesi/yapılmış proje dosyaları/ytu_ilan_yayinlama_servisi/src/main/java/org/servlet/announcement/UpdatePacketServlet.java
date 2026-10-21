package org.servlet.announcement;

import org.db.dao.AnnouncementPacketDAO;
import org.db.dao.BankAccountDAO;
import org.db.dao.CurrencyDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.hibernate.BankAccountHibernateImpl;
import org.db.hibernate.CurrencyHibernateImpl;
import org.db.model.AnnouncementPacket;
import org.db.model.BankAccountInfo;
import org.db.model.Currency;

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

/**
 * Created by mgunes on 27.12.2016.
 */
@WebServlet(name = "UpdatePacketServlet", urlPatterns = {"/updatepacket"})
public class UpdatePacketServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();

        AnnouncementPacket packet = (AnnouncementPacket) session.getAttribute("packet");
        BankAccountInfo accountInfo;
        Currency currency;

        CurrencyDAO currencyDAO = new CurrencyHibernateImpl();
        //currency = currencyDAO.getCurrency(Integer.parseInt(request.getParameter("currency")));
        currency = currencyDAO.getCurrency(1);

        BankAccountDAO accountDAO = new BankAccountHibernateImpl();
        accountInfo = accountDAO.getAccount(request.getParameter("account"));

        packet.setTitle(request.getParameter("packet_name"));
        packet.setActiveTime(Integer.parseInt(request.getParameter("activate_date")));
        packet.setLastDateUsed(new Date());
        packet.setAnnouncementCount(Integer.parseInt(
                request.getParameter("announcement_number")));
        packet.setPrice(Integer.parseInt(request.getParameter("price")));
        packet.setCondition(request.getParameter("condition"));
        packet.setAccountInfo(accountInfo);
        packet.setCurrency(currency);
        packet.setVisible(false);

        try {
            String date = request.getParameter("last_date_used");
            Date expired = new SimpleDateFormat("dd/MM/yyyy").parse(date);
            packet.setLastDateUsed(expired);
        } catch (ParseException e) {
            System.out.println("Son kullanım tarihi okunamadı");
            e.printStackTrace();
        }

        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();

        if(packetDAO.savePacket(packet)) {
            session.setAttribute("duzenle", 1);
        } else {
            session.setAttribute("duzenle", 2);
        }

        response.sendRedirect("admin/paket-guncelle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
