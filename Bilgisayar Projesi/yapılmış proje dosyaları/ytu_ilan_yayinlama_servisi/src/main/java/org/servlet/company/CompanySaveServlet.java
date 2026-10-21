package org.servlet.company;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.compositePK.CommunicationWayPK;
import org.db.dao.CompanyDAO;
import org.db.dao.NotificationDAO;
import org.db.dao.UserDAO;
import org.db.dao.UserTypeDAO;
import org.db.hibernate.CompanyHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.hibernate.UserTypeHibernateImpl;
import org.db.model.*;

@WebServlet(name = "CompanySaveServlet", urlPatterns = { "/companysaveservlet" })
public class CompanySaveServlet extends HttpServlet {

	/**
	 *
	 */
	private static final long serialVersionUID = 1L;

	private static Company company;
	private static CommunicationWay mail;
	private static CommunicationWay telephone;
	
	public CompanySaveServlet() {
		company = new Company();
		mail = new CommunicationWay();
		telephone = new CommunicationWay();
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
		HttpSession httpSession = request.getSession();
		prepareObjects(request);
		CompanyDAO companyDAO = new CompanyHibernateImpl();

		UserDAO userDAO = new UserHibernateImpl();

		// kullanıcı adı alınmış
		if (userDAO.isUserExist(request.getParameter("username"))) {
			httpSession.setAttribute("kayit", 2);
			httpSession.setAttribute("kullaniciAdi", request.getParameter("username"));
			httpSession.setAttribute("kurumAdi", request.getParameter("company_name"));
			httpSession.setAttribute("telefonNumarasi", request.getParameter("telephone_number"));
			httpSession.setAttribute("mail", request.getParameter("email"));
			httpSession.setAttribute("name", request.getParameter("name"));
			httpSession.setAttribute("surname", request.getParameter("surname"));
            httpSession.setAttribute("contactMail", request.getParameter("contactMail"));
            httpSession.setAttribute("contactTel", request.getParameter("contactTel"));
            httpSession.setAttribute("kep", request.getParameter("kep"));
            httpSession.setAttribute("mersis", request.getParameter("mersis"));
			response.sendRedirect("sirket-kayit.jsp");
		} else if (companyDAO.saveCompany(company)) { // başarıyla kaydedildi
			//bildirim
			Notification notification = new Notification();
            notification.setTriggerFactor(company.getUserName());
            notification.setTriggerTarget(new User("admin"));
            notification.setDescription(company.getCompanyName() + " şirketinden üyelik isteği geldi.");
            notification.setTriggerDate(new Date());
            notification.setState("info");

            NotificationDAO notificationDAO = new NotificationHibernateImpl();
            notificationDAO.saveNotification(notification);

			httpSession.setAttribute("kayit", 1);
			response.sendRedirect("companyremoveformattributesservlet");
		} else { // bir hata meydana geldi
			httpSession.setAttribute("kayit", 3);
			httpSession.setAttribute("kullaniciAdi", request.getParameter("username"));
			httpSession.setAttribute("kurumAdi", request.getParameter("company_name"));
			httpSession.setAttribute("telefonNumarasi", request.getParameter("telephone_number"));
			httpSession.setAttribute("mail", request.getParameter("email"));
			httpSession.setAttribute("name", request.getParameter("name"));
			httpSession.setAttribute("surname", request.getParameter("surname"));
            httpSession.setAttribute("contactMail", request.getParameter("contactMail"));
            httpSession.setAttribute("contactTel", request.getParameter("contactTel"));
            httpSession.setAttribute("kep", request.getParameter("kep"));
            httpSession.setAttribute("mersis", request.getParameter("mersis"));
			response.sendRedirect("sirket-kayit.jsp");
		}
	}

	private void prepareObjects(HttpServletRequest request) {
		company.setUserName(request.getParameter("username"));
		company.setPassword(request.getParameter("password"));
		company.setCompanyName(request.getParameter("company_name"));
		company.setName(request.getParameter("name"));
		company.setSurname(request.getParameter("surname"));
        company.setContactMail(request.getParameter("contactMail"));
        company.setContactTel(request.getParameter("contactTel"));
        company.setMersis(request.getParameter("mersis"));
        company.setKep(request.getParameter("kep"));
		
		UserTypeDAO typeDAO = new UserTypeHibernateImpl();
        UserType type  = typeDAO.getUserType(2);
        
		company.setUserTypeNo(type); // sirket maili onayladıktan sonra status
									// admin onayı bekleniyor olacak
									// veya tam tersi?

		company.setStatus(4); // Admin onayı bekleniyor

		CommunicationWayPK telephonePK = new CommunicationWayPK();

		telephonePK.setCommType("telefon");
		telephonePK.setCommValue(request.getParameter("telephone_number"));
		telephone.setPk(telephonePK);
		telephone.setUser(company);

		CommunicationWayPK mailPK = new CommunicationWayPK();

		mailPK.setCommType("mail");
		mailPK.setCommValue(request.getParameter("email"));
		mail.setPk(mailPK);
		mail.setUser(company);
		
		company.getCommWays().add(mail);
		company.getCommWays().add(telephone);
	}

}
