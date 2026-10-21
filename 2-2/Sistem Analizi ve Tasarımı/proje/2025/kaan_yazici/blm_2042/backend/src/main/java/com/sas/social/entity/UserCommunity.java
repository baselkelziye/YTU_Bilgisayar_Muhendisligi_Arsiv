package com.sas.social.entity;

import java.io.Serializable;
import java.util.Objects;

import jakarta.persistence.Column;
import jakarta.persistence.Embeddable;
import jakarta.persistence.EmbeddedId;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.MapsId;
import jakarta.persistence.Table;

@Entity
@Table(name = "user_community")
public class UserCommunity {

    @EmbeddedId
    private UserCommunityId id;

    @ManyToOne(fetch = FetchType.LAZY)
    @MapsId("userId") // maps to id.userId
    @JoinColumn(name = "user_id", nullable = false)
    private User user;

    @ManyToOne(fetch = FetchType.LAZY)
    @MapsId("communityId") // maps to id.communityId
    @JoinColumn(name = "community_id", nullable = false)
    private Community community;

    @Column(name = "user_role", nullable = false)
    private String userRole;

    public UserCommunity() {}

    public UserCommunity(User user, Community community, String userRole) {
        this.user = user;
        this.community = community;
        this.userRole = userRole;
        this.id = new UserCommunityId(user.getUserId(), community.getCommunityId());
    }
	
	// getters and setters
	public String getUserRole() {
		return userRole;
	}

	public void setUserRole(String userRole) {
		this.userRole = userRole;
	}

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}

	public Community getCommunity() {
		return community;
	}

	public void setCommunity(Community community) {
		this.community = community;
	}
	
	public UserCommunityId getId() {
		return id;
	}
	
	// Composite key class
	@Embeddable
	public static class UserCommunityId implements Serializable {
	
	    private Integer userId;
	    private Integer communityId;
	
	    public UserCommunityId() {}
	
	    public UserCommunityId(Integer userId, Integer communityId) {
	        this.userId = userId;
	        this.communityId = communityId;
	    }
	    
	    // getters and setters 
		public Integer getUserId() {
			return userId;
		}

		public void setUserId(Integer userId) {
			this.userId = userId;
		}

		public Integer getCommunityId() {
			return communityId;
		}

		public void setCommunityId(Integer communityId) {
			this.communityId = communityId;
		}

	    // equals() and hashCode() 
	    @Override
	    public boolean equals(Object o) {
	        if (this == o) return true;
	        if (!(o instanceof UserCommunityId)) return false;
	        UserCommunityId that = (UserCommunityId) o;
	        return Objects.equals(userId, that.userId) &&
	               Objects.equals(communityId, that.communityId);
	    }

		@Override
	    public int hashCode() {
	        return Objects.hash(userId, communityId);
	    }
	}
	
}
