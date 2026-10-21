package com.taskagitmakas.dao;

import java.util.ArrayList;
import java.util.List;
import javax.persistence.TypedQuery;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import com.taskagitmakas.entity.Image;

public class ImageImp implements ImageDao{

	 Session session;
	 SessionFactory sessionFactory;
	public ImageImp() {
	 
		  sessionFactory = new Configuration()
				    .configure().buildSessionFactory(); 
 	}

	@Override
	public void insert(Image image) {
		
		session=sessionFactory.getCurrentSession();
		session.beginTransaction();
  		session.persist(image);
 		session.getTransaction().commit(); 
	}

	@Override
	public Image get(int id) {


		session=sessionFactory.getCurrentSession();
		session.beginTransaction();
		
		Image image=session.get(Image.class, id);
		session.getTransaction().commit();
		
		return image;
		
	}

	@Override
	public List<Image> all() {
		List<Image> list=new ArrayList<Image>();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();

		TypedQuery<Image> query = session.createQuery("from Image", Image.class);
		list=query.getResultList();
 		session.getTransaction().commit(); 

		return list;
 
	}
	@Override
	public List<Image> all(boolean isTest) {
		
		List<Image> list=new ArrayList<Image>();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();
		TypedQuery<Image> query = session.createQuery("from Image where isTest="+isTest, Image.class);
		list=query.getResultList();
 		session.getTransaction().commit(); 

		return list;
 
	}
	
	@Override
	public List<Image> all(int userId) {
		
		List<Image> list=new ArrayList<Image>();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();
		TypedQuery<Image> query = session.createQuery("from Image where userId="+userId, Image.class);
		list=query.getResultList();
 		session.getTransaction().commit(); 

		return list;
 
	}

	
	@Override
	public List<Image> getSampleByCount(int classType) {
		List<Image> list=new ArrayList<Image>();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();

		TypedQuery<Image> query = session.createQuery("from Image where classType="+classType, Image.class);
		list=query.getResultList();
 		session.getTransaction().commit(); 

		return list;
 
	}
	
	@Override
	public List<Image> getAllByUser(int userId) {
		List<Image> list=new ArrayList<Image>();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();
		TypedQuery<Image> query = session.createQuery("from Image where userId="+userId, Image.class);
		list=query.getResultList();
 		session.getTransaction().commit(); 
		return list;
	}
	
	public List<Image> getAllByOtherUsers(int userId) {
		List<Image> list=new ArrayList<Image>();
		session = sessionFactory.getCurrentSession();
		session.beginTransaction();
		TypedQuery<Image> query = session.createQuery("from Image where userId!="+userId, Image.class);
		list=query.getResultList();
 		session.getTransaction().commit(); 
		return list;
	}

	@Override
	public Long getCount() {
		Session session=sessionFactory.getCurrentSession();

		session.beginTransaction();

		Long rowCount = session.createQuery(
			    "select count(i.id ) " +
			    "from Image i ", Long.class )
			.getSingleResult();	
		session.getTransaction().commit(); 

		return rowCount;
	}

	@Override
	public Long getCountByUser(int userId) {
		Session session=sessionFactory.getCurrentSession();
		session.beginTransaction();

		Long rowCount = session.createQuery(
			    "select count(i.id ) " +
			    "from Image i where i.userId="+userId, Long.class )
			.getSingleResult();	
		session.getTransaction().commit(); 
		return rowCount;
	 
	}
	public Long getCountByClassType(int classType) {
		Session session=sessionFactory.getCurrentSession();
		session.beginTransaction();

		Long rowCount = session.createQuery(
			    "select count(i.id ) " +
			    "from Image i where i.classType="+classType, Long.class )
			.getSingleResult();	
		session.getTransaction().commit(); 
		return rowCount;
	 
	}

}
