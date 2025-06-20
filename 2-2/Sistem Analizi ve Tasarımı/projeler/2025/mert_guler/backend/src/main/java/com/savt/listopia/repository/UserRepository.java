package com.savt.listopia.repository;

import com.savt.listopia.model.movie.Movie;
import com.savt.listopia.model.user.User;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.Optional;
import java.util.UUID;

@Repository
public interface UserRepository extends JpaRepository<User, Long> {
    Optional<User> findByEmail(String email);
    Optional<User> findByUsername(String username);
    Optional<User> findByUsernameLower(String usernameLower);
    Optional<User> findByUuid(UUID uuid);
    boolean existsByUsername(String username);
    boolean existsByEmail(String email);
    boolean existsByUsernameLower(String usernameLower);

    @Query("SELECT m FROM User u JOIN u.likedMovies m WHERE u.id = :userId")
    Page<Movie> findLikedMoviesByUserId(@Param("userId") Long userId, Pageable page);

    @Query("SELECT u FROM User u JOIN u.friends f WHERE f.id = :userId")
    Page<User> findFriendsByUserId(@Param("userId") Long userId, Pageable pageable);

    @Query("SELECT m FROM User u JOIN u.watchlist m WHERE u.id = :userId")
    Page<Movie> findWatchlistByUserId(@Param("userId") Long userId, Pageable page);

    @Query("SELECT m FROM User u JOIN u.watchedList m WHERE u.id = :userId")
    Page<Movie> findWatchedListByUserId(@Param("userId") Long userId, Pageable page);

    @Query("SELECT u FROM User u JOIN u.likedMovies lm GROUP BY u ORDER BY COUNT(lm) DESC")
    Page<User> findUsersByLikedMoviesCount(Pageable pageDetails);

    @Query("SELECT u FROM User u JOIN u.watchedList wl GROUP BY u ORDER BY COUNT(wl) DESC")
    Page<User> findUsersByWatchedMoviesCount(Pageable pageDetails);

    @Query("SELECT u FROM User u WHERE " +
            "LOWER(u.username) LIKE LOWER(CONCAT('%', :query, '%')) OR " +
            "LOWER(u.firstName) LIKE LOWER(CONCAT('%', :query, '%')) OR " +
            "LOWER(u.lastName) LIKE LOWER(CONCAT('%', :query, '%'))")
    Page<User> searchUsers(@Param("query") String query, Pageable pageable);
}
