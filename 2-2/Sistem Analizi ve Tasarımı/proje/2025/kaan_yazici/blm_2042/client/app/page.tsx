"use client"

import { PostCard } from "@/app/ui/post-card";
import { postCard } from "@/app/lib/definitions";
import { useState, useEffect } from 'react';

export default function Home() {
  const [posts, setPosts] = useState<postCard[]>([]);
  const [offset, setOffset] = useState(0);
  const size = 10;
  const [hasMore, setHasMore] = useState(true);
  const [loading, setLoading] = useState(false);

  const fetchPosts = async () => {
    if (loading || !hasMore) return;
    setLoading(true);
    try {
      const res = await fetch(`/api/user/post-feed?offset=${offset}&size=${size}`, {
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
  }, []);

  useEffect(() => {
    const handleScroll = () => {
      const nearBottom =
        window.innerHeight + window.scrollY >= document.body.offsetHeight - 300;

      if (nearBottom) {
        fetchPosts();
      }
    };

    window.addEventListener("scroll", handleScroll);
    return () => window.removeEventListener("scroll", handleScroll);
  }, [loading, hasMore]);

  return (
    <main className="min-h-screen bg-gray-50 px-6 py-10 flex flex-col items-center gap-10">
      <section className="w-full">
        <div className="w-full flex flex-col items-center gap-y-[64px] text-black">
          {posts.map((post: postCard, index: number) => (
            <div key={index} className="w-full max-w-xl">
              <PostCard Post={post} />
            </div>
          ))}

          {loading && (
            <div className="mt-4 text-gray-600">Loading more posts...</div>
          )}

          {!hasMore && (
            <div className="mt-4 text-gray-500">You’ve reached the end.</div>
          )}
        </div>
      </section>
    </main>
  );
}