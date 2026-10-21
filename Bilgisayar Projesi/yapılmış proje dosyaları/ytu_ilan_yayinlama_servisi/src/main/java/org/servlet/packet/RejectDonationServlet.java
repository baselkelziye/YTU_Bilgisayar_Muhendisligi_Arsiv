package org.servlet.packet;

import org.db.dao.CompanyOwnPacketDAO;
import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.CompanyOwnPacketHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.CompanyOwnPacket;
import org.db.model.DauUser;
import org.db.model.Notification;
import org.db.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 28.01.2017.
 */
@WebServlet(name = "RejectDonationServlet", urlPatterns = {"/rejectdonation"})
public class RejectDonationServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();

        int id = Integer.parseInt(request.getParameter("id"));
        String dauDescription = request.getParameter("content");

        CompanyOwnPacketDAO copDAO = new CompanyOwnPacketHibernateImpl();
        CompanyOwnPacket cop = copDAO.getPacket(id);


        if(cop.getState().getId() == 1) {
            cop.getState().setId(4);
            cop.setDauDescription(dauDescription);
        } else if(cop.getState().getId() == 6) {
            cop.getState().setId(5);
            cop.setSecondDauDescription(dauDescription);
        }

        if(copDAO.save(cop)) {
            session.setAttribute("onaylandi", 3);
            DauUser dauUser = (DauUser) session.getAttribute("user");
            dauUser = (DauUser) new UserHibernateImpl().getUser(dauUser.getUserName());
            DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
            List<CompanyOwnPacket> packet = dauDAO.getWaitingDonation(dauUser.getDau().getUnitName());
            session.setAttribute("packet", packet);
            session.setAttribute("user", dauUser);

            Notification notification = new Notification(
                    cop.getPacket().getAccountInfo().getOwnerUnit().getUnitName(),
                    new User(cop.getOwnerCompany().getUserName()),
                    (cop.getPacket().getTitle() + " paketi için bağış isteğiniz reddedildi."),
                    new Date(),
                    "negative"
            );
            new NotificationHibernateImpl().saveNotification(notification);
        } else {
            session.setAttribute("onaylandi", 4);
        }

        response.sendRedirect("dau/bagis-onaylari.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
