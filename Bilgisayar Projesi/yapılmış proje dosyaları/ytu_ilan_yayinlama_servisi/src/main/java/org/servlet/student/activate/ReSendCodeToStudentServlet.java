package org.servlet.student.activate;

import org.db.dao.StudentDAO;
import org.db.dao.VerificationCodeDAO;
import org.db.hibernate.StudentHibernateImpl;
import org.db.hibernate.VerificationCodeHibernateImpl;
import org.db.model.Student;
import org.db.model.VerificationCode;
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
 * Created by mgunes on 25.01.2017.
 */
@WebServlet(name = "ReSendCodeToStudentServlet", urlPatterns = {"/resendcodetostudent"})
public class ReSendCodeToStudentServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        Student student = (Student) session.getAttribute("user");

        Random random = new Random();
        StudentDAO studentDAO = new StudentHibernateImpl();
        String code;

        do {
            code = String.valueOf(random.nextInt(100000) + 100000);
            code += "lj";
        } while (studentDAO.isCodeExist(code));

        //öğrencinin mail adresini bul
        int i = 0;
        while(i < student.getCommWays().size() && !student.getCommWays().get(i).getPk().getCommType().equals("mail"))
            i++;

        if(i < student.getCommWays().size()) {
            String mail = student.getCommWays().get(i).getPk().getCommValue();
            MailFunction mailFunction = new MailFunction();
            String subject = "Aktifleştirme Kodu";
            StringBuilder text = new StringBuilder();
            text.append("Yeni bir aktifleştirme kodu oluşturuldu. Eski kodlar geçersiz sayılacaktır. ");
            text.append("Hesabınızı aktifleştirmeniz için gerekli kod: " + code + " ");
            mailFunction.send(mail, subject, text.toString());

            //veritabanındaki eski kaydı kapat, yeni kayıt oluştur
            VerificationCodeDAO codeDAO = new VerificationCodeHibernateImpl();

            if(codeDAO.reCode(student, code))
                session.setAttribute("yenikod", 1);
            else
                session.setAttribute("yenikod", 2);
        } else {
            session.setAttribute("yenikod", 2);
        }

        session.setAttribute("aktif", -2);
        response.sendRedirect("student/hesabi-aktiflestir.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
