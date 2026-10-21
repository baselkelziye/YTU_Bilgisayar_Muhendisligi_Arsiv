package org.servlet.dau.spendingrequest;

import org.db.dao.DauUserDAO;
import org.db.dao.DonationAcceptUnitDAO;
import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.DauUserHibernateImpl;
import org.db.hibernate.SRStateHibernateImpl;
import org.db.hibernate.SpendingRequestHibernateImpl;
import org.db.model.DauUser;
import org.db.model.DonationAcceptUnit;
import org.db.model.SpendingRequest;
import org.db.model.SpendingRequestState;

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
@WebServlet(name = "SpendingRequestOrderForDauServlet", urlPatterns = {"/spendingrequestorderfordau"})
public class SpendingRequestOrderForDauServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        DauUser user = (DauUser) session.getAttribute("user");

        String query = (String) session.getAttribute("spendingRequestQuery");
        query += " order by ";
        query += request.getParameter("condition");
        query += " " + request.getParameter("type");

        SpendingRequestDAO srDAO = new SpendingRequestHibernateImpl();
        List<SpendingRequest> srList = srDAO.getSpendingRequestByQuery(query);

        DauUserDAO dauUserDAO = new DauUserHibernateImpl();
        List<DauUser> dauUsers = dauUserDAO.getUsersFromDau(user.getDau().getUnitName());

        List<SpendingRequestState> states = new SRStateHibernateImpl().getAllStates();
        session.setAttribute("stateList", states);

        session.setAttribute("userList", dauUsers);

        session.setAttribute("spendingList", srList);
        response.sendRedirect("dau/harcama-istekleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
