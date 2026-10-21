package org.student.cv;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.StudentDAO;
import org.db.hibernate.EducationInfoHibernateImpl;
import org.db.hibernate.StudentHibernateImpl;
import org.db.model.EducationInfo;
import org.db.model.Student;
import org.db.model.User;

/**
 * Servlet implementation class UpdateCvServlet
 */
@WebServlet("/updatecv")
public class UpdateCvServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UpdateCvServlet() {
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
		
		HttpSession session = request.getSession();
		session.setAttribute("iletisim", 0);
		session.setAttribute("personal", 0);
        session.setAttribute("egitim", 0);

        List<EducationInfo> educationInfoList = new EducationInfoHibernateImpl().getByStudent(student.getUserName());

        session.setAttribute("educationList", educationInfoList);
		session.setAttribute("commWays", student.getCommWays());
		response.sendRedirect("student/cv-duzenle.jsp");
	}

}
