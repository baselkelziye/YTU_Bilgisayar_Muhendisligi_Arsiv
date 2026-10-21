package org.student.cv.communicationway;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.compositePK.CommunicationWayPK;
import org.db.dao.CommunicationWayDAO;
import org.db.dao.StudentDAO;
import org.db.hibernate.CommunicationWayHibernateImpl;
import org.db.hibernate.StudentHibernateImpl;
import org.db.model.CommunicationWay;
import org.db.model.Student;
import org.db.model.User;

/**
 * Servlet implementation class UpdateCommWayServlet
 */
@WebServlet("/addcommwaystudent")
public class AddCommWayServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddCommWayServlet() {
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
        session.setAttribute("personal", 0);
        session.setAttribute("egitim", 0);

		String title = request.getParameter("commTitle");
		String value = request.getParameter("commValue");
		User user = (User) request.getSession().getAttribute("user");
		
		CommunicationWayPK pk = new CommunicationWayPK();
		pk.setCommType(title);
		pk.setCommValue(value);
		
		CommunicationWay way = new CommunicationWay();
		way.setPk(pk);
		way.setUser(user);
		
		CommunicationWayDAO commDAO = new CommunicationWayHibernateImpl();
		
		if(commDAO.saveCommWay(way)) {
			session.setAttribute("iletisim", 1);
		} else {
			session.setAttribute("iletisim", 2);
		}
		
		StudentDAO studentDAO = new StudentHibernateImpl();
		Student student = studentDAO.getStudent(user.getUserName());
		session.setAttribute("commWays", student.getCommWays());
		response.sendRedirect("student/cv-duzenle.jsp");
	}

}
