// src/appapi.ts
import { Movie } from '@/types/movie';
import { FrontMovie, PagedResponse } from '@/types/front';
import { CrewMember, CastMember } from '@/types/crew';
import { Comment } from '@/types/movie';
import { apiFetch as fetch } from './apiClient';
import {PaginatedResponse} from "@/types/friends";

// proxy kullanımı için başına “/” koyuyoruz
import {BASE_URL} from "./apiClient";

export async function fetchMovieById(
    movieId: number,
): Promise<Movie> {
    const res = await fetch(
        `${BASE_URL}api/v1/movies/${movieId}`
    );
    if (!res.ok) throw new Error('Failed to fetch movie');
    return res.json();
}


export async function fetchFrontMovies(
    options: {
        pageNumber?: number;
        pageSize?: number;
        sortBy?: 'popularity' | "releaseDate"| "clickCount"| "likeCount"| "watchCount"| "ratingCount";
        sortOrder?: 'dsc' | 'asc';
        genre?: string;
    } = {}
): Promise<PagedResponse<FrontMovie>> {
    const {
        pageNumber = 0,
        pageSize = 20,
        sortBy = 'popularity',
        sortOrder = 'dsc',
        genre,
    } = options;

    const params = new URLSearchParams({
        pageNumber: pageNumber.toString(),
        pageSize: pageSize.toString(),
        sortBy,
        sortOrder,
    });
    if (genre) params.append('genre', genre);

    const res = await fetch(`${BASE_URL}api/v1/movies/front?${params}`);
    if (!res.ok) throw new Error('Failed to fetch front movies');
    return res.json();
}

export async function searchFrontMovies(
    options: {
        pageNumber?: number;
        pageSize?: number;
        sortBy?: 'popularity';
        sortOrder?: 'dsc' | 'asc';
        genre?: string;
        word: string;
    }
): Promise<PagedResponse<FrontMovie>> {
    const {
        pageNumber = 0,
        pageSize = 20,
        sortBy = 'popularity',
        sortOrder = 'dsc',
        genre,
        word,
    } = options;

    if (!word.trim()) throw new Error('search word is required');

    const params = new URLSearchParams({
        pageNumber: pageNumber.toString(),
        pageSize: pageSize.toString(),
        sortBy,
        sortOrder,
        word,
    });
    if (genre) {
        params.append('genre', genre);
    }

    const url = `${BASE_URL}api/v1/movies/front?${params.toString()}`;
    const res = await fetch(url);
    if (!res.ok) throw new Error(`Failed to search front movies (${res.status})`);
    return res.json();
}



export async function fetchMovieCrews(
    movieId: number,
    options: {
        pageNumber?: number;
        pageSize?: number;
        sortBy?: string;
        sortOrder?: string;
    } = {}
): Promise<PagedResponse<CrewMember>> {
    const {
        pageNumber = 0,
        pageSize = 30,
        sortBy = 'popularity',
        sortOrder = 'dsc',
    } = options;
    const params = new URLSearchParams({
        pageNumber: pageNumber.toString(),
        pageSize: pageSize.toString(),
        sortBy,
        sortOrder,
    });
    const res = await fetch(
        `${BASE_URL}api/v1/movies/${movieId}/crews?${params.toString()}`
    );
    if (!res.ok) throw new Error('Failed to fetch movie crews');
    return res.json();
}

export async function fetchMovieCasts(
    movieId: number,
    options: {
        pageNumber?: number;
        pageSize?: number;
        sortBy?: string;
        sortOrder?: string;
    } = {}
): Promise<PagedResponse<CastMember>> {
    const {
        pageNumber = 0,
        pageSize = 30,
        sortBy = 'popularity',
        sortOrder = 'dsc',
    } = options;
    const params = new URLSearchParams({
        pageNumber: pageNumber.toString(),
        pageSize: pageSize.toString(),
        sortBy,
        sortOrder,
    });
    const res = await fetch(
        `${BASE_URL}api/v1/movies/${movieId}/casts?${params.toString()}`
    );
    if (!res.ok) throw new Error('Failed to fetch movie casts');
    return res.json();
}

