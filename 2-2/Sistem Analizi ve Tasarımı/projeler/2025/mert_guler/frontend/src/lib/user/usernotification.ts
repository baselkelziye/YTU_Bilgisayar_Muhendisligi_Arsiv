import { UserNotification, UserNotificationBecomeFriends, UserNotificationFriendRequest, UserNotificationNewMessage, UserNotificationResponse } from "@/types/user/usernotification";

export function parseUserNotification(raw: UserNotificationResponse): UserNotification {
    switch (raw.type) {
      case "NEW_MESSAGE":
        return {
          ...raw,
          type: "NEW_MESSAGE",
          content: JSON.parse(raw.content),
        };
      case "FRIEND_REQUEST":
        return {
          ...raw,
          type: "FRIEND_REQUEST",
          content: JSON.parse(raw.content),
        };
      case "BECOME_FRIENDS":
        return {
          ...raw,
          type: "BECOME_FRIENDS",
          content: JSON.parse(raw.content),
        };
      default:
        throw new Error(`Unknown notification type: ${raw.type}`);
    }
  }