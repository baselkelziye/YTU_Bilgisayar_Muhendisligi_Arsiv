package com.sas.social.entity;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.hibernate.annotations.CreationTimestamp;

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
import jakarta.persistence.ManyToOne;
import jakarta.persistence.OneToMany;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;

@Entity
@Table(name="post")
public class Post {
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name="post_id")
	private Integer postId;
    
	private String content;
	
    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "media_id")
    private Media postImage;
	
	@Column(name="homepage_visible")
	private Boolean homepageVisible;
	
    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "user_id", nullable = false)
    private User user;  // author of the post

    @OneToMany(mappedBy = "post", cascade = CascadeType.ALL)
    private List<Comment> postComments = new ArrayList<>();
	
    @ManyToMany
    @JoinTable(
      name = "post_like", 
      joinColumns = @JoinColumn(name = "post_id"), 
      inverseJoinColumns = @JoinColumn(name = "user_id")
    )

    private Set<User> likingUsers = new HashSet<>();
    
    @ManyToMany
    @JoinTable(
      name = "post_category", 
      joinColumns = @JoinColumn(name = "post_id"), 
      inverseJoinColumns = @JoinColumn(name = "category_id")
    )
    private Set<Category> postCategories = new HashSet<>();

	@CreationTimestamp
	@Column(name="created_at")
	private LocalDateTime createdAt;

	// Constructor
	public Post() {}

	public Post(String content, Media postImage, Boolean homepageVisible, User user, Set<Category> postCategories) {
		this.content = content;
		this.postImage = postImage;
		this.homepageVisible = homepageVisible;
		this.user = user;
		this.postCategories = postCategories;
	}

	// getters and setters
	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public Media getPostImage() {
		return postImage;
	}

	public void setPostImage(Media media) {
		this.postImage = media;
	}

	public Boolean getHomepaegVisibility() {
		return homepageVisible;
	}

	public void setHomepaegVisibility(Boolean homepaegVisibility) {
		this.homepageVisible = homepaegVisibility;
	}

	public Integer getPostId() {
		return postId;
	}

	public User getUser() {
		return user;
	}
	
	public void setUser(User user) {
		this.user = user;
	}

	public List<Comment> getPostComments() {
		return postComments;
	}

	public Set<User> getLikingUsers() {
		return likingUsers;
	}

	public Set<Category> getPostCategories() {
		return postCategories;
	}

	public LocalDateTime getCreatedAt() {
		return createdAt;
	}	

}
