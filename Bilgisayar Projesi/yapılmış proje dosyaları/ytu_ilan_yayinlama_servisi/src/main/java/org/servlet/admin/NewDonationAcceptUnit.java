package org.servlet.admin;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.CurrencyDAO;
import org.db.hibernate.CurrencyHibernateImpl;
import org.db.model.Currency;

/**
 * Servlet implementation class NewDonationAcceptUnit
 */

@WebServlet(name = "NewDonationAcceptUnit", urlPatterns = {"/newdonationacceptunit"})
public class NewDonationAcceptUnit extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public NewDonationAcceptUnit() {
        super();
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
		CurrencyDAO currencyDAO = new CurrencyHibernateImpl();
        List<Currency> currency = currencyDAO.getAllCurrencies();
        HttpSession session = request.getSession();
        session.setAttribute("curr", currency);
        
        if(session.getAttribute("dau") != null) {
        	session.removeAttribute("dau");
        }
        
        session.setAttribute("kullanicieklendi", 0);
        session.setAttribute("hesapeklendi", 0);
        session.setAttribute("vakifolusturuldu", 0);
        
        response.sendRedirect("admin/bkb-olustur.jsp");
	}

}
