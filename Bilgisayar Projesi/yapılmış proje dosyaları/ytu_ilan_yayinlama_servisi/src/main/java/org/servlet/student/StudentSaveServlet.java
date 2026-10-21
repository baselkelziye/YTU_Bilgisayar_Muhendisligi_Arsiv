package org.servlet.student;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.compositePK.CommunicationWayPK;
import org.db.dao.StudentDAO;
import org.db.dao.UserDAO;
import org.db.dao.UserTypeDAO;
import org.db.hibernate.StudentHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.hibernate.UserTypeHibernateImpl;
import org.db.model.CommunicationWay;
import org.db.model.Department;
import org.db.model.Student;
import org.db.model.UserType;
import org.mail.MailFunction;

@WebServlet(name = "StudentSaveServlet", urlPatterns = {"/studentsaveservlet"})
public class StudentSaveServlet extends HttpServlet {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Student student;
	private CommunicationWay mail;

	public StudentSaveServlet() {
		super();
		student = new Student();
		mail = new CommunicationWay();
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
        readParameters(request);
        
        UserTypeDAO typeDAO = new UserTypeHibernateImpl();
        UserType type  = typeDAO.getUserType(3);
        
        student.setUserTypeNo(type); 
        
        StudentDAO studentDAO = new StudentHibernateImpl();
        UserDAO userDAO = new UserHibernateImpl();

        if (userDAO.isUserExist(request.getParameter("username"))) {
        	httpSession.setAttribute("kayit", 2);
        	httpSession.setAttribute("username", request.getParameter("username"));
        	httpSession.setAttribute("name", request.getParameter("name"));
        	httpSession.setAttribute("surname", request.getParameter("surname"));
        	httpSession.setAttribute("mail", request.getParameter("mail"));
        	response.sendRedirect("ogrenci-kayit.jsp");
        } else {
            String code = studentDAO.saveStudent(student);
            if(!code.equals("hata")) { //başarıyla kaydedildi
                httpSession.setAttribute("kayit", 1);
                MailFunction mailFunction = new MailFunction();
                String subject = "Hesabınızı Aktifleştirin";
                StringBuilder text = new StringBuilder();
                text.append("YTÜ İlan Yayınlama Servisi' ne hoş geldiniz. ");
                text.append("Hesabınızı aktifleştirmeniz için gerekli kod: " + code + " ");

                mailFunction.send(request.getParameter("mail"), subject, text.toString());
                response.sendRedirect("studentremoveformattributesservlet");
            } else {
                httpSession.setAttribute("kayit", 3);
                httpSession.setAttribute("username", request.getParameter("username"));
                httpSession.setAttribute("name", request.getParameter("name"));
                httpSession.setAttribute("surname", request.getParameter("surname"));
                httpSession.setAttribute("mail", request.getParameter("mail"));
                response.sendRedirect("ogrenci-kayit.jsp");
            }
        }
    }
    
    private void readParameters(HttpServletRequest request) {
    	student.setUserName(request.getParameter("username"));
        student.setPassword(request.getParameter("password"));
        student.setName(request.getParameter("name"));
        student.setSurname(request.getParameter("surname"));
        
        Department department = new Department();
        department.setCode(request.getParameter("department"));
        student.setDepartment(department);
        
        CommunicationWayPK mailPK = new CommunicationWayPK();
        mailPK.setCommType("mail");
        mailPK.setCommValue(request.getParameter("mail"));
        
        mail.setPk(mailPK);
        mail.setUser(student);
        
        student.getCommWays().add(mail);
    }

}
