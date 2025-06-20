package com.savt.listopia.util.mail;

import com.mailjet.client.errors.MailjetException;
import com.mailjet.client.MailjetClient;
import com.mailjet.client.ClientOptions;
import com.mailjet.client.transactional.SendContact;
import com.mailjet.client.transactional.SendEmailsRequest;
import com.mailjet.client.transactional.TrackOpens;
import com.mailjet.client.transactional.TransactionalEmail;
import com.mailjet.client.transactional.response.SendEmailsResponse;

public class MailSender {
    public static void sendMailFromListopia(
            String receiverMail,
            String receiverName,
            String textPart,
            String htmlPart,
            String subject
    )  {
        MailjetClient client;
        String senderEmail = "listopia@ensargok.com";

        client = new MailjetClient(ClientOptions.builder().apiKey(System.getenv("MJ_APIKEY_PUBLIC")).apiSecretKey(System.getenv("MJ_APIKEY_PRIVATE")).build());
        TransactionalEmail message1 = TransactionalEmail
                .builder()
                .to(new SendContact(receiverMail, receiverName))
                .from(new SendContact(senderEmail, "Listopia"))
                .textPart(textPart)
                .htmlPart(htmlPart)
                .subject(subject)
                .replyTo(new SendContact("ensarxgok@gmail.com", "Ensar Gök"))
                .trackOpens(TrackOpens.ENABLED)
                .build();

        SendEmailsRequest request = SendEmailsRequest
                .builder()
                .message(message1)
                .build();

        try {
            SendEmailsResponse response = request.sendWith(client);
            System.out.println(response);
        } catch (MailjetException e) {
            System.out.println(e.getMessage());
        }
    }
}