package com.sas.social.controller;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
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
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.sas.social.dto.PostResponseDto;
import com.sas.social.dto.UserProfileDto;
import com.sas.social.dto.UserRegisterDto;
import com.sas.social.dto.UserUpdateDto;
import com.sas.social.entity.UserPrincipal;
import com.sas.social.service.PostService;
import com.sas.social.service.UserService;

import jakarta.transaction.Transactional;

@RestController
@RequestMapping("/user")
public class UserController {

	private UserService userService;
	private PostService postService;
	
	@Autowired
	public UserController(UserService userService, PostService postService) {
		this.userService = userService;
		this.postService = postService;
	}
	
	@PostMapping("/signup")
	public ResponseEntity<?> signUp(@RequestBody UserRegisterDto userRegisterDto) {
		return userService.signUpUser(userRegisterDto);
	}
	
	@PatchMapping("/update")
	public void updateProfile(@AuthenticationPrincipal UserPrincipal userDetails,
				@ModelAttribute UserUpdateDto dto) throws IOException {
		Integer userId = userDetails.getUserId();
		userService.updateUser(dto, userId);
	}
	
	@PostMapping("/profile")
    public UserProfileDto getProfile(
            @AuthenticationPrincipal UserPrincipal userDetails) {
		return userService.getById( userDetails.getUserId() ).get();
	}
	
	@GetMapping("{username}/profile")
	public ResponseEntity<Map<String, Object>> getProfile(
	        @AuthenticationPrincipal UserPrincipal userDetails,
	        @PathVariable("username") String username) {

	    return userService.getByUsername(username)
	            .map(profileDto -> {
	                Map<String, Object> response = new HashMap<>();
	                response.put("UserProfileDto", profileDto);
	                response.put("isFollowing", userService.isUserFollowing(userDetails.getUserId(), username));
	                response.put("isBlocked", userService.isUserBlocking(userDetails.getUserId(), username));
	                return ResponseEntity.ok(response);
	            })
	            .orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND).build());
	}
	
	@GetMapping("/id/{id}")
	public ResponseEntity<UserProfileDto> getById(@PathVariable Integer id) {
	    return userService.getById(id)
	            .map(ResponseEntity::ok)
	            .orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND).build());
	}
	
	@GetMapping("/username/{username}")
	public ResponseEntity<UserProfileDto> getByUsername(@PathVariable String username) {
	    return userService.getByUsername(username)
	            .map(ResponseEntity::ok)
	            .orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND).build());
	}

	@GetMapping("/email/{email}")
	public ResponseEntity<UserProfileDto> getByEmail(@PathVariable String email) {
	    return userService.getByEmail(email)
	            .map(ResponseEntity::ok)
	            .orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND).build());
	}

	@GetMapping("/post-feed")
	public Page<PostResponseDto> geetPostFeed(@AuthenticationPrincipal UserPrincipal userDetails,
		        @RequestParam(defaultValue = "0") int offset,
		        @RequestParam(defaultValue = "10") int size
				) {
		
		Pageable pageable = PageRequest.of(offset / size, size); // converting offset to page number
		
		return postService.getPostFeed(userDetails.getUsername(), pageable);
	}
	
    @PostMapping("/{id}/follow")
    @Transactional
    public ResponseEntity<?> followUser(
            @AuthenticationPrincipal UserPrincipal userDetails,
            @PathVariable("id") String followedUsername) {

    	String followerUsername = userDetails.getUsername();
        if (followerUsername.equals(followedUsername)) {
            return ResponseEntity.badRequest().body("Cannot follow self.");
        }

        try {
            userService.follow(followerUsername, followedUsername);
            return ResponseEntity.ok().build();
        } catch (NoSuchElementException e) {
        	return ResponseEntity.status(HttpStatus.NOT_FOUND).body("This account does not exist.");
        }        
    }
	
    @PostMapping("/{id}/unfollow")
    @Transactional
    public ResponseEntity<?> unfollowUser(
            @AuthenticationPrincipal UserPrincipal userDetails,
            @PathVariable("id") String followedUsername) {

        String followerUsername = userDetails.getUsername();
        if (followerUsername.equals(followedUsername)) {
            return ResponseEntity.badRequest().body("Cannot unfollow self.");
        }

        try {
            userService.unfollow(followerUsername, followedUsername);
            return ResponseEntity.ok().build();
        } catch (NoSuchElementException e) {
        	return ResponseEntity.status(HttpStatus.NOT_FOUND).body("This account does not exist.");
        }        
    }
    
    @PostMapping("/{id}/block")
    public ResponseEntity<?> blockUser(
            @AuthenticationPrincipal UserPrincipal userDetails,
            @PathVariable("id") String blockedUsername) {

        String blockerUsername = userDetails.getUsername();

        if (blockerUsername.equals(blockedUsername)) {
            return ResponseEntity.badRequest().body("Cannot block self.");
        }

        try {
            userService.block(blockerUsername, blockedUsername);
            return ResponseEntity.ok().build();
        } catch (NoSuchElementException e) {
        	return ResponseEntity.status(HttpStatus.NOT_FOUND).body("This account does not exist.");
        }
    }
    
    @PostMapping("/{id}/unblock")
    @Transactional
    public ResponseEntity<?> unblockUser(
            @AuthenticationPrincipal UserPrincipal userDetails,
            @PathVariable("id") String blockedUsername) {

        String blockerUsername = userDetails.getUsername();

        if (blockerUsername.equals(blockedUsername)) {
            return ResponseEntity.badRequest().body("Cannot unblock self.");
        }

        try {
            userService.block(blockerUsername, blockedUsername);
            return ResponseEntity.ok().build();
        } catch (NoSuchElementException e) {
        	return ResponseEntity.status(HttpStatus.NOT_FOUND).body("This account does not exist.");
        }
    }

}
