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
 * Created by mgunes on 08.01.2017.
 */
@WebServlet(name = "UpdateInterestsServlet", urlPatterns = {"/updateinterests"})
public class UpdateInterestsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        HttpSession session = request.getSession();
        session.setAttribute("eklendi", 0);
        session.setAttribute("silindi", 0);

        Student student = (Student) session.getAttribute("user");
        String name = request.getParameter("name");
        int category = Integer.parseInt(request.getParameter("category"));
        int type = Integer.parseInt(request.getParameter("type"));
        String language = request.getParameter("language");
        String keywords = request.getParameter("keywords");

        Interests interests = new Interests();
        interests.setName(name);
        interests.setStudent(student);
        interests.setCategory(new AnnouncementCategory(category));
        interests.setKeywords(keywords);
        interests.setLanguage(language);
        interests.setType(new AnnouncementType(type));

        String oldName = request.getParameter("oldName");
        InterestsDAO interestsDAO = new InterestsHibernateImpl();

        if(interestsDAO.updateInterests(oldName, interests)) {
            session.setAttribute("guncellendi", 1);

            List<Interests> myInterests = interestsDAO.getMyInterests(student.getUserName());

            AnnouncementTypeDAO annTypeDAO = new AnnouncementTypeHibernateImpl();
            List<AnnouncementType> annType = annTypeDAO.getAllAnnouncementTypes();

            AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
            List<AnnouncementCategory> categoryList = categoryDAO.getAllCategories();

            session.setAttribute("annType", annType);
            session.setAttribute("categoryList", categoryList);
            session.setAttribute("interests", myInterests);
        } else {
            session.setAttribute("guncellendi", 2);
        }

        response.sendRedirect("student/ilgilendiklerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
