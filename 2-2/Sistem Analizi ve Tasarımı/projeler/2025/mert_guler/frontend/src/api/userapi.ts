// src/app/api_/userapi.ts
import { User } from "@/types/user";
import {PaginatedResponse} from "@/types/friends"
import { Movie } from '@/types/movie';
import { apiFetch as fetch } from './apiClient';

import {BASE_URL} from "./apiClient";
import { UserFriendRequest } from "@/types/userfriendrequest";
import { UserActivity, UserActivityResponse } from "@/types/user/useractivity";
import { parseUserActivity } from "@/lib/user/useractivity";

////
// @TODO: DO BETTER ERROR HANDLING AND TYPES 
////

export default interface APIResponse {
    message: string,
    success: boolean
}
// ─── AUTH APIs ────────────────────────────────────────────────────────────────

export async function signUp(
    email: string,
    password: string,
    firstName: string,
    lastName: string,
    username: string,
    recaptchaToken: string
): Promise<APIResponse> {
    const res = await fetch(`${BASE_URL}api/v1/auth/signup`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ email, password, firstName, lastName, username, recaptchaToken }),
        credentials: "include"
    });
    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || "Failed to sign up");
    }
    return res.json();
}

export async function signIn(
    username: string,
    password: string,
    recaptchaToken: string
): Promise<APIResponse> {
    const res = await fetch(`${BASE_URL}api/v1/auth/signin`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ username, password, recaptchaToken }),
        credentials: "include"
    });
    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || "Failed to log in");
    }
    return res.json();
}

export async function signOut(): Promise<APIResponse> {
    const res = await fetch(`${BASE_URL}api/v1/auth/signout`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        credentials: "include"
    });
    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || "Failed to log out");
    }
    return res.json();
}

// ─── USER DATA APIs ───────────────────────────────────────────────────────────

export async function fetchUserByUsername(
    username: string
): Promise<User> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/username/${encodeURIComponent(username)}`,{
            credentials: "include",
            method: "GET"
        });
    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || "Failed to fetch user");
    }
    return res.json();
}

export async function changeUsernameRequest(username: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/username`, {
            method: "PUT",
            credentials: "include",
            body: JSON.stringify({
                newUsername: username
            })
        }
    );
    if (!res.ok) throw new Error('Could not change username');
    return res.json();
}

export async function changePasswordRequest(password: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/password`, {
            method: "PUT",
            credentials: "include",
            body: JSON.stringify({
                password: password
            })
        }
    );
    if (!res.ok) throw new Error('Could not change password');
    return res.json();
}

export async function changeBiographyRequest(biography: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/biography`, {
            method: "PUT",
            credentials: "include",
            body: JSON.stringify({
                biography: biography
            })
        }
    );
    if (!res.ok) throw new Error('Could not change biography');
    return res.json();
}

export async function addFriendRequest(uuid: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/friend/add/${uuid}`, {
            method: "POST",
            credentials: "include",
        }
    );
    if (!res.ok) throw new Error('Could not add friend');
    return res.json();
}

export async function acceptFriendRequest(uuid: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/friend/add/${uuid}`, {
            method: "POST",
            credentials: "include",
        }
    );
    if (!res.ok) throw new Error('Could not accept this request');
    return res.json();
}

export async function rejectFriendRequest(uuid: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/friend/reject/${uuid}`, {
            method: "POST",
            credentials: "include",
        }
    );
    if (!res.ok) throw new Error('Could not reject this request');
    return res.json();
}

export async function cancelFriendRequest(uuid: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/friend/request/${uuid}`, {
            method: "DELETE",
            credentials: "include",
        }
    );
    if (!res.ok) throw new Error('Could not cancel this request');
    return res.json();
}

export async function removeFriendRequest(uuid: string) : Promise<APIResponse> {
    const res = await fetch(
        `${BASE_URL}api/v1/user/friend/remove/${uuid}`, {
            method: "DELETE",
            credentials: "include",
        }
    );
    if (!res.ok) throw new Error('Could not remove friend');
    return res.json();
}



