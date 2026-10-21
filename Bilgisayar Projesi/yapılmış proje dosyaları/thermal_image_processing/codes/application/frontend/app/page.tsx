// frontend/app/page.tsx
'use client';

import { useState, useEffect, useRef, memo } from 'react';
import UploadArea from '@/components/UploadArea';
import { Button } from '@/components/ui/button';
import { Progress } from '@/components/ui/progress';
import { ArrowRight } from 'lucide-react';
import { motion, AnimatePresence } from 'framer-motion';

/* ---------- Memoised preview ---------- */
const Preview = memo(
  ({ src, isVideo }: { src: string; isVideo: boolean }) =>
    isVideo ? (
      <video controls src={src} className="w-full rounded-2xl shadow-lg" />
    ) : (
      <img src={src} className="w-full rounded-2xl shadow-lg" />
    )
);
Preview.displayName = 'Preview';

export default function Home() {
  /* ───────── State ───────── */
  const [file, setFile] = useState<File | null>(null);
  const [previewUrl, setPreviewUrl] = useState<string | null>(null);

  /* model seçimleri */
  const [useYolo, setUseYolo] = useState(true);
  const [useDetr, setUseDetr] = useState(false);

  /* yükleme durumu */
  const [loading, setLoading] = useState(false);
  const [progress, setProgress] = useState(0);

  /* çıktı URL’leri */
  const [yoloUrl, setYoloUrl] = useState<string | null>(null);
  const [detrUrl, setDetrUrl] = useState<string | null>(null);

  /* arka plan */
  const [taskId, setTaskId] = useState<string | null>(null);
  const timerRef = useRef<NodeJS.Timeout | null>(null);
  const resultRef = useRef<HTMLDivElement>(null);

  /* ───────── Preview URL ───────── */
  useEffect(() => {
    if (!file) return;
    const url = URL.createObjectURL(file);
    setPreviewUrl(url);
    return () => URL.revokeObjectURL(url);
  }, [file]);

  const hasVideo   = !!file?.type.startsWith('video/');
  const hasResult  = Boolean(yoloUrl || detrUrl);
  const modelsChosen = useYolo || useDetr;         // en az bir model?

  /* ───────── Upload & Infer ───────── */
  const handleUpload = async () => {
    if (!file || !modelsChosen) return;

    setLoading(true);
    setProgress(0);
    setYoloUrl(null);
    setDetrUrl(null);

    const fd = new FormData();
    fd.append('media', file);
    if (useYolo) fd.append('useYolo', '1');
    if (useDetr) fd.append('useDetr', '1');

    const res = await fetch('http://localhost:8000/infer', {
      method: 'POST',
      body: fd,
    });
    const { task_id } = await res.json();
    setTaskId(task_id);

    /* polling */
    timerRef.current = setInterval(async () => {
      const pr = await fetch(
        `http://localhost:8000/progress/${task_id}`
      ).then(r => r.json());

      setProgress(pr.progress);

      const yoloReady = !!pr.outputs?.yolo_output;
      const detrReady = !!pr.outputs?.detr_output;

      const done =
        pr.progress >= 100 &&
        (!useYolo || yoloReady) &&
        (!useDetr || detrReady);

      if (done) {
        if (timerRef.current) clearInterval(timerRef.current);
        timerRef.current = null;

        if (useYolo && yoloReady)
          setYoloUrl(`http://localhost:8000${pr.outputs.yolo_output}`);

        if (useDetr && detrReady)
          setDetrUrl(`http://localhost:8000${pr.outputs.detr_output}`);

        setTimeout(() => {
          setLoading(false);
          resultRef.current?.scrollIntoView({ behavior: 'smooth' });
        }, 400);
      }
    }, 400);
  };

  /* ───────── Reset ───────── */
  const reset = () => {
    if (timerRef.current) clearInterval(timerRef.current);
    setFile(null);
    setPreviewUrl(null);
    setUseYolo(true);
    setUseDetr(false);
    setProgress(0);
    setYoloUrl(null);
    setDetrUrl(null);
    setTaskId(null);
    setLoading(false);
  };

  /* helpers */
  const InputPreview = () =>
    previewUrl && <Preview src={previewUrl} isVideo={hasVideo} />;

  /* === Arrow class helpers (açı + yer) === */
  const arrowUpperCls = [
    'absolute left-1/2 -translate-x-1/2 w-10 h-10 text-indigo-600',
    yoloUrl && detrUrl ? 'rotate-[-30deg]' : '',       // iki model: eğimli
    'top-[25%]',
  ].join(' ');

  const arrowLowerCls = [
    'absolute left-1/2 -translate-x-1/2 w-10 h-10 text-indigo-600',
    yoloUrl && detrUrl ? 'rotate-[30deg]' : '',        // iki model: eğimli
    yoloUrl ? 'bottom-[25%]' : 'top-[25%]',            // tek modelde yukarıda
  ].join(' ');

  /* ───────── JSX ───────── */
  return (
    <main className="min-h-screen bg-gray-50 p-6 flex flex-col items-center">
      {/* Upload / Preview */}
      {!hasResult && (
        <>
          {!file ? (
            <div className="flex flex-1 items-center justify-center w-full h-[70vh]">
              <UploadArea onFileSelect={setFile} />
            </div>
          ) : (
            <div className="flex w-full max-w-4xl gap-8 items-start">
              <motion.div
                initial={{ x: 0, opacity: 0 }}
                animate={{ x: -60, opacity: 1 }}
                transition={{ duration: 1, ease: 'easeOut' }}
                className="w-1/2"
              >
                <UploadArea onFileSelect={setFile} />
              </motion.div>

              <motion.div
                initial={{ x: 0, opacity: 0 }}
                animate={{ x: 60, opacity: 1 }}
                transition={{ duration: 1, ease: 'easeOut' }}
                className="w-1/2"
              >
                {InputPreview()}
              </motion.div>
            </div>
          )}

          {file && (
            <motion.div
              initial={{ opacity: 0 }}
              animate={{ opacity: 1 }}
              className="flex flex-col items-center space-y-4 mt-6"
            >
              <div className="flex items-center space-x-10">
                <label className="inline-flex items-center cursor-pointer">
                  <input
                    type="checkbox"
                    checked={useYolo}
                    onChange={() => setUseYolo(v => !v)}
                  />
                  <span className="ml-2">YOLO</span>
                </label>
                <label className="inline-flex items-center cursor-pointer">
                  <input
                    type="checkbox"
                    checked={useDetr}
                    onChange={() => setUseDetr(v => !v)}
                  />
                  <span className="ml-2">DETR</span>
                </label>
              </div>
              {!modelsChosen && (
                <p className="text-sm text-red-500">En az bir model seçin.</p>
              )}
              <Button
                onClick={handleUpload}
                className="px-8 py-3 rounded-full bg-indigo-600 hover:bg-indigo-700 text-white shadow-lg active:scale-95 transition"
                disabled={loading || !modelsChosen}
              >
                Etiketlemeyi Başlat
              </Button>
            </motion.div>
          )}

          {/* Loading */}
          <AnimatePresence>
            {loading && (
              <motion.div
                className="fixed inset-0 bg-black/60 backdrop-blur-sm flex items-center justify-center z-20"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                exit={{ opacity: 0 }}
              >
                <motion.div
                  initial={{ scale: 0.85 }}
                  animate={{ scale: 1 }}
                  exit={{ scale: 0.85 }}
                  className="bg-white p-6 rounded-2xl shadow-xl w-80"
                >
                  <p className="font-semibold text-center mb-4">İşleniyor...</p>
                  <Progress value={progress} className="h-3 rounded-full" />
                  <p className="text-sm font-mono text-center mt-2">
                    %{progress}
                  </p>
                </motion.div>
              </motion.div>
            )}
          </AnimatePresence>
        </>
      )}

      {/* Results */}
      {hasResult && (
        <motion.div
          ref={resultRef}
          initial={{ opacity: 0, y: 20 }}
          animate={{ opacity: 1, y: 0 }}
          className="flex flex-col items-center space-y-8 w-full max-w-4xl"
        >
          <div className="relative flex w-full gap-16">
            {/* Input */}
            <div className="w-1/2 flex flex-col justify-center">
              <h4 className="font-semibold mb-2 text-center">Girdi</h4>
              {InputPreview()}
            </div>

            {/* Outputs */}
            <div className="w-1/2 flex flex-col items-center gap-6">
              {yoloUrl && (
                <div className="w-full">
                  <h4 className="font-semibold mb-2 text-center">
                    YOLO Sonucu
                  </h4>
                  <Preview src={yoloUrl} isVideo={hasVideo} />
                </div>
              )}

              {detrUrl && (
                <div className="w-full">
                  <h4 className="font-semibold mb-2 text-center">
                    DETR Sonucu
                  </h4>
                  <Preview src={detrUrl} isVideo={hasVideo} />
                </div>
              )}
            </div>

            {/* Oklar */}
            {yoloUrl && (
              <ArrowRight strokeWidth={3} className={arrowUpperCls} />
            )}
            {detrUrl && (
              <ArrowRight strokeWidth={3} className={arrowLowerCls} />
            )}
          </div>

          <Button
            variant="outline"
            onClick={reset}
            className="px-10 py-3 rounded-full shadow hover:bg-indigo-600 hover:text-white"
          >
            Yeni İşlem
          </Button>
        </motion.div>
      )}
    </main>
  );
}
