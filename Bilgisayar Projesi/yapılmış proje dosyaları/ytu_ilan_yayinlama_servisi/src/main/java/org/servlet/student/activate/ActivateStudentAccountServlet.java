package org.servlet.student.activate;

import org.db.dao.VerificationCodeDAO;
import org.db.hibernate.StudentHibernateImpl;
import org.db.hibernate.VerificationCodeHibernateImpl;
import org.db.model.Student;
import org.db.model.User;
import org.db.model.VerificationCode;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Date;

/**
 * Created by mgunes on 25.01.2017.
 */
@WebServlet(name = "ActivateStudentAccountServlet", urlPatterns = {"/activatestudentaccount"})
public class ActivateStudentAccountServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("aktif", -2);
        session.setAttribute("yenikod", 0);

        //Eğer hesap aktif ise, aktifleştirme tarihini bul
        User user = (User) session.getAttribute("user");
        VerificationCodeDAO verificationCodeDAO = new VerificationCodeHibernateImpl();
        VerificationCode code = verificationCodeDAO.findActivateDate(user.getUserName());

        if(code != null) {
            session.setAttribute("operationDate", code.getOperationTime());
        }

        response.sendRedirect("student/hesabi-aktiflestir.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
