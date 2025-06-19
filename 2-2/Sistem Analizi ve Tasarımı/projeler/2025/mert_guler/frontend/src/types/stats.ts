export interface MovieStat {
    movieId: number;
    title: string;
    poster: string | null;
    watchCount: number;
    likeCount: number;
    clickCount: number;
}

export interface GenreStat {
    genreId: number;
    name: string;
    clickCount: number;
    watchCount: number;
    likeCount: number;
}

export interface UserStat {
    uuid: string;
    username: string;
    profilePicture: string;
    watchedCount: number;
    likedCount: number;
}

export interface AdminStats {
    mostWatchedMovies: MovieStat[];
    mostLikedMovies: MovieStat[];
    mostVisitedMovies: MovieStat[];
    movieCount: number;
    mostWatchedGenres: GenreStat[];
    mostLikedGenres: GenreStat[];
    mostVisitedGenres: GenreStat[];
    usersByLikedListSize: UserStat[];
    usersByWatchedListSize: UserStat[];
    userCount: number;
}
