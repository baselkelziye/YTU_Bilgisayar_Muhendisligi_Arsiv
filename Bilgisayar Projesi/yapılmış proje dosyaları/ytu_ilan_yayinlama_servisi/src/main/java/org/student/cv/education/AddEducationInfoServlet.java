package org.student.cv.education;

import org.db.dao.EducationInfoDAO;
import org.db.hibernate.EducationInfoHibernateImpl;
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
 * Created by mgunes on 27.01.2017.
 */
@WebServlet(name = "AddEducationInfoServlet", urlPatterns = {"/addeducationinfo"})
public class AddEducationInfoServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();
        session.setAttribute("personal", 0);
        session.setAttribute("iletisim", 0);
        Student student = (Student) session.getAttribute("user");

        String school = request.getParameter("school");
        String department = request.getParameter("department");
        String degree = request.getParameter("degree");
        int start = Integer.parseInt(request.getParameter("start"));
        int end = Integer.parseInt(request.getParameter("end"));

        EducationInfo info = new EducationInfo();
        info.setDegree(degree);
        info.setDepartment(department);
        info.setEndDate(end);
        info.setSchool(school);
        info.setStartDate(start);
        info.setStudent(student);

        EducationInfoDAO infoDAO = new EducationInfoHibernateImpl();

        if(infoDAO.saveEducationInfo(info)) {
            session.setAttribute("egitim", 1);
            List<EducationInfo> educationInfoList = new EducationInfoHibernateImpl().getByStudent(student.getUserName());
            session.setAttribute("educationList", educationInfoList);
        } else {
            session.setAttribute("egitim", 2);
        }

        response.sendRedirect("student/cv-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
