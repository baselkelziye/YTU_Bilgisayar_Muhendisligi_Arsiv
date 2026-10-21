package org.servlet.packet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementPacketDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.model.AnnouncementPacket;

@WebServlet(name = "DeleteAnnouncementPacket", urlPatterns = {"/deletepacket"})
public class DeleteAnnouncementPacket extends HttpServlet {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        HttpSession session = request.getSession();
        
        int packetId = Integer.parseInt(request.getParameter("id"));
        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();

        if(packetDAO.deletePacket(packetId)) {
            session.setAttribute("paketsil", 1);
            String query = (String) session.getAttribute("searchpacket");
            List<AnnouncementPacket> packetList = packetDAO.getPacketBySQLQuery(query);
            session.setAttribute("packets", packetList);
        } else {
            session.setAttribute("paketsil", 2);
        }

        session.setAttribute("paketaktif", 0);
        response.sendRedirect("admin/paketleri-duzenle.jsp");
    }

}
