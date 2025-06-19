// src/app/search/components/SearchInput.tsx
import React from "react";

interface Props {
    query: string;
    onQueryChange: (q: string) => void;
    onSearch: () => void;
}

const SearchInput: React.FC<Props> = ({ query, onQueryChange, onSearch }) => {
    const submit = (e: React.FormEvent) => {
        e.preventDefault();
        onSearch();
    };

    return (
        <form className="search-input-form" onSubmit={submit}>
            <input
                type="text"
                value={query}
                onChange={e => onQueryChange(e.target.value)}
                placeholder="Search users or movies…"
            />
            <button type="submit">Search</button>
        </form>
    );
};

export default SearchInput;
