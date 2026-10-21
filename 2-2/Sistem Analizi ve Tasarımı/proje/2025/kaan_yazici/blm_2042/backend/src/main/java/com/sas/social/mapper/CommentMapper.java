package com.sas.social.mapper;

import java.util.function.Function;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.sas.social.dto.CommentCreateDto;
import com.sas.social.dto.CommentResponseDto;
import com.sas.social.dto.UserSummary;
import com.sas.social.entity.Comment;
import com.sas.social.entity.Post;
import com.sas.social.entity.User;
import com.sas.social.repository.PostRepository;
import com.sas.social.repository.UserRepository;

import jakarta.persistence.EntityNotFoundException;

@Component
public class CommentMapper 
	implements Function<Comment, CommentResponseDto> {

	@Autowired 
	private UserRepository userRepository;
	
	@Autowired 
	private PostRepository postRepository;
	
	@Override
	public CommentResponseDto apply(Comment comment) {
		
		User user = comment.getUser();
		Integer userProfilePhotoId = null;
		
		if(user.getProfilePhoto() != null) 
			userProfilePhotoId = user.getProfilePhoto().getMediaId();
		
		return new CommentResponseDto(
				comment.getPost().getPostId(),
				
				new UserSummary(
						user.getUserId(),
						user.getVisibleName(),
						user.getUsername(),
						userProfilePhotoId
				),
				
				comment.getText(),
				comment.getCreatedAt()
				);
	}
	
	public Comment toEntity(CommentCreateDto commentDto) {
	    User user = userRepository.findByUsername( commentDto.username() )
	            .orElseThrow(() -> new EntityNotFoundException("User not found"));
	    Post post = postRepository.findById( commentDto.postId() )
	            .orElseThrow(() -> new EntityNotFoundException("Post not found"));
		
	    return new Comment(
				user,
				post,
				commentDto.text()
				);
	}
	
}
