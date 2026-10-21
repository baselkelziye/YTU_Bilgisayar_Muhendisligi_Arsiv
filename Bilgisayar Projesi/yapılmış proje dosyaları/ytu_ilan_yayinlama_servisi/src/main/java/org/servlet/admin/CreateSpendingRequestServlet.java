package org.servlet.admin;

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
import org.db.model.DonationAcceptUnit;

/**
 * Servlet implementation class CreateSpendingRequestServlet
 */
@WebServlet("/createspendingrequest")
public class CreateSpendingRequestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CreateSpendingRequestServlet() {
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
		
		DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
		List<DonationAcceptUnit> dauList = dauDAO.getAllUnits();
		
		if(session.getAttribute("harcamaistegi") != null) {
			session.setAttribute("harcamaistegi", 0);
			session.removeAttribute("title");
			session.removeAttribute("content");
			session.removeAttribute("amount");
			session.removeAttribute("toplamistekler");
			session.removeAttribute("birim");
		}
		
		session.setAttribute("dau", dauList);
			
		response.sendRedirect("admin/harcama-istegi-olustur.jsp");
	}

}
