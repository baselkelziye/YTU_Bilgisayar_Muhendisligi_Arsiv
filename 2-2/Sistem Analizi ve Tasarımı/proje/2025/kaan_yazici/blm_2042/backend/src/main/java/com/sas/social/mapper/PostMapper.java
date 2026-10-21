package com.sas.social.mapper;

import java.io.IOException;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.multipart.MultipartFile;

import com.sas.social.dto.PostCreateDto;
import com.sas.social.dto.PostResponseDto;
import com.sas.social.dto.UserSummary;
import com.sas.social.entity.Category;
import com.sas.social.entity.Post;
import com.sas.social.entity.User;
import com.sas.social.repository.CategoryRepository;
import com.sas.social.repository.PostRepository;
import com.sas.social.repository.UserRepository;

import jakarta.persistence.EntityNotFoundException;

@Component
public class PostMapper {

    UserRepository userRepository;
    PostRepository postRepository;
    CategoryRepository categoryRepository;
 
    @Autowired
    public PostMapper(UserRepository userRepository, PostRepository postRepository,
				CategoryRepository categoryRepository) {
		this.userRepository = userRepository;
		this.postRepository = postRepository;
		this.categoryRepository = categoryRepository;
	}

	public PostResponseDto map(Post post, Integer viewingUserId) {
        Integer postAuthorId = post.getUser().getUserId();
        Integer postId = post.getPostId();

        boolean isPostAuthorFollowed = userRepository.isUserFollowing(viewingUserId, postAuthorId);
        boolean isPostLiked = postRepository.hasUserLikedPost(viewingUserId, postId);
        
        Integer postLikeCount = postRepository.getLikeCount( postId );
        Integer postCommentCount = postRepository.getCommentCount( postId );

        User user = post.getUser();
        Integer profilePhotoId = null;
        Integer postMediaId = null;
        
        if( user.getProfilePhoto() != null)
        	profilePhotoId = user.getProfilePhoto().getMediaId();
        if( post.getPostImage() != null)
        	postMediaId = post.getPostImage().getMediaId();
        
        return new PostResponseDto(
            new UserSummary(
                user.getUserId(),
                user.getVisibleName(),
                user.getUsername(),
                profilePhotoId
            ),
            
            post.getPostId(),
            post.getContent(),
            postMediaId,
            
            isPostAuthorFollowed,
            isPostLiked,
            
            postLikeCount,
            postCommentCount,
            
            post.getCreatedAt()
        );
    }
    
	public Post map(PostCreateDto dto) {
	    User user = userRepository.findByUsername( dto.username() )
	            .orElseThrow(() -> new EntityNotFoundException("User not found"));
	    Set<Category> categories = categoryRepository.findAllByCategoryNameIn( dto.postCategories() );
	    		
		try {
			return new Post(
					dto.title(),
					MediaFactory.fromMultipartFile( dto.postImage() ),
					dto.homepageVisible(),
					user,
					categories
					);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
}
