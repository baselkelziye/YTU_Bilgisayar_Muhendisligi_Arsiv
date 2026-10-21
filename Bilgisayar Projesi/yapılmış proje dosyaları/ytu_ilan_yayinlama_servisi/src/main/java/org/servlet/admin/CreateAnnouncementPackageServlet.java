package org.servlet.admin;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AnnouncementPacketDAO;
import org.db.dao.BankAccountDAO;
import org.db.dao.CurrencyDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.hibernate.BankAccountHibernateImpl;
import org.db.hibernate.CurrencyHibernateImpl;
import org.db.model.AnnouncementPacket;
import org.db.model.BankAccountInfo;
import org.db.model.Currency;


@WebServlet(name = "CreateAnnouncementPackageServlet", urlPatterns = {"/createannouncementpackageservlet"})
public class CreateAnnouncementPackageServlet extends HttpServlet {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private BankAccountInfo accountInfo;
	private AnnouncementPacket packet;
	private Currency currency;
	
	public CreateAnnouncementPackageServlet() {
		super();
		accountInfo = new BankAccountInfo();
		packet = new AnnouncementPacket();
		currency = new Currency();
	}

	@Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();

        CurrencyDAO currencyDAO = new CurrencyHibernateImpl();
    	//currency = currencyDAO.getCurrency(Integer.parseInt(request.getParameter("currency")));
        currency = currencyDAO.getCurrency(1);
        
    	BankAccountDAO accountDAO = new BankAccountHibernateImpl();
    	accountInfo = accountDAO.getAccount(request.getParameter("account"));
    	
        readParameters(request);
                
        AnnouncementPacketDAO packetDAO = new AnnouncementPacketHibernateImpl();
        
        if(packetDAO.savePacket(packet)) {
        	session.setAttribute("olusturuldu", 1);
        } else {
        	session.setAttribute("olusturuldu", 2);
        }        	
        
        response.sendRedirect("admin/paket-olustur.jsp");
    }
    
    private void readParameters(HttpServletRequest request) {
        packet.setTitle(request.getParameter("packet_name"));
        packet.setActiveTime(Integer.parseInt(request.getParameter("activate_date")));
        packet.setAnnouncementCount(Integer.parseInt(
                request.getParameter("announcement_number")));
        packet.setPrice(Integer.parseInt(request.getParameter("price")));
        packet.setCondition(request.getParameter("condition"));
        packet.setAccountInfo(accountInfo);
        packet.setCurrency(currency);
        packet.setVisible(false);

        try {
            String date = request.getParameter("last_date_used");
            Date expired = new SimpleDateFormat("dd/MM/yyyy").parse(date);
            packet.setLastDateUsed(expired);
        } catch (ParseException e) {
            System.out.println("Son kullanım tarihi okunamadı");
            e.printStackTrace();
        }
    }

}
