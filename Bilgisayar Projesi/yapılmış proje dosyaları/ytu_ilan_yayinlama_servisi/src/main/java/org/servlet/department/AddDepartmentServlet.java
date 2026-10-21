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
 * Servlet implementation class AddDepartmentServlet
 */
@WebServlet("/adddepartment")
public class AddDepartmentServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddDepartmentServlet() {
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
		session.setAttribute("bolumsil", 0);
		session.setAttribute("bolumguncelle", 0);
		request.setCharacterEncoding("UTF-8");
		
		String code = request.getParameter("dcode");
		String name = request.getParameter("dname");
		
		System.out.println(code + " " + name);
		
		Department department = new Department();
		department.setCode(code);
		department.setName(name);
		
		DepartmentDAO departmentDAO = new DepartmentHibernateImpl();
		
		if(departmentDAO.isExist(code)) {
			session.setAttribute("bolumekle", 2);
		} else if(departmentDAO.addDepartment(department)) {
			List<Department> departmentList = departmentDAO.getAllDepartments();
			session.setAttribute("departmentList", departmentList);
			session.setAttribute("bolumekle", 1);
		} else {
			session.setAttribute("bolumekle", 3);
		}
		
		response.sendRedirect("admin/bolumleri-gor.jsp");
	}

}
