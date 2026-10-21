package org.servlet.announcement;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.CompanyOwnPacketDAO;
import org.db.dao.UserDAO;
import org.db.hibernate.CompanyOwnPacketHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.Announcement;
import org.db.model.Company;
import org.db.model.CompanyOwnPacket;

/**
 * Servlet implementation class ListMyAnnouncementsServlet
 */
@WebServlet("/listmyannouncementsservlet")
public class ListMyAnnouncementsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ListMyAnnouncementsServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();
		Company company = (Company) session.getAttribute("user");
		UserDAO userDAO = new UserHibernateImpl();
		company = (Company) userDAO.getUser(company.getUserName());
		List<Announcement> announcements = company.getAnnouncements();
		List<CompanyOwnPacket> packets = company.getPackets();

        CompanyOwnPacketDAO copDAO = new CompanyOwnPacketHibernateImpl();
		List<CompanyOwnPacket> availablePackets = copDAO.getAvailablePackets(company.getUserName());

		session.setAttribute("packets", packets);
        session.setAttribute("availablepackets", availablePackets);
		session.setAttribute("announcements", announcements);
		session.setAttribute("user", company);
		response.sendRedirect("company/ilanlarim.jsp");
	}

}
