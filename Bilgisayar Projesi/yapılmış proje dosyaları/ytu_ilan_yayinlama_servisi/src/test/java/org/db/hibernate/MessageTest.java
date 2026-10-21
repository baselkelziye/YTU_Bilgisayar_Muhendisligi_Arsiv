package org.db.hibernate;

import static org.junit.Assert.assertEquals;

import java.util.Date;

import org.db.compositePK.MessagePK;
import org.db.dao.MessageDAO;
import org.db.model.Message;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class MessageTest {
	private Message message;
	private MessageDAO messageDAO;
	private MessagePK pk;
	
	@Before
	public void initialize() {
		message = new Message();
		pk = new MessagePK();
		pk.setMailAddress("test@gmail.com");
        pk.setDateTime(new Date());

        message.setPk(pk);
        message.setIPAddress("127.0.0.1");
        message.setMessageTitle("test title");
        message.setSenderName("test user");
        message.setSenderSurname("test surname");
        message.setMessageBody("test message body");
        message.setIsRead(false);
		messageDAO = new MessageHibernateImpl();
	}
	
	@Test
	public void sendMessage() {
		assertEquals(true, messageDAO.sendMessage(message));
	}
	
	@Test
	public void listMessages() {
		MessageDAO messageDAO = new MessageHibernateImpl();
		assertEquals(1, messageDAO.readMessages().size());
	}

    @After
    public void delete() {
        assertEquals(true, messageDAO.deleteMessage(message));
    }
}
