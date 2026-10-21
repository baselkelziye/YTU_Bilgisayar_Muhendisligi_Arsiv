package org.db.dao;

import java.util.List;

import org.db.model.AnnouncementCategory;

public interface AnnouncementCategoryDAO {
	List<AnnouncementCategory> getAllCategories();
	List<AnnouncementCategory> getParentCategories();
	boolean saveCategory(AnnouncementCategory category);
	AnnouncementCategory getCategory(int id);
	boolean isCategoryNameExist(String name);
	boolean deleteCategory(int id);
	boolean updateCategory(int id, String name);
}
