import { PaginatedResponse } from "@/types/friends";
import { BASE_URL } from "../apiClient";
import APIResponse from "../userapi";
import { UserNotification, UserNotificationResponse } from "@/types/user/usernotification";
import { parseUserNotification } from "@/lib/user/usernotification";

const API_URL = BASE_URL + "api/v1/user/notifications";

export async function getUserNotifications( 
    pageNumber: number = 0,
    pageSize: number = 30
): Promise<PaginatedResponse<UserNotification>> {
    const url = new URL(API_URL);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to fetch user notifications");
    }
    const rawPaginated = await response.json();
    const parsedContent: UserNotification[] = rawPaginated.content.map(parseUserNotification);
    return {
      ...rawPaginated,
      content: parsedContent,
    };
  }

export async function markNotificationAsReadBeforeTimestamp(
    timestamp: number
): Promise<APIResponse> {
    const url = new URL(`${API_URL}/notified`);
    url.searchParams.append("timestamp", timestamp.toString());
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to mark notification as read");
    }
    const data = await response.json();
    return data;
}