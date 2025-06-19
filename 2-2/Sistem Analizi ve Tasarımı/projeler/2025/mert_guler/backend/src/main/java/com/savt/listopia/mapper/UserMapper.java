package com.savt.listopia.mapper;

import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.UserDTO;
import org.mapstruct.Mapper;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;

import java.util.List;

@Mapper(componentModel = "spring")
public interface UserMapper {
    UserDTO toDTO(User user);

    default Page<UserDTO> toDTOPage(Page<User> page) {
        List<UserDTO> dtoList = page.getContent().stream()
                .map(this::toDTO)
                .toList();
        return new PageImpl<>(dtoList, page.getPageable(), page.getTotalElements());
    }
}
