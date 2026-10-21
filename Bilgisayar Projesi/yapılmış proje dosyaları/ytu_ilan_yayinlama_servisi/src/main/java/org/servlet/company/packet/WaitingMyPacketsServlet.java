package org.servlet.company.packet;

import org.db.dao.CompanyOwnPacketDAO;
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
 * Created by mgunes on 05.12.2016.
 */
@WebServlet("/companywaitingpacketlist")
public class WaitingMyPacketsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        Company company = (Company) session.getAttribute("user");
        CompanyOwnPacketDAO copDAO = new CompanyOwnPacketHibernateImpl();
        List<CompanyOwnPacket> copList = copDAO.getWaitingPacketsToCompany(company.getUserName());
        session.setAttribute("packetList", copList);

        response.sendRedirect("company/bekleyen-isteklerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
