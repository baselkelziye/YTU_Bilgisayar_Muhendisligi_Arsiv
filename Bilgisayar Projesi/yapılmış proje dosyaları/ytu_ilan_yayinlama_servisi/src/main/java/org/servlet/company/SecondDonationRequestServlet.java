package org.servlet.company;

import org.db.dao.AnnouncementPacketDAO;
import org.db.dao.AnnouncementPacketStateDAO;
import org.db.dao.CompanyOwnPacketDAO;
import org.db.hibernate.AnnouncementPacketHibernateImpl;
import org.db.hibernate.CompanyOwnPacketHibernateImpl;
import org.db.hibernate.PacketStateHibernateImpl;
import org.db.model.AnnouncementPacket;
import org.db.model.AnnouncementPacketState;
import org.db.model.Company;
import org.db.model.CompanyOwnPacket;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.*;
import java.util.Date;
import java.util.List;
import java.util.Random;

/**
 * Created by mgunes on 28.01.2017.
 */
@MultipartConfig
@WebServlet(name = "SecondDonationRequestServlet", urlPatterns = {"/seconddonationrequest"})
public class SecondDonationRequestServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();

        System.out.println(request.getParameter("description"));
        System.out.println(request.getParameter("packetId"));
        int packetId = Integer.parseInt(request.getParameter("packetId"));
        String description = request.getParameter("description");

        HttpSession httpSession = request.getSession();

        CompanyOwnPacket cop = new CompanyOwnPacketHibernateImpl().getPacket(packetId);
        cop.setTimeToRequest(new Date());
        cop.setSecondCompanyDescription(description);
        cop.setState(new AnnouncementPacketState(6));


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

                cop.setSecondFilePath(fileName);
            }

            CompanyOwnPacketDAO copDAO = new CompanyOwnPacketHibernateImpl();

            if(copDAO.save(cop)) {
                Company company = (Company) session.getAttribute("user");
                List<CompanyOwnPacket> packets = company.getPackets();
                session.setAttribute("packets", packets);
                httpSession.setAttribute("ikinciistek", 1);
            } else {
                httpSession.setAttribute("ikinciistek", 2);
            }

            response.sendRedirect("company/paketlerim.jsp");
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

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
