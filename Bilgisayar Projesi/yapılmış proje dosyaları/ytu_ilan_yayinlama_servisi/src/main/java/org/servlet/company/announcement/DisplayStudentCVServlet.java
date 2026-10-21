package org.servlet.company.announcement;

import org.db.dao.StudentDAO;
import org.db.hibernate.EducationInfoHibernateImpl;
import org.db.hibernate.StudentHibernateImpl;
import org.db.model.EducationInfo;
import org.db.model.Student;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 28.01.2017.
 */
@WebServlet(name = "DisplayStudentCVServlet", urlPatterns = {"/displaystudentcv"})
public class DisplayStudentCVServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String username = request.getParameter("username");

        Student student = new StudentHibernateImpl().getStudent(username);
        List<EducationInfo> educationInfoList = new EducationInfoHibernateImpl().getByStudent(student.getUserName());
        session.setAttribute("educationList", educationInfoList);
        session.setAttribute("commWays", student.getCommWays());
        session.setAttribute("student", student);
        response.sendRedirect("company/ogrenci-cv.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
