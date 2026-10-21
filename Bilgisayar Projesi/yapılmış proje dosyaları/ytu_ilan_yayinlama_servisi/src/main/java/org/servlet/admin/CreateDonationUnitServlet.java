package org.servlet.admin;

import java.io.IOException;
import java.util.Date;

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
 * Servlet implementation class CreateDonationUnitServlet
 */

@WebServlet(name = "CreateDonationUnitServlet", urlPatterns = {"/createdonationunitservlet"})
public class CreateDonationUnitServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CreateDonationUnitServlet() {
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
		// TODO Auto-generated method stub
		//okunan form bilgisi Türkçe karaktere uygun hale getirildi
        request.setCharacterEncoding("UTF-8");
        HttpSession httpSession  = request.getSession();
       
        //Bağış kabul birimi özelliklerini oku
        DonationAcceptUnit dau = new DonationAcceptUnit();
        dau.setUnitName(request.getParameter("unit_name"));
        dau.setBalance(0);
        dau.setCreatedDate(new Date());
        
        DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
        
        if(dauDAO.saveDonationAcceptUnit(dau)) {
        	httpSession.setAttribute("vakifolusturuldu", 1);
        	httpSession.setAttribute("dau", dau);
        } else {
        	httpSession.setAttribute("vakifolusturuldu", 2);
        }
        
        httpSession.setAttribute("hesapeklendi", 0);
        httpSession.setAttribute("kullanicieklendi", 0);
        
        response.sendRedirect("admin/bkb-olustur.jsp");
	}

}
