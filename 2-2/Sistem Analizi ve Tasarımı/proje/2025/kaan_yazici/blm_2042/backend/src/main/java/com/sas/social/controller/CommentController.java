package com.sas.social.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.sas.social.dto.CommentCreateDto;
import com.sas.social.service.CommentService;

@RestController
@RequestMapping("/comment")
public class CommentController {

	@Autowired
	private CommentService commentService;
	
	@PostMapping("/create")
	public ResponseEntity<?> createComment(@RequestBody CommentCreateDto commentCreateDto) {
		return commentService.createPost(commentCreateDto);
	}
	
}
