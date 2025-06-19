package com.savt.listopia.controller.admin;

import com.savt.listopia.model.user.UserRole;
import com.savt.listopia.service.AuthService;
import com.savt.listopia.util.FetchUtil;
import info.movito.themoviedbapi.tools.TmdbException;
import jakarta.validation.constraints.Max;
import jakarta.validation.constraints.Min;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1/admin/fetch")
public class FetchController {
    private static final Logger LOGGER = LoggerFactory.getLogger(FetchController.class);

    private final FetchUtil fetchUtil;
    private final AuthService authService;

    public FetchController(FetchUtil fetchUtil, AuthService authService) {
        this.fetchUtil = fetchUtil;
        this.authService = authService;
    }

    @PostMapping("/genres")
    public ResponseEntity<String> fetchGenres() throws TmdbException {
        authService.requireRoleOrThrow(UserRole.ADMIN);
        LOGGER.info("fetchGenres: fetching genres");
        fetchUtil.fetchGenres();
        return new ResponseEntity<>("Fetched genres", HttpStatus.CREATED);
    }

    @PostMapping("/movies")
    public ResponseEntity<String> fetchMovies(@Min(1) @RequestParam(name = "startId", defaultValue = "1", required = false) Integer startId,
                                              @Max(1000001) @RequestParam(name = "endId", defaultValue = "100", required = false) Integer endId,
                                              @Min(0) @RequestParam(name = "minPopularity", defaultValue = "20", required = false) Integer minPopularity,
                                              @RequestParam(name = "fetchAllImages", defaultValue = "false", required = false) Boolean fetchAllImages,
                                              @RequestParam(name = "fetchKeywords", defaultValue = "false", required = false) Boolean fetchKeywords) {
        authService.requireRoleOrThrow(UserRole.ADMIN);
        LOGGER.info("fetchGenres: fetching movies");
        fetchUtil.fetchMovies(startId, endId, minPopularity, fetchAllImages, fetchKeywords);
        return new ResponseEntity<>("Fetching movies is completed", HttpStatus.CREATED);
    }
}
