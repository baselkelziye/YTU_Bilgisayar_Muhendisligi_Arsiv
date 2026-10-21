package org.servlet.student.complaint;

import org.db.dao.ComplaintDAO;
import org.db.hibernate.ComplaintHibernateImpl;
import org.db.model.Complaint;
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
 * Created by mgunes on 10.01.2017.
 */
@WebServlet(name = "MyComplaintOrderServlet", urlPatterns = {"/mycomplaintorder"})
public class MyComplaintOrderServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        Student student = (Student) session.getAttribute("user");
        String query = new String();
        String condition = request.getParameter("condition");
        String type = request.getParameter("type");

        if(condition.equals("complaint_time")) {
            query = (String) session.getAttribute("sikayetsorgu");
            query += " ORDER BY complaint_time " + type;
        } else if(condition.equals("company_name")) {
            query = "select c1.id, c1.student, c1.announcement, c1.description, c1.complaint_time, c1.result, c1.result_time, c1.result_reply " +
            " from complaint c1, company c2, announcement a " +
            " where c1.student = '" + student.getUserName() + "' and " +
                    " c1.announcement = a.id and a.owner_company = c2.user_name order by c2.company_name " + type;
        } else if(condition.equals("title")) {
            query = "select c1.id, c1.student, c1.announcement, c1.description, c1.complaint_time, c1.result, c1.result_time, c1.result_reply " +
                    " from complaint c1, company c2, announcement a " +
                    " where c1.student = '" + student.getUserName() + "' and " +
                    " c1.announcement = a.id and a.owner_company = c2.user_name order by a.title " + type;
        }

        ComplaintDAO complaintDAO = new ComplaintHibernateImpl();
        List<Complaint> complaintList = complaintDAO.getComplaintBySQLQuery(query);
        session.setAttribute("complaintList", complaintList);

        response.sendRedirect("student/sikayetlerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
