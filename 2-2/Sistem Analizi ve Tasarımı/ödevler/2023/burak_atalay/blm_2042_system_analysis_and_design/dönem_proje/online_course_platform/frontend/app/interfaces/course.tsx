export interface WeekResponse {
    id: number
    reading: string;
}

export interface CourseResponse {
    id: number;
    title: string;
    description: string;
    instructorId: number;
    instructorName: string;
    duration: number;
    price: number;
    enrollmentCount: number;
    weeks: WeekResponse[];
}

