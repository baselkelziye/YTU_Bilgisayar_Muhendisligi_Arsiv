import { useState } from 'react';
import { useForm } from 'react-hook-form';
import { zodResolver } from '@hookform/resolvers/zod';
import * as z from 'zod';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import {
  Dialog,
  DialogContent,
  DialogDescription,
  DialogFooter,
  DialogHeader,
  DialogTitle,
  DialogTrigger,
} from '@/components/ui/dialog';
import { useAuth } from '@/hooks/use-auth';
import api from '@/lib/api';
import type { User } from '@/types';

const profileSchema = z.object({
  firstName: z.string().min(2, 'First name must be at least 2 characters'),
  lastName: z.string().min(2, 'Last name must be at least 2 characters'),
  statusMessage: z.string().optional(),
  // profilePicture: z.string().optional(), // For future implementation
});

type ProfileFormValues = z.infer<typeof profileSchema>;

interface ProfileDialogProps {
  trigger?: React.ReactNode;
}

export function ProfileDialog({ trigger }: ProfileDialogProps) {
  const { user, login, token } = useAuth();
  const [open, setOpen] = useState(false);
  const [isLoading, setIsLoading] = useState(false);

  const { register, handleSubmit, formState: { errors } } = useForm<ProfileFormValues>({
    resolver: zodResolver(profileSchema),
    defaultValues: {
      firstName: user?.first_name || '',
      lastName: user?.last_name || '',
      statusMessage: user?.status_message || '',
    },
  });

  const onSubmit = async (data: ProfileFormValues) => {
    if (!user) return;
    setIsLoading(true);
    try {
      const response = await api.put(`/users/${user.id}`, data);
      if (response.data.success && response.data.data) {
        // Update local user state
        // We need the token to call login, assuming it hasn't changed
        if (token) {
             // The API returns the updated user object.
             // We need to map it back if the structure is different or just pass it.
             // Assuming response.data.data is the User object
             login(token, response.data.data); 
        }
        setOpen(false);
      }
    } catch (error) {
      console.error('Failed to update profile', error);
      // You might want to show a toast here
    } finally {
      setIsLoading(false);
    }
  };

  return (
    <Dialog open={open} onOpenChange={setOpen}>
      <DialogTrigger asChild>
        {trigger || <Button variant="outline">Edit Profile</Button>}
      </DialogTrigger>
      <DialogContent className="sm:max-w-[425px]">
        <DialogHeader>
          <DialogTitle>Edit Profile</DialogTitle>
          <DialogDescription>
            Make changes to your profile here. Click save when you're done.
          </DialogDescription>
        </DialogHeader>
        <form onSubmit={handleSubmit(onSubmit)} className="grid gap-4 py-4">
          <div className="grid grid-cols-4 items-center gap-4">
            <Label htmlFor="firstName" className="text-right">
              First Name
            </Label>
            <Input
              id="firstName"
              className="col-span-3"
              {...register('firstName')}
            />
            {errors.firstName && (
                <p className="col-start-2 col-span-3 text-sm text-red-500">{errors.firstName.message}</p>
            )}
          </div>
          <div className="grid grid-cols-4 items-center gap-4">
            <Label htmlFor="lastName" className="text-right">
              Last Name
            </Label>
            <Input
              id="lastName"
              className="col-span-3"
              {...register('lastName')}
            />
             {errors.lastName && (
                <p className="col-start-2 col-span-3 text-sm text-red-500">{errors.lastName.message}</p>
            )}
          </div>
          <div className="grid grid-cols-4 items-center gap-4">
            <Label htmlFor="statusMessage" className="text-right">
              Status
            </Label>
            <Input
              id="statusMessage"
              className="col-span-3"
              {...register('statusMessage')}
              placeholder="What's on your mind?"
            />
          </div>
          <DialogFooter>
            <Button type="submit" disabled={isLoading}>
              {isLoading ? 'Saving...' : 'Save changes'}
            </Button>
          </DialogFooter>
        </form>
      </DialogContent>
    </Dialog>
  );
}