export async function fetchMovieComments(
    movieId: number,
    pageNumber: number = 0,
    pageSize: number = 30
): Promise<{ content: Comment[], totalPages: number, totalElements: number }> {
    const params = new URLSearchParams({
        pageNumber: pageNumber.toString(),
        pageSize: pageSize.toString(),
    });

    const res = await fetch(`${BASE_URL}api/v1/movies/${movieId}/comment?${params.toString()}`);
    if (!res.ok) throw new Error('Failed to fetch movie comments');

    const data = await res.json();

    // Returning relevant data from the response
    return {
        content: data.content || [],  // Ensure content is an array, default to empty array
        totalPages: data.totalPages || 0,  // Handle totalPages if not in the response
        totalElements: data.totalElements || 0  // Handle totalElements if not in the response
    };
}


// Submit a new comment for a movie
export async function submitMovieComment(
    movieId: number,
    userUUID: string,
    message: string,
    isSpoiler: boolean
): Promise<Comment> {
    // Construct the query parameters as per the API documentation
    const params = new URLSearchParams({
        message: message,  // Message in the query string
        isSpoiler: isSpoiler.toString(),  // Convert isSpoiler to a string (query parameter)
    });

    const response = await fetch(`${BASE_URL}api/v1/movies/${movieId}/comment?${params.toString()}`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        credentials: 'include', // Ensure that cookies are sent if needed
        body: JSON.stringify({
            userUUID, // Only userUUID is sent in the body
            sentAtTimestampSeconds: Math.floor(Date.now() / 1000), // Current timestamp
        }),
    });

    if (!response.ok) {
        const errorResponse = await response.text();
        console.error('Failed to submit comment:', errorResponse);
        throw new Error(`Failed to submit comment: ${errorResponse}`);
    }

    return response.json();
}

/**
 * Update an existing comment
 */
export async function updateMovieComment(
    commentId: number,
    message: string,
    isSpoiler: boolean
): Promise<Comment> {
    const params = new URLSearchParams({
        message,
        isSpoiler: isSpoiler.toString(),
    });
    const res = await fetch(
        `${BASE_URL}api/v1/movies/comment/${commentId}?${params.toString()}`,
        {
            method: 'PUT',
            credentials: 'include',
            headers: { 'Content-Type': 'application/json' },
        }
    );
    if (!res.ok) throw new Error('Failed to update comment');
    return res.json();
}

/**
 * Delete a comment
 */
export async function deleteMovieComment(
    commentId: number
): Promise<{ message: string; success: boolean }> {
    const res = await fetch(
        `${BASE_URL}api/v1/movies/comment/${commentId}`,
        {
            method: 'DELETE',
            credentials: 'include',
        }
    );
    if (!res.ok) throw new Error('Failed to delete comment');
    return res.json();
}

/**
 * Report a comment
 */
export async function reportMovieComment(
    commentId: number
): Promise<{ message: string; success: boolean }> {
    const res = await fetch(
        `${BASE_URL}api/v1/movies/comment/${commentId}/report`,
        {
            method: 'POST',
            credentials: 'include',
        }
    );
    if (!res.ok) throw new Error('Failed to report comment');
    return res.json();
}
export async function likeMovie(
    movieId: number,
    liked: boolean
): Promise<{ message: string; success: boolean }> {

    const params = new URLSearchParams({
        liked: liked.toString(),
    });

    const res = await fetch(
        `${BASE_URL}api/v1/user/movie/${movieId}/like?${params.toString()}`,
        {
            method: 'PUT',
            credentials: 'include',
            headers: { 'Content-Type': 'application/json' },
        }
    );

    if (!res.ok) {
        const errorText = await res.text();
        console.error('Failed to like/unlike movie:', res.status, errorText);
        throw new Error(`Failed to like/unlike movie: ${res.status} ${errorText}`);
    }

    // Başarılı yanıtı JSON olarak işle
    return res.json();
}


