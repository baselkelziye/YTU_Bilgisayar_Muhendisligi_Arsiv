package org.servlet.packet;

import java.io.IOException;
import java.util.Date;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.compositePK.AccountingPK;
import org.db.dao.AccountingDAO;
import org.db.dao.AnnouncementPacketStateDAO;
import org.db.dao.CompanyOwnPacketDAO;
import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.*;
import org.db.model.*;

/**
 * Servlet implementation class ApprovedDonationServlet
 */
@WebServlet("/approveddonationservlet")
public class ApprovedDonationServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ApprovedDonationServlet() {
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
		User user = (User) session.getAttribute("user");
		//nesneyi bul ve approved, timeToAppreved, userForApproved alanlarını güncelle
		CompanyOwnPacketDAO copDAO = new CompanyOwnPacketHibernateImpl();
		CompanyOwnPacket cop = copDAO.getPacket(Integer.parseInt(request.getParameter("packetId")));
		
		AnnouncementPacketStateDAO stateDAO = new PacketStateHibernateImpl();
		AnnouncementPacketState state = stateDAO.getPacketState(2);
		
		cop.setApproved(true);
		cop.setTimeToApproved(new Date());
		cop.setUsernameForApproved(user.getUserName());
		cop.setState(state);

		long time = new Date().getTime() + cop.getPacket().getActiveTime() * 24 * 60 * 60 * 1000;
        Date date = new Date();
        date.setTime(time);
        cop.setTimeToExpired(date);

		if(copDAO.updatePacket(cop)) {
			session.setAttribute("onaylandi", 1);
			
			//listeyi güncelle
			DauUser dauUser = (DauUser) session.getAttribute("user");
			dauUser = (DauUser) new UserHibernateImpl().getUser(dauUser.getUserName());
			DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();
			List<CompanyOwnPacket> packet = dauDAO.getWaitingDonation(dauUser.getDau().getUnitName());
			session.setAttribute("packet", packet);
			session.setAttribute("user", dauUser);
			
			//parayı ekle -- dau tablosu trigger
			Accounting accounting = new Accounting();
			AccountingPK accountingPK = new AccountingPK();
			
			accountingPK.setDateTime(new Date());
			accountingPK.setUnit(dauUser.getDau());
			
			accounting.setAccountingPK(accountingPK);
			accounting.setAmount(cop.getPacket().getPrice());
			accounting.setDauUser(dauUser);
			accounting.setDescription(cop.getOwnerCompany().getCompanyName() + " şirketinin " + cop.getPacket().getTitle()
				+ " paketi için yapmış olduğu istek onaylandı." );
			
			AccountingDAO accountingDAO = new AccountingHibernateImpl();
			accountingDAO.saveAccounting(accounting);


			Notification notification = new Notification(
					cop.getPacket().getAccountInfo().getOwnerUnit().getUnitName(),
					new User(cop.getOwnerCompany().getUserName()),
					(cop.getPacket().getTitle() + " paketi için bağış isteğiniz onaylandı."),
					new Date(),
                    "positive"
			);
			new NotificationHibernateImpl().saveNotification(notification);
			
		} else {
			session.setAttribute("onaylandi", 2);
		}
		
		response.sendRedirect("dau/bagis-onaylari.jsp");
	}

}
