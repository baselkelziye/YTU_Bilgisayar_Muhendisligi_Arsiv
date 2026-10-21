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
import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.CurrencyHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.BankAccountInfo;
import org.db.model.Currency;
import org.db.model.DonationAcceptUnit;

/**
 * Servlet implementation class SelectDauForPacketServlet
 */
@WebServlet("/selectdauforpacketservlet")
public class SelectDauForPacketServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SelectDauForPacketServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession httpSession = request.getSession();
		request.setCharacterEncoding("UTF-8");
		
		DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
        DonationAcceptUnit dau = dauDAO.getUnit(request.getParameter("unit"));
        
        if(dau != null) {
        	CurrencyDAO currencyDAO = new CurrencyHibernateImpl();
        	List<Currency> currencyList = currencyDAO.getAllCurrencies();
        	List<BankAccountInfo> accountList = dau.getAccount();
        	
        	httpSession.setAttribute("vakifsecildi", 1);
        	httpSession.setAttribute("dau", dau);
        	httpSession.setAttribute("curr", currencyList);
        	httpSession.setAttribute("accountList", accountList);
        } else {
        	httpSession.setAttribute("vakifsecildi", 2);
        }
        
		response.sendRedirect("admin/paket-olustur.jsp");
	}

}
