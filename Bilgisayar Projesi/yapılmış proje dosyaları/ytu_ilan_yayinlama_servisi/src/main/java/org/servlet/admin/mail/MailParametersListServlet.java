package org.servlet.admin.mail;

import org.db.dao.GlobalParameterDAO;
import org.db.hibernate.GlobalParameterHibernateImpl;
import org.db.model.GlobalParameter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;
import java.util.Map;

/**
 * Created by mgunes on 27.01.2017.
 */
@WebServlet(name = "MailParametersListServlet", urlPatterns = {"/mailparameterslist"})
public class MailParametersListServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("guncellendi", 0);
        session.setAttribute("parola", 0);

        GlobalParameterDAO parameterDAO = new GlobalParameterHibernateImpl();
        Map<String, String> mailParameters = parameterDAO.getParameters("mail");

        session.setAttribute("mailParameters", mailParameters);
        response.sendRedirect("admin/mail-parametreleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
