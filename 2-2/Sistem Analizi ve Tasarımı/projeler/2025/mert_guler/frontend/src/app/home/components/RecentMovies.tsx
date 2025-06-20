import React, { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';
import { fetchFrontMovies } from '@/api/movieapi';
import { FrontMovie } from '@/types/front';
import { CardSlider } from './CardSlider';
import '../style/RecentMovies.css';
import { getPosterUrl } from '@/lib/utils';
import { movieToSlug } from '../util/slug';

export const RecentMovies: React.FC = () => {
    const [movies, setMovies] = useState<FrontMovie[]>([]);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        fetchFrontMovies({
            sortBy: 'releaseDate',
            sortOrder: 'dsc',
            pageSize: 20
        })
            .then(res => setMovies(res.content))
            .catch(console.error)
            .finally(() => setLoading(false));
    }, []);

    if (loading) return <div className="loading">Loading recent movies…</div>;

    return (
        <section className="section">
            <h2>Recent Movies</h2>
            <CardSlider
                items={movies}
                className=""
                renderItem={m => (
                    <Link to={movieToSlug(m)} className="slider-card">
                        <div className="slider-poster">
                        <img
                         src={getPosterUrl(m.poster)} alt={m.title}
                        />
                        </div>
                    </Link>
                )}
            />
        </section>
    );
};
