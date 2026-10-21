package org.servlet.company.packet;

import org.db.dao.CompanyOwnPacketDAO;
import org.db.hibernate.CompanyOwnPacketHibernateImpl;
import org.db.model.CompanyOwnPacket;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 09.01.2017.
 */
@WebServlet(name = "OrderMyPacketsServlet", urlPatterns = {"/ordermypackets"})
public class OrderMyPacketsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String query = (String) session.getAttribute("paketsorgu");
        String condition = request.getParameter("condition");
        String type = request.getParameter("type");

        if(condition.equals("title")) {
            query = "SELECT id, owner_company, packet, announcement_packet_state, used_announcements, approved, " +
                    " user_for_approved, time_to_request, time_to_approved, time_to_expired, company_description, file_path, second_file_path," +
                    " dau_description, second_dau_description " +
                    " FROM company_own_packet c, announcement_packet a " +
                    " WHERE owner_company = 'sirket1'  AND c.packet = a.packet_id ORDER BY a.title " + type;
        } else {
            query += " ORDER BY " + condition + " " + type + ";";
        }

        CompanyOwnPacketDAO copDAO = new CompanyOwnPacketHibernateImpl();
        List<CompanyOwnPacket> copList = copDAO.getPacketBySQLQuery(query);
        session.setAttribute("packets", copList);

        response.sendRedirect("company/paketlerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
