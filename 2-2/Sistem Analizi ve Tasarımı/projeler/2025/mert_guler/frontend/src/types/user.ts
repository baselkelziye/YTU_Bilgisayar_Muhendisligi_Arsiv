export interface User {
    uuid:string;
    username:string;
    firstName:string;
    lastName:string;
    biography: string | null,
    role: string | null,
    lastOnline: number,
    createdAt: number,
    profilePicture: string
}
