import Link from 'next/link';

export default function HomePage() {
    return (
        <div className="flex flex-col items-center justify-center min-h-screen bg-gray-100">
            <h1 className="text-4xl font-bold text-gray-800 mb-6">Welcome to Our Application</h1>
            <p className="text-lg text-gray-600 mb-8">Get started by logging in or registering a new account.</p>
            <div>
                <Link href="/login">
                    <button className="inline-block px-6 py-3 mr-4 text-white bg-blue-500 rounded-md shadow hover:bg-blue-600 transition ease-in-out duration-150">
                        Login
                    </button>
                </Link>
                <Link href="/register">
                    <button className="inline-block px-6 py-3 text-white bg-green-500 rounded-md shadow hover:bg-green-600 transition ease-in-out duration-150">
                        Register
                    </button>
                </Link>
            </div>
        </div>
    );
}
