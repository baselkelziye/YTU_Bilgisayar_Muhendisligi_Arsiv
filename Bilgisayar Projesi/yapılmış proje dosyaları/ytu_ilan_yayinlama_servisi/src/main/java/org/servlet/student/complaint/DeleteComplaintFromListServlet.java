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
 * Created by mgunes on 12.12.2016.
 */
@WebServlet(name = "DeleteComplaintFromListServlet", urlPatterns = {"/deletecomplaintfromlist"})
public class DeleteComplaintFromListServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("basvuruldu", 0);

        int annID = Integer.parseInt(request.getParameter("announcementId"));
        Student student = (Student) session.getAttribute("user");
        ComplaintDAO complaintDAO = new ComplaintHibernateImpl();

        if(complaintDAO.deleteComplaint(student.getUserName(), annID)) {
            session.setAttribute("sikayetgericek", 1);
            student = (Student) new UserHibernateImpl().getUser(student.getUserName());
            session.setAttribute("user", student);
        } else {
            session.setAttribute("sikayetgericek", 2);
        }

        response.sendRedirect("student/sikayetlerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
