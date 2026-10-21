package org.servlet.student;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.db.dao.StudentDAO;
import org.db.hibernate.StudentHibernateImpl;
import org.db.model.Student;
import org.db.model.User;

/**
 * Servlet implementation class MyApplicationsServlet
 */
@WebServlet("/myapplications")
public class MyApplicationsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public MyApplicationsServlet() {
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
		StudentDAO studentDAO = new StudentHibernateImpl();
		User user = (User) request.getSession().getAttribute("user");
		Student student = studentDAO.getStudent(user.getUserName());
		request.getSession().setAttribute("student", student);
		
		response.sendRedirect("student/basvurularim.jsp");
	}

}
