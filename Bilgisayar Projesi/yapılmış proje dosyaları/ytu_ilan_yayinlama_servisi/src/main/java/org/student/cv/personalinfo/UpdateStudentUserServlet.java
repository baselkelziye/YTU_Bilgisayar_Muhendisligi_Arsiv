package org.student.cv.personalinfo;

import org.db.dao.UserDAO;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.Student;

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
@WebServlet(name = "UpdateStudentUserServlet", urlPatterns = {"/updatestudentuser"})
public class UpdateStudentUserServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();
        session.setAttribute("iletisim", 0);
        session.setAttribute("egitim", 0);

        String name = request.getParameter("name");
        String surname = request.getParameter("surname");
        int birthDate = Integer.parseInt(request.getParameter("birthdate"));

        Student student = (Student) session.getAttribute("user");
        student.setName(name);
        student.setSurname(surname);
        student.setBirthDate(birthDate);

        UserDAO userDAO = new UserHibernateImpl();

        if(userDAO.update(student)) {
            session.setAttribute("personal", 1);
            student = (Student) userDAO.getUser(student.getUserName());
            session.setAttribute("user", student);
        } else {
            session.setAttribute("personal", 2);
        }

        response.sendRedirect("student/cv-duzenle.jsp");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
