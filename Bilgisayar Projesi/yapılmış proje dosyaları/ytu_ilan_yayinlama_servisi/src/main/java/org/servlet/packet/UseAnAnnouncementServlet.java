package org.servlet.packet;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementDAO;
import org.db.dao.CompanyOwnPacketDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.CompanyOwnPacketHibernateImpl;
import org.db.model.Announcement;
import org.db.model.CompanyOwnPacket;

/**
 * Servlet implementation class UseAnAnnouncementServlet
 */
@WebServlet("/useanannouncement")
public class UseAnAnnouncementServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UseAnAnnouncementServlet() {
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
		int packetID = Integer.parseInt(request.getParameter("ap"));
		int announcementID = Integer.parseInt(String.valueOf( request.getParameter("ann")));
		session.setAttribute("ilansil", 0);
		
		//ilan durumunu aktife çevir		
		//packettten 1 hak azalt 
		// eğer 0 sa zaten hiç seçim şansının gelmemiş olması gerek
		
		AnnouncementDAO announcementDAO = new AnnouncementHibernateImpl();
		Announcement ann = announcementDAO.getAnnouncement(announcementID);
		ann.getState().setId(2);
		ann.getState().setTitle("active");
		ann.setPublishDate(new Date());
		
		CompanyOwnPacketDAO packetDAO = new CompanyOwnPacketHibernateImpl();
		CompanyOwnPacket cop = packetDAO.getPacket(packetID);
		cop.setUsedAnnouncements(cop.getUsedAnnouncements() + 1); //yayına al metodu yap
		
		ann.setOwnerPacket(cop);
        long time = new Date().getTime() + cop.getPacket().getActiveTime() * 24 * 60 * 60 * 1000;
        Date date = new Date();
        date.setTime(time);
        ann.setExpiredDate(date);
		
		if(announcementDAO.updateAnnouncement(ann) && packetDAO.updatePacket(cop)) {
			session.setAttribute("ilanaktif", 1);
		}

		response.sendRedirect("mypassiveannouncements");
	}

}
