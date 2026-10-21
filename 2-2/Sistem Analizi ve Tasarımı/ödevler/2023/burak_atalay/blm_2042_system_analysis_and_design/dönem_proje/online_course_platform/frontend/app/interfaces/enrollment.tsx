import { WeekResponse } from '@/app/interfaces/course';
export interface UserProgress {
    id: number;
    week: WeekResponse;
    status: boolean;
}

export interface Enrollment {
    id: number;
    courseId: number;
    studentId: number;
    date: Date;
    userProgresses?: UserProgress[];
}