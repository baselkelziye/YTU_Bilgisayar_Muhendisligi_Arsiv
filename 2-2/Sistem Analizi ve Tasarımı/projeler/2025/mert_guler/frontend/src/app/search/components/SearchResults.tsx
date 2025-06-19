// src/app/search/components/SearchResults.tsx
import React from "react";
import { Link } from "react-router-dom";
import { SearchCategory, SearchResponse } from "@/api/searchapi";
import { getPosterUrl } from "@/lib/utils";
import {movieToSlug} from "@/app/home/util/slug";

interface Props {
    loading:      boolean;
    data:         SearchResponse | null;
    category:     SearchCategory;
    onPageChange: (n: number) => void;
}

type PageSlice<T> = {
    content:    T[];
    number:     number;    // Spring’s `number`
    totalPages: number;    // Spring’s `totalPages`
    last:       boolean;   // Spring’s `last`
};


function PaginatedList<T extends { uuid?: string; movieId?: number }>({
                                                                          pageData, renderCard,
                                                                          onPageChange
                                                                      }: {
    pageData: PageSlice<T>;
    renderCard: (item: T) => React.ReactNode;
    onPageChange: (n: number) => void;
}) {
    if (!pageData || pageData.content.length === 0) {
        return <p>No results.</p>;
    }

    return (
        <>
            <div className="results-list">
                {pageData.content.map(item => {
                    const key = "uuid" in item ? item.uuid! : String(item.movieId);
                    return <React.Fragment key={key}>{renderCard(item)}</React.Fragment>;
                })}
            </div>

            <div className="pagination">
                <button
                    disabled={pageData.number === 0}
                    onClick={() => onPageChange(pageData.number - 1)}
                >
                    Previous
                </button>
                <span>
          Page {pageData.number + 1} of {pageData.totalPages}
        </span>
                <button
                    disabled={pageData.last}
                    onClick={() => onPageChange(pageData.number + 1)}
                >
                    Next
                </button>
            </div>
        </>
    );
}

function truncate(text: string, maxLen = 50) {
    return text.length > maxLen ? text.slice(0, maxLen) + "…" : text;
}

export default function SearchResults({
                                          loading, data, category, onPageChange
                                      }: Props) {
    if (loading) return <p>Loading…</p>;
    if (!data)   return <p>Enter a query above.</p>;

    const { users, movies } = data.results;

    if (category === SearchCategory.USERS) {
        return (
            <PaginatedList
                pageData={users}
                onPageChange={onPageChange}
                renderCard={u => (
                    <Link to={`/profile/${u.username}`} className="card">
                        <img src={u.profilePicture} alt={u.username} />
                        <h5>{u.username}</h5>
                    </Link>
                )}
            />
        );
    }

    if (category === SearchCategory.MOVIES) {
        return (
            <PaginatedList
                pageData={movies}
                onPageChange={onPageChange}
                renderCard={m => (
                    <Link to={movieToSlug(m)} className="card">
                        <img src={getPosterUrl(m.poster) ?? "/placeholder.png"} alt={m.title} />
                        <h5>{truncate(m.title)}</h5>
                        <div className="card-footer">
                            <span>❤️ {m.likeCount}</span>
                            <span>👁️ {m.watchCount}</span>
                        </div>
                    </Link>
                )}
            />
        );
    }

    // ALL
    if (category === SearchCategory.ALL) {
        return (
            <>
                <h3 style={{ color: "#fff" }}>Users</h3>
                <div className="results-list">
                    {users.content.map(u => (
                        <Link to={`/profile/${u.username}`} className="card" key={u.uuid}>
                            <img src={u.profilePicture ?? "/default-avatar.png"} alt={u.username} />
                            <h5>{u.username}</h5>
                        </Link>
                    ))}
                </div>

                <h3 style={{ color: "#fff", marginTop: "2rem" }}>Movies</h3>
                 <PaginatedList
                   pageData={movies}
                   onPageChange={onPageChange}
                   renderCard={m => (
                     <Link to={movieToSlug(m)} className="card">
                         <img
                             src={getPosterUrl(m.poster) ?? "/placeholder.png"}
                             alt={m.title}
                         />
                         <h5>{truncate(m.title)}</h5>
                         <div className="card-footer">
                             <span>❤️ {m.likeCount}</span>
                             <span>👁️ {m.watchCount}</span>
                         </div>
                         </Link>
                   )}
                 />

            </>
        );
    }
}
