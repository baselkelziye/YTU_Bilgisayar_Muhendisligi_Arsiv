import React, { useState } from 'react';
import { CastMember } from '@/types/crew';
import '../style/CastList.css';

const IMAGE_BASE_URL = 'https://image.tmdb.org/t/p/w185';

interface Props {
    casts: CastMember[];
}

const CastList: React.FC<Props> = ({ casts }) => {
    const [expanded, setExpanded] = useState(false);
    const limit = 8;
    const toShow = expanded ? casts : casts.slice(0, limit);

    // Filter out cast members with no profile image
    const filteredCasts = toShow.filter((c) => c.profilePath);
    const truncate = (text: string, max: number) =>
        text.length > max ? text.slice(0, max) + '…' : text

    return (
        <section className="cast-list">
            <h3>Cast</h3>
            <div className="cast-grid">
                {filteredCasts.map((c) => (
                    <div
                        key={c.personId || `${c.originalName}-${c.character}`}
                        className="cast-card"
                    >
                        <img
                            src={`${IMAGE_BASE_URL}${c.profilePath}`}
                            alt={c.originalName}
                            loading="lazy"
                        />
                        <p className="name">{c.originalName}</p>
                        <p className="character">{truncate(c.character, 50)}</p>
                    </div>
                ))}
            </div>

            {casts.length > limit && (
                <button
                    className="cast-expand-btn"
                    onClick={() => setExpanded(!expanded)}
                >
                    {expanded ? 'Show less' : '… Show all'}
                </button>
            )}
        </section>
    );
};

export default CastList;