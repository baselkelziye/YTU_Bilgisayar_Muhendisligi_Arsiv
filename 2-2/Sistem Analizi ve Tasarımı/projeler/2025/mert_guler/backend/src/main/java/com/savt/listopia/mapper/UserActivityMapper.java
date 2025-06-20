package com.savt.listopia.mapper;

import com.savt.listopia.model.user.UserActivity;
import com.savt.listopia.payload.dto.UserActivityDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;

import java.util.List;

@Mapper(componentModel = "spring")
public interface UserActivityMapper {
    @Mapping(source = "content", target = "content")
    UserActivityDTO toDTO(UserActivity notification);

    default Page<UserActivityDTO> toDTOPage(Page<UserActivity> page) {
        List<UserActivityDTO> dtoList = page.getContent().stream()
                .map(this::toDTO)
                .toList();
        return new PageImpl<>(dtoList, page.getPageable(), page.getTotalElements());
    }
}
