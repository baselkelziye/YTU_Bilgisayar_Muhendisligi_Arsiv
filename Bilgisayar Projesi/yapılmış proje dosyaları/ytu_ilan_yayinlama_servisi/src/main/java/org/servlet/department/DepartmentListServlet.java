package org.servlet.department;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.DepartmentDAO;
import org.db.hibernate.DepartmentHibernateImpl;
import org.db.model.Department;

/**
 * Servlet implementation class DepartmentListServlet
 */
@WebServlet("/departmentlist")
public class DepartmentListServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DepartmentListServlet() {
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
		DepartmentDAO departmentDAO = new DepartmentHibernateImpl();
		List<Department> departmentList = departmentDAO.getAllDepartments();
		
		HttpSession session = request.getSession();
		session.setAttribute("departmentList", departmentList);
		session.setAttribute("bolumekle", 0);
		session.setAttribute("bolumsil", 0);
		
		response.sendRedirect("admin/bolumleri-gor.jsp");
	}

}
