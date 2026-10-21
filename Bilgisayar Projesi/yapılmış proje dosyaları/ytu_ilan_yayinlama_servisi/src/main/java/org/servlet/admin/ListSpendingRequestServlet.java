package org.servlet.admin;

import org.db.dao.DonationAcceptUnitDAO;
import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.SRStateHibernateImpl;
import org.db.hibernate.SpendingRequestHibernateImpl;
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
import java.util.ArrayList;
import java.util.List;

/**
 * Created by mgunes on 06.12.2016.
 */
@WebServlet(name = "ListSpendingRequestServlet", urlPatterns = {"/listspendingrequesttoadmin"})
public class ListSpendingRequestServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        //String query = "SELECT * FROM spending_request";
        //session.setAttribute("harcamasorgu", query);

        SpendingRequestDAO spendingRequestDAO = new SpendingRequestHibernateImpl();
        List<SpendingRequest> spendingRequestList = spendingRequestDAO.getAllSpendingRequest();
        //session.setAttribute("srList", spendingRequestList);

        DonationAcceptUnitDAO dauDAO  = new DauHibernateImpl();
        List<DonationAcceptUnit> dauList = dauDAO.getAllUnits();
        List<SpendingRequestState> states = new SRStateHibernateImpl().getAllStates();

        session.setAttribute("srList", new ArrayList<SpendingRequest>());
        session.setAttribute("dauList", dauList);
        session.setAttribute("stateList", states);

        response.sendRedirect("admin/harcama-istekleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
