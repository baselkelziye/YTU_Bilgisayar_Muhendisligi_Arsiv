package org.servlet.student;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.dao.AnnouncementTypeDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.hibernate.AnnouncementTypeHibernateImpl;
import org.db.model.AnnouncementCategory;
import org.db.model.AnnouncementType;

/**
 * Servlet implementation class SearchInitializeServlet
 */
@WebServlet("/searchinitialize")
public class SearchInitializeServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SearchInitializeServlet() {
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
		AnnouncementTypeDAO annTypeDAO = new AnnouncementTypeHibernateImpl();
		List<AnnouncementType> annType = annTypeDAO.getAllAnnouncementTypes();
		
		AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
		List<AnnouncementCategory> category = categoryDAO.getAllCategories();
		
		HttpSession session = request.getSession();
		session.setAttribute("annType", annType);
		session.setAttribute("categoryList", category);
		
		response.sendRedirect("student/ilan-ara.jsp");
	}

}
