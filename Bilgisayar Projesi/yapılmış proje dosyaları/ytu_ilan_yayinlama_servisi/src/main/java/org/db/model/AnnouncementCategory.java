package org.db.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.annotations.Fetch;
import org.hibernate.annotations.FetchMode;

@Entity
@Table(name = "announcement_category")
public class AnnouncementCategory implements Serializable {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Id
	@Column(name = "id")
	@GeneratedValue(strategy=GenerationType.AUTO)
	private int id;
	
	@Column(name = "category_name", nullable = false)
	private String categoryName;
	
	@Column(name = "parent_category_id")
	private int parentCategory;
	
	@OneToMany(mappedBy = "parentCategory", targetEntity = AnnouncementCategory.class, 
    		fetch = FetchType.EAGER, cascade=CascadeType.ALL)
	@Fetch(value = FetchMode.SUBSELECT)
	private List<AnnouncementCategory> children = new ArrayList<AnnouncementCategory>();

	@Column(name = "references_count", columnDefinition = "int default 0")
	private int referencesCount;

	public AnnouncementCategory() {
		super();
	}
	
	public AnnouncementCategory(int id) {
		super();
		this.id = id;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getCategoryName() {
		return categoryName;
	}

	public void setCategoryName(String categoryName) {
		this.categoryName = categoryName;
	}

	public int getParentCategory() {
		return parentCategory;
	}

	public void setParentCategory(int parentCategory) {
		this.parentCategory = parentCategory;
	}
	
	public List<AnnouncementCategory> getChildren() {
		return children;
	}

	public void setChildren(List<AnnouncementCategory> children) {
		this.children = children;
	}

	public int getReferencesCount() {
		return referencesCount;
	}

	public void setReferencesCount(int referencesCount) {
		this.referencesCount = referencesCount;
	}
}
