import React, { useState } from 'react';
import { CrewMember } from '@/types/crew';
import '../style/CrewList.css';


interface Props {
    crews: CrewMember[];
}

const CrewList: React.FC<Props> = ({ crews }) => {
    const [expanded, setExpanded] = useState(false);
    const limit = 5;
    const toShow = expanded ? crews : crews.slice(0, limit);

    return (
        <section className="crew-list">
            <h3>Crew</h3>
            <ul>
                {toShow.map((c, idx) => (
                    <li key={`${c.personId ?? 'noid'}-${c.job}-${idx}`}>
                        <strong>{c.originalName}</strong> — {c.department}, {c.job}
                    </li>
                ))}
            </ul>

            {crews.length > limit && (
                <button
                    className="crew-expand-btn"
                    onClick={() => setExpanded(!expanded)}
                >
                    {expanded ? 'Show less' : '… Show all'}
                </button>
            )}
        </section>
    );
};

export default CrewList;
