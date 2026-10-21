package org.servlet.dau.spendingrequest;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.DauUserDAO;
import org.db.dao.DonationAcceptUnitDAO;
import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.DauUserHibernateImpl;
import org.db.hibernate.SRStateHibernateImpl;
import org.db.hibernate.SpendingRequestHibernateImpl;
import org.db.model.DauUser;
import org.db.model.SpendingRequest;
import org.db.model.SpendingRequestState;

/**
 * Servlet implementation class ListSpendingRequestServlet
 */
@WebServlet("/listspendingrequest")
public class ListSpendingRequestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ListSpendingRequestServlet() {
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
		DauUser user = (DauUser) session.getAttribute("user");
		
		//SpendingRequestDAO spendingDAO = new SpendingRequestHibernateImpl();
		//List<SpendingRequest> spendingRequestList = spendingDAO.listSpendingRequest(user.getDau().getUnitName(), 1);

        DauUserDAO dauUserDAO = new DauUserHibernateImpl();
        List<DauUser> dauUsers = dauUserDAO.getUsersFromDau(user.getDau().getUnitName());

        List<SpendingRequestState> states = new SRStateHibernateImpl().getAllStates();
        session.setAttribute("stateList", states);

		session.setAttribute("userList", dauUsers);
		session.setAttribute("istekguncelle", 0);
		session.setAttribute("spendingList", new ArrayList<SpendingRequest>());
		
		response.sendRedirect("dau/harcama-istekleri.jsp");
	}

}
