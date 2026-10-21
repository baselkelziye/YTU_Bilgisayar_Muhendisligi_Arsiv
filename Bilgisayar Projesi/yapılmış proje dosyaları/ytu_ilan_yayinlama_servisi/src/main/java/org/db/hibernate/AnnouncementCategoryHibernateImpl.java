package org.db.hibernate;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.db.dao.AnnouncementCategoryDAO;
import org.db.model.AnnouncementCategory;

public class AnnouncementCategoryHibernateImpl extends AbstractDAO implements AnnouncementCategoryDAO {
	public List<AnnouncementCategory> getAllCategories() {
	    String sql = "SELECT * FROM announcement_category ORDER BY id;";
		return  getRowsBySQLQuery(AnnouncementCategory.class, sql);
	}

	public boolean saveCategory(AnnouncementCategory category) {
		// TODO Auto-generated method stub
		return save(category);
	}

	public AnnouncementCategory getCategory(int id) {
		return (AnnouncementCategory) getObject(AnnouncementCategory.class, (Object)id);
	}

	public boolean isCategoryNameExist(String name) {
        String query = "from AnnouncementCategory where categoryName = :name";
        Map<String, Object> parameter = new HashMap<String, Object>();
        parameter.put("name", name);
        List<AnnouncementCategory> row = getRowsByQuery(AnnouncementCategory.class, query, parameter);

        if(row.isEmpty())
            return false;
        else
            return true;
	}

    public boolean deleteCategory(int id) {
       return deleteByQuery(AnnouncementCategory.class, "AnnouncementCategory", "id", id);
    }

    public boolean updateCategory(int id, String name) {
        Map<String, Object> parameter = new HashMap<String, Object>();
        parameter.put("name", name);
        parameter.put("id", id);

        String query = "update AnnouncementCategory set categoryName = :name where id = :id";
        return updateByQuery(AnnouncementCategory.class, query, parameter);
    }

    public List<AnnouncementCategory> getParentCategories() {
        String query = "from AnnouncementCategory where parentCategory = :id";
        Map<String, Object> parameter = new HashMap<String, Object>();
        parameter.put("id", 0);
        List<AnnouncementCategory> parent = getRowsByQuery(AnnouncementCategory.class, query, parameter);
        return parent;
	}
		
}
