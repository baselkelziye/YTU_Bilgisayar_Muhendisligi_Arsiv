package org.servlet.admin;

import org.db.dao.BankAccountDAO;
import org.db.hibernate.BankAccountHibernateImpl;
import org.db.hibernate.DauHibernateImpl;
import org.db.model.BankAccountInfo;
import org.db.model.DonationAcceptUnit;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by mgunes on 22.12.2016.
 */
@WebServlet(name = "UpdateAccountServlet", urlPatterns = {"/updateaccount"})
public class UpdateAccountServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");

        //Banka hesap bilgisi özelliklerini oku
        BankAccountInfo bai  = new BankAccountInfo();
        bai.setBankAccountNumber(Integer.parseInt(request.getParameter("account_number")));
        bai.setBankName(request.getParameter("bank_name"));
        bai.setBranchBankName(request.getParameter("name_of_branch"));
        //bai.setCurrency(Integer.parseInt(request.getParameter("currency")));
        bai.setCurrency(1);
        bai.setIban(request.getParameter("newIban"));

        HttpSession httpSession = request.getSession();
        DonationAcceptUnit dau = (DonationAcceptUnit) httpSession.getAttribute("dau");
        bai.setOwnerUnit(dau);

        String oldIban = request.getParameter("iban");

        BankAccountDAO baiDAO = new BankAccountHibernateImpl();

        /*if(httpSession.getAttribute("dau") == null) {
            httpSession.setAttribute("hesapguncellendi", 4);
        } else if(baiDAO.updateBankAccount(bai, oldIban)) {
            dau = new DauHibernateImpl().getUnit(dau.getUnitName());
            httpSession.setAttribute("dau", dau);
            httpSession.setAttribute("hesapguncellendi", 1);
        } else {
            httpSession.setAttribute("hesapguncellendi", 2);
        }*/

        if(httpSession.getAttribute("dau") == null) {
            httpSession.setAttribute("hesapguncellendi", 4);
        } else if(baiDAO.saveBankAccount(bai)) {
            dau = new DauHibernateImpl().getUnit(dau.getUnitName());
            httpSession.setAttribute("dau", dau);
            httpSession.setAttribute("hesapguncellendi", 1);
        } else {
            httpSession.setAttribute("hesapguncellendi", 2);
        }

        httpSession.setAttribute("kullanicisil", 0);
        httpSession.setAttribute("hesapeklendi", 0);
        httpSession.setAttribute("kullanicieklendi", 0);
        httpSession.setAttribute("hesapsil", 0);

        response.sendRedirect("admin/bkb-detay.jsp");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
