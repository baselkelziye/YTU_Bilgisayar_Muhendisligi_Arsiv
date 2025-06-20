package com.savt.listopia.mapper;

import com.savt.listopia.model.user.Notification;
import com.savt.listopia.payload.dto.NotificationDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;

import java.util.List;

@Mapper(componentModel = "spring")
public interface NotificationMapper {
    @Mapping(source = "content", target = "content")
    NotificationDTO toDTO(Notification notification);

    default Page<NotificationDTO> toDTOPage(Page<Notification> page) {
        List<NotificationDTO> dtoList = page.getContent().stream()
                .map(this::toDTO)
                .toList();
        return new PageImpl<>(dtoList, page.getPageable(), page.getTotalElements());
    }
}
