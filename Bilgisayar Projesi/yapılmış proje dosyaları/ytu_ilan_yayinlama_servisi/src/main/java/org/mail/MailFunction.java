package org.mail;

/**
 * Created by mgunes on 25.01.2017.
 */
import org.db.dao.GlobalParameterDAO;
import org.db.hibernate.GlobalParameterHibernateImpl;
import org.db.model.GlobalParameter;
import org.hibernate.Session;

import javax.activation.DataHandler;
import javax.activation.DataSource;
import javax.activation.FileDataSource;
import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeBodyPart;
import javax.mail.internet.MimeMessage;
import javax.mail.internet.MimeMultipart;
import javax.mail.util.ByteArrayDataSource;
import java.io.IOException;
import java.util.Map;
import java.util.Properties;

public class MailFunction {
    private String senderMail = null; //yeni mail açman lazım
    private String username = null; //sender mail ile aynı
    private String password = null; //mail in şifresi vt den oku - admine arayüz yap
    private String host = null;
    private String port = null;
    private Map<String, String> mailParameter;

    public MailFunction() {
        GlobalParameterDAO parameterDAO = new GlobalParameterHibernateImpl();
        mailParameter = parameterDAO.getParameters("mail");
        senderMail = mailParameter.get("Mail Adresi");
        username = mailParameter.get("Kullanıcı Adı");
        password = mailParameter.get("Mail Parola");
        host = mailParameter.get("Host");
        port = mailParameter.get("Port");
    }

    public void send(final String to, final String subject, final String text) {
        new Thread(new Runnable() {
            public void run() {
                Properties props = new Properties();
                props.put("mail.smtp.auth", "true");
                props.put("mail.smtp.starttls.enable", "true");
                props.put("mail.smtp.host", host);
                props.put("mail.smtp.port", port);

                javax.mail.Session session;
                session = javax.mail.Session.getInstance(props, new javax.mail.Authenticator() {
                    @Override
                    protected PasswordAuthentication getPasswordAuthentication() {
                        return new PasswordAuthentication(username, password);
                    }
                });

                try {
                    Message message = new MimeMessage(session);
                    message.setFrom(new InternetAddress(senderMail));
                    message.setRecipients(Message.RecipientType.TO, InternetAddress.parse(to));
                    message.setSubject(subject);
                    message.setText(text);
                    Transport.send(message);
                } catch (MessagingException e) {
                    throw new RuntimeException(e);
                }
            }
        }).start();
    }
}
