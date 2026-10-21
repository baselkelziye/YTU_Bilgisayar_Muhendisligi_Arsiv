package org.servlet.dau.spendingrequest;

import java.io.*;
import java.util.Date;
import java.util.List;
import java.util.Random;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.db.compositePK.AccountingPK;
import org.db.dao.AccountingDAO;
import org.db.dao.SpendingRequestDAO;
import org.db.hibernate.*;
import org.db.model.*;

/**
 * Servlet implementation class AcceptSendingRequestServlet
 */
@WebServlet("/acceptsendingrequest")
@MultipartConfig
public class AcceptSendingRequestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();
        request.setCharacterEncoding("UTF-8");
		
		int requestId = Integer.parseInt(request.getParameter("requestId"));
		String answer = request.getParameter("description");
		DauUser dauUser = (DauUser) session.getAttribute("user");
		dauUser = (DauUser) new UserHibernateImpl().getUser(dauUser.getUserName());
		session.setAttribute("user", dauUser);
		
		SpendingRequestDAO requestDAO = new SpendingRequestHibernateImpl();
		
		SpendingRequest spendingRequest = requestDAO.getSpendingRequest(requestId);
		spendingRequest.setAnswerFromUpdater(answer);
		spendingRequest.setUpdatedDateTime(new Date());
		spendingRequest.setDauUser(dauUser);
		spendingRequest.setState(new SpendingRequestState(2));

        AccountingPK pk = new AccountingPK();
        pk.setDateTime(new Date());
        pk.setUnit(dauUser.getDau());

        Accounting accounting = new Accounting();
        accounting.setAccountingPK(pk);
        accounting.setAmount(-spendingRequest.getAmount());
        accounting.setDauUser(dauUser);
        accounting.setDescription(spendingRequest.getTitle() + " başlıklı harcama isteği onaylandı.");
        new AccountingHibernateImpl().saveAccounting(accounting);

        Part filePart = null;
        String fileName = "";
        String filePath = "";
        Part imagePart = null;
        String imageName = "";
        String imagePath = "";

        if(request.getPart("file") != null) {
            filePart = request.getPart("file");
            fileName += new Random().nextInt(100000) + "_";
            fileName += getFileName(filePart);
            filePath = request.getServletContext().getInitParameter("pdfFilePath");
        }

        if(request.getPart("image") != null) {
            imagePart = request.getPart("image");
            imageName += new Random().nextInt(100000) + "_";
            imageName += getFileName(imagePart);
            imagePath = request.getServletContext().getInitParameter("imageFilePath");
        }

        OutputStream out = null;
        InputStream filecontent = null;
        PrintWriter writer = response.getWriter();

        try {
            if(request.getPart("file") != null) {
                out = new FileOutputStream(new File(filePath + File.separator
                        + fileName));
                filecontent = filePart.getInputStream();

                int read = 0;
                final byte[] bytes = new byte[1024];

                while ((read = filecontent.read(bytes)) != -1) {
                    out.write(bytes, 0, read);
                }


                if(fileName.length() > 6)
                    spendingRequest.setPdfPath(fileName);
            }

            if(request.getPart("image") != null) {
                out = new FileOutputStream(new File(imagePath + File.separator
                        + imageName));
                filecontent = imagePart.getInputStream();

                int read = 0;
                final byte[] bytes = new byte[1024];

                while ((read = filecontent.read(bytes)) != -1) {
                    out.write(bytes, 0, read);
                }

                if(getFileName(imagePart).length() != 0)
                    spendingRequest.setImagePath(imageName);
            }

            //vakfın bakiyesi yeterli mi kontrol et
            DauUser user = (DauUser) session.getAttribute("user");
            int currentBalance = new DauHibernateImpl().getUnit(user.getDau().getUnitName()).getBalance();
            int spendingAmount = requestDAO.getSpendingRequest(requestId).getAmount();

            if(spendingAmount > (currentBalance + spendingAmount)) {
                session.setAttribute("istekguncelle", 5);
            } else {
                if(requestDAO.updateRequest(spendingRequest)) {
                    session.setAttribute("istekguncelle", 1);
                    String query = (String) session.getAttribute("spendingRequestQuery");
                    List<SpendingRequest> spendingRequestList = new SpendingRequestHibernateImpl().getSpendingRequestByQuery(query);
                    session.setAttribute("spendingList", spendingRequestList);

                    //Bildirim
                    Notification notification = new Notification(
                            dauUser.getUserName(),
                            new User("admin"),
                            (spendingRequest.getTitle() + " başlıklı harcama isteğiniz onaylandı"),
                            new Date(),
                            "positive"
                    );
                    new NotificationHibernateImpl().saveNotification(notification);
                } else {
                    session.setAttribute("istekguncelle", 2);
                }
            }

            response.sendRedirect("dau/harcama-istekleri.jsp");
        } catch (FileNotFoundException fne) {
            writer.println("You either did not specify a file to upload or are "
                    + "trying to upload a file to a protected or nonexistent "
                    + "location.");
            writer.println("<br/> ERROR: " + fne.getMessage());
        } finally {
            if (out != null) {
                out.close();
            }
            if (filecontent != null) {
                filecontent.close();
            }
            if (writer != null) {
                writer.close();
            }
        }
	}

    private String getFileName(final Part part) {
        final String partHeader = part.getHeader("content-disposition");
        for (String content : part.getHeader("content-disposition").split(";")) {
            if (content.trim().startsWith("filename")) {
                return content.substring(
                        content.indexOf('=') + 1).trim().replace("\"", "");
            }
        }
        return null;
    }
}
