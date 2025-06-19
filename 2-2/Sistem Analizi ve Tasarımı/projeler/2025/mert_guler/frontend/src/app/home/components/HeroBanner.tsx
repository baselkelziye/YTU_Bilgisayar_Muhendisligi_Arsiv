// src/features/home/components/HeroBanner.tsx
import React from 'react';
import {Link} from 'react-router-dom';
import '../style/HeroBanner.css';
import { movieToSlug } from '../util/slug';
import {FrontMovie} from "@/types/front";

type Props = { movie: FrontMovie };

export const HeroBanner: React.FC<Props> = ({ movie }) => {
    const backdropUrl = `https://image.tmdb.org/t/p/original${movie.poster}`;

    return (
        <Link to={movieToSlug(movie)}>
            <section
                className="hero-banner"
                style={{
                    backgroundImage: `url(${backdropUrl})`,
                    backgroundSize: 'cover',
                    backgroundPosition: 'center',
                }}
            >
                <div className="overlay">
                    <div className="content">
                        <h1>{movie.title}</h1>
                        <button className="btn-primary">
                            View Details
                        </button>
                    </div>
                </div>
            </section>
        </Link>
    );
};
