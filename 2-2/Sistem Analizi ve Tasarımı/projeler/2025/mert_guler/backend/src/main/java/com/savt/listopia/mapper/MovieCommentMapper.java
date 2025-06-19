package com.savt.listopia.mapper;

import com.savt.listopia.model.user.MovieComment;
import com.savt.listopia.payload.dto.MovieCommentDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;

import java.util.List;

@Mapper(componentModel = "spring", uses = { UserMapper.class })
public interface MovieCommentMapper {

    @Mapping(source = "id", target = "commentId")
    @Mapping(source = "sentAtTimestampSeconds", target = "sentAt")
    @Mapping(source = "fromUser", target = "user")
    @Mapping(source = "movie.movieId", target = "movieId")
    @Mapping(source = "message", target = "message")
    @Mapping(source = "isSpoiler", target = "isSpoiler")
    @Mapping(source = "isUpdated", target = "isUpdated")
    MovieCommentDTO toDTO(MovieComment comment);

    default Page<MovieCommentDTO> toDTOPage(Page<MovieComment> page) {
        List<MovieCommentDTO> dtoList = page.getContent().stream()
                .map(this::toDTO)
                .toList();

        return new PageImpl<>(dtoList, page.getPageable(), page.getTotalElements());
    }
}
