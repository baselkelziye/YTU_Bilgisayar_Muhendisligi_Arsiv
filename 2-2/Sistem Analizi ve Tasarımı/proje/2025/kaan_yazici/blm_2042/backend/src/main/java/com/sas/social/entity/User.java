package com.sas.social.entity;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.JoinTable;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.OneToMany;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;

@Entity
@Table(name = "users")
public class User {

    @Id
    @Column(name="user_id")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer userId;

    @Column(name="visible_name", nullable = false, unique = true)
    private String visibleName;
    
    @Column(nullable = false, unique = true)
    private String username;

    @Column(nullable = false, unique = true)
    private String email;

    private String bio;
    
    @Column(name ="user_password", nullable = false)
    private String password;

    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "profile_photo_id")
    private Media profilePhoto;
    
    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "banner_photo_id")
    private Media bannerPhoto;
    
    @OneToMany(mappedBy = "user", cascade = CascadeType.ALL)
    private List<Post> posts = new ArrayList<>();
    
    @ManyToMany(mappedBy = "likingUsers")
    private List<Post> likedPosts = new ArrayList<>();

//    @OneToMany(mappedBy = "user", cascade = CascadeType.ALL)
//    private List<Comment> comments = new ArrayList<>();
    
    @OneToMany(mappedBy = "user", cascade = CascadeType.ALL)
    private Set<UserCommunity> participatedCommunities = new HashSet<>();
    
    @ManyToMany
    @JoinTable(
      name = "user_interest", 
      joinColumns = @JoinColumn(name = "user_id"), 
      inverseJoinColumns = @JoinColumn(name = "category_id")
    )
    private Set<Category> userCategories = new HashSet<>();
   
    @ManyToMany
    @JoinTable(
      name = "user_follow", 
      joinColumns = @JoinColumn(name = "follower_id"), 
      inverseJoinColumns = @JoinColumn(name = "followed_id")
    )

    private Set<User> follows = new HashSet<>();
    
    @ManyToMany
    @JoinTable(
      name = "user_follow", 
      joinColumns = @JoinColumn(name = "followed_id"), 
      inverseJoinColumns = @JoinColumn(name = "follower_id")
    )

    private Set<User> followers = new HashSet<>();
    
    @ManyToMany
    @JoinTable(
      name = "user_block", 
      joinColumns = @JoinColumn(name = "blocker_id"), 
      inverseJoinColumns = @JoinColumn(name = "blocked_id")
    )

    private Set<User> blockedUsers = new HashSet<>();
    
    // Constructors
    public User() {}
    
    // Constructor for registration
	public User(String visibleName, String username, String email, String password, Set<Category> userCategories) {
		this.visibleName = visibleName;
		this.username = username;
		this.email = email;
		this.password = password;
		this.userCategories = userCategories;
	}
	
	// getters and setters
	public String getVisibleName() {
		return visibleName;
	}

	public void setVisibleName(String nameSurname) {
		this.visibleName = nameSurname;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getBio() {
		return bio;
	}
	
	public void setBio(String bio) {
		this.bio = bio;
	}
	
	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public Media getProfilePhoto() {
		return profilePhoto;
	}

	public void setProfilePhoto(Media profilePhoto) {
		this.profilePhoto = profilePhoto;
	}
	
	public Media getBannerPhoto() {
		return bannerPhoto;
	}

	public void setBannerPhoto(Media bannerPhoto) {
		this.bannerPhoto = bannerPhoto;
	}

	public Integer getUserId() {
		return userId;
	}

	public List<Post> getPosts() {
		return posts;
	}

	public List<Post> getLikedPosts() {
		return likedPosts;
	}

	public Set<UserCommunity> getParticipatedCommunities() {
		return participatedCommunities;
	}

	public Set<Category> getUserCategories() {
		return userCategories;
	}

	public Set<User> getFollowers() {
		return followers;
	}

	public Set<User> getFollows() {
		return follows;
	}

	public Set<User> getBlockedUsers() {
		return blockedUsers;
	}
          
}
