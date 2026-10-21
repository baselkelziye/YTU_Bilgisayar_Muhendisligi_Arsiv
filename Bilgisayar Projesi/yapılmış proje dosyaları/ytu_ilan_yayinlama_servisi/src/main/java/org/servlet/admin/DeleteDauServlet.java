package org.servlet.admin;

import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.DonationAcceptUnit;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * Created by mgunes on 08.12.2016.
 */
@WebServlet("/deletedau")
public class DeleteDauServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String unitName = request.getParameter("unitName");
        DonationAcceptUnitDAO dauDAO = new DauHibernateImpl();

        if(dauDAO.deleteDau(unitName)) {
            session.setAttribute("bkbsil", 1);
            List<DonationAcceptUnit> dauList = dauDAO.getAllUnits();
            session.setAttribute("dauList", dauList);
        } else {
            session.setAttribute("bkbsil", 2);
        }

        response.sendRedirect("admin/bkb-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
