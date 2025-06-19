// src/components/MovieHeader.tsx

import React, { useState, useEffect } from 'react';
import { Movie } from '@/types/movie';
import '../style/MovieHeader.css';
import { getPosterUrl } from '@/lib/utils';
import {
    likeMovie,
    markMovieAsWatched,
    addMovieToWatchlist,
    removeMovieFromWatched,
    removeMovieFromWatchlist,
    fetchWatchedMoviesByUser,
    fetchWatchlistMoviesByUser,
} from '@/api/movieapi';
import { fetchLikedMovies } from '@/api/userapi';
import { useAuth } from '@/app/auth/hooks/AuthContext';
import { useNavigate } from 'react-router-dom';

interface Props {
    movie: Movie;
}

const MovieHeader: React.FC<Props> = ({ movie }) => {
    const { user } = useAuth();
    const navigate = useNavigate();

    // Like state
    const [liked, setLiked] = useState(false);
    const [isLiking, setIsLiking] = useState(false);
    const [likeError, setLikeError] = useState<string | null>(null);

    // Watched state
    const [watched, setWatched] = useState(false);
    const [isUpdatingWatched, setIsUpdatingWatched] = useState(false);
    const [watchedError, setWatchedError] = useState<string | null>(null);

    // Watchlist state
    const [watchlist, setWatchlist] = useState(false);
    const [isUpdatingWatchlist, setIsUpdatingWatchlist] = useState(false);
    const [watchlistError, setWatchlistError] = useState<string | null>(null);

    // Fetching statuses
    const [isFetchingStatus, setIsFetchingStatus] = useState(true);
    const [fetchError, setFetchError] = useState<string | null>(null);

    useEffect(() => {
        if (!user) {
            setIsFetchingStatus(false);
            return;
        }

        setIsFetchingStatus(true);
        setFetchError(null);
        setLikeError(null);
        setWatchedError(null);
        setWatchlistError(null);

        Promise.allSettled([
            fetchLikedMovies(user.uuid),
            fetchWatchedMoviesByUser(user.uuid),
            fetchWatchlistMoviesByUser(user.uuid),
        ]).then(results => {
            // Liked
            if (results[0].status === 'fulfilled') {
                setLiked(results[0].value.content.some(m => m.movieId === movie.movieId));
            } else {
                setFetchError('Beğeni durumunu alırken hata oluştu.');
            }
            // Watched
            if (results[1].status === 'fulfilled') {
                setWatched(results[1].value.content.some(m => m.movieId === movie.movieId));
            } else {
                setFetchError('İzlendi durumunu alırken hata oluştu.');
            }
            // Watchlist
            if (results[2].status === 'fulfilled') {
                setWatchlist(results[2].value.content.some(m => m.movieId === movie.movieId));
            } else {
                setFetchError('İzleme listesi durumunu alırken hata oluştu.');
            }
        }).finally(() => {
            setIsFetchingStatus(false);
        });
    }, [user?.uuid, movie.movieId]);

    const handleLike = async () => {
        if (!user) { navigate('/login/'); return; }
        if (isLiking || isFetchingStatus || isUpdatingWatched || isUpdatingWatchlist) return;

        setIsLiking(true);
        setLikeError(null);
        const prev = liked;
        setLiked(!prev);

        try {
            const res = await likeMovie(movie.movieId, !prev);
            if (!res.success) {
                setLikeError(res.message || 'Beğeni güncellenemedi.');
                setLiked(prev);
            }
        } catch (e) {
            setLikeError((e as Error).message);
            setLiked(prev);
        } finally {
            setIsLiking(false);
        }
    };

    const handleWatched = async () => {
        if (!user) { navigate('/login/'); return; }
        if (isUpdatingWatched || isLiking || isFetchingStatus || isUpdatingWatchlist) return;

        setIsUpdatingWatched(true);
        setWatchedError(null);
        setWatchlistError(null);

        try {
            if (!watched) {
                if (watchlist) {
                    const rem = await removeMovieFromWatchlist(movie.movieId);
                    if (rem.success) setWatchlist(false);
                    else setWatchlistError('İzleme listesinden çıkarılamadı.');
                }
                const mark = await markMovieAsWatched(movie.movieId);
                if (mark.success) setWatched(true);
                else setWatchedError('İzlendi olarak işaretlenemedi.');
            } else {
                const rem = await removeMovieFromWatched(movie.movieId);
                if (rem.success) setWatched(false);
                else setWatchedError('İzlendi işareti kaldırılamadı.');
            }
        } catch (e) {
            setWatchedError((e as Error).message);
        } finally {
            setIsUpdatingWatched(false);
        }
    };

    const handleWatchlist = async () => {
        if (!user) { navigate('/login/'); return; }
        if (isUpdatingWatchlist || isLiking || isFetchingStatus || isUpdatingWatched) return;

        setIsUpdatingWatchlist(true);
        setWatchlistError(null);
        setWatchedError(null);

        try {
            if (!watchlist) {
                if (watched) {
                    const rem = await removeMovieFromWatched(movie.movieId);
                    if (rem.success) setWatched(false);
                    else setWatchedError('İzlenenlerden çıkarılamadı.');
                }
                const add = await addMovieToWatchlist(movie.movieId);
                if (add.success) setWatchlist(true);
                else setWatchlistError('İzleme listesine eklenemedi.');
            } else {
                const rem = await removeMovieFromWatchlist(movie.movieId);
                if (rem.success) setWatchlist(false);
                else setWatchlistError('İzleme listesinden kaldırılamadı.');
            }
        } catch (e) {
            setWatchlistError((e as Error).message);
        } finally {
            setIsUpdatingWatchlist(false);
        }
    };

    const isBusy = isLiking || isUpdatingWatched || isUpdatingWatchlist || isFetchingStatus;

    // Backdrop & IMDb link
    const backdropUrl = movie.backdrop
        ? `https://image.tmdb.org/t/p/original${movie.backdrop}`
        : '';
    const imdbLink = movie.imdbId
        ? `https://www.imdb.com/title/${movie.imdbId}`
        : null;

    return (
        <header
            className="movie-header"
            style={
                backdropUrl
                    ? {
                        backgroundImage: `linear-gradient(to bottom, rgba(0,0,0,0.6), rgba(0,0,0,0.9)), url(${backdropUrl})`
                    }
                    : {}
            }
        >
            <div className="movie-header__inner">
                <div className="movie-header__poster">
                    <img
                        src={getPosterUrl(movie.poster || '')}
                        alt={`${movie.title} poster`}
                    />
                </div>
                <div className="movie-header__info">
                    <h1 className="movie-header__title">{movie.title}</h1>
                    {movie.tagline && (
                        <p className="movie-header__tagline">“{movie.tagline}”</p>
                    )}
                    <div className="movie-header__meta">
                        <span><strong>Release:</strong> {movie.releaseDate}</span>
                        <span><strong>Runtime:</strong> {movie.runtime} min</span>
                        <span><strong>Genres:</strong> {movie.genres.map(g => g.name).join(', ') || 'N/A'}</span>
                    </div>

                    <div className="movie-side-by-side-links">
                        {imdbLink && (
                            <div className="movie-header__imdb-link">
                                <a href={imdbLink} target="_blank" rel="noopener noreferrer">
                                    View on IMDb
                                </a>
                            </div>
                        )}
                        {movie.trailerLink && (
                            <div className="movie-header__trailer-link">
                                <a
                                    href={movie.trailerLink}
                                    target="_blank"
                                    rel="noopener noreferrer"
                                    className="action-button trailer-button"
                                >
                                    <img
                                        src="https://upload.wikimedia.org/wikipedia/commons/7/75/YouTube_social_white_squircle_(2017).svg"
                                        alt="YouTube"
                                        className="youtube-logo"
                                    />
                                    Fragman
                                </a>
                            </div>
                        )}
                    </div>

                    {movie.overview && (
                        <p className="movie-header__overview">
                            <strong>Overview:</strong> {movie.overview}
                        </p>
                    )}

                    <div className="movie-header__actions">
                        <button
                            title={liked ? 'Unlike' : 'Like'}
                            onClick={handleLike}
                            disabled={isBusy}
                            className={`action-button like-button ${liked ? 'liked' : ''} ${isLiking ? 'processing' : ''}`}
                        >
                            {liked ? '❤️' : '♡'}
                        </button>

                        <button
                            title={watched ? 'Unmark watched' : 'Mark watched'}
                            onClick={handleWatched}
                            disabled={isBusy}
                            className={`action-button watched-button ${watched ? 'active' : ''} ${isUpdatingWatched ? 'processing' : ''}`}
                        >
                            Watched
                        </button>

                        <button
                            title={watchlist ? 'Remove from watchlist' : 'Add to watchlist'}
                            onClick={handleWatchlist}
                            disabled={isBusy}
                            className={`action-button watchlist-button ${watchlist ? 'active' : ''} ${isUpdatingWatchlist ? 'processing' : ''}`}
                        >
                            Want to Watch
                        </button>

                        {(likeError || fetchError || watchedError || watchlistError) && (
                            <p className="error-message">
                                {[likeError, fetchError, watchedError, watchlistError].filter(Boolean).join(' ')}
                            </p>
                        )}
                    </div>
                </div>
            </div>
        </header>
    );
};

export default MovieHeader;
