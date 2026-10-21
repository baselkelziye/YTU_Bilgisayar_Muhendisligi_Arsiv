package org.servlet.category;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.model.Announcement;
import org.db.model.AnnouncementCategory;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 04.12.2016.
 */
@WebServlet("/deletecategory")
public class DeleteCategoryServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        int id = Integer.parseInt(request.getParameter("id"));
        AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();

        if(categoryDAO.deleteCategory(id)) {
            List<AnnouncementCategory> categoryList = categoryDAO.getParentCategories();
            session.setAttribute("categoryList", categoryList);
            session.setAttribute("kategorisil", 1);
        } else {
            session.setAttribute("kategorisil", 2);
        }

        session.setAttribute("kategorieklendi", 0);
        response.sendRedirect("admin/kategori-ekle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
