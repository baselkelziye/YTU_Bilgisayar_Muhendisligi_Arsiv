/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.servlet.admin;

import java.io.IOException;
import java.util.List;

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
 *
 * @author must
 */
@WebServlet(name = "ReadMessageServlet", urlPatterns = {"/readmessageservlet"})
public class ReadMessageServlet extends HttpServlet {
   
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
    	
    	MessageDAO messageDAO = new MessageHibernateImpl();
        List<Message> messages = messageDAO.readMessages();
        
        HttpSession session = request.getSession();
        session.setAttribute("message", messages);
        
        response.sendRedirect("admin/mesajlari-gor.jsp");
    }

}
