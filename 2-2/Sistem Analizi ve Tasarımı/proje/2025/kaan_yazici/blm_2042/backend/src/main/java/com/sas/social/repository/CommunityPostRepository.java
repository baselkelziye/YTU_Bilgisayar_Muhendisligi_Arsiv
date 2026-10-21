package com.sas.social.repository;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;

import com.sas.social.entity.CommunityPost;

public interface CommunityPostRepository extends JpaRepository<CommunityPost, Integer>{

	Page<CommunityPost> findByCommunity_CommunityIdOrderByPost_CreatedAtDesc(Integer communityId, Pageable pageable);
}
