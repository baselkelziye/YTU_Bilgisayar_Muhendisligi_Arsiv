package org.student.cv.communicationway;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.CommunicationWayDAO;
import org.db.dao.StudentDAO;
import org.db.hibernate.CommunicationWayHibernateImpl;
import org.db.hibernate.StudentHibernateImpl;
import org.db.model.Student;
import org.db.model.User;

/**
 * Servlet implementation class DeleteCommServlet
 */
@WebServlet("/deletecommwaystudent")
public class DeleteCommServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteCommServlet() {
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
        session.setAttribute("personal", 0);
        session.setAttribute("egitim", 0);

		String title = request.getParameter("type");
		String value = request.getParameter("value");
		
		CommunicationWayDAO wayDAO = new CommunicationWayHibernateImpl();
		
		if(wayDAO.deleteCommWay(title, value)) {
			session.setAttribute("iletisim", 3);
		} else {
			session.setAttribute("iletisim", 4);
		}
		
		User user = (User) request.getSession().getAttribute("user");
		StudentDAO studentDAO = new StudentHibernateImpl();
		Student student = studentDAO.getStudent(user.getUserName());
		session.setAttribute("commWays", student.getCommWays());
		response.sendRedirect("student/cv-duzenle.jsp");
	}

}
