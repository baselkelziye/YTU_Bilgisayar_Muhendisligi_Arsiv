package org.servlet.admin;

import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.SpendingRequestHibernateImpl;
import org.db.model.SpendingRequest;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 06.12.2016.
 */
@WebServlet(name = "SpendingRequestDauServlet", urlPatterns = {"/spendingrequestdau"})
public class SpendingRequestDauServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();

        int state = Integer.parseInt(request.getParameter("state"));
        String dauName = request.getParameter("department");

        StringBuilder query = new StringBuilder();
        query.append("SELECT * FROM spending_request WHERE 1 = 1 ");

        if(state != -1) {
            query.append(" AND state = " + state + " ");
        }

        if(!dauName.equals("Tüm Birimler")) {
            query.append(" AND dau = '" + dauName + "' ");
        }

        session.setAttribute("harcamasorgu", query.toString());

        SpendingRequestDAO srDAO = new SpendingRequestHibernateImpl();
        List<SpendingRequest> srList = srDAO.getSpendingRequestByQuery(query.toString());

        session.setAttribute("srList", srList);
        response.sendRedirect("admin/harcama-istekleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
