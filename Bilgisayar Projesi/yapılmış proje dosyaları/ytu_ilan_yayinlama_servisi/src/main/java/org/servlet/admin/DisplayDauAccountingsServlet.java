package org.servlet.admin;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AccountingDAO;
import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.AccountingHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.Accounting;
import org.db.model.DonationAcceptUnit;

/**
 * Servlet implementation class DisplayDauAccountingsServlet
 */
@WebServlet("/displaydauaccountings")
public class DisplayDauAccountingsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DisplayDauAccountingsServlet() {
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
		
		//AccountingDAO accDAO = new AccountingHibernateImpl();
		//List<Accounting> acc = accDAO.getAllAccountings();
		
		DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
		List<DonationAcceptUnit> dauList = dauDAO.getAllUnits();
				
		//session.setAttribute("accounting", acc);
		session.setAttribute("dau", new ArrayList<DonationAcceptUnit>());
        session.setAttribute("accounting", new ArrayList<Accounting>());
		session.setAttribute("alldau", dauList);
		
		response.sendRedirect("admin/muhasebe-kayitlari.jsp");
		
	}

}
