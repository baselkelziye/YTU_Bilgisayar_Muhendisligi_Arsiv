import { clsx, type ClassValue } from "clsx"
import { twMerge } from "tailwind-merge"

const IMAGE_BASE_URL = 'https://image.tmdb.org/t/p/w300';
export const PLACEHOLDER_POSTER = '/not-found.jpg';
// public/images altında koyduğunuz placeholder

export function getPosterUrl(poster: string | null): string {
    if (!poster) {
        return PLACEHOLDER_POSTER;
    }
    return poster.startsWith('http')
        ? poster
        : `${IMAGE_BASE_URL}${poster}`;
}

export function cn(...inputs: ClassValue[]) {
  return twMerge(clsx(inputs))
}

export function formatTimeAgo(timestamp: number): string {
  const now = Date.now();
  const diffMs = now - timestamp;
  const diffSec = Math.floor(diffMs / 1000);

  if (diffSec < 300) { // 300 seconds = 5 minutes
    return 'online';
  }

  const minutes = Math.floor(diffSec / 60);
  if (minutes < 60) {
    return `${minutes}m`;
  }

  const hours = Math.floor(minutes / 60);
  if (hours < 24) {
    return `${hours}h`;
  }

  const days = Math.floor(hours / 24);
  return `${days}d`;
}
