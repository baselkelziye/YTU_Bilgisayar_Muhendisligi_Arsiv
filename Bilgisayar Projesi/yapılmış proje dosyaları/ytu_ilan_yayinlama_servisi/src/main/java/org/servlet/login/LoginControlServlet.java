package org.servlet.login;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.UserDAO;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.User;

@WebServlet("/logincontrolservlet")
public class LoginControlServlet extends HttpServlet {
    
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
        HttpSession httpSession = request.getSession();
        
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String remember = request.getParameter("rememberMe");
        
        UserDAO userDAO = new UserHibernateImpl();
        User user = userDAO.getUser(username);
        
        //giriste membership status kontrol edilecek
        if(user == null || !user.getPassword().equals(password)) {

        	httpSession.setAttribute("giris", 0);
        	response.sendRedirect("giris-yap.jsp");
        }  else if(user != null && user.getStatus() == 4) {
			httpSession.setAttribute("giris", 3);
			response.sendRedirect("giris-yap.jsp");
		}
        else {
        	if(remember != null && Integer.parseInt(remember) == 1) {
        		Cookie cookieUsername = new Cookie("username", user.getUserName());
        		Cookie cookiePassword = new Cookie("password", user.getPassword());
        		cookieUsername.setMaxAge(60*60*2*24);
        		cookiePassword.setMaxAge(60*60*2*24);
        		response.addCookie(cookieUsername);
        		response.addCookie(cookiePassword);
        	}
        	
        	httpSession.setAttribute("user",user);
        	httpSession.setAttribute("status", user.getStatus());
        	response.sendRedirect(user.getUserType().getMainPage());
        }

    }
}