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
@WebServlet(name = "ActivePacketServlet", urlPatterns = {"/activepacket"})
public class ActivePacketServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        int packetId = Integer.parseInt(request.getParameter("id"));

        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();

        if(packetDAO.activePacket(packetId)) {
            session.setAttribute("paketaktif", 1);
            String query = (String) session.getAttribute("searchpacket");
            List<AnnouncementPacket> packetList = packetDAO.getPacketBySQLQuery(query);
            session.setAttribute("packets", packetList);
        } else {
            session.setAttribute("paketaktif", 2);
        }

        session.setAttribute("paketsil", 0);
        response.sendRedirect("admin/paketleri-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
