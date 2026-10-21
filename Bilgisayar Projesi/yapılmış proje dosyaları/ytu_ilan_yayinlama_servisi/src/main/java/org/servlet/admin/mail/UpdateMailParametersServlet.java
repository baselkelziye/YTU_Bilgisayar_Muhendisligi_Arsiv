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
import java.util.HashMap;
import java.util.Map;

/**
 * Created by mgunes on 27.01.2017.
 */
@WebServlet(name = "UpdateMailParametersServlet", urlPatterns = {"/updatemailparameters"})
public class UpdateMailParametersServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        HttpSession session = request.getSession();
        session.setAttribute("parola", 0);

        String mailAddress = request.getParameter("mailAddress");
        String username = request.getParameter("username");
        String port = request.getParameter("port");
        String host = request.getParameter("host");

        Map<String, String> mailParameters = new HashMap<String, String>();
        mailParameters.put("Mail Adresi", mailAddress);
        mailParameters.put("Kullanıcı Adı",username);
        mailParameters.put("Host", host);
        mailParameters.put("Port", port);

        GlobalParameterDAO parameterDAO = new GlobalParameterHibernateImpl();

        if(parameterDAO.updateParameters(mailParameters)) {
            session.setAttribute("guncellendi", 1);
            parameterDAO = new GlobalParameterHibernateImpl();
            mailParameters = parameterDAO.getParameters("mail");

            session.setAttribute("mailParameters", mailParameters);
        } else {
            session.setAttribute("guncellendi", 2);
        }

        response.sendRedirect("admin/mail-parametreleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
