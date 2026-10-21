'use client';

import { useState, useEffect } from 'react';

import { notFound } from 'next/navigation';
import { postCard } from '@/app/lib/definitions';
import { PostCard } from '@/app/ui/post-card';

export default function PostPage({ id }: { id: string }) {
  const [post, setPost] = useState<postCard | null>(null);

  useEffect(() => {
    fetch(`/api/post/${id}`, {
      method: 'GET',
      credentials: 'include',
    }).then(async res => {
      const data = await res.json();

      if (res.ok) {
        const postData = {
          postId: parseInt(id),
          owner_username: data.userSummary.username,
          owner_name: data.userSummary.visibleName,
          owner_image_url: data.userSummary.profilePhotoId,
          content_image_url: data.mediaId,
          message: data.content,
          date: data.createdAt,
          likes: data.numberOfPostLike,
          comments: data.numberOfPostComment,
          isLiked: data.isPostLiked,
          isFollowed: data.isPostFollowed,
        } as postCard;

        // Set the post data with image IDs (no need to fetch images here)
        setPost(postData);
      } else if (res.status === 404) {
        return notFound();
      }
    });
  }, [id]);

  return (
    <main className="max-w-3xl mx-auto py-10 px-4">
      {post && (<PostCard Post={post}/>)}
    </main>
  )
}