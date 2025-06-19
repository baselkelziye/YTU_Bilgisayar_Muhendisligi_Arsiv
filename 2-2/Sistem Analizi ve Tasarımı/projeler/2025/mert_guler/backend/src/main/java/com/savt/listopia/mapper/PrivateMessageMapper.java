package com.savt.listopia.mapper;

import com.savt.listopia.model.user.PrivateMessage;
import com.savt.listopia.model.user.UserActivity;
import com.savt.listopia.payload.dto.PrivateMessageDTO;
import com.savt.listopia.payload.dto.UserActivityDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;

import java.util.List;

@Mapper(componentModel = "spring", uses = { UserMapper.class })
public interface PrivateMessageMapper {
    @Mapping(source = "id", target = "id")
    @Mapping(source = "fromUser", target = "from")
    @Mapping(source = "toUser", target = "recipient")
    @Mapping(source = "sentAtTimestampSeconds", target = "sentAt")
    @Mapping(source = "message", target = "message")
    PrivateMessageDTO toDTO(PrivateMessage privateMessage);

    default Page<PrivateMessageDTO> toDTOPage(Page<PrivateMessage> page) {
        List<PrivateMessageDTO> dtoList = page.getContent().stream()
                .map(this::toDTO)
                .toList();
        return new PageImpl<>(dtoList, page.getPageable(), page.getTotalElements());
    }
}
