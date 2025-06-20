// src/features/genre/components/SearchBar.tsx
import React from 'react';
import '../style/SearchBar.css';

interface Props {
    value: string;
    onChange: (v: string) => void;
    placeholder: string;
}

export const SearchBar: React.FC<Props> = ({ value, onChange, placeholder}) => (
    <div className="search-bar">
        <input
            type="text"
            placeholder= {placeholder}
            value={value}
            onChange={e => onChange(e.target.value)}
        />
    </div>
);
