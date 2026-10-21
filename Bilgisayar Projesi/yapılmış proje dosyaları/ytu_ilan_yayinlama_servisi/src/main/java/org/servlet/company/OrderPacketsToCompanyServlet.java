package org.servlet.company;

import org.db.dao.AnnouncementPacketDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.model.AnnouncementPacket;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 29.12.2016.
 */
@WebServlet(name = "OrderPacketsToCompanyServlet", urlPatterns = {"/orderpacketstocompany"})
public class OrderPacketsToCompanyServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        StringBuilder query = new StringBuilder();
        query.append("SELECT * FROM announcement_packet where visible = true and last_date_used > now() ");

        String condition = request.getParameter("condition");
        String order = request.getParameter("order");

        query.append(" ORDER BY " + condition + " " + order);

        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();
        List<AnnouncementPacket> packetList = packetDAO.getPacketBySQLQuery(query.toString());

        HttpSession session = request.getSession();
        session.setAttribute("packets", packetList);

        response.sendRedirect("company/paketleri-gor.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
