package org.servlet.admin;

import org.db.dao.DauUserDAO;
import org.db.dao.UserDAO;
import org.db.dao.UserTypeDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.hibernate.DauUserHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.hibernate.UserTypeHibernateImpl;
import org.db.model.DauUser;
import org.db.model.DonationAcceptUnit;
import org.db.model.UserType;

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
@WebServlet(name = "UserExistDauServlet", urlPatterns = {"/userexistdau"})
public class UserExistDauServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession httpSession = request.getSession();

        DauUser dauUser = new DauUser();
        dauUser.setUserName(request.getParameter("username"));
        dauUser.setPassword(request.getParameter("password"));
        dauUser.setName(request.getParameter("name"));
        dauUser.setSurname(request.getParameter("surname"));
        dauUser.setContactMail(request.getParameter("contactMail"));
        dauUser.setContactTel(request.getParameter("contactTel"));

        UserTypeDAO typeDAO = new UserTypeHibernateImpl();
        UserType type  = typeDAO.getUserType(1);

        dauUser.setUserTypeNo(type);

        DonationAcceptUnit dau = (DonationAcceptUnit) httpSession.getAttribute("dau");
        dauUser.setDau(dau);

        DauUserDAO dauUserDAO = new DauUserHibernateImpl();
        UserDAO userDAO = new UserHibernateImpl();

        if(httpSession.getAttribute("dau") == null) {
            httpSession.setAttribute("kullanicieklendi", 4);
        } else if(userDAO.isUserExist(dauUser.getUserName())) {
            httpSession.setAttribute("kullanicieklendi", 3);
        } else if(dauUserDAO.saveDauUser(dauUser)) {
            dau = new DauHibernateImpl().getUnit(dau.getUnitName());
            httpSession.setAttribute("dau", dau);
            httpSession.setAttribute("kullanicieklendi", 1);
        } else {
            httpSession.setAttribute("kullanicieklendi", 2);
        }

        httpSession.setAttribute("kullanicisil", 0);
        httpSession.setAttribute("hesapeklendi", 0);
        httpSession.setAttribute("hesapsil", 0);
        httpSession.setAttribute("hesapguncellendi", 0);

        response.sendRedirect("admin/bkb-detay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
