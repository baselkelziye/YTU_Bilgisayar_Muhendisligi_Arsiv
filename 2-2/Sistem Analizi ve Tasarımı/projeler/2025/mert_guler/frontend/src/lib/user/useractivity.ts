import { UserActivity, UserActivityResponse } from "@/types/user/useractivity";

export function parseUserActivity(raw: UserActivityResponse): UserActivity {
    switch (raw.type) {
      case "BECOME_FRIENDS":
        return {
          ...raw,
          type: "BECOME_FRIENDS",
          content: JSON.parse(raw.content),
        };
      case "MOVIE_ADD_WATCHLIST":
        return {
          ...raw,
          type: "MOVIE_ADD_WATCHLIST",
          content: JSON.parse(raw.content),
        };
      case "MOVIE_ADD_WATCHED":
        return {
          ...raw,
          type: "MOVIE_ADD_WATCHED",
          content: JSON.parse(raw.content),
        };
      case "MOVIE_LIKED":
        return {
          ...raw,
          type: "MOVIE_LIKED",
          content: JSON.parse(raw.content),
        };
      case "MOVIE_COMMENT":
        return {
          ...raw,
          type: "MOVIE_COMMENT",
          content: JSON.parse(raw.content)
        };
    default:
        throw new Error(`Unknown user activity type: ${raw.type}`);
    }
  }