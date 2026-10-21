package com.taskagitmakas.dao;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.TypedQuery;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import com.taskagitmakas.entity.Image;
import com.taskagitmakas.entity.User;

public class UserImp implements UserDao {

		Session session;
	 SessionFactory sessionFactory;
	
	 public UserImp() {

		 sessionFactory = new Configuration()
				    .configure().buildSessionFactory(); 
		 

	 }
	
	@Override
	public void insert(User user) {
		
	session=sessionFactory.getCurrentSession();
	session.beginTransaction();
	session.persist(user);
	session.getTransaction().commit();
		
		
	}

	@Override
	public User getUser(int id) {
		session=sessionFactory.getCurrentSession();
		session.beginTransaction();
		
		User user=session.get(User.class, id);
		session.getTransaction().commit();
		
		return user;
	}

	@Override
	public List<User> all() {
		
		List<User> list=new ArrayList<User>();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();
		TypedQuery<User> query = session.createQuery("from User", User.class);
		list=query.getResultList();
 		session.getTransaction().commit(); 

		return list;

		
	}

}
