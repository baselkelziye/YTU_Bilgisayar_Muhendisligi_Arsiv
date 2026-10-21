package org.servlet.company;

import org.db.dao.AnnouncementDAO;
import org.db.hibernate.AnnouncementHibernateImpl;
import org.db.model.Announcement;
import org.db.model.Company;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 29.12.2016.
 */
@WebServlet(name = "SearchMyAnnServlet", urlPatterns = {"/searchmyann"})
public class SearchMyAnnServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        HttpSession session = request.getSession();

        Company company = (Company) session.getAttribute("user");
        String language = request.getParameter("language");
        String state = request.getParameter("state");

        StringBuilder query = new StringBuilder();
        query.append("SELECT * FROM announcement WHERE owner_company = '" + company.getUserName() + "' ");

        //dil şartını sorguya ekle
        if(!language.equals("tümü")) {
            query.append(" AND announcement_language = '" + language + "' ");
        }

        if(state.equals("aktif")) {
            query.append(" AND expired_date > now() AND state = 2 ");
        } else if(state.equals("pasif")) {
            query.append(" AND state = 1 ");
        } else if(state.equals("cezalı")) {
            query.append(" AND state = 4 ");
        } else if(state.equals("süresidolmuş")){
            query.append(" AND expired_date < now() AND state = 2 ");
        }

        AnnouncementDAO annDAO = new AnnouncementHibernateImpl();
        List<Announcement> annList = annDAO.getBySQLCriteria(query.toString());

        session.setAttribute("ilansorgu", query.toString());
        session.setAttribute("annList", annList);

        response.sendRedirect("company/ilanlarimda-ara.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
