package org.servlet.announcement;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementDAO;
import org.db.dao.StudentDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.hibernate.StudentHibernateImpl;
import org.db.model.Announcement;
import org.db.model.Student;
import org.db.model.User;

/**
 * Servlet implementation class AnnouncementDetailToStudentServlet
 */
@WebServlet("/announcementdetailtostudent")
public class AnnouncementDetailToStudentServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AnnouncementDetailToStudentServlet() {
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
		StudentDAO studentDAO = new StudentHibernateImpl();
		User user = (User) request.getSession().getAttribute("user");
		Student student = studentDAO.getStudent(user.getUserName());
		request.getSession().setAttribute("student", student);
		
		if(announcement != null) {
			announcement.setNumberOfPageViews(announcement.getNumberOfPageViews() + 1); //tek metotla 1 artır
			annDAO.updateAnnouncement(announcement); //aynı kullanıcı için sadece 1 görüntülenme sayılsın
			session.setAttribute("ilangetir", 1);
			//session.setAttribute("basvuruldu", 0);
			
			if(student.isApplication(announcement.getId())) {
				session.setAttribute("basvuruvar", 1);
			} else {
				session.setAttribute("basvuruvar", 2);
			}

			if(student.isComplaint(annID)) {
                session.setAttribute("sikayetvar", 1);
            } else {
                session.setAttribute("sikayetvar", 2);
            }
			
			session.setAttribute("announcement", announcement);
		} else {
			session.setAttribute("ilangetir", 1);
		}

		session.setAttribute("sikayetedildi", 0);
        session.setAttribute("ilangericek", 0);
		session.setAttribute("basvuruldu", 0);
		response.sendRedirect("student/ilan-detay.jsp");
	}

}
