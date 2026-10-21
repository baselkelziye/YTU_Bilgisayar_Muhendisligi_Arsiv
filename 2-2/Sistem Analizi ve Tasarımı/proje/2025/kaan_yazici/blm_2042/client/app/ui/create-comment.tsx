'use client';

import { Textarea } from "@/components/ui/textarea";
import { Button } from "@/components/ui/button";
import { useState, useEffect } from "react";
import nullUser from '@/public/user-circle-svgrepo-com.svg';
import { Comment } from '@/app/lib/definitions';

export default function CreateComment({
  postId,
  onCommentPosted,
  }: {
  postId: number;
  onCommentPosted: (comment: Comment) => void;
  }) {
  const [text, setText] = useState("");
  const [username, setUsername] = useState("");

  useEffect(() => {
    fetch(`/api/user/profile`, {
      method: 'POST',
      credentials: 'include',
    }).then(async res => {
      const data = await res.json();

      setUsername(data.username);
      console.log(data);
    })
  }, [])

  const postComment = () => {
    if (!text.trim()) {
      return;
    }
    fetch(`/api/comment/create`, {
      method: "POST",
      credentials: 'include',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({
        postId,
        username: username,
        text,
      }),
    }).then(async res => {
      if (res.ok) {
        const newComment: Comment = {
          authorUsername: username,
          authorProfilePic: nullUser,
          content: text,
          date: new Date(),
        };
        onCommentPosted(newComment);
        setText('');
      }
    });
  };

  return (
    <div className="border-t p-4 shrink-0 flex flex-row space-x-2">
      <Textarea
        value={text}
        onChange={(e) => setText(e.target.value)}
        placeholder="Add a comment..."
        className="w-full mb-2" />
      <Button type="submit" onClick={postComment} className="w-auto">Post Comment</Button>
    </div>
  );
}