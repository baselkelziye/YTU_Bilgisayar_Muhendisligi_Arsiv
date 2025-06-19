package com.savt.listopia.controller.admin;

import com.savt.listopia.model.user.UserRole;
import com.savt.listopia.payload.dto.statistic.StatisticDTO;
import com.savt.listopia.service.AuthService;
import com.savt.listopia.service.admin.StatService;
import com.savt.listopia.util.FetchUtil;
import info.movito.themoviedbapi.tools.TmdbException;
import jakarta.validation.constraints.Max;
import jakarta.validation.constraints.Min;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/v1/admin/stats")
public class StatController {
    private static final Logger LOGGER = LoggerFactory.getLogger(StatController.class);

    private final AuthService authService;
    private final StatService statService;

    public StatController(AuthService authService, StatService statService) {
        this.authService = authService;
        this.statService = statService;
    }

    @GetMapping("/all")
    public ResponseEntity<StatisticDTO> getStatistics() {
        authService.requireRoleOrThrow(UserRole.ADMIN);
        LOGGER.info("getStatistics: getting statistics");
        StatisticDTO statisticDTO = statService.getStatistics();
        return new ResponseEntity<>(statisticDTO, HttpStatus.OK);
    }

}
