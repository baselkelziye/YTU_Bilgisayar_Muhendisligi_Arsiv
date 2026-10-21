package org.servlet.announcement;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.dao.AnnouncementDAO;
import org.db.dao.AnnouncementStateDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.AnnouncementStateHibernateImpl;
import org.db.model.Announcement;
import org.db.model.AnnouncementState;
import org.db.model.AnnouncementType;
import org.db.model.Company;

/**
 * Servlet implementation class AnnouncementCreateServlet
 */
@WebServlet("/announcementcreate")
public class AnnouncementCreateServlet extends HttpServlet {
	private Announcement announcement = new Announcement();
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		HttpSession session = request.getSession();
		readForm(request);
		
		AnnouncementStateDAO stateDAO = new AnnouncementStateHibernateImpl();
		AnnouncementState state = stateDAO.getState(1);
		announcement.setState(state);
		announcement.setOwnerCompany((Company)session.getAttribute("user"));
		announcement.setProperComplaint(true);
		//announcement.setOwnerPacket(-1);

		if(new AnnouncementHibernateImpl().saveAnnouncement(announcement)) {
			session.setAttribute("olusturuldu", 1);
		}
		else {
			session.setAttribute("olusturuldu", 2);
		}
		
		response.sendRedirect("company/ilan-olustur.jsp");
	}

	private void readForm(HttpServletRequest request) {
		announcement.setTitle(request.getParameter("title"));
		announcement.setBrief(request.getParameter("brief"));
		announcement.setContent(request.getParameter("content"));
		announcement.setAnnouncementLanguage(request.getParameter("language"));
		
		AnnouncementType annType = new AnnouncementType();
		annType.setId(Integer.parseInt(request.getParameter("type")));
		announcement.setAnnouncementType(annType);
		
		AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
		announcement.setCategory(categoryDAO.getCategory(Integer.parseInt((String)request.getParameter("category"))));
	}
}
