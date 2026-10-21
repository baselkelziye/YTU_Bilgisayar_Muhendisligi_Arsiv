package org.db.hibernate;

import java.util.List;

import org.db.dao.MessageDAO;
import org.db.model.Message;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

public class MessageHibernateImpl extends AbstractDAO implements MessageDAO {
	private Session session;
	
	public List<Message> readMessages() {
		List<Message> messageList = (List<Message>) getAllRows(Message.class);
		return messageList;
	}
	

	public boolean sendMessage(Message message) {
		return save(message);
	}
	
	public boolean deleteMessage(Message message) {
        String query = "DELETE FROM message where message_no = " + message.getMessageNo();
        return updateBySQLQuery(Message.class, query);
	}


	public Message getMessage(int messageNo) {
		try {

			String query = "select * from message where message_no = " + messageNo + ";";
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(Message.class);
			List<Message> message = sqlQuery.list();
			session.getTransaction().commit();
			
			return message.get(0);
			
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("Mesaj getirilemedi:" + ex.getMessage());
			return null;
			
		} finally {
			session.close();
		}
		
	}

}
