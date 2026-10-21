package org.servlet.company;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(name = "CompanySaveInitializeServlet", urlPatterns = { "/companysaveinitializeservlet" })
public class CompanySaveInitializeServlet extends HttpServlet {

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

		// sektör vt den çekilecek //sektör olacak mı? seçenekler sun, ve diğer
		// input text
		// sektör tablosu-sınıfı-ilgili foreign key ler

		HttpSession httpSession = request.getSession();
		httpSession.setAttribute("kayit", 0);
		
		response.sendRedirect("sirket-kayit.jsp");
	}

}
