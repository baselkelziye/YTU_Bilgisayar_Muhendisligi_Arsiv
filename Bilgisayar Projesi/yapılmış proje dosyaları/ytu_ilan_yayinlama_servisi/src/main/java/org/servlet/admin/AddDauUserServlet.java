package org.servlet.admin;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.DauUserDAO;
import org.db.dao.UserDAO;
import org.db.dao.UserTypeDAO;
import org.db.hibernate.DauUserHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.hibernate.UserTypeHibernateImpl;
import org.db.model.DauUser;
import org.db.model.DonationAcceptUnit;
import org.db.model.UserType;

/**
 * Servlet implementation class AddDauUserServlet
 */
@WebServlet("/adddauuserservlet")
public class AddDauUserServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddDauUserServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
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
        	httpSession.setAttribute("kullanicieklendi", 1);
        } else {
        	httpSession.setAttribute("kullanicieklendi", 2);
        }							  
        
        httpSession.setAttribute("vakifolusturuldu", 0);
        httpSession.setAttribute("hesapeklendi", 0);
        
        response.sendRedirect("admin/bkb-olustur.jsp");
	}

}
