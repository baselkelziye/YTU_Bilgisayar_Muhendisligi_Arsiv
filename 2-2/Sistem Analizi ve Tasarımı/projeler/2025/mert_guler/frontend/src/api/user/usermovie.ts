import { BASE_URL } from "../apiClient";
import APIResponse from "../userapi";

const API_URL = BASE_URL + "api/v1/user/movie";

// like
export async function addMovieToLiked(
    movieId: number
): Promise<APIResponse> {
    const url = `${API_URL}/${movieId}/like`;
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to like movie");
    }
    const data = await response.json();
    return data;
}

export async function removeMovieFromLiked(
    movieId: number
): Promise<APIResponse> {
    const url = `${API_URL}/${movieId}/like`;
    const response = await fetch(url, {
        method: "DELETE",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to dislike movie");
    }
    const data = await response.json();
    return data;
}

// watchlist
export async function addMovieToWatchlist(
    movieId: number
): Promise<APIResponse> {
    const url = `${API_URL}/${movieId}/watchlist`;
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to add movie to watchlist");
    }
    const data = await response.json();
    return data;
}

export async function removeMovieFromWatchlist(
    movieId: number
): Promise<APIResponse> {
    const url = `${API_URL}/${movieId}/watchlist`;
    const response = await fetch(url, {
        method: "DELETE",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to remove movie from watchlist");
    }
    const data = await response.json();
    return data;
}

// watched
export async function addMovieToWatched(
    movieId: number
): Promise<APIResponse> {
    const url = `${API_URL}/${movieId}/watched`;
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to add movie to watched");
    }
    const data = await response.json();
    return data;
}

export async function removeMovieFromWatched(
    movieId: number
): Promise<APIResponse> {
    const url = `${API_URL}/${movieId}/watched`;
    const response = await fetch(url, {
        method: "DELETE",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to remove movie from watched");
    }
    const data = await response.json();
    return data;
}