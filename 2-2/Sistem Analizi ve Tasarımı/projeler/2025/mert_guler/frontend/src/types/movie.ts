import { Genre } from './genre';
import { User } from './user';

export interface Movie {
    movieId: number;
    originalLanguage: string;
    originalTitle: string;
    title: string;
    overview: string;
    tagline: string;
    releaseDate: string;
    trailerLink: string;
    runtime: number;
    backdrop: string;
    poster: string;
    logo: string | null;
    genres: Genre[];
    watchCount: number;
    likeCount: number;
    ratingCount: number;
    imdbId: string;
    wikidataId: string;
    facebookId: string | null;
    instagramId: string | null;
    twitterId: string | null;
    clickCount: number | null;
}

export interface Comment {
    commentId: number;   // ID of the comment
    movieId: number;     // ID of the movie the comment is related to
    user: User;
    sentAt: number;      // Timestamp when the comment was sent (in milliseconds)
    message: string;     // The actual comment message
    isSpoiler: boolean;  // Flag to indicate if the comment contains spoilers
    isUpdated: boolean;  // Flag to indicate if the comment was updated
}


