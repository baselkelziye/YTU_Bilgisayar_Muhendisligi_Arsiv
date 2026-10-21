package org.servlet.student;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.algorithm.FilterAnnouncement;
import org.announcement.SearchCriteria;
import org.db.dao.AnnouncementDAO;
import org.db.hibernate.AnnouncementCategoryHibernateImpl;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.model.Announcement;
import org.db.model.AnnouncementCategory;

/**
 * Servlet implementation class SearchAnnouncementServlet
 */
@WebServlet("/searchannouncement")
public class SearchAnnouncementServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");

		int categoryId = Integer.parseInt(request.getParameter("category"));
        int annTypeId = Integer.parseInt(request.getParameter("type"));
        String language = request.getParameter("language");

        StringBuilder sql = new StringBuilder();

        sql.append("SELECT * FROM announcement WHERE now() between publish_date and expired_date" +
                " and state <> 4 and visibility = true ");

        //İlan tipi seçildiyse sorguya ekle
        if(annTypeId != -1) {
            sql.append(" AND announcement_type = " + annTypeId + " ");
        }

        //ilan kategorisi seçildiyse
        if(categoryId != -1) {
            AnnouncementCategory category = new AnnouncementCategoryHibernateImpl().getCategory(categoryId);

            if(category.getParentCategory() == 0) { //ana kategori, alt kategoriler de gelecek
                sql.append(" AND announcement_category IN " +
                        "(select id from announcement_category where parent_category_id = " + categoryId + ") ");
            } else {
                sql.append(" AND announcement_category = " + categoryId + " ");
            }
        }

        //Dil seçimi
        if(!language.equals("alllanguages")) {
            sql.append(" AND announcement_language = '" + language + "' ");
        }

        //anahtar kelimeler varsa parse et
        if(request.getParameter("keywords") != null) {
            String[] keywords = request.getParameter("keywords").split(",");
            sql.append(" AND ( ");

            for(String s: keywords) {
                s = s.trim();
                sql.append(" title LIKE '%" + s + "%' OR  brief LIKE '%" + s + "%' OR content LIKE '%" + s + "%' OR ");
            }

            sql.append(" 1 = 0 )");
        }

        AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
        List<Announcement> annList = annDAO.getBySQLCriteria(sql.toString());
		
		HttpSession session = request.getSession();
        session.setAttribute("searchannouncementquery", sql.toString());
        session.setAttribute("announcements", annList);
		
		response.sendRedirect("student/ilan-ara.jsp");
	}

}
