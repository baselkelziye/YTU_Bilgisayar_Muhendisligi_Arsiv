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
import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.hibernate.SpendingRequestHibernateImpl;
import org.db.model.*;

/**
 * Servlet implementation class SendSpendingRequestServlet
 */
@WebServlet("/sendspendingrequest")
public class SendSpendingRequestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SendSpendingRequestServlet() {
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
		request.setCharacterEncoding("utf-8");
		
		DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
		DonationAcceptUnit dau = dauDAO.getUnit(request.getParameter("dau"));
		
		int balance = dau.getBalance();
		String title = request.getParameter("title");
		String content = request.getParameter("content");
		int amount = Integer.parseInt(request.getParameter("amount"));
		
		if(balance < amount) {
			session.setAttribute("harcamaistegi", 2);
			session.setAttribute("title", title);
			session.setAttribute("content", content);
			session.setAttribute("amount", amount);
			
		} else {
			SpendingRequest spendingRequest = new SpendingRequest();
			spendingRequest.setTitle(title);
			spendingRequest.setContent(content);
			spendingRequest.setAmount(amount);
			spendingRequest.setSentDateTime(new Date());
			spendingRequest.setState(new SpendingRequestState(1));
			spendingRequest.setDau(dau);
			
			SpendingRequestDAO srDAO = new SpendingRequestHibernateImpl();
			
			if(srDAO.sendRequest(spendingRequest)) {
				if(session.getAttribute("harcamaistegi") != null) {
					session.removeAttribute("title");
					session.removeAttribute("content");
					session.removeAttribute("amount");
					
					int totalSpendingRequest = srDAO.calculateTotalRequestAmount(dau.getUnitName());
					
					if(dau.getBalance() < totalSpendingRequest) {
						session.setAttribute("birim", dau.getUnitName());
						session.setAttribute("toplamistekler", 1);
					} else {
						session.setAttribute("toplamistekler", 0);
					}
					
				}

                //Bildirim
                for(DauUser user: dau.getDauUser()) {
                    Notification notification = new Notification(
                            "Admin",
                            new User(user.getUserName()),
                            (spendingRequest.getTitle() + " başlıklı harcama isteği gönderildi."),
                            new Date(),
                            "info"
                    );
                    new NotificationHibernateImpl().saveNotification(notification);
                }
				
				session.setAttribute("harcamaistegi", 1);
			} else {
				session.setAttribute("harcamaistegi", 3);
				session.setAttribute("title", title);
				session.setAttribute("content", content);
				session.setAttribute("amount", amount);
			}
		}
		
		response.sendRedirect("admin/harcama-istegi-olustur.jsp");
	}

}
