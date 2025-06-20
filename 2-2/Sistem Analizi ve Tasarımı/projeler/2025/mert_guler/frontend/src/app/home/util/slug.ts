import { FrontMovie } from "@/types/front";
import { User } from "@/types/user";

export function createSlug(movie: FrontMovie): string {
  const slugifiedTitle = movie.title
    .toLowerCase()
    .trim()
    .replace(/[^a-z0-9]+/g, '-')
    .replace(/^-+|-+$/g, '');

  return `${slugifiedTitle}-${movie.movieId}`;
}
export function usernameToSlug(username: string): string {
    return username
        .toLowerCase()
        .trim()
        .replace(/[^a-z0-9]+/g, "-")
        .replace(/^-+|-+$/g, "");
}
  
export function movieIdFromSlug(slug: string): number | null {
  const idPart = slug.split('-').pop(); // Take the last part after the last hyphen
  const id = Number(idPart);
  if (isNaN(id)) {
    return null;
  }
  return id;
}

export function movieToSlug(movie: FrontMovie): string {
    let slug = createSlug(movie);
    return `/movies/${slug}`
}


export function userProfilePath(user: User): string {
    return `/profile/${usernameToSlug(user.username)}`;
}