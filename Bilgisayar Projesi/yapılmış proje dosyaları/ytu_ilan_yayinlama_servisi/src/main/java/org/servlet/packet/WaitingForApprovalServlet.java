package org.servlet.packet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.CompanyOwnPacket;
import org.db.model.DauUser;

/**
 * Servlet implementation class WaitingForApprovalServlet
 */
@WebServlet("/waitingforapprovalservlet")
public class WaitingForApprovalServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public WaitingForApprovalServlet() {
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
		DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
		HttpSession session = request.getSession();
		DauUser user = (DauUser) session.getAttribute("user");
		List<CompanyOwnPacket> packet = dauDAO.getWaitingDonation(user.getDau().getUnitName());
		session.setAttribute("packet", packet);
		session.setAttribute("onaylandi", 0);
		response.sendRedirect("dau/bagis-onaylari.jsp");
	}

}
