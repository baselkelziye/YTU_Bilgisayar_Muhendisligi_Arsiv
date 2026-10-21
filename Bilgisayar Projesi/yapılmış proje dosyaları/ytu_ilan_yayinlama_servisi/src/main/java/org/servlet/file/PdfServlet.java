package org.servlet.file;

import com.lowagie.text.Document;
import com.lowagie.text.DocumentException;
import com.lowagie.text.Paragraph;
import com.lowagie.text.pdf.PdfWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.nio.file.Files;

import static com.sun.xml.internal.stream.Entity.ScannedEntity.DEFAULT_BUFFER_SIZE;

/**
 * Created by mgunes on 06.12.2016.
 */
@WebServlet(name = "PdfServlet", urlPatterns = {"/pdfviewer"})
public class PdfServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String fileName = request.getParameter("fileName").trim();
        String type = request.getParameter("fileType").trim();
        String path = "";

        if(type.equals("pdf")) {
            path += request.getServletContext().getInitParameter("pdfFilePath");
        } else if(type.equals("image")) {
            path += request.getServletContext().getInitParameter("imageFilePath");
        } else {
            path += request.getServletContext().getInitParameter("commonFilePath");
        }

        path += fileName;

        ServletContext context = getServletContext();
        response.setContentType(context.getMimeType(fileName));

        response.setHeader("Content-disposition","attachment; filename=" + path);

        File my_file = new File(path);

        OutputStream out = response.getOutputStream();
        FileInputStream in = new FileInputStream(my_file);
        byte[] buffer = new byte[4096];
        int length;

        while ((length = in.read(buffer)) > 0){
            out.write(buffer, 0, length);
        }

        in.close();
        out.flush();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
