import { User } from "../user";

// TODO : FIX

export interface UserNotificationResponse {
    id: number;
    type: string;
    content: string;
    notified: boolean;
    time: number;
};

export interface UserNotificationNewMessage {
    user: User;
    message: string;
}

export interface UserNotificationFriendRequest {
    user: User;
}

export interface UserNotificationBecomeFriends {
    user: User;
}

export type UserNotification =
  | {
      id: number;
      type: "NEW_MESSAGE";
      content: UserNotificationNewMessage;
      notified: boolean;
      time: number;
    }
  | {
      id: number;
      type: "FRIEND_REQUEST";
      content: UserNotificationFriendRequest;
      notified: boolean;
      time: number;
    }
  | {
      id: number;
      type: "BECOME_FRIENDS";
      content: UserNotificationBecomeFriends;
      notified: boolean;
      time: number;
    };
