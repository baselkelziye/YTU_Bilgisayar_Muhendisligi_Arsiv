"use client"
import React, { useState, useEffect } from 'react';
import { useRouter } from 'next/navigation';
import useAuthActions from '../services/AuthService';

interface Week {
    reading: string;
}

interface CourseData {
    title: string;
    description: string;
    price: number;
    instructorId: number | undefined;
    weeks: Week[];
}

const CourseCreateForm: React.FC = () => {
    const [title, setTitle] = useState<string>('');
    const [description, setDescription] = useState<string>('');
    const [price, setPrice] = useState<string>('');  
    const [weeks, setWeeks] = useState<Week[]>([{ reading: '' }]);
    const [instructorID, setInstructorID] = useState<number>();
    const router = useRouter();
    const { PostWithAuth } = useAuthActions();

    useEffect(() => {
        const storedUserId = localStorage.getItem('currentUserId');

        if (storedUserId) {
            setInstructorID(parseInt(storedUserId));
        }
    }, []);

    const handleWeekChange = (index: number, value: string) => {
        const newWeeks = weeks.map((week, idx) => idx === index ? { ...week, reading: value } : week);
        setWeeks(newWeeks);
    };

    const addWeek = () => {
        setWeeks([...weeks, { reading: '' }]);
    };

    const removeWeek = (index: number) => {
        setWeeks(weeks.filter((_, idx) => idx !== index));
    };

    const handleSubmit = async (event: React.FormEvent<HTMLFormElement>) => {
        event.preventDefault();

        const courseData: CourseData = {
            title,
            description,
            price: parseFloat(price),
            instructorId: instructorID,
            weeks
        };
        console.log("course data: ", courseData);

        const response = await PostWithAuth('/courses', courseData);

        if (response.ok) {
            alert('Submission successful!');
            router.push('/instructor-profile/');
        } else {
            alert('Failed to create the course.');
        }
    };

    return (
        <div className="container mx-auto p-4 bg-white rounded-lg shadow">
            <h1 className="text-xl font-bold text-gray-800 mb-4">Create New Course</h1>
            <form onSubmit={handleSubmit} className="space-y-4">
                <input type="text" value={title} onChange={(e) => setTitle(e.target.value)} placeholder="Course Title" required className="w-full p-2 border border-gray-300 rounded bg-gray-100 text-gray-900 focus:bg-white focus:text-gray-900 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent" />
                <textarea value={description} onChange={(e) => setDescription(e.target.value)} placeholder="Course Description" required className="w-full p-2 border border-gray-300 rounded bg-gray-100 text-gray-900 focus:bg-white focus:text-gray-900 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent" />
                <input type="number" value={price} onChange={(e) => setPrice(e.target.value)} placeholder="Price" required className="w-full p-2 border border-gray-300 rounded bg-gray-100 text-gray-900 focus:bg-white focus:text-gray-900 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent" />
                {weeks.map((week, index) => (
                    <div key={index} className="flex items-center space-x-2">
                        <textarea value={week.reading} onChange={(e) => handleWeekChange(index, e.target.value)} placeholder={`Reading for Week ${index + 1}`} required className="flex-1 p-2 border border-gray-300 rounded bg-gray-100 text-gray-900 focus:bg-white focus:text-gray-900 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent" />
                        <button type="button" onClick={() => removeWeek(index)} className="px-4 py-2 bg-red-500 text-white rounded hover:bg-red-600 focus:outline-none focus:ring-2 focus:ring-red-500 focus:ring-opacity-50">Remove</button>
                    </div>
                ))}
                <button type="button" onClick={addWeek} className="px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 focus:outline-none focus:ring-2 focus:ring-green-500 focus:ring-opacity-50">Add Week</button>
                <div className="flex justify-between mt-4">
                    <button type="submit" className="px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:ring-opacity-50">Submit</button>
                    <button type="button" onClick={() => router.push('/instructor-profile/')} className="px-4 py-2 bg-gray-500 text-white rounded hover:bg-gray-600 focus:outline-none focus:ring-2 focus:ring-gray-500 focus:ring-opacity-50">
                        Back to Profile
                    </button>
                </div>
            </form>
        </div>
    );
};

export default CourseCreateForm;
