package com.sas.social.dto;

import java.time.LocalDateTime;

public record CommentResponseDto(
		Integer postId,
		UserSummary userSummary,
		String text,
		LocalDateTime createdAt) {

}
