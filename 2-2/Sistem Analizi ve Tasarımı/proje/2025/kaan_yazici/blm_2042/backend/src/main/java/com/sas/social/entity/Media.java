package com.sas.social.entity;

import java.sql.Types;

import org.hibernate.annotations.JdbcTypeCode;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Lob;
import jakarta.persistence.Table;

@Entity
@Table(name="media")
public class Media {

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Integer media_id;
	
	@Column(name="image_name")
	private String imageName;
	
	@Column(name="image_type")
	private String imageType;
	
	@Lob
	@Column(name = "image_byte")
	@JdbcTypeCode(Types.BINARY)
	private byte[] imageByte;
	
	public Media() {}

	public Media(String imageName, String imageType, byte[] imageByte) {
		this.imageName = imageName;
		this.imageType = imageType;
		this.imageByte = imageByte;
	}

	public Integer getMediaId() {
		return media_id;
	}

	public String getImageName() {
		return imageName;
	}

	public void setImageName(String imageName) {
		this.imageName = imageName;
	}

	public String getImageType() {
		return imageType;
	}

	public void setImageType(String imageType) {
		this.imageType = imageType;
	}

	public byte[] getImageByte() {
		return imageByte;
	}

	public void setImageByte(byte[] imageByte) {
		this.imageByte = imageByte;
	}

}
