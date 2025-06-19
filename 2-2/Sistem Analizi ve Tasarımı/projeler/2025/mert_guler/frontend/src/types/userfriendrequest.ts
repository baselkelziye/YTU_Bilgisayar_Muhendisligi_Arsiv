import { User } from "./user";

export interface UserFriendRequest {
    id: number;
    userRequestSent: User,
    userRequestReceived: User,
    timestamp: number
};