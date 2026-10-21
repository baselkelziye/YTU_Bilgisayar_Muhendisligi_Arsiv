#!/usr/bin/env python3
"""
find_best_conf.py

Run YOLO inference once (at a low conf), then grid-search over confidence thresholds
to find the one that maximizes F1 on your test set.

Usage:
    python find_best_conf.py \
      --weights runs/detect/train10 \
      --images processed/test/images \
      --labels processed/test/labels \
      [--imgsz 640] [--workers 0] [--iou-th 0.50] [--step 0.01]
"""
import sys
import argparse
from pathlib import Path
from itertools import chain
from PIL import Image
from ultralytics import YOLO

def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument('--weights', required=True,
        help='Path to weights file or runs/detect/trainX directory')
    p.add_argument('--images',  required=True, help='Dir of test images')
    p.add_argument('--labels',  required=True, help='Dir of YOLO .txt labels')
    p.add_argument('--imgsz',   type=int,   default=640, help='Inference size')
    p.add_argument('--workers', type=int,   default=0,   help='DataLoader workers')
    p.add_argument('--iou-th',  type=float, default=0.50,help='IoU threshold for TP/FP')
    p.add_argument('--step',    type=float, default=0.01,help='Grid step for conf sweep')
    return p.parse_args()

def load_gt(label_path, w, h):
    boxes = []
    for L in open(label_path).read().splitlines():
        if not L: continue
        cls, xc, yc, bw, bh = map(float, L.split())
        x1 = (xc - bw/2)*w;  y1 = (yc - bh/2)*h
        x2 = (xc + bw/2)*w;  y2 = (yc + bh/2)*h
        boxes.append([x1,y1,x2,y2])
    return boxes

def iou(a, b):
    xA = max(a[0],b[0]);  yA = max(a[1],b[1])
    xB = min(a[2],b[2]);  yB = min(a[3],b[3])
    inter = max(0, xB-xA)*max(0, yB-yA)
    A = (a[2]-a[0])*(a[3]-a[1]); B = (b[2]-b[0])*(b[3]-b[1])
    return inter/(A+B-inter+1e-6)

def eval_thresh(preds, gts, iou_th):
    TP=FP=FN=0
    for img_id, gt in gts.items():
        pr = preds[img_id]
        matched = set()
        for pb in pr:
            best_i=0; best_j=-1
            for j,gb in enumerate(gt):
                if j in matched: continue
                cur = iou(pb,gb)
                if cur>best_i: best_i, best_j = cur,j
            if best_i>=iou_th:
                TP+=1; matched.add(best_j)
            else:
                FP+=1
        FN += len(gt)-len(matched)
    P = TP/(TP+FP+1e-6)
    R = TP/(TP+FN+1e-6)
    F1=2*P*R/(P+R+1e-6)
    return P,R,F1

def main():
    args = parse_args()

    # resolve weights
    w = Path(args.weights)
    wfile = w if w.is_file() else w/'weights'/'best.pt'
    if not wfile.exists():
        print(f"[ERROR] Weights not found: {wfile}", file=sys.stderr)
        sys.exit(1)

    model = YOLO(str(wfile))
    img_dir, lbl_dir = Path(args.images), Path(args.labels)

    # gather images (.jpg/.png) sorted by numeric stem if possible
    files = list(chain(img_dir.glob('*.jpg'), img_dir.glob('*.png')))
    try:
        files = sorted(files, key=lambda p:int(p.stem))
    except:
        files = sorted(files)

    # 1) Run inference once at tiny conf to collect **all** dets
    raw_preds, gts = {}, {}
    for img_path in files:
        img_id = img_path.stem
        img = Image.open(img_path); w_img,h_img = img.size

        # load GT
        lf = lbl_dir/f"{img_id}.txt"
        gts[img_id] = load_gt(lf, w_img,h_img) if lf.exists() else []

        # run inference
        res = model.predict(
            source=str(img_path),
            imgsz=args.imgsz,
            conf=0.001,   # very low
            workers=args.workers,
            verbose=False
        )
        dets = []
        if res and res[0].boxes.data is not None:
            for *xyxy,conf,cls in res[0].boxes.data.tolist():
                dets.append((xyxy,conf))
        raw_preds[img_id] = dets

    # 2) Grid-search conf thresholds
    best, best_conf = 0,0
    c = 0.0
    while c<=1.0:
        # filter preds by current conf
        preds = {i: [xy for xy,cf in raw_preds[i] if cf>=c]
                 for i in raw_preds}
        P,R,F1 = eval_thresh(preds, gts, args.iou_th)
        if F1>best:
            best, best_conf = F1, c
            bestP,bestR = P,R
        c = round(c+args.step, 4)

    print(f"\nOptimal conf = {best_conf:.2f}")
    print(f"Precision = {bestP:.4f}, Recall = {bestR:.4f}, F1 = {best:.4f}")

if __name__=='__main__':
    main()

