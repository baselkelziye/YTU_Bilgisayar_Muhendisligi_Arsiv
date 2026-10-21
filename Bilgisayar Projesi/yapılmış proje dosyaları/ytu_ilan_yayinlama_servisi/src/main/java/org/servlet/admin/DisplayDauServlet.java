package org.servlet.admin;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.DonationAcceptUnitDAO;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.DonationAcceptUnit;

@WebServlet(name = "DisplayDauServlet", urlPatterns = {"/displaydauservlet"})
public class DisplayDauServlet extends HttpServlet {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
    	DonationAcceptUnitDAO dauDAO  = new DauHibernateImpl();
        List<DonationAcceptUnit> dauList = dauDAO.getAllUnits();
        
        HttpSession session = request.getSession();
        session.setAttribute("dauList", dauList);
        session.setAttribute("bkbsil", 0);
        
        response.sendRedirect("admin/bkb-duzenle.jsp");
    }

}
