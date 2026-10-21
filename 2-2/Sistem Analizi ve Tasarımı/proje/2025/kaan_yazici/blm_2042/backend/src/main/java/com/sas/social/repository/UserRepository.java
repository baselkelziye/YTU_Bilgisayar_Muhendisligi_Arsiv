package com.sas.social.repository;

import java.util.List;
import java.util.Optional;
import java.util.Set;

import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.NativeQuery;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import com.sas.social.entity.User;

public interface UserRepository extends JpaRepository<User, Integer>{
	
    Optional<User> findByUsername(String username);

    Optional<User> findByEmail(String email);

    @Query("SELECT u FROM User u JOIN u.follows f WHERE f.userId = :userId")
    List<User> findFollowersByUserId(@Param("userId") Integer userId);

    @Query("SELECT f FROM User u JOIN u.follows f WHERE u.userId = :userId")
    List<User> findFollowsByUserId(@Param("userId") Integer userId);

    @Query("SELECT b FROM User u JOIN u.blockedUsers b WHERE u.userId = :userId")
    List<User> findBlockedUsersByUserId(@Param("userId") Integer userId);

    // For profile appearance 
    
    @NativeQuery(value = "SELECT COUNT(*) FROM user_follow WHERE followed_id = :userId")
    int getNumberOfFollowers(@Param("userId") Integer userId);
   
    @NativeQuery(value = "SELECT COUNT(*) FROM user_follow WHERE follower_id = :userId")
    int getNumberOfFollowing(@Param("userId") Integer userId);
    
    @NativeQuery(value = "SELECT COUNT(*) FROM post WHERE user_id = :userId")
    int getPostNumber(@Param("userId") Integer userId);
    
    // For profile search
    
    List<User> findByusernameStartingWith(String str);
    
    List<User> findByvisibleNameStartingWith(String str);
    
    // For validation
    
    boolean existsByUsername(String username);

    boolean existsByEmail(String email);
    
    // Existence checks
    
    @NativeQuery(value = "SELECT EXISTS(SELECT 1 FROM user_follow WHERE follower_id = :follower_id AND followed_id = :followed_id)")
    boolean isUserFollowing(@Param("follower_id") Integer followerId, 
                            @Param("followed_id") Integer followedId);

    @NativeQuery(value = "SELECT EXISTS(SELECT 1 FROM user_block WHERE blocker_id = :blocker_id AND blocked_id = :blocked_id)")
    boolean isUserBlocking(@Param("blocker_id") Integer blocker_id, 
                            @Param("blocked_id") Integer blocked_id);

    @Query("""
    	    SELECT u FROM User u
    	    WHERE u IN :followedUsers
    	      AND (
    	          LOWER(u.username) LIKE LOWER(CONCAT('%', :searchTerm, '%')) OR
    	          LOWER(u.visibleName) LIKE LOWER(CONCAT('%', :searchTerm, '%'))
    	      )
    	    """)
	List<User> profileSearchFollowedUsers(@Param("searchTerm") String searchTerm,
								   @Param("followedUsers") Set<User> followedUsers,
								   Pageable  limit);

    @Query("""
    	    SELECT u FROM User u
    	    WHERE u NOT IN :excludedUsers
    	      AND (
    	          LOWER(u.username) LIKE LOWER(CONCAT('%', :searchTerm, '%')) OR
    	          LOWER(u.visibleName) LIKE LOWER(CONCAT('%', :searchTerm, '%')) 
    	      )
    	    """)
	List<User> profileSearchOtherUsers(@Param("searchTerm") String searchTerm,
	                            @Param("excludedUsers") Set<User> excludedUsers,
	                            Pageable limit);

}
