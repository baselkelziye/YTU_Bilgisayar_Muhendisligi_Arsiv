import { User } from "../user";

export interface UserMessage {
    id: number;
    from: User;
    recipient: User;
    sentAt: number;
    message: string;
    isRead: boolean;
} 