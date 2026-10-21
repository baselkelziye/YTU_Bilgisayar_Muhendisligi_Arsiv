package org.db.hibernate;

import java.io.Serializable;
import java.util.List;
import java.util.Map;

import org.hibernate.Query;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

public abstract class AbstractDAO {
	private Session session;
	
	protected <T> Object getObject(Class<T> c, Object primaryKey) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			Object object = session.get(c, (Serializable) primaryKey);
			session.getTransaction().commit();
			return object;
		} catch(Exception ex) {
			System.err.println("Obje getirilemedi"); // logla
			session.getTransaction().rollback();
			return false;
		} finally {
			session.close();
		}
		
	}

	protected boolean delete(Object o) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			session.delete(o);
			session.getTransaction().commit();
			return true;
		} catch (Exception ex) {
			System.err.println("Silme işlemi başarısız"); // logla
			session.getTransaction().rollback();
			return false;
		} finally {
			session.close();
		}
	}

	protected <T> List<T> getAllRows(Class<T> c) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			return session.createCriteria(c).list();

		} catch (Exception ex) {
			System.err.println("Veriler okunamadı: "+ ex.getMessage()); // logla
			session.getTransaction().rollback();
			return null;
		} finally {
			session.close();
		}
	}

	protected <T> boolean deleteByQuery(Class<T> c, String className, String pkColumnName, Object pk) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			String query = "delete from " + className + " where " + pkColumnName + " = :id";
			session.getTransaction().begin();
			Query hqlQuery = session.createQuery(query);
			hqlQuery.setParameter("id", pk);
			hqlQuery.executeUpdate();
			session.getTransaction().commit();
			return true;
		} catch (Exception ex) {
			session.getTransaction().rollback();
			System.out.println("Silme işlemi başarısız:"  + ex.getMessage());
			return false;
		} finally {
			session.close();
		}
	}

	protected <T> List<T> getRowsByQuery(Class<T> c, String hqlQuery, Map<String, Object> parameterList) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			Query query = session.createQuery(hqlQuery);

			for(String columnName: parameterList.keySet()) {
				query.setParameter(columnName, parameterList.get(columnName));
			}

			List<T> rows = query.list();
			session.getTransaction().commit();
			return rows;

		} catch(Exception ex) {
			System.err.println("Sorguya göre veri çekme işlemi başarısız: "+ ex.getMessage()); // logla
			session.getTransaction().rollback();
			return null;
		} finally {
			session.close();
		}
	}

    protected <T> List<T> getRowsBySQLQuery(Class<T> c, String query) {
        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.beginTransaction();
            SQLQuery q = session.createSQLQuery(query);
            q.addEntity(c);

            List<T> rows = q.list();
            session.getTransaction().commit();
            return rows;

        } catch(Exception ex) {
            System.err.println("Sorguya göre veri çekme işlemi başarısız: "+ ex.getMessage()); // logla
            session.getTransaction().rollback();
            return null;
        } finally {
            session.close();
        }
    }

    protected <T> boolean updateBySQLQuery(Class<T> c ,String query) {
    	try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			SQLQuery q = session.createSQLQuery(query);
			q.addEntity(c);
			q.executeUpdate();
			session.getTransaction().commit();
			return true;
		} catch(Exception ex) {
			System.err.println("Sorgu çalıştırma işlemi başarısız: "+ ex.getMessage()); // logla
			session.getTransaction().rollback();
			return false;
		} finally {
			session.close();
		}
	}

	protected boolean save(Object o) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			session.saveOrUpdate(o);
			session.getTransaction().commit();
			return true;
		} catch (Exception ex) {
			System.err.println("Kayıt işlemi başarısız " + ex.getMessage()); // logla
			session.getTransaction().rollback();
			return false;
		} finally {
			session.close();
		}
	}

	protected boolean justSave(Object o) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			session.save(o);
			session.getTransaction().commit();
			return true;
		} catch (Exception ex) {
			System.err.println("Kayıt işlemi başarısız " + ex.getMessage()); // logla
			session.getTransaction().rollback();
			return false;
		} finally {
			session.close();
		}
	}

	protected <T> boolean updateByQuery(Class<T> c, String hqlQuery, Map<String, Object> parameterList) {
        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.beginTransaction();

            Query query = session.createQuery(hqlQuery);

            for(String columnName: parameterList.keySet()) {
                query.setParameter(columnName, parameterList.get(columnName));
            }

            System.out.println("sorgu-" +query.executeUpdate());
            session.getTransaction().commit();
            return true;
        } catch (Exception ex) {
            System.err.println("Güncelleme işlemi başarısız " + ex.getMessage()); // logla
            session.getTransaction().rollback();
            return false;
        } finally {
            session.close();
        }
    }

}
