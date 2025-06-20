// src/features/profile/components/ProfileStatistics.tsx
import React, { useState, useEffect, useRef } from 'react';
import { Eye, Clock, Heart } from 'lucide-react';
import { fetchLikedMovies } from '@/api/userapi';
import {
    fetchWatchedMoviesByUser,
    fetchWatchlistMoviesByUser,
} from '@/api/movieapi';
import type { Movie } from '@/types/movie';
import type { PaginatedResponse } from '@/types/friends';
import { Link } from 'react-router-dom';
import { movieToSlug } from '@/app/home/util/slug';
import styles from "../style/ProfileStatistics.module.css";

interface ProfileStatisticsProps {
    stats: { watched: number; wantToWatch: number; liked: number };
    userUuid: string;
}

const pageSize = 20;

const ProfileStatistics: React.FC<ProfileStatisticsProps> = ({
                                                                 stats,
                                                                 userUuid,
                                                             }) => {
    const [counts, setCounts] = useState(stats);
    const [activeList, setActiveList] = useState<
        'watched' | 'watchlist' | 'liked' | null
    >(null);
    const [movies, setMovies] = useState<Movie[]>([]);
    const [loading, setLoading] = useState(false);
    const [error, setError] = useState<string | null>(null);
    const [totalPages, setTotalPages] = useState(0);
    const sliderRef = useRef<HTMLDivElement | null>(null);

    // fetch initial counts
    useEffect(() => {
        (async () => {
            try {
                const [watchedRes, watchlistRes, likedRes] = await Promise.all([
                    fetchWatchedMoviesByUser(userUuid, { pageNumber: 0, pageSize: 1 }),
                    fetchWatchlistMoviesByUser(userUuid, {
                        pageNumber: 0,
                        pageSize: 1,
                    }),
                    fetchLikedMovies(userUuid, 0, 1),
                ]);
                setCounts({
                    watched: watchedRes.totalElements,
                    wantToWatch: watchlistRes.totalElements,
                    liked: likedRes.totalElements,
                });
            } catch {
                console.error('Error fetching initial stats');
            }
        })();
    }, [userUuid]);

    const handleStatClick = async (
        type: 'watched' | 'watchlist' | 'liked'
    ) => {
        if (activeList === type) {
            setActiveList(null);
            setMovies([]);
            return;
        }
        setActiveList(type);
        setLoading(true);
        setError(null);

        try {
            let res: PaginatedResponse<Movie>;
            if (type === 'watched') {
                res = await fetchWatchedMoviesByUser(userUuid, {
                    pageNumber: 0,
                    pageSize,
                });
                setCounts((c) => ({ ...c, watched: res.totalElements }));
            } else if (type === 'watchlist') {
                res = await fetchWatchlistMoviesByUser(userUuid, {
                    pageNumber: 0,
                    pageSize,
                });
                setCounts((c) => ({ ...c, wantToWatch: res.totalElements }));
            } else {
                res = await fetchLikedMovies(userUuid, 0, pageSize);
                setCounts((c) => ({ ...c, liked: res.totalElements }));
            }
            setMovies(res.content);
            setTotalPages(res.totalPages);
        } catch {
            const turkish =
                type === 'watched'
                    ? 'izlenen'
                    : type === 'watchlist'
                        ? 'izlenecek'
                        : 'beğenilen';
            setError(`${turkish} filmler yüklenemedi.`);
            setMovies([]);
            setTotalPages(0);
        } finally {
            setLoading(false);
        }
    };

    const scroll = (offset: number) => {
        if (sliderRef.current) {
            sliderRef.current.scrollBy({ left: offset, behavior: 'smooth' });
        }
    };

    const showNav = movies.length > 1;

    return (
        <div className={styles.profileStats}>
            <div className={styles.cardsContainer}>
                {/** Watched **/}
                <div
                    className={`${styles.baseCard} ${styles.watchedCard}`}
                    onClick={() => handleStatClick('watched')}
                    onMouseOver={(e) =>
                        (e.currentTarget.style.transform = 'scale(1.03)')
                    }
                    onMouseOut={(e) => (e.currentTarget.style.transform = 'scale(1)')}
                >
                    <div className={`${styles.iconBase} ${styles.watchedIcon}`}>
                        <Eye size={24} color="white" />
                    </div>
                    <div className={styles.count}>{counts.watched}</div>
                    <div className={styles.label}>Watched</div>
                </div>

                {/** To Watch **/}
                <div
                    className={`${styles.baseCard} ${styles.watchlistCard}`}
                    onClick={() => handleStatClick('watchlist')}
                    onMouseOver={(e) =>
                        (e.currentTarget.style.transform = 'scale(1.03)')
                    }
                    onMouseOut={(e) => (e.currentTarget.style.transform = 'scale(1)')}
                >
                    <div className={`${styles.iconBase} ${styles.watchlistIcon}`}>
                        <Clock size={24} color="white" />
                    </div>
                    <div className={styles.count}>{counts.wantToWatch}</div>
                    <div className={styles.label}>To Watch</div>
                </div>

                {/** Liked **/}
                <div
                    className={`${styles.baseCard} ${styles.likedCard}`}
                    onClick={() => handleStatClick('liked')}
                    onMouseOver={(e) =>
                        (e.currentTarget.style.transform = 'scale(1.03)')
                    }
                    onMouseOut={(e) => (e.currentTarget.style.transform = 'scale(1)')}
                >
                    <div className={`${styles.iconBase} ${styles.likedIcon}`}>
                        <Heart size={24} color="white" />
                    </div>
                    <div className={styles.count}>{counts.liked}</div>
                    <div className={styles.label}>Liked</div>
                </div>
            </div>

            {activeList && (
                <div className={styles.movieList}>
                    <h3 className={styles.movieListHeader}>
                        {activeList === 'watched'
                            ? 'Movies Watched'
                            : activeList === 'watchlist'
                                ? 'Movies to Watch'
                                : 'Liked Movies'}
                    </h3>

                    {loading && (
                        <div style={{ textAlign: 'center', padding: '16px' }}>
                            Loading...
                        </div>
                    )}
                    {error && <div className={styles.error}>{error}</div>}
                    {!loading && !error && movies.length === 0 && (
                        <div className={styles.empty}>No movies found in this list.</div>
                    )}

                    {!loading && !error && movies.length > 0 && (
                        <>
                            {showNav && (
                                <button
                                    className={`${styles.profileNav} ${styles.profilePrev}`}
                                    onClick={() => scroll(-300)}
                                >
                                    ‹
                                </button>
                            )}

                            <div
                                className={styles.sliderContainer}
                                ref={sliderRef}
                            >
                                {movies.map((movie) => (
                                    <Link
                                        key={movie.movieId}
                                        to={movieToSlug(movie)}
                                        style={{ minWidth: '180px', textDecoration: 'none' }}
                                    >
                                        <div
                                            style={{
                                                marginBottom: '8px',
                                                borderRadius: '4px',
                                                overflow: 'hidden',
                                            }}
                                        >
                                            <img
                                                src={
                                                    movie.poster
                                                        ? `https://image.tmdb.org/t/p/w200${movie.poster}`
                                                        : '/placeholder.svg?height=150&width=100'
                                                }
                                                alt={movie.title}
                                                loading="lazy"
                                                style={{ width: '100%', display: 'block' }}
                                                onError={(e) =>
                                                    ((e.target as HTMLImageElement).src =
                                                        '/placeholder.svg?height=150&width=100')
                                                }
                                            />
                                        </div>
                                        <h4
                                            style={{
                                                color: 'white',
                                                fontSize: '1rem',
                                                margin: 0,
                                            }}
                                        >
                                            {movie.title}
                                        </h4>
                                    </Link>
                                ))}
                            </div>

                            {showNav && (
                                <button
                                    className={`${styles.profileNav} ${styles.profileNext}`}
                                    onClick={() => scroll(300)}
                                >
                                    ›
                                </button>
                            )}
                        </>
                    )}
                </div>
            )}
        </div>
    );
};

export default ProfileStatistics;
