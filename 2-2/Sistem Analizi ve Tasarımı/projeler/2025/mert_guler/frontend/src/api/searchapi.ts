
import {BASE_URL} from "./apiClient";
import { User } from "@/types/user";
import { FrontMovie } from "@/types/front";
// import { PagedResponse }     from "@/types/front";

const API_URL = BASE_URL + "api/v1/search";


// A direct mapping of Spring’s Page<T> JSON:
export interface SpringPage<T> {
    content:       T[];
    number:        number;        // current page (0-based)
    size:          number;        // pageSize
    totalElements: number;
    totalPages:    number;
    last:          boolean;
    first:         boolean;
    // …plus any other fields you need (sort, pageable), or drop them
}

export interface SearchResponse {
    results: {
        users:  SpringPage<User>;
        movies: SpringPage<FrontMovie>;
    };
}


export enum SearchCategory {
    ALL = 'all',
    USERS = 'users',
    MOVIES = 'movies'
}


export async function searchUsersMovies(
    query: string,
    category: SearchCategory,
    page: number = 0,
    size: number = 15
): Promise<SearchResponse> {
    const url = new URL(`${API_URL}`);
    url.searchParams.append("query", query.toString());
    url.searchParams.append("category", category.toString());
    url.searchParams.append("pageNumber",     page.toString());
    url.searchParams.append("pageSize",     size.toString());
    const response = await fetch(url, {
        method: "GET",
        credentials: "include",
    });
    if (!response.ok) {
        throw new Error("Failed to get received messages");
    }
    const data = await response.json();
    return data;
}
