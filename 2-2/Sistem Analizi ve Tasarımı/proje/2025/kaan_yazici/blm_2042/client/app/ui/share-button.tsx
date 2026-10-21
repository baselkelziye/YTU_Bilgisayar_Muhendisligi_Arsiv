'use client'

import { ShareIcon } from "@heroicons/react/24/solid";
import { Button } from "@/components/ui/button";
import { toast } from 'sonner';
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuLabel,
  DropdownMenuSeparator,
  DropdownMenuTrigger,
} from '@/components/ui/dropdown-menu';
import { Copy } from 'lucide-react';

export default function ShareButton({ postId }: { postId: number }) {
  const base = 'http://localhost:3000/post/';

  return (
    <DropdownMenu>
      <DropdownMenuTrigger asChild>
        <Button
          variant="ghost"
          className="flex items-center gap-2 text-sm text-muted-foreground hover:text-green-500 hover:scale-110 transition-colors duration-200"
          onClick={() => {
            navigator.clipboard.writeText(base+postId)
              .then(() => toast.success('Copied to clipboard'));
          } }
        >
          <ShareIcon className="w-5" />
        </Button>
      </DropdownMenuTrigger>
      <DropdownMenuContent className="w-auto">
        <DropdownMenuLabel>Share Link</DropdownMenuLabel>
        <DropdownMenuSeparator />
        <div className="flex flex-row gap-2 mr-2 my-2 items-center">
          <span className="text-muted-foreground text-sm mx-2 bg-gray-100 rounded-sm px-1.5 py-1.5">
            {base + postId}
          </span>
          <Button
            variant="ghost"
            className="transition-colors duration-300 ease-in-out w-5 h-5 p-2 hover:scale-105 hover:bg-gray-100"
            onClick={() => {
              navigator.clipboard.writeText(base+postId)
                .then(() => toast.success('Link copied to clipboard'));
            } }
          >
            <Copy className="w-4"/>
          </Button>
        </div>
      </DropdownMenuContent>
    </DropdownMenu>
  );
}
