import { apiFetch, BASE_URL } from './apiClient';
import { AdminStats, MovieStat, GenreStat, UserStat } from '@/types/stats';
import {Movie} from "@/types/movie";
import { User } from '@/types/user';

function clampNonNegative(n: number): number {
    return n < 0 ? 0 : n;
}

export async function fetchAdminStatsAll(): Promise<AdminStats> {
    const res = await apiFetch(`${BASE_URL}api/v1/admin/stats/all`, {
        method: 'GET',
        credentials: 'include'
    });
    if (!res.ok) throw new Error('İstatistikler alınamadı');
    const data: AdminStats = await res.json();

    // ——— Negative değerleri 0’a çek, poster’ı nullable yap ———
    data.mostWatchedMovies = data.mostWatchedMovies.map((m: MovieStat) => ({
        ...m,
        watchCount: clampNonNegative(m.watchCount),
        likeCount:  clampNonNegative(m.likeCount),
        clickCount: clampNonNegative(m.clickCount),
        poster:     m.poster ?? null
    }));
    data.mostLikedMovies = data.mostLikedMovies.map((m: MovieStat) => ({
        ...m,
        watchCount: clampNonNegative(m.watchCount),
        likeCount:  clampNonNegative(m.likeCount),
        clickCount: clampNonNegative(m.clickCount),
        poster:     m.poster ?? null
    }));
    data.mostVisitedMovies = data.mostVisitedMovies.map((m: MovieStat) => ({
        ...m,
        watchCount: clampNonNegative(m.watchCount),
        likeCount:  clampNonNegative(m.likeCount),
        clickCount: clampNonNegative(m.clickCount),
        poster:     m.poster ?? null
    }));

    data.mostWatchedGenres = data.mostWatchedGenres.map((g: GenreStat) => ({
        ...g,
        watchCount: clampNonNegative(g.watchCount),
        likeCount:  clampNonNegative(g.likeCount),
        clickCount: clampNonNegative(g.clickCount)
    }));
    data.mostLikedGenres = data.mostLikedGenres.map((g: GenreStat) => ({
        ...g,
        watchCount: clampNonNegative(g.watchCount),
        likeCount:  clampNonNegative(g.likeCount),
        clickCount: clampNonNegative(g.clickCount)
    }));
    data.mostVisitedGenres = data.mostVisitedGenres.map((g: GenreStat) => ({
        ...g,
        watchCount: clampNonNegative(g.watchCount),
        likeCount:  clampNonNegative(g.likeCount),
        clickCount: clampNonNegative(g.clickCount)
    }));

    data.usersByWatchedListSize = data.usersByWatchedListSize.map((u: UserStat) => ({
        ...u,
        watchedCount: clampNonNegative(u.watchedCount),
        likedCount:   clampNonNegative(u.likedCount)
    }));
    data.usersByLikedListSize = data.usersByLikedListSize.map((u: UserStat) => ({
        ...u,
        watchedCount: clampNonNegative(u.watchedCount),
        likedCount:   clampNonNegative(u.likedCount)
    }));

    data.movieCount = clampNonNegative(data.movieCount);
    data.userCount  = clampNonNegative(data.userCount);

    return data;
}

// 1) Admin DB’ye PUT ile güncelleme
export async function updateAdminMovieById(id: number, data: Movie): Promise<Movie> {
    const res = await apiFetch(`${BASE_URL}api/v1/admin/movies/${id}`, {
        method: "PUT",
        credentials: 'include',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(data)
    });
    if (!res.ok) throw new Error('Film güncelleme başarısız');
    return res.json();
}

// 2) Dış kaynaktan (TMDB vb.) çekip DB’yi yenileyen endpoint
export async function fetchExternalAdminMovieById(id: number): Promise<Movie> {
    const res = await apiFetch(`${BASE_URL}api/v1/admin/movies/${id}/fetch`, {
        method: "PUT",
        credentials: 'include'
    });
    if (!res.ok) throw new Error('Dış kaynaktan çekme başarısız');
    return res.json();
}

export async function adminUpdateUserByUuid(uuid: string, updatedUser: User) {
    const response = await fetch(`${BASE_URL}api/v1/admin/user/uuid/${uuid}`, {
        method: 'PUT',
        credentials: 'include',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(updatedUser),
    });

    if (!response.ok) {
        throw new Error('Failed to update user');
    }

    return await response.json();
}

export async function adminDeleteUserByUuid(uuid: string) {
    const response = await fetch(`${BASE_URL}api/v1/admin/user/uuid/${uuid}`, {
        method: 'DELETE',
        credentials: 'include',
    });

    if (!response.ok) {
        throw new Error('Failed to update user');
    }

    return await response.json();
}