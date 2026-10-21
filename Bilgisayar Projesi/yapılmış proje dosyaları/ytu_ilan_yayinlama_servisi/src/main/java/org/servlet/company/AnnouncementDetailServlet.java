package org.servlet.company;

import java.io.IOException;

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
 * Servlet implementation class AnnouncementDetailServlet
 */
@WebServlet("/announcementdetail")
public class AnnouncementDetailServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AnnouncementDetailServlet() {
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
		AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
		Announcement ann = annDAO.getAnnouncement(Integer.parseInt(request.getParameter("packetId"))); //isim yanlış düzeltilecek
				
		if(ann != null) {
			HttpSession session = request.getSession();
			session.setAttribute("announcement", ann);
			response.sendRedirect("company/ilan-detay.jsp");
		}
	}

}
