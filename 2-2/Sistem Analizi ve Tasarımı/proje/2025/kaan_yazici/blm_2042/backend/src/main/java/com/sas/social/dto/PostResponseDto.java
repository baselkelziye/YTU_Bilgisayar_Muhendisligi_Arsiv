package com.sas.social.dto;

import java.time.LocalDateTime;

public record PostResponseDto(
		UserSummary userSummary,
		Integer postId,
		String content,
		Integer mediaId,
		Boolean isPostAuthorFollowed,
		Boolean isPostLiked,
		Integer numberOfPostLike,
		Integer numberOfPostComment,
		LocalDateTime createdAt
		) {

}
