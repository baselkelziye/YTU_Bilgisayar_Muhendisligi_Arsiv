package org.servlet.dau.spendingrequest;

import java.io.IOException;
import java.util.Date;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.hibernate.SpendingRequestHibernateImpl;
import org.db.model.*;

/**
 * Servlet implementation class RejectSendingRequestServlet
 */
@WebServlet("/rejectsendingrequest")
public class RejectSendingRequestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public RejectSendingRequestServlet() {
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
		request.setCharacterEncoding("utf-8");
		HttpSession session = request.getSession();
		
		int requestId = Integer.parseInt(request.getParameter("requestId"));
		String answer = request.getParameter("description");
		DauUser dauUser = (DauUser) session.getAttribute("user");
		
		SpendingRequestDAO requestDAO = new SpendingRequestHibernateImpl();
		SpendingRequest spendingRequest = requestDAO.getSpendingRequest(requestId);
		spendingRequest.setId(requestId);
		spendingRequest.setAnswerFromUpdater(answer);
		spendingRequest.setUpdatedDateTime(new Date());
		spendingRequest.setDauUser(dauUser);
		spendingRequest.setState(new SpendingRequestState(3));
		
		if(requestDAO.updateRequest(spendingRequest)) {
			session.setAttribute("istekguncelle", 3);
			SpendingRequestDAO spendingDAO = new SpendingRequestHibernateImpl();
            String query = (String) session.getAttribute("spendingRequestQuery");
            List<SpendingRequest> spendingRequestList = spendingDAO.getSpendingRequestByQuery(query);
			session.setAttribute("spendingList", spendingRequestList);

			//Bildirim
            Notification notification = new Notification(
                    dauUser.getUserName(),
                    new User("admin"),
                    (spendingRequest.getTitle() + " başlıklı harcama isteğiniz reddedildi"),
                    new Date(),
                    "negative"
            );
            new NotificationHibernateImpl().saveNotification(notification);

		} else {
			session.setAttribute("istekguncelle", 4);
		}

		response.sendRedirect("dau/harcama-istekleri.jsp");
	}

}
