import ProfileSettingsForm from "@/app/ui/profile-settings-form";

export default function SettingsPage() {
  return (
    <div className="max-w-3xl mx-auto mt-12 px-6 py-8 bg-white shadow-lg rounded-xl">
      <h1 className="text-3xl font-extrabold text-blue-600 mb-8">
        Profile Settings
      </h1>
      <ProfileSettingsForm />
    </div>
  );
}
