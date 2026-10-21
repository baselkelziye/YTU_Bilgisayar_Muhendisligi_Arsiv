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
import jakarta.persistence.OneToMany;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;

@Entity
@Table(name="community")
public class Community {

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name="community_id")
	private Integer communityId;

	@Column(name="community_name", unique = true, nullable = false)
	private String communityName;
	
	@Column(name="community_description", nullable = false)
	private String communityDescription;
	
    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "media_id")
    private Media media;
	
    @OneToMany(mappedBy = "community", cascade = CascadeType.ALL)
    private List<CommunityPost> communityPosts = new ArrayList<>();
    
    @OneToMany(mappedBy = "community", cascade = CascadeType.ALL)
    private Set<UserCommunity> communityUsers = new HashSet<>();

    public Community() {}

	public Community(String communityName, String communityDescription, Media media) {
		this.communityName = communityName;
		this.media = media;
		this.communityDescription = communityDescription;
	}

	public Integer getCommunityId() {
		return communityId;
	}

	public String getCommunityName() {
		return communityName;
	}

	public void setCommunityName(String communityName) {
		this.communityName = communityName;
	}
	
	public String getCommunityDescription() {
		return communityDescription;
	}
	
	public void setCommunityDescription(String description) {
		this.communityDescription = description;
	}

	public Media getMedia() {
		return media;
	}

	public void setMedia(Media media) {
		this.media = media;
	}

	public List<CommunityPost> getCommunityPosts() {
		return communityPosts;
	}

	public Set<UserCommunity> getCommunityUsers() {
		return communityUsers;
	}
    
}
