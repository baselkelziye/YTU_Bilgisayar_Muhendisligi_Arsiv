package org.db.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.Inheritance;
import javax.persistence.InheritanceType;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name = "users")
@Inheritance(strategy = InheritanceType.JOINED)
public class User implements Serializable {
	private static final long serialVersionUID = 1L;

	@Id
	@Column(name = "user_name")
	private String userName;

	@Column(name = "passwordFor", nullable = true)
	private String password;

	@ManyToOne
	@JoinColumn(name = "user_type_no")
	private UserType userType;

	@Column(name = "membership_status")
	private int status;

	@OneToMany(mappedBy="user",  
            targetEntity=CommunicationWay.class, 
    fetch=FetchType.EAGER, cascade = CascadeType.ALL)
	private List<CommunicationWay> commWays = new ArrayList<CommunicationWay>();

	@Column(name = "birth_date")
	private int birthDate;

	public User() {
		super();
	}

	public User(String userName, String password, UserType userType) {
	    super();
		this.userName = userName;
		this.password = password;
		this.userType = userType;
	}

	public User(String username){
	    super();
        this.userName = username;
    }

	public List<CommunicationWay> getCommWays() {
		return commWays;
	}

	public String getPassword() {
		return password;
	}

	public int getStatus() {
		return status;
	}

	public String getUserName() {
		return userName;
	}

	public UserType getUserType() {
		return userType;
	}

	public void setCommWays(List<CommunicationWay> commWays) {
		this.commWays = commWays;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public void setStatus(int id) {
		status = id;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public void setUserTypeNo(UserType userType) {
		this.userType = userType;
	}

    public int getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(int birthDate) {
        this.birthDate = birthDate;
    }
}
