package org.student.cv.communicationway;

import org.db.dao.CommunicationWayDAO;
import org.db.dao.StudentDAO;
import org.db.hibernate.CommunicationWayHibernateImpl;
import org.db.hibernate.StudentHibernateImpl;
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
@WebServlet(name = "UpdateStudentCommWayServlet", urlPatterns = {"/updatestudentcommway"})
public class UpdateStudentCommWayServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        HttpSession session = request.getSession();
        session.setAttribute("personal", 0);
        session.setAttribute("egitim", 0);
        User user = (User) request.getSession().getAttribute("user");

        String type = request.getParameter("type");
        String value = request.getParameter("value");
        String oldType = request.getParameter("oldType");
        String oldValue = request.getParameter("oldValue");

        CommunicationWayDAO wayDAO = new CommunicationWayHibernateImpl();

        if(wayDAO.updateCommWay(user.getUserName(), oldType, oldValue, type, value)) {
            session.setAttribute("iletisim", 5);
            StudentDAO studentDAO = new StudentHibernateImpl();
            Student student = studentDAO.getStudent(user.getUserName());
            session.setAttribute("commWays", student.getCommWays());
        } else {
            session.setAttribute("iletisim", 6);
        }

        response.sendRedirect("student/cv-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
