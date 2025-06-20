import React, { useState, useEffect } from 'react';
import { redirect, useParams } from 'react-router-dom';
import {
    fetchMovieById,
    fetchMovieCasts,
    fetchMovieCrews,
} from '@/api/movieapi';
import { CrewMember } from '@/types/crew';
import { CastMember } from '@/types/crew';
import { Movie } from '@/types/movie';
import MovieHeader from './components/MovieHeader';
import CastList from './components/CastList';
import CrewList from './components/CrewList';
import ReviewList from './components/ReviewList';
import OtherMovies from './components/OtherMovies';
import './style/MoviePage.css';
import { movieIdFromSlug } from '../home/util/slug';

export const MoviePage: React.FC = () => {
    const { movieSlug } = useParams<{ movieSlug: string }>();
    const [movie, setMovie] = useState<Movie | null>(null);
    const [casts, setCasts] = useState<CastMember[]>([]);
    const [crews, setCrews] = useState<CrewMember[]>([]);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        if (!movieSlug) {
            setLoading(false)
            redirect('/');
            return;
        }
        const id = movieIdFromSlug(movieSlug);
        if (!id) {
            setLoading(false)
            return
        }

        // 1) Film bilgisini çek
        fetchMovieById(id)
            .then(m => {
                setMovie(m);
                document.title = `${m.title} - Listopia`;
            })
            .catch(err => console.error('Failed to fetch movie:', err))
            .finally(() => setLoading(false));

        // 2) Cast listesini çek (hata olsa bile devam etsin)
        fetchMovieCasts(id)
            .then(res => setCasts(res.content))
            .catch(err => console.error('Failed to fetch casts:', err));

        // 3) Crew listesini çek
        fetchMovieCrews(id)
            .then(res => setCrews(res.content))
            .catch(err => console.error('Failed to fetch crews:', err));
    }, [movieSlug]);

    if (loading) return <p>Loading…</p>;
    if (!movie) return <p>Movie not found</p>;

    const primaryGenre = movie.genres[0]?.name || '';

    return (
        <main className="movie-page">
            <MovieHeader movie={movie} />

            <div className="people-and-lists">
                <div className="people">
                    <CastList casts={casts} />
                    <CrewList crews={crews} />
                </div>
            </div>

            <ReviewList />

            <OtherMovies genre={primaryGenre} />
        </main>
    );
};

export default MoviePage;
