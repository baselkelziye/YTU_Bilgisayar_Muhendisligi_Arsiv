'use client';

import React, {useState, useEffect} from 'react';
import { useRouter, useParams } from 'next/navigation';
import { toast } from 'sonner';
import {ToggleGroup, ToggleGroupItem} from '@/components/ui/toggle-group';
import { tags } from '@/app/lib/definitions';
import { deslugify } from '@/app/lib/actions';

export default function NewPostPage() {
  const router = useRouter();
  const params = useParams();

  const communityName = params?.['id'] as string;

  const [username, setUsername] = useState("");
  const [message, setMessage] = useState("");
  const [image, setImage] = useState<File | null>(null);
  const [selectedTags, setSelectedTags] = useState<string[]>([]);
  const [homepageVisible, setHomepageVisible] = useState(false);

  useEffect(() => {
    fetch(`/api/user/profile`, {
      method: 'POST',
      credentials: 'include',
    }).then(async res => {
      const data = await res.json();

      if (res.ok) {
        setUsername(data.username);
      }
    });
  }, []);

  const handleSubmit = async (e: React.FormEvent<HTMLFormElement>) => {
    e.preventDefault();

    if (!message.trim() && !image) {
      toast.error("Lütfen bir mesaj yazın veya görsel ekleyin.");
      return;
    }

    const formData = new FormData();
    formData.append("username", username);
    formData.append("homepageVisible", String(homepageVisible));
    image && formData.append("postImage", image);
    message && formData.append("title", message);
    selectedTags.forEach(tag => formData.append("postCategories", tag));

    const res = await fetch(`/api/community/${deslugify(communityName)}/share-post`, {
      method: 'POST',
      credentials: 'include',
      body: formData
    });

    if (res.ok) {
      toast.success("Posted successfully!", {
        description: selectedTags.length > 0
          ? `Tags: ${selectedTags.join(", ")}`
          : "No tag chosen.",
      });
      setHomepageVisible(false);
      setMessage("");
      setImage(null);
      setSelectedTags([]);

      router.push(`/community/${communityName}`);
    }
  };

  return (
    <main className="max-w-2xl mx-auto py-8 px-4">
      <div className="bg-white rounded-2xl shadow-lg p-6 space-y-6">
        <h1 className="text-2xl font-bold text-blue-600">Create New Post</h1>
        <form
          onSubmit={handleSubmit}
          className="space-y-4 max-w-md mx-auto p-4 bg-white rounded-lg shadow-sm"
        >
      <textarea
        className="w-full p-3 border rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500 transition-all text-sm"
        placeholder="Start typing."
        value={message}
        onChange={(e) => setMessage(e.target.value)}
        rows={3}
      />

          <div className="flex flex-col items-center justify-between gap-2">
            <input
              type="file"
              accept="image/*"
              onChange={(e) => setImage(e.target.files?.[0] || null)}
              className="file:mr-2 file:py-1 file:px-3 file:rounded-md file:border file:bg-blue-50 file:text-blue-600 text-sm cursor-pointer"
            />
            {image && (
              <div className="mt-4 flex justify-center w-full">
                <img
                  src={URL.createObjectURL(image)}
                  alt="Profile Preview"
                  className="w-full h-32 object-contain rounded-lg border-2 border-gray-300 shadow-md"
                />
              </div>
            )}
          </div>

          <div>
            <p className="text-sm font-medium mb-2 text-gray-700">Choose tags for this post</p>
            <ToggleGroup
              type="multiple"
              value={selectedTags}
              onValueChange={setSelectedTags}
              className="flex flex-wrap gap-2"
            >
              {tags.map((tag) => (
                <ToggleGroupItem
                  key={tag}
                  value={tag}
                  className="px-10 py-2 text-sm rounded-full border border-gray-300 text-gray-600 hover:bg-blue-100 data-[state=on]:bg-blue-600 data-[state=on]:text-white"
                >
                  {tag}
                </ToggleGroupItem>
              ))}
            </ToggleGroup>
          </div>
          <button
            type="submit"
            className="w-full bg-blue-500 text-white py-2 rounded-md hover:bg-blue-600 transition-all text-sm"
          >
            Post
          </button>
        </form>
      </div>
    </main>
  );
}
