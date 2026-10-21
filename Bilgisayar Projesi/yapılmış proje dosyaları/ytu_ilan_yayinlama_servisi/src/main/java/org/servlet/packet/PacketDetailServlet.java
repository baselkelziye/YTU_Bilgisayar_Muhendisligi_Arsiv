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
import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.AnnouncementPacket;
import org.db.model.DonationAcceptUnit;

/**
 * Servlet implementation class PacketDetailServlet
 */
@WebServlet("/packetdetail")
public class PacketDetailServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PacketDetailServlet() {
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
		int packetId = Integer.parseInt(request.getParameter("packetId"));
		
		AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();
		AnnouncementPacket packet = packetDAO.getPacket(packetId);

		DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
		List<DonationAcceptUnit> dauList = dauDAO.getAllUnits();

        session.setAttribute("alldau", dauList);
		session.setAttribute("packet", packet);
		response.sendRedirect("admin/paket-detay.jsp");
	}

}
