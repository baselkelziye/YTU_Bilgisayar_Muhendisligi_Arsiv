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

/**
 * Servlet implementation class DisplayPacketsToCompany
 */
@WebServlet("/displaypacketstocompany")
public class DisplayPacketsToCompany extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DisplayPacketsToCompany() {
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
		AnnouncementPacketDAO annPacketDAO = new AnnouncementPacketHibernateImpl();
		List<AnnouncementPacket> packets = annPacketDAO.getAvailablePackets();
		HttpSession httpSession = request.getSession();
		httpSession.setAttribute("donation_request", 0);
		httpSession.setAttribute("packets", packets);
		response.sendRedirect("company/paketleri-gor.jsp");
	}

}
