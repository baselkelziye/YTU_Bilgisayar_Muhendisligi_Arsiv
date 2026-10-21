package org.servlet.announcement;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.db.dao.AnnouncementDAO;
import org.db.dao.ApplicationDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.ApplicationHibernateImpl;
import org.db.model.Announcement;
import org.db.model.User;

/**
 * Servlet implementation class DeleteApplicationServlet
 */
@WebServlet("/deleteapplication")
public class DeleteApplicationServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteApplicationServlet() {
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
		User user = (User) request.getSession().getAttribute("user");
		System.out.println("id " + annID);
		System.out.println("user " + user.getUserName());
		System.out.println("-------" + (String)request.getParameter("deleteUrl"));
		
		ApplicationDAO appDAO = new ApplicationHibernateImpl();
		
		if(appDAO.deleteApplication(user.getUserName(), annID)) {
			request.getSession().setAttribute("basvuruvar", 2);
			request.getSession().setAttribute("basvuruldu", 3);
		} else {
			request.getSession().setAttribute("basvuruldu", 4);
		}
		
		AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
		Announcement announcement = annDAO.getAnnouncement(annID);
		request.getSession().setAttribute("announcement", announcement);
		
		//response.sendRedirect("student/ilan-detay.jsp");
		
		response.sendRedirect((String)request.getParameter("deleteUrl"));
	}

}
