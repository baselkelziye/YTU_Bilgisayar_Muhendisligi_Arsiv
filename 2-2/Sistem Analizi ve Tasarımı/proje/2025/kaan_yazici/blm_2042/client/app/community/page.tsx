'use client';

import Link from "next/link";
import { useState, useEffect } from 'react';
import { Community } from '@/app/lib/definitions'
import clsx from 'clsx';
import { slugify } from '@/app/lib/actions';
import { Button } from '@/components/ui/button';

export default function CommunityPage() {
  const [communities, setCommunities] = useState<Community[]>([]);
  const [imageUrls, setImageUrls] = useState<{ [key: string]: string }>({});

  useEffect(() => {
    fetch(`/api/community/all`, {
      method: 'GET',
      credentials: 'include',
    }).then(async res => {
      const data = await res.json();

      if (res.ok) {
        const parsedCommunities = data.map((community: any) => ({
          id: community.id,
          name: community.communityName,
          description: community.communityDescription,
          imageId: community.mediaId,
          isJoined: community.isJoined,
        })) as Community[];

        setCommunities(parsedCommunities);
      }
    });
  }, []);

  useEffect(() => {
    communities.forEach(async (community, index) => {
      if (!community.imageId) return;

      try {
        const res = await fetch(`/api/media/${community.imageId}`);
        const blob = await res.blob();
        const url = URL.createObjectURL(blob);

        setImageUrls(prev => ({
          ...prev,
          [index]: url, // store by index
        }));
      } catch (err) {
        console.error(`Error loading image for index ${index}`, err);
      }
    });

    return () => {
      Object.values(imageUrls).forEach(URL.revokeObjectURL);
    };
  }, [communities]);

  const joinCommunity = (communityName: string) => {
    fetch(`/api/community/${communityName}/join`, {
      method: 'POST',
      credentials: 'include',
    });
  }

  return (
    <main className="max-w-5xl mx-auto p-6">
      <h1 className="text-4xl font-bold text-blue-600 mb-8">Communities</h1>
      <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6">
        {communities.map((community: Community, index: number) => (
          <Link key={index} href={`/community/${slugify(community.name)}`}
            className="group block bg-white rounded-2xl shadow-md hover:shadow-lg transition overflow-hidden">
            <div className="flex items-center p-6 space-x-4">
              <div className="p-2 bg-gray-100 rounded-full group-hover:bg-gray-200 transition">
                {imageUrls[index] ? (
                  <img
                    src={imageUrls[index]}
                    alt={community.name}
                    className="w-16 h-16 rounded-full object-cover"
                  />
                ) : (
                  <div className="w-16 h-16 bg-gray-200 rounded-full" />
                )}
              </div>
              <div>
                <h2 className="text-xl font-semibold text-gray-900 group-hover:text-blue-600 transition">{community.name}</h2>
                <p className="text-gray-600 mt-1">{community.description}</p>
              </div>
            </div>
            <div className="px-6 py-4 bg-gray-50 group-hover:bg-blue-50 transition">
              <Button
                onClick={() => joinCommunity(slugify(community.name))}
                className={clsx(
                  "w-full text-center text-sm font-medium py-2 rounded-lg transition",
                  community.isJoined
                    ? "bg-blue-100 text-blue-500 hover:bg-blue-600 hover:text-white"
                    : "bg-blue-500 text-blue-100 hover:bg-blue-600 hover:text-white"
                )}
              >
                {community.isJoined ? "Enter" : "Join"}
              </Button>
            </div>
          </Link>
        ))}
      </div>
    </main>
  );
}
