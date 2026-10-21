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
 * Servlet implementation class DeleteDepartmentServlet
 */
@WebServlet("/deletedepartment")
public class DeleteDepartmentServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteDepartmentServlet() {
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
		String code = request.getParameter("code");
		HttpSession session = request.getSession();
		session.setAttribute("bolumekle", 0);
        session.setAttribute("bolumguncelle", 0);
		
		DepartmentDAO departmentDAO = new DepartmentHibernateImpl();
		
		if(departmentDAO.deleteDepartment(code)) {
			List<Department> departmentList = departmentDAO.getAllDepartments();
			session.setAttribute("departmentList", departmentList);
			session.setAttribute("bolumsil", 1);	
		} else {
			session.setAttribute("bolumsil", 2);
		}
		
		response.sendRedirect("admin/bolumleri-gor.jsp");
		
	}

}
