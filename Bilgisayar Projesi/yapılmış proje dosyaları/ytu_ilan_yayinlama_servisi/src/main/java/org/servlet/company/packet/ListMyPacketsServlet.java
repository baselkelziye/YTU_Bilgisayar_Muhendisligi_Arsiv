package org.servlet.company.packet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementPacketStateDAO;
import org.db.hibernate.PacketStateHibernateImpl;
import org.db.model.AnnouncementPacketState;
import org.db.model.Company;
import org.db.model.CompanyOwnPacket;

/**
 * Servlet implementation class ListMyPacketsServlet
 */
@WebServlet("/listmypacketsservlet")
public class ListMyPacketsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ListMyPacketsServlet() {
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
		session.setAttribute("ikinciistek", 0);
		Company company = (Company) session.getAttribute("user");
		List<CompanyOwnPacket> packets = company.getPackets();

		List<AnnouncementPacketState> packetStateList = new PacketStateHibernateImpl().getAllStates();

		String query = "SELECT * FROM company_own_packet WHERE owner_company = '" + company.getUserName() + "' ";

        session.setAttribute("paketsorgu", query.toString());
		//session.setAttribute("packets", packets);
        session.setAttribute("packetStates", packetStateList);
		response.sendRedirect("company/paketlerim.jsp");
	}

}
