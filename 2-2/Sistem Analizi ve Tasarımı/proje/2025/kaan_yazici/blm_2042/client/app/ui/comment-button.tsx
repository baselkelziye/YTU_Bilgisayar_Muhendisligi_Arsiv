'use client'

import { ChatBubbleLeftRightIcon } from "@heroicons/react/24/solid";
import { Button } from "@/components/ui/button";

export default function CommentButton({ comments }: { comments: number }) {
  return (
    <Button
      variant="ghost"
      className="flex items-center gap-2 text-sm text-muted-foreground hover:text-blue-600 hover:scale-110 transition-colors duration-300 ease-in-out"
    >
      <ChatBubbleLeftRightIcon className="w-5" />
      {comments}
    </Button>
  );
}
