import { PaginatedResponse } from "@/types/friends";
import { BASE_URL } from "../apiClient";
import { UserMessage } from "@/types/user/usermessage";
import APIResponse from "../userapi";

const API_URL = BASE_URL + "api/v1/user/message";

// report
export async function reportMessage(
    messageId: number,
): Promise<void> {
    const url = `${API_URL}/${messageId}/report`;
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to report message");
    }
}

// send
export async function sendMessageToUser(
    message: string,
    uuid: string,
): Promise<UserMessage> {
    const url = `${API_URL}/`;
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify({
            to: uuid,
            message: message,
        }),
    });
    if (!response.ok) {
        throw new Error("Failed to send message");
    }
    const data = await response.json();
    return data;
}

// get messages sent
export async function getMessagesSent(
    pageNumber: number = 0,
    pageSize: number = 30,
): Promise<PaginatedResponse<UserMessage>> {
    const url = new URL(`${API_URL}/sent`);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get sent messages");
    }
    const data = await response.json();
    return data;
}

// get messages sent to
export async function getMessagesSentToUser(
    uuid: string,
    pageNumber: number = 0,
    pageSize: number = 30,
): Promise<PaginatedResponse<UserMessage>> {
    const url = new URL(`${API_URL}/sent/${uuid}`);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get sent messages");
    }
    const data = await response.json();
    return data;
}

// get messages received
export async function getMessagesReceived(
    pageNumber: number = 0,
    pageSize: number = 30,
): Promise<PaginatedResponse<UserMessage>> {
    const url = new URL(`${API_URL}/received`);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get received messages");
    }
    const data = await response.json();
    return data;
}

// get messages received from
export async function getMessagesReceivedFromUser(
    uuid: string,
    pageNumber: number = 0,
    pageSize: number = 30,
): Promise<PaginatedResponse<UserMessage>> {
    const url = new URL(`${API_URL}/received/${uuid}`);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get received messages");
    }
    const data = await response.json();
    return data;
}

export async function getMessagesWithUser(
    uuid: string,
    pageNumber: number = 0,
    pageSize: number = 30,
): Promise<PaginatedResponse<UserMessage>> {
    const url = new URL(`${API_URL}/with/${uuid}`);
    url.searchParams.append("pageNumber", pageNumber.toString());
    url.searchParams.append("pageSize", pageSize.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get received messages");
    }
    const data = await response.json();
    return data;
}

export async function markMessagesAsRead(
    uuid: string,
    time: number
): Promise<APIResponse> {
    const url = new URL(`${API_URL}/read}`);
    url.searchParams.append("userUuid", uuid.toString());
    url.searchParams.append("time", time.toString());
    const response = await fetch(url, {
        method: "POST",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get received messages");
    }
    const data = await response.json();
    return data;
    
}