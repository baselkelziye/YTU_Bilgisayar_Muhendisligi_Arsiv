'use client';

import { useEffect, useState } from 'react';
import ProfileHeader from "@/app/ui/profileHeader";
import { PostCard } from '@/app/ui/post-card';
import { postCard, User } from '@/app/lib/definitions';

export default function UserPage({ username }: { username: string }) {
  const [user, setUser] = useState<User | null>(null);
  const [id, setId] = useState<number | null>(null);
  const [posts, setPosts] = useState<postCard[]>([]);
  const [offset, setOffset] = useState(0);
  const size = 10;
  const [hasMore, setHasMore] = useState(true);
  const [loading, setLoading] = useState(false);

  useEffect(() => {
    let sessionUsername: string | null = null;

    fetch(`/api/user/profile`, {
      method: 'POST',
      credentials: 'include',
    }).then(async res => {
      const data = await res.json();
      if (res.ok) {
        sessionUsername = data.username;
        return sessionUsername;
      }
    }).then(() => {
      return fetch(`/api/user/${username}/profile`, {
        method: "GET",
        credentials: 'include',
      });
    }).then(async res => {
      const data = await res.json();

      const userId = data.UserProfileDto.userId;
      setId(userId);
      const userData: User = {
        displayName: data.UserProfileDto.visibleName,
        username: data.UserProfileDto.username,
        postNumber: data.UserProfileDto.postNumber,
        followers: data.UserProfileDto.followerNumber,
        following: data.UserProfileDto.followingNumber,
        isCurrentUser: sessionUsername === data.UserProfileDto.username,
        profilePicId: data.UserProfileDto.profilePhotoId,
        bannerId: data.UserProfileDto.bannerPhotoId,
        isFollowed: data.isFollowing,
        isBlocked: data.isBlocked,
        bio: data.UserProfileDto.bio,
      };
      setUser(userData);
    });
  }, [username]);

  const fetchPosts = async () => {
    if (loading || !hasMore || id === null) return;
    setLoading(true);
    try {
      const res = await fetch(`/api/post/${id}/posts?offset=${offset}&size=${size}`, {
        method: 'GET',
        credentials: 'include',
      });
      const data = await res.json();

      if (res.ok) {
        const newPosts: postCard[] = data.content.map((post: any) => ({
          postId: post.postId,
          owner_username: post.userSummary.username,
          owner_name: post.userSummary.visibleName,
          owner_image_url: post.userSummary.profilePhotoId,
          content_image_url: post.mediaId,
          message: post.content,
          likes: post.numberOfPostLike,
          comments: post.numberOfPostComment,
          isLiked: post.isPostLiked,
          isFollowed: post.isPostAuthorFollowed,
          date: post.createdAt,
        }));

        setPosts(prev => {
          const existingIds = new Set(prev.map(p => p.postId));
          const filtered = newPosts.filter(p => !existingIds.has(p.postId));
          return [...prev, ...filtered];
        });
        setOffset(prev => prev + size);
        setHasMore(!data.last);
      }
    } catch (err) {
      console.error("Failed to fetch posts", err);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    fetchPosts();
  }, [id]);

  useEffect(() => {
    const handleScroll = () => {
      const nearBottom = window.innerHeight + window.scrollY >= document.body.offsetHeight - 300;
      if (nearBottom) {
        fetchPosts();
      }
    };

    window.addEventListener("scroll", handleScroll);
    return () => window.removeEventListener("scroll", handleScroll);
  }, [loading, hasMore]);

  return (
    <div className="bg-gray-100 min-w-screen min-h-screen p-4">
      <div className="mx-auto">
        {user && <ProfileHeader user={user} />}
        <div className="flex items-center flex-col gap-y-[64px] justify-center text-black mt-4">
          {posts.map((post: postCard, index: number) => (
            <PostCard Post={post} key={index} />
          ))}
          {loading && <div className="mt-4 text-gray-600">Loading more posts...</div>}
          {!hasMore && <div className="mt-4 text-gray-500">You’ve reached the end.</div>}
        </div>
      </div>
    </div>
  );
}
