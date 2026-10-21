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
@WebServlet(name = "SearchPacketServlet", urlPatterns = {"/searchpacket"})
public class SearchPacketServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");

        String type = request.getParameter("type");
        String state = request.getParameter("state");
        String dauName = request.getParameter("department");

        StringBuilder query = new StringBuilder();
        query.append("SELECT * FROM announcement_packet WHERE 1 = 1 ");

        if(type.equals("Aktif")) { //aktif-pasif
            query.append(" AND visible = true " );
        } else if(type.equals("Pasif")) {
            query.append(" AND visible = false " );
        }
        System.out.println(type);
        if(state.equals("Güncel")) { //zamansal arama
            query.append(" AND last_date_used > now() ");
        } else if(state.equals("Tarihi Geçmiş")) {
            query.append(" AND last_date_used < now() ");
        }
        System.out.println(state);
        System.out.println(dauName);
        if(!dauName.equals("Tüm Birimler")) {
            query.append(" AND bank_account_info in " +
                    "( SELECT iban from bank_account_info WHERE owner_unit_name = '" + dauName + "') ");
        }

        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();
        List<AnnouncementPacket> packetList = packetDAO.getPacketBySQLQuery(query.toString());

        HttpSession session = request.getSession();
        session.setAttribute("paketsil", 0);
        session.setAttribute("searchpacket", query.toString());
        session.setAttribute("packets", packetList);

        response.sendRedirect("admin/paketleri-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
