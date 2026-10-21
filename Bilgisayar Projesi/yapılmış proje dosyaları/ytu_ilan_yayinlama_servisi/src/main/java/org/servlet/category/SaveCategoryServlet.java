package org.servlet.category;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.model.AnnouncementCategory;

/**
 * Servlet implementation class SaveCategoryServlet
 */
@WebServlet("/savecategory")
public class SaveCategoryServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SaveCategoryServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		
		AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
		HttpSession session = request.getSession();
		AnnouncementCategory category = new AnnouncementCategory();
		category.setCategoryName(request.getParameter("categoryName"));
		category.setParentCategory(Integer.parseInt(request.getParameter("parentCategory")));
		
		if(categoryDAO.isCategoryNameExist(request.getParameter("categoryName"))) {
			session.setAttribute("kategorieklendi", 3);
			session.setAttribute("kategoriadi", request.getParameter("categoryName"));
		} else if(categoryDAO.saveCategory(category)) {
			session.setAttribute("kategorieklendi", 1);
			List<AnnouncementCategory> categoryList = categoryDAO.getParentCategories();
			AnnouncementCategory root = categoryList.get(0);
			session.setAttribute("rootCategory", root);
			session.setAttribute("categoryList", categoryList);
		} else {
			session.setAttribute("kategorieklendi", 2);
		}

		session.setAttribute("kategorisil", 0);
		response.sendRedirect("admin/kategori-ekle.jsp");
	}

}
