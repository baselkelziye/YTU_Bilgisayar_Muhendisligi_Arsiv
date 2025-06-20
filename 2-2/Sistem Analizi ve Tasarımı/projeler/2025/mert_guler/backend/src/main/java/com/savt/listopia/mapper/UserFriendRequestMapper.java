package com.savt.listopia.mapper;

import com.savt.listopia.model.user.UserFriendRequest;
import com.savt.listopia.payload.dto.UserFriendRequestDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;

import java.util.List;

@Mapper(componentModel = "spring", uses = { UserMapper.class })
public interface UserFriendRequestMapper {
    @Mapping(source = "id", target = "id")
    @Mapping(source = "userRequestSent", target = "userRequestSent")
    @Mapping(source = "userRequestReceived", target = "userRequestReceived")
    @Mapping(source = "timestamp", target = "timestamp")
    UserFriendRequestDTO toDTO(UserFriendRequest userFriendRequest);

    default Page<UserFriendRequestDTO> toDTOPage(Page<UserFriendRequest> page) {
        List<UserFriendRequestDTO> dtoList = page.getContent().stream()
                .map(this::toDTO)
                .toList();
        return new PageImpl<>(dtoList, page.getPageable(), page.getTotalElements());

    }
}
