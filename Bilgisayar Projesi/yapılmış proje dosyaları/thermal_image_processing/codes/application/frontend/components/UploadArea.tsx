'use client';
import { Card } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { useDropzone } from 'react-dropzone';
import { UploadCloud } from 'lucide-react';
import { motion } from 'framer-motion';

type Props = { onFileSelect: (file: File) => void };

export default function UploadArea({ onFileSelect }: Props) {
  const { getRootProps, getInputProps, isDragActive } = useDropzone({
    accept: { 'video/*': [], 'image/*': [] },
    maxFiles: 1,
    onDrop: (files) => onFileSelect(files[0]),
  });

  return (
    <motion.div
      initial={{ opacity: 1 }}
      animate={{ opacity: 1 }}
      className="w-full max-w-md"
    >
      <Card className="border-dashed border-2 border-gray-300 hover:border-indigo-500 transition-colors rounded-2xl p-8">
        <div
          {...getRootProps()}
          className="flex flex-col items-center justify-center h-60 cursor-pointer"
        >
          <input {...getInputProps()} />
          <UploadCloud className="h-16 w-16 text-indigo-400" />
          {isDragActive ? (
            <p className="mt-4 text-indigo-600 font-medium">Bırakın ve yükleyin</p>
          ) : (
            <p className="mt-4 text-gray-600">
              Video veya fotoğrafı buraya sürükle ya da{' '}
              <Button
                variant="link"
                className="text-indigo-600 font-semibold hover:underline"
              >
                seçin
              </Button>
            </p>
          )}
        </div>
      </Card>
    </motion.div>
  );
}
