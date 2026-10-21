package org.servlet.student;

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

@WebServlet(name = "StudentRegisterServlet", urlPatterns = {"/studentsaveinitializeservlet"})
public class StudentSaveInitializeServlet extends HttpServlet {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;


	@Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }


    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    	DepartmentDAO departmentDAO = new DepartmentHibernateImpl();
    	List<Department> departments = departmentDAO.getAllDepartments();
    	HttpSession httpSession =  request.getSession();
    	
		httpSession.setAttribute("kayit", 0);
		httpSession.setAttribute("departments", departments);
    	
        response.sendRedirect("ogrenci-kayit.jsp");
    }


}
