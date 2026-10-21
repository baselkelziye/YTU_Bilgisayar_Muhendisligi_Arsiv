package org.db.hibernate;

import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class HibernateSessionFactory {
	
	private static SessionFactory sessionFactory = null;
    
    private static SessionFactory buildSessionFactory() {
     
      try {
          Configuration c = new Configuration();
          c = c.configure();
          

          return c.buildSessionFactory();
      }
      catch(Throwable ex) {
          System.err.println("yaratılamadı:" + ex.getMessage());
          ex.getCause().printStackTrace();
          throw new ExceptionInInitializerError(ex);
      }
    }
  
  public static SessionFactory getSessionFactory() {
      if(sessionFactory == null)
    	  sessionFactory = buildSessionFactory();
      
      return sessionFactory;
  }
}
