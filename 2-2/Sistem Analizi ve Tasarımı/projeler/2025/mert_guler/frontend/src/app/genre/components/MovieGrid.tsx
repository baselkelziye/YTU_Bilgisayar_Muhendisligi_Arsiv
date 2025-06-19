// src/features/genre/components/MovieGrid.tsx
import React from 'react';
import { Link } from 'react-router-dom';
import { FrontMovie } from '@/types/front';
import '../style/MovieGrid.css';
//
// // TMDB için örnek base URL; ihtiyacına göre w200/w300/w500 vs. seçebilirsin
// const IMAGE_BASE_URL = 'https://image.tmdb.org/t/p/w300';

interface Props { movies: FrontMovie[]; }
import { getPosterUrl } from '@/lib/utils';
import { movieToSlug } from '@/app/home/util/slug';

function truncate(text: string, maxLen = 50) {
    return text.length > maxLen
        ? text.slice(0, maxLen) + '…'
        : text;
}
export const MovieGrid: React.FC<Props> = ({ movies }) => (
    <div className="movie-grid">
        {movies.map(movie => {
            // Eğer API full URL döndürdüyse olduğu gibi kullan, aksi halde base URL + relative path
            const posterUrl = getPosterUrl(movie.poster);
            // console.log('poster path:', movie.poster); // debug için
            const title = truncate(movie.title, 50);

            return (
                <Link
                    key={movie.movieId}
                    to={movieToSlug(movie)}
                    className="movie-card"
                >
                    <img
                        src={posterUrl}
                        alt={movie.title}
                        className="movie-poster"
                    />
                    <h3 className="movie-title">{title}</h3>
                </Link>
            );
        })}
    </div>
);
