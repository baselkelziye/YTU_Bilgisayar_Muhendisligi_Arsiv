package org.servlet.student.interests;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.dao.AnnouncementTypeDAO;
import org.db.dao.InterestsDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.hibernate.AnnouncementTypeHibernateImpl;
import org.db.hibernate.InterestsHibernateImpl;
import org.db.model.AnnouncementCategory;
import org.db.model.AnnouncementType;
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
@WebServlet(name = "ListMyInterestsServlet", urlPatterns = {"/listmyinterests"})
public class ListMyInterestsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("eklendi", 0);
        session.setAttribute("silindi", 0);
        session.setAttribute("guncellendi", 0);

        Student student = (Student) session.getAttribute("user");
        InterestsDAO interestsDAO = new InterestsHibernateImpl();
        List<Interests> myInterests = interestsDAO.getMyInterests(student.getUserName());

        AnnouncementTypeDAO annTypeDAO = new AnnouncementTypeHibernateImpl();
        List<AnnouncementType> annType = annTypeDAO.getAllAnnouncementTypes();

        AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
        List<AnnouncementCategory> category = categoryDAO.getAllCategories();

        session.setAttribute("annType", annType);
        session.setAttribute("categoryList", category);
        session.setAttribute("interests", myInterests);

        response.sendRedirect("student/ilgilendiklerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
