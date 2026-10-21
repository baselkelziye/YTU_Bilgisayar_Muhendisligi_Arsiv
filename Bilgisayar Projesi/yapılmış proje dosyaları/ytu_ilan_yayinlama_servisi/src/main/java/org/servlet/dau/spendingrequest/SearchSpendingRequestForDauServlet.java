package org.servlet.dau.spendingrequest;

import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.SpendingRequestHibernateImpl;
import org.db.model.DauUser;
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
 * Created by mgunes on 27.01.2017.
 */
@WebServlet(name = "SearchSpendingRequestForDauServlet", urlPatterns = {"/searchspendingrequestfordau"})
public class SearchSpendingRequestForDauServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        DauUser user = (DauUser) session.getAttribute("user");
        String unitName = user.getDau().getUnitName();

        StringBuilder spendingRequestQuery = new StringBuilder();
        spendingRequestQuery.append("SELECT * FROM spending_request WHERE dau = '" + unitName + "' ");

        String userName = request.getParameter("username");
        int state = Integer.parseInt(request.getParameter("state"));

        if(!userName.equals("all")) {
            spendingRequestQuery.append(" AND updater = '" + userName + "' ");
        }

        if(state != -1) {
            spendingRequestQuery.append(" AND state = " + state + " ");
        }

        session.setAttribute("spendingRequestQuery", spendingRequestQuery.toString());

        SpendingRequestDAO spendingDAO = new SpendingRequestHibernateImpl();
        List<SpendingRequest> spendingRequestList = spendingDAO.getSpendingRequestByQuery(spendingRequestQuery.toString());
        session.setAttribute("spendingList", spendingRequestList);

        response.sendRedirect("dau/harcama-istekleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
