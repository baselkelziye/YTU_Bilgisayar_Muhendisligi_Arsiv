package org.servlet.admin.mail;

import com.sun.org.apache.regexp.internal.RE;
import org.db.dao.GlobalParameterDAO;
import org.db.hibernate.GlobalParameterHibernateImpl;

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
@WebServlet(name = "UpdateMailPasswordServlet", urlPatterns = {"/updatemailpassword"})
public class UpdateMailPasswordServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        HttpSession session = request.getSession();
        session.setAttribute("guncellendi", 0);
        session.setAttribute("parola", 0);

        String password = request.getParameter("password");

        Map<String, String> mailParameters = new HashMap<String, String>();
        mailParameters.put("Mail Parola", password);

        GlobalParameterDAO parameterDAO = new GlobalParameterHibernateImpl();

        if(parameterDAO.updateParameters(mailParameters)) {
            session.setAttribute("parola", 1);
            parameterDAO = new GlobalParameterHibernateImpl();
            mailParameters = parameterDAO.getParameters("mail");

            session.setAttribute("mailParameters", mailParameters);
        } else {
            session.setAttribute("parola", 2);
        }

        response.sendRedirect("admin/mail-parametreleri.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
