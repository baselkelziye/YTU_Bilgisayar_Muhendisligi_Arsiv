import { PaginatedResponse } from "@/types/friends";
import { BASE_URL } from "../apiClient";
import APIResponse from "../userapi";
import { UserFriendRequest } from "@/types/userfriendrequest";

const API_URL = BASE_URL + "api/v1/user/friend";

// reject friend request
export async function rejectFriendRequest(
    uuid: string,
): Promise<APIResponse> {
    const url = `${API_URL}/reject/${uuid}`;
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to reject friend request");
    }
    const data = await response.json();
    return data;
}

// add friend request
export async function addFriend(
    uuid: string,
): Promise<APIResponse> {
    const url = `${API_URL}/add/${uuid}`;
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to add friend");
    }
    const data = await response.json();
    return data;
}

// get sent friend requests
export async function getSentFriendRequests(
    pageNumber: number = 0,
    pageSize: number = 30,
): Promise<PaginatedResponse<UserFriendRequest>> {
    const url = new URL(`${API_URL}/requests/sent`);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get sent friend requests");
    }
    const data = await response.json();
    return data;
}

// get received friend requests
export async function getReceivedFriendRequests(
    pageNumber: number = 0,
    pageSize: number = 30,
): Promise<PaginatedResponse<UserFriendRequest>> {
    const url = new URL(`${API_URL}/requests/received`);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get received friend requests");
    }
    const data = await response.json();
    return data;
}

// reject friend request
export async function acceptFriendRequest(
    uuid: string,
): Promise<APIResponse> {
    const url = `${API_URL}/request/${uuid}`;
    const response = await fetch(url, {
        method: "DELETE",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to accept friend request");
    }
    const data = await response.json();
    return data;
}

// remove friends
export async function removeFriend(
    uuid: string,
): Promise<APIResponse> {
    const url = `${API_URL}/remove/${uuid}`;
    const response = await fetch(url, {
        method: "DELETE",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to remove friend");
    }
    const data = await response.json();
    return data;
}