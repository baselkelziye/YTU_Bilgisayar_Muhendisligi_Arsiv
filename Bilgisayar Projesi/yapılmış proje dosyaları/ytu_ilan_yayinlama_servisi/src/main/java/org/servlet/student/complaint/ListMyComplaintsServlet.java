package org.servlet.student.complaint;

import org.db.dao.ComplaintDAO;
import org.db.hibernate.ComplaintHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.Complaint;
import org.db.model.Student;
import org.db.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 11.12.2016.
 */
@WebServlet(name = "ListMyComplaintsServlet", urlPatterns = {"/listmycomplaints"})
public class ListMyComplaintsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        /*ComplaintDAO  complaintDAO = new ComplaintHibernateImpl();

        List<Complaint> myComplaints = complaintDAO.getStudentCompl*/

        Student student = (Student) session.getAttribute("user");
        student = (Student) new UserHibernateImpl().getUser(student.getUserName());
        session.setAttribute("user", student);
        session.setAttribute("sikayetgericek", 0);
        response.sendRedirect("student/sikayetlerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
