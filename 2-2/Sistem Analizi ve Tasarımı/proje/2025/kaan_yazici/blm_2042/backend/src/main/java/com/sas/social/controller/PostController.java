package com.sas.social.controller;

import java.util.NoSuchElementException;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RequestPart;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.sas.social.dto.PostCreateDto;
import com.sas.social.dto.PostResponseDto;
import com.sas.social.entity.UserPrincipal;
import com.sas.social.service.CommentService;
import com.sas.social.service.PostService;

import jakarta.persistence.EntityNotFoundException;

@RestController
@RequestMapping("/post")
public class PostController {

	private PostService postService;
	private CommentService commentService;

	@Autowired
	public PostController(PostService postService, CommentService commentService) {
		this.postService = postService;
		this.commentService = commentService;
	}
	
	@PostMapping("/create")
	public ResponseEntity<?> createPost(@ModelAttribute PostCreateDto postCreateDto) {
		return postService.createPost(postCreateDto);
	}
	
	@GetMapping("/{postId}")
	public ResponseEntity<?> getPost(@AuthenticationPrincipal UserPrincipal userDetails,
			@PathVariable Integer postId) {
		Integer viewingUserId = userDetails.getUserId();
		
		try {
			PostResponseDto responseDto = postService.getPost(postId, viewingUserId).get();
			return ResponseEntity.ok(responseDto);
		}
		catch(NoSuchElementException e) {
			return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Post doesn't exist or belongs to a blocked account.");
		}
	}
	
	@GetMapping("/{userId}/posts")
	public ResponseEntity<Page<PostResponseDto>> getLatestPostsOfUser(
	        @PathVariable Integer userId,
	        @RequestParam(defaultValue = "0") int offset,
	        @RequestParam(defaultValue = "10") int size,
	        @AuthenticationPrincipal UserPrincipal userDetails) {

	    Integer viewerId = userDetails.getUserId();
	    Pageable pageable = PageRequest.of(offset / size, size); // converting offset to page number

	    Page<PostResponseDto> posts = postService.getPostsOfUser(userId, viewerId, pageable);
	    return ResponseEntity.ok(posts);
	}

	@GetMapping("/{postId}/comments")
	public ResponseEntity<?> getPostComments(@PathVariable Integer postId,
			@AuthenticationPrincipal UserPrincipal userDetails) {
		
		return commentService.getPostComments(postId, userDetails.getUserId());
	}
	
	@PostMapping("/{postId}/like") 
	public ResponseEntity<?> likePost(@PathVariable Integer postId, 
			 	@AuthenticationPrincipal UserPrincipal userDetails) {
		Integer likerId = userDetails.getUserId();
		try {
			postService.likePost(postId, likerId);
			return ResponseEntity.ok().build();
		}
		catch(EntityNotFoundException e) {
			return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
		}
	}
	
	@PostMapping("/{postId}/unlike") 
	public ResponseEntity<?> unlikePost(@PathVariable Integer postId, 
			 	@AuthenticationPrincipal UserPrincipal userDetails) {
		Integer likerId = userDetails.getUserId();
		try {
			postService.unlikePost(postId, likerId);
			return ResponseEntity.ok().build();
		}
		catch(EntityNotFoundException e) {
			return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
		}
	}


}
