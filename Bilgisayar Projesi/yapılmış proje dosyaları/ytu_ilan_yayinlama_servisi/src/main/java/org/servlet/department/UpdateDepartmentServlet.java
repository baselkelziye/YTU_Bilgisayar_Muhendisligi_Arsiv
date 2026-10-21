package org.servlet.department;

import org.db.dao.DepartmentDAO;
import org.db.hibernate.DepartmentHibernateImpl;
import org.db.model.Department;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 03.12.2016.
 */
@WebServlet("/updatedepartment")
public class UpdateDepartmentServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        String oldCode = request.getParameter("oldCode");
        String newCode = request.getParameter("codeChange");
        String name = request.getParameter("name");

        DepartmentDAO departmentDAO = new DepartmentHibernateImpl();
        HttpSession session = request.getSession();
        session.setAttribute("bolumekle", 0);
        session.setAttribute("bolumekle", 0);

        if(departmentDAO.updateDepartment(oldCode, newCode, name)) {
            session.setAttribute("bolumguncelle", 1);
            List<Department> departmentList = departmentDAO.getAllDepartments();
            session.setAttribute("departmentList", departmentList);
        } else {
            session.setAttribute("bolumguncelle", 2);
        }

        response.sendRedirect("admin/bolumleri-gor.jsp");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
