package org.db.model;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name="user_type")
public class UserType implements Serializable {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Id
    @Column(name="type_no")
    private int typeNo;
    
    @Column(name="type_name")
    private String typeName;
    
    @Column(name="main_page")
    private String mainPage;
    
    @Column(name = "unauthorized_page")
    private String unauthorizedPage;

    public String getUnauthorizedPage() {
		return unauthorizedPage;
	}

	public int getTypeNo() {
        return typeNo;
    }

    public void setType_no(int typeNo) {
        this.typeNo = typeNo;
    }

    public String getTypeName() {
        return typeName;
    }

    public void setType_name(String typeNo) {
        this.typeName = typeNo;
    }

    public String getMainPage() {
        return mainPage;
    }

    public void setMainPage(String main_page) {
        this.mainPage = main_page;
    }
}
