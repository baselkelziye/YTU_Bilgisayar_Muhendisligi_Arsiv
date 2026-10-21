package org.servlet.student.complaint;

import org.db.dao.ComplaintDAO;
import org.db.hibernate.ComplaintHibernateImpl;
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
 * Created by mgunes on 11.12.2016.
 */
@WebServlet(name = "DeleteComplaintServlet", urlPatterns = {"/deletecomplaint"})
public class DeleteComplaintServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        int annID = Integer.parseInt(request.getParameter("announcementId"));
        Student student = (Student) session.getAttribute("user");
        ComplaintDAO complaintDAO = new ComplaintHibernateImpl();

        if(complaintDAO.deleteComplaint(student.getUserName(), annID)) {
            session.setAttribute("ilangericek", 1);
            session.setAttribute("sikayetedildi", 0);
            session.setAttribute("basvuruldu", 0);
            session.setAttribute("sikayetvar", 2);
            student = (Student) new UserHibernateImpl().getUser(student.getUserName());
            session.setAttribute("user", student);
        } else {
            session.setAttribute("ilangericek", 2);
        }

        response.sendRedirect("student/ilan-detay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
