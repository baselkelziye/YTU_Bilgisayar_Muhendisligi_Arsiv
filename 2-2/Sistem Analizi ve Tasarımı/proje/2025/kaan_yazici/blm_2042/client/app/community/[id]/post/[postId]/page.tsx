// app/community/[id]/post/[postId]/page.tsx

import Link from 'next/link';
import { notFound } from 'next/navigation';
import { HeartIcon } from 'lucide-react';

type Post = {
  id: string;
  author: string;
  avatar: string;
  title: string;
  content: string;
  date: string;
  likes: number;
  comments: number;
};

type Comment = {
  author: string;
  content: string;
  date: string;
};

const allPosts: Record<string, Post[]> = {
  gaming: [
    {
      id: '1', author: 'Admin', avatar: 'https://i.pravatar.cc/150?u=gaming',
      title: 'En iyi 2025 oyunları',
      content: 'Bu yılın en iyi oyunları şunlardı...',
      date: '2025-01-01', likes: 120, comments: 34,
    },
    {
      id: '2', author: 'User123', avatar: 'https://i.pravatar.cc/150?u=gaming2',
      title: 'LoL vs Valorant',
      content: 'Hangisi daha rekabetçi?',
      date: '2025-02-15', likes: 78, comments: 12,
    },
  ],
};

const allComments: Record<string, Comment[]> = {
  '1': [
    { author: 'User1', content: 'Bu oyun gerçekten harika!', date: '2025-01-02' },
    { author: 'User2', content: 'Katılıyorum, 2025’in en iyisi!', date: '2025-01-03' },
  ],
  '2': [
    { author: 'User1', content: 'Valorant mı, LoL mi?', date: '2025-02-16' },
  ],
};

export default async function PostPage(props: { params: Promise<{ id: string, postId: string }> }) {
  const { id, postId } = await props.params;

  const post = allPosts[id]?.find(p => p.id === postId);
  if (!post) return notFound();
  const comments = allComments[postId] ?? [];

  return (
    <main className="max-w-xl mx-auto py-8 px-6 space-y-8">
      {/* Post Card */}
      <article className="bg-white rounded-2xl shadow-lg overflow-hidden">
        <header className="flex items-center px-6 py-4 space-x-4">
          <img src={post.avatar} alt={post.author} className="w-14 h-14 rounded-full object-cover" />
          <div>
            <h1 className="text-xl font-semibold text-gray-900">{post.author}</h1>
            <time className="text-sm text-gray-500">{post.date}</time>
          </div>
        </header>
        <div className="px-6 pb-4 space-y-4">
          <h2 className="text-2xl font-bold text-gray-800">{post.title}</h2>
          <p className="text-gray-700 leading-relaxed">{post.content}</p>
        </div>
        <footer className="flex justify-start items-center px-6 py-3 bg-gray-50 space-x-6">
          <button className="flex items-center space-x-2 text-gray-600 hover:text-red-500 transition">
            <HeartIcon size={20} />
            <span className="text-sm font-medium">{post.likes}</span>
          </button>
        </footer>
      </article>

      {/* Comments Section */}
      <section className="space-y-6">
        <h3 className="text-lg font-semibold text-gray-800">Yorumlar ({comments.length})</h3>
        {comments.map((c, idx) => (
          <div key={idx} className="bg-gray-50 rounded-xl p-4">
            <div className="flex items-center space-x-3 mb-1">
              <span className="font-semibold text-gray-900">{c.author}</span>
              <time className="text-xs text-gray-500">{c.date}</time>
            </div>
            <p className="text-gray-700">{c.content}</p>
          </div>
        ))}
      </section>

      {/* Comment Form */}
      <section className="bg-white rounded-2xl shadow-sm p-6 space-y-4">
        <h3 className="text-lg font-semibold text-gray-800">Yeni Yorum</h3>
        <form className="space-y-3">
          <textarea
            placeholder="Yorumunuzu yazın..."
            className="w-full border border-gray-200 rounded-lg p-3 focus:outline-none focus:ring-2 focus:ring-blue-200"
            rows={3}
          />
          <button type="submit" className="w-full text-center px-5 py-2 bg-blue-600 text-white rounded-lg hover:bg-blue-700 transition">
            Gönder
          </button>
        </form>
      </section>

      {/* Back to Community */}
      <Link href={`/community/${id}`} className="inline-block text-blue-600 hover:underline">
        ← Topluluğa Dön
      </Link>
    </main>
  );
}
