package org.servlet.admin;

import org.db.dao.DonationAcceptUnitDAO;
import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.SpendingRequestHibernateImpl;
import org.db.model.DonationAcceptUnit;
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
@WebServlet(name = "SpendingRequestOrderServlet", urlPatterns={"/spendingrequestorder"})
public class SpendingRequestOrderServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String query = (String) session.getAttribute("harcamasorgu");
        query += " order by ";
        query += request.getParameter("condition");
        query += " " + request.getParameter("type");

        SpendingRequestDAO srDAO = new SpendingRequestHibernateImpl();
        List<SpendingRequest> srList = srDAO.getSpendingRequestByQuery(query);

        DonationAcceptUnitDAO dauDAO  = new DauHibernateImpl();
        List<DonationAcceptUnit> dauList = dauDAO.getAllUnits();
        session.setAttribute("dauList", dauList);

        session.setAttribute("srList", srList);
        response.sendRedirect("admin/harcama-istekleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
