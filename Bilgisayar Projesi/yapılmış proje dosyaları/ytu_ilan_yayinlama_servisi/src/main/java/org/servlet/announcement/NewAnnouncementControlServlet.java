package org.servlet.announcement;

import java.io.IOException;
import java.util.ArrayList;
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
 * Servlet implementation class NewAnnouncementControlServlet
 */
@WebServlet("/newannouncementcontrolservlet")
public class NewAnnouncementControlServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public NewAnnouncementControlServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession httpSession = request.getSession();
		List<AnnouncementType> annType = new ArrayList<AnnouncementType>();
		AnnouncementTypeDAO annTypeDAO = new AnnouncementTypeHibernateImpl();
		AnnouncementCategoryDAO categoryDAO = new AnnouncementCategoryHibernateImpl();
		List<AnnouncementCategory> categoryList = categoryDAO.getParentCategories();
		
		annType = annTypeDAO.getAllAnnouncementTypes();
		httpSession.setAttribute("categoryList", categoryList);
		httpSession.setAttribute("annType", annType);
		httpSession.setAttribute("olusturuldu", 0);
		response.sendRedirect("company/ilan-olustur.jsp");
	}

}
