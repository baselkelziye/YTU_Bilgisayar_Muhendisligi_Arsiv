package org.servlet.dau.accounting;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.db.dao.AccountingDAO;
import org.db.dao.DauUserDAO;
import org.db.hibernate.AccountingHibernateImpl;
import org.db.hibernate.DauUserHibernateImpl;
import org.db.hibernate.UserHibernateImpl;
import org.db.model.Accounting;
import org.db.model.DauUser;
import org.db.model.User;

/**
 * Servlet implementation class ListAccountingHistoryServlet
 */
@WebServlet("/listaccountinghistory")
public class ListAccountingHistoryServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ListAccountingHistoryServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();
		DauUser user = (DauUser) session.getAttribute("user");
		user = (DauUser) new UserHibernateImpl().getUser(user.getUserName());
		
		AccountingDAO accDAO = new AccountingHibernateImpl();
		List<Accounting> acc = accDAO.getUnitAccountings(user.getDau().getUnitName());
		//session.setAttribute("accounting", acc);
        session.setAttribute("user", user);

		//o birime ait kullanıcıları çek
        DauUserDAO dauUserDAO = new DauUserHibernateImpl();
        List<DauUser> dauUsers = dauUserDAO.getUsersFromDau(user.getDau().getUnitName());

        session.setAttribute("userList", dauUsers);
		response.sendRedirect("dau/muhasebe-kayitlari.jsp");
	}

}
