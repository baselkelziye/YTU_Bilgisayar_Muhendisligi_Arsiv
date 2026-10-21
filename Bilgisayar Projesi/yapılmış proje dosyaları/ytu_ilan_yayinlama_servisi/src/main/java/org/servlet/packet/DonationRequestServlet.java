package org.servlet.packet;

import java.io.*;
import java.util.Date;
import java.util.Random;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.db.dao.AnnouncementPacketDAO;
import org.db.dao.AnnouncementPacketStateDAO;
import org.db.dao.CompanyOwnPacketDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.hibernate.CompanyOwnPacketHibernateImpl;
import org.db.hibernate.NotificationHibernateImpl;
import org.db.hibernate.PacketStateHibernateImpl;
import org.db.model.*;

/**
 * Servlet implementation class DonatedPacket
 */
@WebServlet("/donationrequestservlet")
@MultipartConfig
public class DonationRequestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DonationRequestServlet() {
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
	    request.setCharacterEncoding("UTF-8");

        System.out.println(request.getParameter("packetId"));
        System.out.println(request.getParameter("description"));
        int packetId = Integer.parseInt(request.getParameter("packetId"));
		
		AnnouncementPacketDAO annDAO = new AnnouncementPacketHibernateImpl();
		AnnouncementPacket packet = annDAO.getPacket(packetId);
		
		AnnouncementPacketStateDAO stateDAO = new PacketStateHibernateImpl();
		AnnouncementPacketState state = stateDAO.getPacketState(1);
		
		HttpSession httpSession = request.getSession();
		Company company = (Company) httpSession.getAttribute("user");
		
		CompanyOwnPacket cop = new CompanyOwnPacket();
		cop.setOwnerCompany(company);
		cop.setPacket(packet);
		cop.setTimeToRequest(new Date());
		cop.setState(state);
		cop.setCompanyDescription(request.getParameter("description"));


        //dosyayı kaydet
        Part filePart = null;
        String fileName = "";
        String filePath = "";

        if(request.getPart("file") != null) {
            filePart = request.getPart("file");
            fileName += new Random().nextInt(100000) + "_";
            fileName += getFileName(filePart);
            filePath = request.getServletContext().getInitParameter("commonFilePath");
        }

        OutputStream out = null;
        InputStream filecontent = null;
        PrintWriter writer = response.getWriter();

        try {
            if (request.getPart("file") != null) {
                out = new FileOutputStream(new File(filePath + File.separator
                        + fileName));
                filecontent = filePart.getInputStream();

                int read = 0;
                final byte[] bytes = new byte[1024];

                while ((read = filecontent.read(bytes)) != -1) {
                    out.write(bytes, 0, read);
                }

                if(fileName.length() > 6)
                    cop.setFilePath(fileName);
            }

            CompanyOwnPacketDAO copDAO = new CompanyOwnPacketHibernateImpl();

            if(copDAO.save(cop)) {
                httpSession.setAttribute("donation_request", 1);
                //Bildirim
                for(DauUser user: packet.getAccountInfo().getOwnerUnit().getDauUser()) {
                    Notification notification = new Notification(
                            company.getCompanyName(),
                            new User(user.getUserName()),
                            (company.getCompanyName() + " şirketi tarafından bağış isteği gönderildi."),
                            new Date(),
                            "info"
                    );
                    new NotificationHibernateImpl().saveNotification(notification);
                }
            } else {
                httpSession.setAttribute("donation_request", 2);
            }

            response.sendRedirect("company/paketleri-gor.jsp");
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
