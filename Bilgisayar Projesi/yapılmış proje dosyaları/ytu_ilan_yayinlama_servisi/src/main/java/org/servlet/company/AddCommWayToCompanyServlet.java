package org.servlet.company;

import org.db.compositePK.CommunicationWayPK;
import org.db.hibernate.CommunicationWayHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.CommunicationWay;
import org.db.model.Company;
import org.db.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 09.12.2016.
 */
@WebServlet(name = "AddCommWayToCompanyServlet", urlPatterns = {"/addcommwaytocompany"})
public class AddCommWayToCompanyServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("guncelle", 0);
        session.setAttribute("parolaguncelle", 0);
        session.setAttribute("iletisimeklendi", 0);
        session.setAttribute("iletisimsil", 0);
        session.setAttribute("iletisimguncelle", 0);

        Company company = (Company) session.getAttribute("user");

        String newCommType = request.getParameter("newCommType");
        String newCommValue = request.getParameter("newCommValue");

        CommunicationWayPK pk = new CommunicationWayPK();
        pk.setCommType(newCommType);
        pk.setCommValue(newCommValue);

        CommunicationWay way = new CommunicationWay();
        way.setPk(pk);
        way.setUser((User) session.getAttribute("user"));

        if(new CommunicationWayHibernateImpl().saveCommWay(way)) {
            session.setAttribute("iletisimeklendi", 1);
            company = (Company) new UserHibernateImpl().getUser(company.getUserName());
            session.setAttribute("user", company);
        } else {
            session.setAttribute("iletisimeklendi", 2);
        }

        response.sendRedirect("company/profil-duzenle.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
