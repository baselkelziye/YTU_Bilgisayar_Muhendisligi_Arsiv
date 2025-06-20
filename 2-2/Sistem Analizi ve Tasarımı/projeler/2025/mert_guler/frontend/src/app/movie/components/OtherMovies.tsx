import React, { useState, useEffect } from 'react';
import { fetchFrontMovies } from '@/api/movieapi';
import { FrontMovie } from '@/types/front';
import { CardSlider } from '@/app/home/components/CardSlider';
import { Link } from 'react-router-dom';
import '../style/OtherFilms.css';

interface Props {
    genre: string;
}

const OtherMovies: React.FC<Props> = ({ genre }) => {
    const [movies, setMovies] = useState<FrontMovie[]>([]);

    useEffect(() => {
        if (!genre) return;
        fetchFrontMovies({ genre, pageSize: 15, sortOrder:'dsc', sortBy:"watchCount" })
            .then(res => setMovies(res.content))
            .catch(console.error);
    }, [genre]);

    if (!movies.length) return null;

    return (
        <section className="other-movies">
            <h2>Others Also Watched</h2>
            <CardSlider
                items={movies}
                renderItem={m => (
                    <Link key={m.movieId} to={`/movies/${m.movieId}`}>
                        <img
                            src={`https://image.tmdb.org/t/p/w300${m.poster}`}
                            alt={m.title}
                        />
                    </Link>
                )}
            />
        </section>
    );
};

export default OtherMovies;
