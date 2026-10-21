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
 * Servlet implementation class AddCategoryServlet
 */
@WebServlet("/addcategory")
public class AddCategoryServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddCategoryServlet() {
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
		AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
		List<AnnouncementCategory> categoryList = categoryDAO.getParentCategories();
		AnnouncementCategory root = categoryList.get(0);
		
		HttpSession session = request.getSession();
		session.setAttribute("categoryList", categoryList);
		session.setAttribute("kategorieklendi", 0);
		session.setAttribute("kategorisil", 0);
        session.setAttribute("kategoriguncelle", 0);
		session.setAttribute("rootCategory", root);
		
		response.sendRedirect("admin/kategori-ekle.jsp");
	}

}
