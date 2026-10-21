package com.sas.social.dto;

public record CommentCreateDto(
		Integer postId,
		String username,
		String text) {

}
