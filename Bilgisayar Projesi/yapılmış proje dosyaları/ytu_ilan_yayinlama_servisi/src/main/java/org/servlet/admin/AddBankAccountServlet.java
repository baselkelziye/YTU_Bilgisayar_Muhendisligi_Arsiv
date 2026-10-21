package org.servlet.admin;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.BankAccountDAO;
import org.db.hibernate.BankAccountHibernateImpl;
import org.db.model.BankAccountInfo;
import org.db.model.DonationAcceptUnit;

/**
 * Servlet implementation class AddBankAccountServlet
 */
@WebServlet("/addbankaccountservlet")
public class AddBankAccountServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddBankAccountServlet() {
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
		request.setCharacterEncoding("UTF-8");
		
		//Banka hesap bilgisi özelliklerini oku
        BankAccountInfo bai  = new BankAccountInfo();
        bai.setBankAccountNumber(Integer.parseInt(request.getParameter("account_number")));
        bai.setBankName(request.getParameter("bank_name"));
        bai.setBranchBankName(request.getParameter("name_of_branch"));
        //bai.setCurrency(Integer.parseInt(request.getParameter("currency")));
        bai.setCurrency(1);
        bai.setIban(request.getParameter("iban"));
        
        HttpSession httpSession = request.getSession();
        DonationAcceptUnit dau = (DonationAcceptUnit) httpSession.getAttribute("dau");
        bai.setOwnerUnit(dau);
        
        BankAccountDAO baiDAO = new BankAccountHibernateImpl();
        
        if(httpSession.getAttribute("dau") == null) {
        	httpSession.setAttribute("hesapeklendi", 4);
        } else if(baiDAO.saveBankAccount(bai)) {
        	httpSession.setAttribute("hesapeklendi", 1);
        } else {
        	httpSession.setAttribute("hesapeklendi", 2);
        }
        
        httpSession.setAttribute("vakifolusturuldu", 0);
        httpSession.setAttribute("kullanicieklendi", 0);
        
        response.sendRedirect("admin/bkb-olustur.jsp");
	}

}
