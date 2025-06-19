// src/features/home/components/CardSlider.tsx
import React, { useRef } from 'react';
import clsx from 'clsx';
import '../style/CardSlider.css';

type CardSliderProps<T> = {
    items: T[];
    renderItem: (item: T) => React.ReactNode;
    className?: string;
};

export function CardSlider<T>({
                                  items,
                                  renderItem,
                                  className,
                              }: CardSliderProps<T>) {
    const sliderRef = useRef<HTMLDivElement>(null);
    const showNav = items.length > 1;

    const scroll = (offset: number) => {
        sliderRef.current?.scrollBy({ left: offset, behavior: 'smooth' });
    };

    return (
        <div className={clsx('card-slider', className)}>
            {showNav && (
                <button className="nav prev" onClick={() => scroll(-300)}>
                    ‹
                </button>
            )}
            <div className="slider-container" ref={sliderRef}>
                {items.map((item, i) => (
                    <div className="card" key={i}>
                        {renderItem(item)}
                    </div>
                ))}
            </div>
            {showNav && (
                <button className="nav next" onClick={() => scroll(300)}>
                    ›
                </button>
            )}
        </div>
    );
}
