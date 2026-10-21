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
@WebServlet(name = "SearchMyComplaintServlet", urlPatterns = {"/searchmycomplaint"})
public class SearchMyComplaintServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        HttpSession session = request.getSession();
        Student student = (Student) session.getAttribute("user");

        String type = request.getParameter("result");
        String query = "SELECT * FROM complaint WHERE student = '" + student.getUserName() + "' ";

        if(type.equals("Bekleyen")) {
            query += " AND result is null ";
        } else if(type.equals("Sonuçlanan")) {
            query += " AND result is not null ";
        }

        ComplaintDAO complaintDAO = new ComplaintHibernateImpl();
        List<Complaint> complaintList = complaintDAO.getComplaintBySQLQuery(query);

        session.setAttribute("complaintList", complaintList);
        session.setAttribute("sikayetsorgu", query);
        response.sendRedirect("student/sikayetlerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
