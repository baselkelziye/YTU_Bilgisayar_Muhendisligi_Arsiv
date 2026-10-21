// Backend icin daha rahat olacaksa tipler ayarlanabilir

export type postCard = {
  postId: number;
  owner_username: string;
  owner_name: string;
  owner_image_url: string;
  content_image_url?: string;
  message?: string;
  date: Date;
  likes: number;
  comments: number;
  isLiked: boolean;
  isFollowed: boolean;
};

export type Comment = {
  authorUsername: string,
  authorProfilePic: string,
  content: string,
  date: Date,
};

export type Community = {
  id: number,
  name: string,
  description: string,
  imageId: string,
  isJoined: boolean,
}

export type User = {
  displayName: string;
  username: string;
  postNumber: number;
  following: number;
  followers: number;
  profilePicId: string;
  bannerId: string;
  isCurrentUser?: boolean;
  isFollowed: boolean;
  isBlocked: boolean;
  bio?: string;
};

export const tags: string[] = ['Technology', 'Sports', 'Gaming', 'Music', 'Art', 'Photography', 'Animals', 'Learning'];