package org.servlet.announcement;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.model.Announcement;

/**
 * Servlet implementation class GetAllAnnouncementsServlet
 */
@WebServlet(name = "AnnouncementsToStudentServlet", urlPatterns = {"/announcementstostudent"})
public class AnnouncementsToStudentServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AnnouncementsToStudentServlet() {
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
		HttpSession httpSession = request.getSession();
		AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
		String query = "SELECT * FROM announcement WHERE now() between publish_date and expired_date " +
				" and state <> 4 and visibility = true ";
		List<Announcement> announcements = annDAO.getBySQLCriteria(query);
		httpSession.setAttribute("searchannouncementquery", query);
		httpSession.setAttribute("announcements", announcements);
		response.sendRedirect("student/ilan-ara.jsp");
	}

}
