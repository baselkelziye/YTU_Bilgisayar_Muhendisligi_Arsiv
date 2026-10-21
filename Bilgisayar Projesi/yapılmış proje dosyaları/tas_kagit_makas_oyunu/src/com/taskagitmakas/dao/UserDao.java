package com.taskagitmakas.dao;

import java.util.List;

import com.taskagitmakas.entity.User;

public interface UserDao {

	
	public void insert(User user);
	public User getUser(int id);
	public List<User> all();
	
	
	
}
