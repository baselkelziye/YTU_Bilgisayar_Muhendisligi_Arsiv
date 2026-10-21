package org.servlet.packet;

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
 * Created by mgunes on 27.12.2016.
 */
@WebServlet(name = "OrderPacketServlet", urlPatterns = {"/orderpacket"})
public class OrderPacketServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String condition = request.getParameter("condition");
        String order = request.getParameter("order");
        String query = (String) session.getAttribute("searchpacket");
        query += " ORDER BY " + condition + " " + order;

        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();
        List<AnnouncementPacket> packetList = packetDAO.getPacketBySQLQuery(query.toString());

        //session.setAttribute("searchpacket", query);
        session.setAttribute("packets", packetList);

        response.sendRedirect("admin/paketleri-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
