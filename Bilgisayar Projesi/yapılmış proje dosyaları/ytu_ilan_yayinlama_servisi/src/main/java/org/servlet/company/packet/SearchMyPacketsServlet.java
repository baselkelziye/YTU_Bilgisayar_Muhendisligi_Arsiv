package org.servlet.company.packet;

import org.db.hibernate.CompanyOwnPacketHibernateImpl;
import org.db.model.Company;
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
 * Created by mgunes on 29.12.2016.
 */
@WebServlet(name = "SearchMyPacketsServlet", urlPatterns = {"/searchmypackets"})
public class SearchMyPacketsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        Company company = (Company) session.getAttribute("user");
        int state = Integer.parseInt(request.getParameter("packetState"));

        StringBuilder query = new StringBuilder();
        query.append("SELECT * FROM company_own_packet WHERE owner_company = '" + company.getUserName() + "' ");

        if(state == 3) {
            query.append(" AND time_to_expired < now()");
        } else if(state == 2) {
            query.append(" AND time_to_expired > now()");
        } else if(state != -1) {
            query.append(" AND announcement_packet_state = " + state);
        }

        List<CompanyOwnPacket> packetList = new CompanyOwnPacketHibernateImpl().getPacketBySQLQuery(query.toString());
        session.setAttribute("packets", packetList);
        session.setAttribute("paketsorgu", query.toString());

        response.sendRedirect("company/paketlerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