export async function fetchSentFriendRequests(
    pageNumber: number = 0,
    pageSize: number = 30
): Promise<PaginatedResponse<User>> {
    const url = new URL(`${BASE_URL}api/v1/user/friend/requests/sent`);
    url.searchParams.append('pageNumber', pageNumber.toString());
    url.searchParams.append('pageSize', pageSize.toString());

    const res = await fetch(url.toString(), {
        method: "GET",
        credentials: "include"
    });

    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || `Failed to fetch sent friend requests`);
    }
    const data = await res.json() as PaginatedResponse<UserFriendRequest>;

    return {
        ...data,
        content: data.content.map(request => request.userRequestReceived)
    };
}

export async function fetchReceivedFriendRequests(
    pageNumber: number = 0,
    pageSize: number = 30
): Promise<PaginatedResponse<User>> {
    const url = new URL(`${BASE_URL}api/v1/user/friend/requests/received`);
    url.searchParams.append('pageNumber', pageNumber.toString());
    url.searchParams.append('pageSize', pageSize.toString());

    const res = await fetch(url.toString(), {
        method: "GET",
        credentials: "include"
    });

    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || `Failed to fetch received friend requests`);
    }
    const data = await res.json() as PaginatedResponse<UserFriendRequest>;

    return {
        ...data,
        content: data.content.map(request => request.userRequestSent)
    };
}

export async function fetchFriendsByUUID(
    uuid: string,
    pageNumber: number = 0,
    pageSize: number = 30
): Promise<PaginatedResponse<User>> {
    const url = new URL(`${BASE_URL}api/v1/user/uuid/${encodeURIComponent(uuid)}/friends`);
    url.searchParams.append('pageNumber', pageNumber.toString());
    url.searchParams.append('pageSize', pageSize.toString());

    const res = await fetch(url.toString(), {
        method: "GET",
        credentials: "include"
    });

    if (!res.ok) {
        const errorText = await res.text();
        // Daha spesifik hata yönetimi eklenebilir
        throw new Error(errorText || `Failed to fetch friend lists   for user ${uuid}`);
    }
    // Dönen JSON yanıtının PaginatedResponse<Movie> formatında olduğunu varsayıyoruz
    return res.json() as Promise<PaginatedResponse<User>>;
}

export async function fetchUserMe(): Promise<User>{
    const res = await fetch(`${BASE_URL}api/v1/user/me`, {
        method: "GET",
        credentials: "include"
    });
    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || "Failed to fetch user");
    }
    return res.json();
}
export async function fetchLikedMovies(
    uuid: string,
    pageNumber: number = 0,
    pageSize: number = 30
): Promise<PaginatedResponse<Movie>> { // <--- Movie arayüzünü kullanıyoruz
    // Construct the URL with query parameters
    const url = new URL(`${BASE_URL}api/v1/user/uuid/${encodeURIComponent(uuid)}/liked_movies`);
    url.searchParams.append('pageNumber', pageNumber.toString());
    url.searchParams.append('pageSize', pageSize.toString());

    const res = await fetch(url.toString(), {
        method: "GET",
        credentials: "include"
    });

    if (!res.ok) {
        const errorText = await res.text();
        // Daha spesifik hata yönetimi eklenebilir
        throw new Error(errorText || `Failed to fetch liked movies for user ${uuid}`);
    }
    // Dönen JSON yanıtının PaginatedResponse<Movie> formatında olduğunu varsayıyoruz
    return res.json() as Promise<PaginatedResponse<Movie>>;
}

export async function fetchUserActivity(
    uuid: string,
    pageNumber: number = 0,
    pageSize: number = 30
): Promise<PaginatedResponse<UserActivity>> {
    const url = new URL(`${BASE_URL}api/v1/user/uuid/${encodeURIComponent(uuid)}/activity`);
    url.searchParams.append('pageNumber', pageNumber.toString());
    url.searchParams.append('pageSize', pageSize.toString());
    const res = await fetch(url.toString(), {
        method: "GET",
        credentials: "include"
    });
    if (!res.ok) {
        const errorText = await res.text();
        throw new Error(errorText || "Failed to fetch user activity");
    }
    const data = await res.json() as PaginatedResponse<UserActivityResponse>;
    return {
        ...data,
        content: data.content.map(activity => parseUserActivity(activity))
    };
}