import PostForm from "@/app/ui/add-post";

export default function AddPostPage() {
  return (
    <div className="max-w-2xl mx-auto mt-12 bg-white shadow-xl rounded-xl px-6 py-8">
      <h1 className="text-3xl font-extrabold text-blue-500 mb-6">
        Create New Post
      </h1>
      <p className="text-lg text-gray-600 mb-6">
        What's on your mind?
      </p>
      <PostForm />
    </div>
  );
}
