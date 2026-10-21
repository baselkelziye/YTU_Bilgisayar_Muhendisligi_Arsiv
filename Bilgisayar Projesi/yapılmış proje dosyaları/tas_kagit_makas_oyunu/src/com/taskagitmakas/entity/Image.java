package com.taskagitmakas.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

import org.hibernate.annotations.Type;

@Entity
@Table(name="images")
public class Image {
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getRowCount() {
		return rowCount;
	}

	public void setRowCount(int rowCount) {
		this.rowCount = rowCount;
	}

	public int getColCount() {
		return colCount;
	}

	public void setColCount(int colCount) {
		this.colCount = colCount;
	}

	public String getHogDescriptionVector() {
		return hogDescriptionVector;
	}

	public void setHogDescriptionVector(String hogDescriptionVector) {
		this.hogDescriptionVector = hogDescriptionVector;
	}

	public int getClassType() {
		return classType;
	}

	public void setClassType(int classType) {
		this.classType = classType;
	}

	public int getUserId() {
		return userId;
	}

	public void setUserId(int userId) {
		this.userId = userId;
	}
 
	public boolean isTest() {
		return isTest;
	}

	public void setTest(boolean isTest) {
		this.isTest = isTest;
	}

	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	private int id;
	
	@Column(name="`rowCount`")
	private int rowCount;
	
	@Column(name="`colCount`")
	private int colCount;
	
	@Column(name="`hogDescriptionVector`")
	@Type(type="text")
	private String hogDescriptionVector;
	
	@Column(name="`classType`")
	private int classType;
	
	@Column(name="`userId`")
	private int userId;
	
	@Column(name="`isTest`")
	private boolean isTest;
 
}
