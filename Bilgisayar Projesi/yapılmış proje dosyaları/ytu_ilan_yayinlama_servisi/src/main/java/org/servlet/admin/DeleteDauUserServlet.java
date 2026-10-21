package org.servlet.admin;

import org.db.dao.DauUserDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.DauUserHibernateImpl;
import org.db.model.DauUser;
import org.db.model.DonationAcceptUnit;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 22.12.2016.
 */
@WebServlet(name = "DeleteDauUserServlet", urlPatterns = {"/deletedauuser"})
public class DeleteDauUserServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String username = request.getParameter("username");

        DauUserDAO userDAO = new DauUserHibernateImpl();

        if(userDAO.deleteUser(username)) {
            DonationAcceptUnit dau = (DonationAcceptUnit) session.getAttribute("dau");
            dau = new DauHibernateImpl().getUnit(dau.getUnitName());
            session.setAttribute("dau", dau);
            session.setAttribute("kullanicisil", 1);
        } else {
            session.setAttribute("kullanicisil", 2);
        }

        session.setAttribute("hesapeklendi", 0);
        session.setAttribute("kullanicieklendi", 0);
        session.setAttribute("hesapsil", 0);
        session.setAttribute("hesapguncellendi", 0);

        response.sendRedirect("admin/bkb-detay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
