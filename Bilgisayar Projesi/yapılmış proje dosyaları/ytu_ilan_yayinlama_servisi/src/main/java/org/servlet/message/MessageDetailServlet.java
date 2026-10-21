package org.servlet.message;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.MessageDAO;
import org.db.hibernate.MessageHibernateImpl;
import org.db.model.Message;

/**
 * Servlet implementation class MessageDetailServlet
 */
@WebServlet("/messagedetail")
public class MessageDetailServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public MessageDetailServlet() {
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
		int messageNo = Integer.parseInt(request.getParameter("messagePK"));
		HttpSession httpSession = request.getSession();
		MessageDAO messageDAO = new MessageHibernateImpl();
		Message message = messageDAO.getMessage(messageNo);
		
		if(message == null) {
			httpSession.setAttribute("mesajyok", 1);
		} else {
			httpSession.setAttribute("mesajyok", 0);
			httpSession.setAttribute("message", message);
		}
		
		response.sendRedirect("admin/mesaj-oku.jsp");
	}

}
