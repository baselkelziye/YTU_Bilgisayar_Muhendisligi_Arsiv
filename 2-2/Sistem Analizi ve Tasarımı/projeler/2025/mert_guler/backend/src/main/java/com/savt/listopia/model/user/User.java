package com.savt.listopia.model.user;

import com.savt.listopia.model.movie.Movie;
import jakarta.persistence.*;
import lombok.Data;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

@Data
@Entity
@Table(name = "users")
public class User {
    @Id
    @GeneratedValue
    Long id;

    @Column(unique = true)
    UUID uuid = UUID.randomUUID();

    @Column(unique = true)
    String username;

    @Column(unique = true)
    String usernameLower;

    @Column(columnDefinition = "TEXT")
    String biography = "";

    String firstName;
    String lastName;

    @Column(unique = true)
    String email;

    String hashedPassword;

    private String profilePicture;

    @Enumerated(EnumType.STRING)
    private UserRole role = UserRole.USER;

    private Long lastOnline;
    private Long createdAt;

    private Boolean isDeleted = Boolean.FALSE;

    @ManyToMany
    @JoinTable(
            name = "user_liked_movies",
            joinColumns = @JoinColumn(name = "user_id"),
            inverseJoinColumns = @JoinColumn(name = "movie_id")
    )
    List<Movie> likedMovies = new ArrayList<>();

    @ManyToMany(fetch = FetchType.LAZY)
    @JoinTable(
            name = "user_watchlist",
            joinColumns = @JoinColumn(name = "user_id"),
            inverseJoinColumns = @JoinColumn(name = "movie_id")
    )
    private List<Movie> watchlist = new ArrayList<>();

    @ManyToMany(fetch = FetchType.LAZY)
    @JoinTable(
            name = "user_watched_list",
            joinColumns = @JoinColumn(name = "user_id"),
            inverseJoinColumns = @JoinColumn(name = "movie_id")
    )
    private List<Movie> watchedList = new ArrayList<>();

    @ManyToMany
    @JoinTable(
            name = "user_friends",
            joinColumns = @JoinColumn(name = "user_id"),
            inverseJoinColumns = @JoinColumn(name = "friend_id")
    )
    List<User> friends = new ArrayList<>();

    @OneToMany(mappedBy = "user", cascade = CascadeType.ALL, fetch = FetchType.LAZY, orphanRemoval = true)
    private List<Notification> notifications = new ArrayList<>();

    @OneToMany(mappedBy = "user", cascade = CascadeType.ALL, fetch = FetchType.LAZY, orphanRemoval = true)
    private List<UserActivity> activities = new ArrayList<>();

    public int getLikedCount(){
        return likedMovies.size();
    }

    public int getWatchedCount(){
        return watchedList.size();
    }
}
