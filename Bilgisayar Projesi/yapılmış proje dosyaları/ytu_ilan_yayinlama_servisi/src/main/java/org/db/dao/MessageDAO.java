package org.db.dao;

import java.util.List;

import org.db.model.Message;

public interface MessageDAO {
	List<Message> readMessages();
	boolean sendMessage(Message message);
	boolean deleteMessage(Message message);
	Message getMessage(int messageNo);
}
