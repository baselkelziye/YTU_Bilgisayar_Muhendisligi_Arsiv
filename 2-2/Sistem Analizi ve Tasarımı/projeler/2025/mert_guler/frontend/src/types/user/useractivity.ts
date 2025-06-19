import { FrontMovie } from "../front";
import { Comment } from "../movie";
import { User } from "../user";

export interface UserActivityResponse {
    id: number;
    type: string;
    content: string;
    time: number;
};

export type UserActivity =
  | {
      id: number;
      type: "BECOME_FRIENDS";
      content: User;
      time: number;
    }
  | {
      id: number;
      type: "MOVIE_ADD_WATCHLIST";
      content: FrontMovie;
      time: number;
    }
  | {
      id: number;
      type: "MOVIE_ADD_WATCHED";
      content: FrontMovie;
      time: number;
    }
  | {
      id: number;
      type: "MOVIE_LIKED";
      content: FrontMovie;
      time: number;
    }
  | {
      id: number;
      type: "MOVIE_COMMENT";
      content: Comment;
      time: number;
    };