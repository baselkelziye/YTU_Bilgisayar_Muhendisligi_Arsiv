package org.servlet.student.interests;

import org.db.dao.InterestsDAO;
import org.db.hibernate.InterestsHibernateImpl;
import org.db.model.Interests;
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
 * Created by mgunes on 07.01.2017.
 */
@WebServlet(name = "InterestsOrderServlet", urlPatterns = {"/interestsorder"})
public class InterestsOrderServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String condition = request.getParameter("condition");
        String order = request.getParameter("type");
        String query = "";
        Student student = (Student) session.getAttribute("user");

        if(condition.equals("category")) {
            query = "select i.name, i.student, i.category, i.ann_type, i.language, i.keywords " +
                    " from interests i, announcement_category a " +
                    " where i.category = a.id AND student = '" + student.getUserName() + "' order by a.category_name " + order;

        } else {
            query = "SELECT * FROM interests WHERE student = '" + student.getUserName() + "' ORDER BY " + condition + " " + order;
        }

        InterestsDAO interestsDAO = new InterestsHibernateImpl();
        List<Interests> orderedInterests = interestsDAO.getInterestsByQuery(query);

        session.setAttribute("interests", orderedInterests);
        session.setAttribute("eklendi", 0);
        session.setAttribute("silindi", 0);

        response.sendRedirect("student/ilgilendiklerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
