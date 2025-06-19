// src/features/genre/components/GenreSidebar.tsx
import React from 'react';
import { Link } from 'react-router-dom';
import '../style/GenreSidebar.css';

interface Props {
    genres: string[];
    selected?: string;
}

export const GenreSidebar: React.FC<Props> = ({ genres, selected }) => (
    <aside className="genre-sidebar">
        <h3>Genres</h3>
        <ul>
            {genres.map(g => {
                const to = g === 'All' ? '/genres/' : `/genres/${g}`;
                return (
                    <li key={g}>
                        <Link to={to} className={g === selected ? 'active' : ''}>
                            {g}
                        </Link>
                    </li>
                );
            })}
        </ul>
    </aside>
);
