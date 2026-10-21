package org.servlet.message;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.compositePK.MessagePK;
import org.db.dao.MessageDAO;
import org.db.hibernate.MessageHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.model.Message;
import org.db.model.Notification;
import org.db.model.User;

@WebServlet(name = "SendMessageServlet", urlPatterns = {"/sendmessageservlet"})
public class SendMessageServlet extends HttpServlet {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Message message;
	private MessagePK pk;
	
	public SendMessageServlet() {
		message = new Message();
		pk = new MessagePK();
	}
    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        message = new Message();
        request.setCharacterEncoding("UTF-8");
        readRequest(request);

        MessageDAO messageDAO = new MessageHibernateImpl();
        HttpSession httpSession = request.getSession();
        
        if(messageDAO.sendMessage(message)) {
        	httpSession.setAttribute("gonderildi", 1);
            //Bildirim
            Notification notification = new Notification(
                    (message.getSenderName() + " " + message.getSenderSurname()),
                    new User("admin"),
                    "Yeni bir mesajınız var",
                    new Date(),
                    "info"
            );
            new NotificationHibernateImpl().saveNotification(notification);
        } else {
        	httpSession.setAttribute("gonderildi", 2);
        }
        
        response.sendRedirect("iletisim.jsp");
    }

    private void readRequest(HttpServletRequest request){
    	message.setSenderName(request.getParameter("name"));
    	message.setSenderSurname(request.getParameter("surname"));
        message.setMessageTitle(request.getParameter("title"));
        message.setMessageBody(request.getParameter("message"));
        message.setIPAddress(request.getRemoteAddr());
        
        pk.setMailAddress(request.getParameter("mail"));
        pk.setDateTime(new Date());
 
        message.setPk(pk);
    }
}
