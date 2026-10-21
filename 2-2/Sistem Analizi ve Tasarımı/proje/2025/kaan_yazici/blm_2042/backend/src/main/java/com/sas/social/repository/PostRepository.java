package com.sas.social.repository;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Set;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.NativeQuery;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import com.sas.social.entity.Category;
import com.sas.social.entity.Post;
import com.sas.social.entity.User;

public interface PostRepository extends JpaRepository<Post, Integer> {
        
    // Get stats for a post
    
    @NativeQuery(value = "SELECT COUNT(*) FROM post_like WHERE post_id = :postId")
    int getLikeCount(@Param("postId") Integer postId);
        
    @NativeQuery(value = "SELECT COUNT(*) FROM comment WHERE post_id = :postId")
    int getCommentCount(@Param("postId") Integer postId);
    
    // Check if a user has liked a post
    @NativeQuery(value = "SELECT EXISTS(SELECT 1 FROM post_like WHERE post_id = :postId AND user_id = :userId)")
    boolean hasUserLikedPost(@Param("userId") Integer userId, @Param("postId") Integer postId);
        
    // Search posts by caption content
    List<Post> findBycontentContainingIgnoreCase(String keyword);
    
    @Query("SELECT p FROM Post p WHERE p.user.userId = :userId ORDER BY p.createdAt DESC")
    Page<Post> findByUserId_OrderByCreationDate(@Param("userId") Integer userId, Pageable pageable);
    
    boolean existsByPostId(Integer postId);
    
    @Query("SELECT p FROM Post p JOIN CommunityPost cp ON p.postId = cp.post.postId WHERE cp.community.communityId = :communityId ORDER BY p.createdAt DESC")
    Page<Post> getCommunityPosts(@Param("communityId") Integer communityId, Pageable pageable);

    @Query("""
    	    SELECT DISTINCT p FROM Post p
    	    JOIN p.user u
    	    LEFT JOIN p.postCategories pc
    	    WHERE 
    	        p.createdAt >= :cutoffDate AND (
    	            u IN :followedUsers
    	            OR (
    	                u NOT IN :blockedUsers AND
    	                u <> :currentUser AND
    	                p.homepageVisible = true AND
    	                pc IN :interestedCategories  
    	            )
    	        )
    	    """)
    	Page<Post> getPagedPostFeed (
    		@Param("currentUser") User user,
    	    @Param("followedUsers") Set<User> followedUsers,
    	    @Param("blockedUsers") Set<User> blockedUsers,
    	    @Param("interestedCategories") Set<Category> interestedCategories,
    	    @Param("cutoffDate") LocalDateTime cutoffDate,
    	    Pageable pageable
    	);

}