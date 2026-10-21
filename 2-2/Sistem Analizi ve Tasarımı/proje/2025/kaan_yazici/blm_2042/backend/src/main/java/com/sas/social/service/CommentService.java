package com.sas.social.service;

import java.util.List;
import java.util.NoSuchElementException;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import com.sas.social.dto.CommentCreateDto;
import com.sas.social.dto.CommentResponseDto;
import com.sas.social.entity.Comment;
import com.sas.social.entity.User;
import com.sas.social.mapper.CommentMapper;
import com.sas.social.repository.CommentRepository;
import com.sas.social.repository.PostRepository;
import com.sas.social.repository.UserRepository;

@Service
public class CommentService {
	 
	private CommentRepository commentRepository;
	private PostRepository postRepository;
	private UserRepository userRepository;
	private CommentMapper commentMapper;
	
	@Autowired
	public CommentService(CommentRepository commentRepository, CommentMapper commentMapper,
			UserRepository userRepository, PostRepository postRepository){
		this.commentRepository = commentRepository;
		this.commentMapper = commentMapper;
		this.userRepository = userRepository;
		this.postRepository = postRepository;
	}

	public ResponseEntity<?> createPost(CommentCreateDto commentDto) {
		try {
			Comment comment = commentMapper.toEntity(commentDto);
			commentRepository.save(comment);
			return ResponseEntity.ok().build();
		} 
		catch(NoSuchElementException e) {
			return ResponseEntity.status(HttpStatus.NOT_FOUND).body( e.getMessage() );
		}
	}
	
	public ResponseEntity<?> getPostComments(Integer postId, Integer viewingId) {
		if( !postRepository.existsByPostId(postId))
			return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Post doesn't exist");
		
		User user = userRepository.findById(viewingId).get();
		
		Set<User> blockedUsers = user.getBlockedUsers(); 

		List<Comment> comments = commentRepository.findByPostPostId(postId);

		List<CommentResponseDto> commentDtoList = comments
			.stream()
			.filter( comment -> !blockedUsers.contains( comment.getUser() )) 
			.map(commentMapper)
			.toList();

		return ResponseEntity.ok(commentDtoList);	}

}
