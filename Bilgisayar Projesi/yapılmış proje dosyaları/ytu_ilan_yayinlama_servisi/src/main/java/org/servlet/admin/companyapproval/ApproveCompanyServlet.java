package org.servlet.admin.companyapproval;

import org.db.dao.CompanyDAO;
import org.db.hibernate.CompanyHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.model.Company;
import org.db.model.Notification;
import org.db.model.User;
import org.mail.MailFunction;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 28.01.2017.
 */
@WebServlet(name = "ApproveCompanyServlet", urlPatterns = {"/approvecompanyservlet"})
public class ApproveCompanyServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        String username = request.getParameter("username");
        CompanyDAO companyDAO = new CompanyHibernateImpl();
        Company company = companyDAO.getCompany(username);

        company.setStatus(1);


        if(companyDAO.saveCompany(company)) {
            List<Company> companyList = companyDAO.getWaitingApproval();
            session.setAttribute("companyList", companyList);
            session.setAttribute("istek", 3);

            //Bilgilendirme maili
            MailFunction mailFunction = new MailFunction();
            mailFunction.send(company.getContactMail(), "Kayıt Onayı", "Artık hesabınıza giriş yapabilirsiniz.");

            Notification notification = new Notification(
                    "Sistem",
                    new User(company.getUserName()),
                    ("Sisteme hoşgeldiniz. Hesabınız yönetici tarafından onaylandı."),
                    new Date(),
                    "info"
            );
            new NotificationHibernateImpl().saveNotification(notification);

        } else {
            session.setAttribute("istek", 2);
        }

        response.sendRedirect("admin/sirket-kayit-onay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
