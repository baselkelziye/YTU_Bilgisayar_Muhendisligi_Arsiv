'use client';

import { useState, useEffect } from 'react';
import { postCard } from '@/app/lib/definitions';
import { PostCard } from '@/app/ui/post-card';
import {deslugify, slugify} from '@/app/lib/actions';
import Link from 'next/link';

export default function CommunityPage({ id }: { id: string }) {
  const [communityDescription, setCommunityDescription] = useState<string>('');
  const [communityImage, setCommunityImage] = useState<string | null>(null);
  const [posts, setPosts] = useState<postCard[]>([]);
  const [offset, setOffset] = useState(0);
  const size = 10;
  const [hasMore, setHasMore] = useState(true);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    const fetchCommunityData = async () => {
      setLoading(true);
      setError(null);

      try {
        const res = await fetch(`/api/community/all`);
        const data = await res.json();

        const community = data.find((c: any) => slugify(c.communityName.trim()) === id);
        if (community) {
          setCommunityDescription(community.communityDescription);
          if (community.mediaId) {
            const mediaRes = await fetch(`/api/media/${community.mediaId}`);
            const blob = await mediaRes.blob();
            const url = URL.createObjectURL(blob);
            setCommunityImage(url);
          }
        }
      } catch {
        setError('Failed to load community info.');
      } finally {
        setLoading(false);
      }
    };

    fetchCommunityData();
  }, [id]);

  const fetchPosts = async () => {
    if (loading || !hasMore) return;
    setLoading(true);
    try {
      const res = await fetch(`/api/community/${id}/posts?offset=${offset}&size=${size}`);
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
    } catch {
      setError('Failed to load posts.');
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

  if (loading && !communityDescription) {
    return (
      <div className="flex items-center justify-center min-h-screen">
        <p className="text-lg text-gray-600">Loading...</p>
      </div>
    );
  }

  if (error) {
    return (
      <div className="flex items-center justify-center min-h-screen">
        <p className="text-lg text-red-600">{error}</p>
      </div>
    );
  }

  return (
    <main className="max-w-5xl mx-auto px-4 py-8 space-y-12">
      <section className="flex items-center space-x-6 bg-white shadow-md p-6 rounded-xl">
        <div className="w-24 h-24 rounded-full overflow-hidden border-4 border-blue-300">
          {communityImage ? (
            <img
              src={communityImage}
              alt="Community Avatar"
              className="w-full h-full object-cover"
            />
          ) : (
            <div className="w-full h-full bg-gray-200" />
          )}
        </div>
        <div className="flex-1">
          <h1 className="text-4xl font-bold text-blue-600 capitalize">
            {deslugify(id)}
          </h1>
          <p className="text-base text-gray-600 mt-2">{communityDescription}</p>
        </div>
        <Link
          href={`/community/${id}/add-post`}
          className="w-auto p-1 bg-blue-500 text-blue-100 hover:bg-blue-600 hover:text-white text-center text-sm font-medium py-2 rounded-lg transition"
        >
          Create New Post
        </Link>
      </section>

      <section>
        <h2 className="text-3xl font-semibold text-blue-500 mb-6">Latest Posts</h2>
        <div className="grid gap-10">
          {posts.length > 0 ? (
            posts.map((post, index) => (
              <PostCard Post={post} key={index} />
            ))
          ) : (
            <p className="text-gray-500 text-center">No posts yet.</p>
          )}
        </div>

        {loading && (
          <div className="mt-4 text-gray-600 text-center">Loading more posts...</div>
        )}

        {!hasMore && (
          <div className="mt-4 text-gray-500 text-center">You’ve reached the end.</div>
        )}
      </section>
    </main>
  );
}
