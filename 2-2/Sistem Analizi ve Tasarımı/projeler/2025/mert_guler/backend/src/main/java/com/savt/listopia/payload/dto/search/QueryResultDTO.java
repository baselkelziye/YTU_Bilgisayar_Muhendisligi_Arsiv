package com.savt.listopia.payload.dto.search;

import com.savt.listopia.model.Category;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import org.springframework.data.domain.Page;

import java.util.HashMap;
import java.util.Map;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
public class QueryResultDTO {
    private Map<Category, Page<?>> results = new HashMap<>();
}
