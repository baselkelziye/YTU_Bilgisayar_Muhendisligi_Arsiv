// src/app/search/components/SearchFilters.tsx
import React from "react";
import { SearchCategory } from "@/api/searchapi";

interface Props {
    category: SearchCategory;
    onCategoryChange: (c: SearchCategory) => void;
}

const SearchFilters: React.FC<Props> = ({ category, onCategoryChange }) => (
    <div>
        <h4>Show</h4>
        {Object.values(SearchCategory).map(cat => (
            <label key={cat}>
                <input
                    type="radio"
                    name="category"
                    value={cat}
                    checked={category === cat}
                    onChange={() => onCategoryChange(cat)}
                />
                {cat.charAt(0).toUpperCase() + cat.slice(1)}
            </label>
        ))}
    </div>
);

export default SearchFilters;
