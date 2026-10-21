package org.servlet.newpassword;

import org.db.dao.UserDAO;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.Student;
import org.db.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 27.01.2017.
 */
@WebServlet(name = "SaveNewPasswordStudentServlet", urlPatterns = {"/savenewpasswordstudent"})
public class SaveNewPasswordStudentServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        Student student = (Student) session.getAttribute("user");
        String password = request.getParameter("password");

        student.setPassword(password);
        student.setStatus(1);

        UserDAO userDAO = new UserHibernateImpl();

        if(userDAO.update(student)) {
            session.setAttribute("yeniparola", 1);
            User user = userDAO.getUser(student.getUserName());
            session.setAttribute("user", user);
        } else {
            session.setAttribute("yeniparola", 2);
        }

        response.sendRedirect("student/index.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
