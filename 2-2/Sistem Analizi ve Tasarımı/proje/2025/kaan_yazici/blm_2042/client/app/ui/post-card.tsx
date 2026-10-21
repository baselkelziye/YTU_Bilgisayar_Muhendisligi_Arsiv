'use client';

import { postCard, Comment } from '@/app/lib/definitions';
import {
  Dialog,
  DialogContent,
  DialogTrigger,
  DialogTitle,
} from "@/components/ui/dialog";
import nullUser from '@/public/user-circle-svgrepo-com.svg'
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
} from "@/components/ui/card";
import { CalendarIcon } from "@heroicons/react/24/solid";
import Image from "next/image";
import { inter } from '@/app/ui/fonts'
import LikeButton from '@/app/ui/like-button'
import CommentButton from "@/app/ui/comment-button";
import FollowButton from "@/app/ui/follow-button";
import ShareButton from '@/app/ui/share-button';
import CreateComment from '@/app/ui/create-comment';
import Link from "next/link";
import { useEffect, useState } from "react";

export function PostCard({ Post }: { Post: postCard } ) {
  const postId = Post.postId;

  const [comments, setComments] = useState<Comment[]>([]);
  const [ownerImageUrl, setOwnerImageUrl] = useState<string | null>(null);
  const [contentImageUrl, setContentImageUrl] = useState<string | null>(null);

  useEffect(() => {
    fetch(`/api/post/${postId}/comments`, {
      method: 'GET',
      credentials: 'include',
    }).then(async res => {
      const data = await res.json();

      if (res.ok) {
        const parsedComments = data.map((comment: any) => ({
          authorUsername: comment.userSummary.username,
          authorProfilePic: comment.userSummary.profilePhoto,
          content: comment.text,
          date: comment.createdAt,
        })) as Comment[];
        setComments(parsedComments);
      }
    });

    // Fetch owner image if the id exists
    if (Post.owner_image_url) {
      fetch(`/api/media/${Post.owner_image_url}`, {
        credentials: 'include',
      })
        .then(res => res.blob())
        .then(blob => {
          const url = URL.createObjectURL(blob);
          setOwnerImageUrl(url);
        });
    }

    // Fetch content image if the id exists
    if (Post.content_image_url) {
      fetch(`/api/media/${Post.content_image_url}`, {
        credentials: 'include',
      })
        .then(res => res.blob())
        .then(blob => {
          const url = URL.createObjectURL(blob);
          setContentImageUrl(url);
        });
    }
  }, [Post.owner_image_url, Post.content_image_url, postId]);


  return (
    <Dialog>
      <div className="relative w-full max-w-2xl mx-auto">
        <DialogTrigger asChild>
          <div className="cursor-pointer">
            <Card className={`shadow-2xl ${inter.className} transition-all duration-300 hover:shadow-xl`}>
              <CardHeader>
                <CardTitle className='flex items-center gap-1.5 text-lg'>
                  <div className='flex items-center w-full justify-between gap-3 px-1.5'>
                    <Link href={`/user/${Post.owner_username}`} className='flex flex-row items-center gap-1.5' onClick={(e) => e.stopPropagation()}>
                      <Image
                        src={ownerImageUrl ?? nullUser}
                        className="mr-2 rounded-full"
                        width={48}
                        height={48}
                        alt={'image'}/>
                      {Post.owner_name}
                    </Link>
                    <div onClick={(e) => e.stopPropagation()}>
                      <FollowButton username={Post.owner_username} isFollow={Post.isFollowed} />
                    </div>
                  </div>
                </CardTitle>
              </CardHeader>

              <CardContent className="grid gap-4">
                <div className="space-y-2">
                  <p className='text-lg border-t-2 mt-5 pt-2 whitespace-normal'>
                    {Post.message ?? ''}
                  </p>

                  {contentImageUrl && (
                    <div className="w-full max-w-[500px] mx-auto">
                      <Image
                        src={contentImageUrl}
                        alt="post image"
                        width={500}
                        height={500}
                        className="rounded-lg border-2 border-gray-200 hover:border-blue-500 transition-all object-contain w-full h-auto"
                        sizes="(max-width: 640px) 100vw, (max-width: 1024px) 80vw, 500px"
                      />
                    </div>
                  )}

                  <div className="flex justify-between items-center mx-1">
                    <div className="flex justify-start text-muted-foreground gap-3 text-sm">
                      <CalendarIcon className='w-5' /> {String(Post.date).split('T')[0]}
                    </div>
                    <div className="flex flex-row justify-end gap-1" onClick={(e) => e.stopPropagation()}>
                      <LikeButton postId={Post.postId} likes={Post.likes} isLiked={Post.isLiked} />
                      <CommentButton comments={Post.comments} />
                      <ShareButton postId={Post.postId} />
                    </div>
                  </div>
                </div>
              </CardContent>
            </Card>
          </div>
        </DialogTrigger>

        <DialogContent className={`w-full min-w-[80vw] min-h-[90vh] p-0 ${inter.className}`}>
          <DialogTitle className="sr-only">Post</DialogTitle>
          <div className="flex flex-col md:flex-row w-full h-[90vh] overflow-hidden">

            <div className="flex justify-center items-center md:w-auto">
              {contentImageUrl && (
                <Image
                  src={contentImageUrl}
                  alt="post image"
                  width={500}
                  height={500}
                  className="rounded-lg"
                />
              )}
            </div>

            <div className="flex flex-col flex-1 min-w-[300px] h-full border-l overflow-hidden bg-white">
              <div className="p-4 pb-2 border-b">
                <div className="flex items-center justify-between gap-3 mb-2 pr-10">
                  <Link href={`/user/${Post.owner_username}`} className='flex flex-row items-center gap-1.5 text-lg font-bold'>
                    <Image
                      src={ownerImageUrl ?? nullUser}
                      className="mr-2 rounded-full"
                      width={48}
                      height={48}
                      alt={'image'}/>

                    {Post.owner_name}
                  </Link>
                  <FollowButton username={Post.owner_username} isFollow={Post.isFollowed} />
                </div>
                <p className="text-sm">{Post.message}</p>
                <div className="flex justify-start text-sm text-muted-foreground gap-3 mt-2">
                  <CalendarIcon className='w-4' /> {String(Post.date).split('T')[0]}
                </div>
              </div>

              <div className="flex-1 overflow-y-auto scrollbar-hide p-4 space-y-2">
                {comments.map((comment: Comment, index: number) => (
                  <div
                    key={index}
                    className="flex items-start gap-3 p-3 bg-white rounded-lg hover:shadow-sm transition"
                  >
                    <Image
                      src={comment.authorProfilePic ?? nullUser}
                      className="rounded-full object-cover"
                      width={36}
                      height={36}
                      alt={`${comment.authorUsername}'s profile picture`}
                    />
                    <div className="flex flex-col flex-grow">
                      <Link
                        href={`/user/${comment.authorUsername}`}
                        className="font-semibold hover:underline text-sm text-black"
                      >
                        {comment.authorUsername}
                      </Link>
                      <p className="text-sm text-gray-700">{comment.content}</p>
                    </div>
                    <div className="flex items-center gap-2 text-sm text-muted-foreground self-end">
                      <CalendarIcon className="w-4 h-4 " />
                      <p>{String(comment.date).split('T')[0]}</p>
                    </div>
                  </div>
                ))}
              </div>
              <CreateComment
                postId={Post.postId}
                onCommentPosted={(newComment: Comment) => {
                  setComments((prev) => [...prev, newComment])
                }}
              />
            </div>
          </div>
        </DialogContent>
      </div>
    </Dialog>
  );
}