export async function fetchWatchedMoviesByUser(
    uuid: string,
    options: {
        pageNumber?: number;
        pageSize?: number;
    } = {}
): Promise<PaginatedResponse<Movie>> {
    const {
        pageNumber = 0,
        pageSize = 30,
    } = options;

    if (!uuid) {
        throw new Error('User UUID is required to fetch watched movies.');
    }

    const params = new URLSearchParams({
        pageNumber: pageNumber.toString(),
        pageSize: pageSize.toString(),
    });

    const res = await fetch(
        `${BASE_URL}api/v1/user/uuid/${uuid}/watched?${params.toString()}`,
        {
            credentials: 'include',
        }
    );

    if (!res.ok) {
        const errorText = await res.text();
        console.error('Failed to fetch watched movies:', res.status, errorText);
        throw new Error(`Failed to fetch watched movies: ${res.status} ${errorText}`);
    }
    return res.json() as Promise<PaginatedResponse<Movie>>;
}

export async function fetchWatchlistMoviesByUser(
    uuid: string,
    options: {
        pageNumber?: number;
        pageSize?: number;
    } = {}
): Promise<PaginatedResponse<Movie>> {
    const {
        pageNumber = 0,
        pageSize = 30,
    } = options;


    if (!uuid) {
        throw new Error('User UUID is required to fetch watchlist movies.');
    }

    const params = new URLSearchParams({
        pageNumber: pageNumber.toString(),
        pageSize: pageSize.toString(),
    });

    const res = await fetch(
        `${BASE_URL}api/v1/user/uuid/${uuid}/watchlist?${params.toString()}`,
        {
            credentials: 'include',
        }
    );

    if (!res.ok) {
        const errorText = await res.text();
        console.error('Failed to fetch watchlist movies:', res.status, errorText);
        throw new Error(`Failed to fetch watchlist movies: ${res.status} ${errorText}`);
    }

    return res.json() as Promise<PaginatedResponse<Movie>>;
}
export async function addMovieToWatchlist(
    movieId: number
): Promise<{ message: string; success: boolean }> {

    const res = await fetch(
        `${BASE_URL}api/v1/user/movie/${movieId}/watchlist`,
        {
            method: 'POST',
            credentials: 'include',
            headers: {

                'Content-Type': 'application/json',
            },
        }
    );

    if (!res.ok) {
        const errorText = await res.text();
        console.error('Failed to add movie to watchlist:', res.status, errorText);
        throw new Error(`Failed to add movie to watchlist: ${res.status} ${errorText || 'Unknown error'}`);
    }

    return res.json();
}
export async function markMovieAsWatched(
    movieId: number
): Promise<{ message: string; success: boolean }> {

    const res = await fetch(
        `${BASE_URL}api/v1/user/movie/${movieId}/watched`,
        {
            method: 'POST',
            credentials: 'include',
            headers: {
                'Content-Type': 'application/json',
            },
        }
    );

    if (!res.ok) {
        const errorText = await res.text();
        console.error('Failed to mark movie as watched:', res.status, errorText);
        throw new Error(`Failed to mark movie as watched: ${res.status} ${errorText || 'Unknown error'}`);
    }
    return res.json();
}

export async function removeMovieFromWatchlist(
    movieId: number
): Promise<{ message: string; success: boolean }> {


    const res = await fetch(
        `${BASE_URL}api/v1/user/movie/${movieId}/watchlist`,
        {
            method: 'DELETE',
            credentials: 'include',
            headers: {
                'Content-Type': 'application/json',
            },
        }
    );

    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(`Failed to remove movie from watchlist: ${res.status} ${errorText || 'Unknown error'}`);
    }
    return res.json();
}
export async function removeMovieFromWatched(
    movieId: number
): Promise<{ message: string; success: boolean }> {

    const res = await fetch(
        `${BASE_URL}api/v1/user/movie/${movieId}/watched`,
        {
            method: 'DELETE',
            credentials: 'include',
            headers: {
                'Content-Type': 'application/json',
            },
        }
    );

    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(`Failed to remove movie from watched list: ${res.status} ${errorText || 'Unknown error'}`);
    }

    return res.json();
}

