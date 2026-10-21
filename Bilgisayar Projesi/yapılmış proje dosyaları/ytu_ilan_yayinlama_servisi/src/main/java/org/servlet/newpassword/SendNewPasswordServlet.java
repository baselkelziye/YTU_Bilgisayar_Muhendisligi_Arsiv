package org.servlet.newpassword;

import org.db.dao.UserDAO;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.User;
import org.mail.MailFunction;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Random;

/**
 * Created by mgunes on 27.01.2017.
 */
@WebServlet(name = "SendNewPasswordServlet", urlPatterns = {"/sendnewpassword"})
public class SendNewPasswordServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        HttpSession session = request.getSession();

        String mail = request.getParameter("mail");

        //kullanıcıyı bul, durumunu 6 yap
        //random bir parolo oluştur
        //mail gönder
        //anasayfada kontrol et durumu 6 olanlarda sadece yeni şifre oluşturma formu olacak
        //sonra tekrar durumunu 1 e çek

        UserDAO userDAO = new UserHibernateImpl();
        User user = userDAO.getUserByMail(mail);

        if(user == null) {
            session.setAttribute("yeniparola", 2);
        } else {
            Random random = new Random();
            int password = random.nextInt(888888) + 100000;
            user.setStatus(6);
            user.setPassword(String.valueOf(password));
            userDAO.update(user);

            MailFunction mailFunction = new MailFunction();
            String text = "Geçici Parolanız: " + password + " ";
            mailFunction.send(mail, "Geçici Parola", text);

            session.setAttribute("yeniparola", 1);
        }

        response.sendRedirect("parolami-unuttum.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
