package com.sas.social.repository;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

import com.sas.social.entity.Comment;

public interface CommentRepository extends JpaRepository<Comment, Integer> {    
       
	List<Comment> findByPostPostId(Integer postId);

}