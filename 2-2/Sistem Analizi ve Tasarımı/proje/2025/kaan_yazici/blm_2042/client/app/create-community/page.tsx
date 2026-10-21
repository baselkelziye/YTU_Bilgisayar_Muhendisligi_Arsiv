import CommunityForm from "@/app/ui/create-community-form";

export default function CreateCommunityPage() {
  return (
    <div className="max-w-2xl mx-auto mt-12 bg-white shadow-xl rounded-xl px-6 py-8">
      <h1 className="text-3xl font-extrabold text-blue-600 mb-6">
        Create new community
      </h1>
      <p className="text-lg text-gray-600 mb-6">
        Fill the form to create a new community.
      </p>
      <CommunityForm />
    </div>
  );
}
