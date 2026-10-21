package org.servlet.announcement;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.compositePK.ApplicationPK;
import org.db.dao.AnnouncementDAO;
import org.db.dao.ApplicationDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.ApplicationHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.model.Announcement;
import org.db.model.Application;
import org.db.model.Notification;
import org.db.model.User;

/**
 * Servlet implementation class ApplicationToAnnouncementServlet
 */
@WebServlet("/applicationtoannouncement")
public class ApplicationToAnnouncementServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ApplicationToAnnouncementServlet() {
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
		int annID = Integer.parseInt(request.getParameter("announcement"));
		AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
		Announcement announcement = annDAO.getAnnouncement(annID);

		HttpSession session = request.getSession();
		User user = (User) session.getAttribute("user");
		
		ApplicationPK pk = new ApplicationPK();
		pk.setAnnouncement(announcement);
		pk.setUser(user);
				
		Application app = new Application();
		app.setPk(pk);
		app.setTimeToApplication(new Date());
		app.setIpAddress(request.getRemoteAddr());
		
		ApplicationDAO appDAO = new ApplicationHibernateImpl();
		
		if(appDAO.application(app)) {
			session.setAttribute("basvuruldu", 1);
			session.setAttribute("basvuruvar", 1);
			announcement = annDAO.getAnnouncement(annID);
			session.setAttribute("announcement", announcement);

			Notification notification = new Notification(
					user.getUserName(),
					new User(announcement.getOwnerCompany().getUserName()),
					(announcement.getTitle() + " başlıklı ilanınıza başvuru var."),
					new Date(),
                    "info"
			);
			new NotificationHibernateImpl().saveNotification(notification);
		} else {
			session.setAttribute("basvuruvar", 2);
			session.setAttribute("basvuruldu", 2); //0 atamaya c set ile dene
		}

		response.sendRedirect("student/ilan-detay.jsp");
	}

}
