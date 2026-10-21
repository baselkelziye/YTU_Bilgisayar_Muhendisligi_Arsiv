package org.servlet.dau;

import org.db.model.DauUser;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 08.12.2016.
 */
@WebServlet(name = "DauPersonalInfoServlet", urlPatterns = {"/daupersonalinfo"})
public class DauPersonalInfoServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session  = request.getSession();
        DauUser user = (DauUser) session.getAttribute("user");
        session.setAttribute("user", user);
        session.setAttribute("guncelle", 0);
        session.setAttribute("parolaguncelle", 0);
        response.sendRedirect("dau/kisisel-bilgilerim.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
