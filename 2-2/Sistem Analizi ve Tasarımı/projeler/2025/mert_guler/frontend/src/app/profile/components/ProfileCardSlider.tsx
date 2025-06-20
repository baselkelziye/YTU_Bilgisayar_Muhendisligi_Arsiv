// src/features/profile/components/ProfileCardSlider.tsx
import React, { useRef } from 'react'
import clsx from 'clsx'
import '../style/ProfileCardSlider.css'

type ProfileCardSliderProps<T> = {
    items: T[]
    renderItem: (item: T) => React.ReactNode
    className?: string
}

export function ProfileCardSlider<T>({
                                         items,
                                         renderItem,
                                         className,
                                     }: ProfileCardSliderProps<T>) {
    const sliderRef = useRef<HTMLDivElement>(null)
    const showNav = items.length > 1

    const scroll = (offset: number) => {
        sliderRef.current?.scrollBy({ left: offset, behavior: 'smooth' })
    }

    return (
        <div className={clsx('profile-card-slider', className)}>
            {showNav && (
                <button className="profile-nav profile-prev" onClick={() => scroll(-300)}>
                    ‹
                </button>
            )}
            <div className="profile-slider-container" ref={sliderRef}>
                {items.map((item, i) => (
                    <div className="profile-card" key={i}>
                        {renderItem(item)}
                    </div>
                ))}
            </div>
            {showNav && (
                <button className="profile-nav profile-next" onClick={() => scroll(300)}>
                    ›
                </button>
            )}
        </div>
    )
}
