
import React, { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';

import { fetchFrontMovies } from '@/api/movieapi';
import { FrontMovie } from '@/types/front';
import { CardSlider } from './CardSlider';
import '../style/PopularMovies.css';
import {getPosterUrl} from "@/lib/utils";
import { movieToSlug } from '../util/slug';

export const MostVisitedMovies: React.FC = () => {
    const [movies, setMovies] = useState<FrontMovie[]>([]);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        fetchFrontMovies({
            sortBy: 'clickCount',
            sortOrder: 'dsc',
            pageSize: 20,
        })
            .then((res) => setMovies(res.content))
            .catch(console.error)
            .finally(() => setLoading(false));
    }, []);

    if (loading) return <div>Loading most visited movies…</div>;

    return (
        <section className="section">
            <h2>Most Visited Movies</h2>
            <CardSlider
                items={movies}
                renderItem={(m) => (
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
