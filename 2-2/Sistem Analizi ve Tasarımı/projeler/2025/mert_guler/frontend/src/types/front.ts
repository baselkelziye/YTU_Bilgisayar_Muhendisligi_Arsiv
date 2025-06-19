export interface FrontMovie {
    movieId: number;
    title: string;
    poster: string | null;
    watchCount: number;
    likeCount: number;
}

export interface PagedResponse<T> {
    content: T[];
    pageNumber: number;
    pageSize: number;
    totalElements: number;
    totalPages: number;
    lastPage: boolean;
}
