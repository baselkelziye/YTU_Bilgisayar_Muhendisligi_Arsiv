package com.sas.social.service;

import java.time.LocalDateTime;
import java.util.Optional;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import com.sas.social.dto.PostCreateDto;
import com.sas.social.dto.PostResponseDto;
import com.sas.social.entity.Category;
import com.sas.social.entity.Post;
import com.sas.social.entity.User;
import com.sas.social.mapper.PostMapper;
import com.sas.social.repository.MediaRepository;
import com.sas.social.repository.PostRepository;
import com.sas.social.repository.UserRepository;

import jakarta.persistence.EntityNotFoundException;

@Service
public class PostService {

	PostRepository postRepository;
	UserRepository userRepository;
	PostMapper postMapper;
	MediaRepository mediaRepository;
	
	@Autowired
	public PostService(PostRepository postRepository, UserRepository userRepository, 
				PostMapper postMapper, MediaRepository mediaRepository) {
		this.postRepository = postRepository;
		this.userRepository = userRepository;
		this.postMapper = postMapper;
		this.mediaRepository = mediaRepository;
	}

	public ResponseEntity<?> createPost(PostCreateDto postDto) {
		if(postDto.title() == null &&  postDto.postImage() == null )
			return ResponseEntity.badRequest().body("Cannot create empty post");
		
		Post post = postMapper.map( postDto);
		
		if( post.getPostImage() != null)
			mediaRepository.save( post.getPostImage() );
		
		postRepository.save(post);
		return ResponseEntity.ok().build();
	}

	// Returns empty if user is blocked
	public Optional<PostResponseDto> getPost(Integer postId, Integer viewerId) {
		Post post = postRepository.findById(postId).get();
		
		if( userRepository.isUserBlocking(viewerId, post.getUser().getUserId()) ) {
			return Optional.empty();
		}

		return Optional.of(postMapper.map(post, viewerId));
	}
	
	// Returns empty if user is blocked
	public Page<PostResponseDto> getPostsOfUser(Integer userId, Integer viewerId, Pageable pageable) {
		
		if( userRepository.isUserBlocking(viewerId, userId) ) {
			return Page.empty();
		}
		
		Page<Post> posts = postRepository.findByUserId_OrderByCreationDate(userId, pageable);
		return posts.map(p -> postMapper.map(p, viewerId));
	}
	
	
	public Page<PostResponseDto> getPostFeed(String username, Pageable pageable) {
		
		User user = userRepository.findByUsername(username).get();
		
		Set<User> followedUsers = user.getFollows();
		Set<User> blockedUsers = user.getBlockedUsers();
		Set<Category> interestedCategories = user.getUserCategories();
		
		LocalDateTime cutoffDate = LocalDateTime.now().minusDays(20);
		
		return postRepository.getPagedPostFeed(user, followedUsers, blockedUsers, 
							interestedCategories, cutoffDate, pageable)

				.map(p -> postMapper.map(p, user.getUserId() )
				);
				
	}
	
	public void likePost(Integer postId, Integer likerId) {
		User user = userRepository.findById(likerId)
	            .orElseThrow(() -> new EntityNotFoundException("User not found"));
		Post post = postRepository.findById(postId)
	            .orElseThrow(() -> new EntityNotFoundException("Post not found"));

		
		post.getLikingUsers().add(user);
		postRepository.save(post);
	}
	
	public void unlikePost(Integer postId, Integer likerId) {
		User user = userRepository.findById(likerId)
	            .orElseThrow(() -> new EntityNotFoundException("User not found"));
		Post post = postRepository.findById(postId)
	            .orElseThrow(() -> new EntityNotFoundException("Post not found"));

		
		post.getLikingUsers().remove(user);
		postRepository.save(post);
	}

}
