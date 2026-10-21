#!/usr/bin/env python3
"""
evaluate_yolo_simple.py

Evaluate a YOLO model on a custom test dataset (YOLO-format labels) and compute simple detection metrics.
- Runs inference image-by-image with a single worker to avoid deadlocks.
- Suppresses verbose logs.
- Handles varying image resolutions by resizing input for inference.

Usage:
    python evaluate_yolo_simple.py \
      [--weights RUNS_DIR_OR_WEIGHTS] \
      --images processed/test/images \
      --labels processed/test/labels

If --weights points to a runs/detect/trainX directory, automatically uses its weights/best.pt.
Supports both .jpg and .png test images.
"""
import sys
import argparse
from pathlib import Path
from itertools import chain
from PIL import Image
from ultralytics import YOLO

def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument(
        '--weights', default='runs/detect/train10',
        help='Path to YOLO weights file or runs/detect/trainX directory (will use weights/best.pt)'
    )
    p.add_argument('--images',  required=True, help='Directory of test images')
    p.add_argument('--labels',  required=True, help='Directory of YOLO-format .txt labels')
    p.add_argument('--imgsz',   type=int,   default=640,   help='Inference image size')
    p.add_argument('--conf',    type=float, default=0.001, help='Confidence threshold')
    p.add_argument('--workers', type=int,   default=0,     help='Number of data loader workers')
    return p.parse_args()

def load_gt_boxes(label_file, img_w, img_h):
    """Load YOLO-format ground truth, convert to xyxy."""
    boxes = []
    for line in open(label_file, 'r').read().splitlines():
        if not line.strip():
            continue
        cls, xc, yc, w, h = map(float, line.split())
        x1 = (xc - w/2) * img_w
        y1 = (yc - h/2) * img_h
        x2 = (xc + w/2) * img_w
        y2 = (yc + h/2) * img_h
        boxes.append([x1, y1, x2, y2])
    return boxes

def iou(boxA, boxB):
    xA = max(boxA[0], boxB[0])
    yA = max(boxA[1], boxB[1])
    xB = min(boxA[2], boxB[2])
    yB = min(boxA[3], boxB[3])
    inter = max(0, xB - xA) * max(0, yB - yA)
    areaA = (boxA[2] - boxA[0]) * (boxA[3] - boxA[1])
    areaB = (boxB[2] - boxB[0]) * (boxB[3] - boxB[1])
    return inter / (areaA + areaB - inter + 1e-6)

def evaluate(preds, gts, iou_th=0.5):
    TP = FP = FN = 0
    for img_id, gt_boxes in gts.items():
        pred_boxes = preds.get(img_id, [])
        matched = set()
        for pb in pred_boxes:
            best_iou = 0
            best_j = -1
            for j, gb in enumerate(gt_boxes):
                if j in matched:
                    continue
                curr = iou(pb, gb)
                if curr > best_iou:
                    best_iou = curr
                    best_j = j
            if best_iou >= iou_th:
                TP += 1
                matched.add(best_j)
            else:
                FP += 1
        FN += len(gt_boxes) - len(matched)
    precision = TP / (TP + FP + 1e-6)
    recall    = TP / (TP + FN + 1e-6)
    f1        = 2 * precision * recall / (precision + recall + 1e-6)
    return TP, FP, FN, precision, recall, f1

def main():
    args = parse_args()

    # resolve weights
    w = Path(args.weights)
    if w.is_dir():
        weights_file = w / 'weights' / 'best.pt'
    else:
        weights_file = w
    if not weights_file.exists():
        print(f"[ERROR] Weights file not found: {weights_file}", file=sys.stderr)
        sys.exit(1)
    model = YOLO(str(weights_file))

    img_dir = Path(args.images)
    lbl_dir = Path(args.labels)

    gts = {}
    preds = {}

    # collect both jpg and png
    image_paths = list(chain(img_dir.glob('*.jpg'), img_dir.glob('*.png')))
    # sort by numeric stem
    try:
        image_paths = sorted(image_paths, key=lambda p: int(p.stem))
    except ValueError:
        image_paths = sorted(image_paths)

    for img_path in image_paths:
        # derive numeric ID if possible
        try:
            img_id = int(img_path.stem)
        except ValueError:
            img_id = img_path.stem

        img = Image.open(img_path)
        w_img, h_img = img.size

        # load ground truth
        label_file = lbl_dir / f"{img_id}.txt"
        gt_boxes = []
        if label_file.exists():
            gt_boxes = load_gt_boxes(label_file, w_img, h_img)
        gts[img_id] = gt_boxes

        # run inference quietly
        res = model.predict(
            source=str(img_path), imgsz=args.imgsz,
            conf=args.conf, workers=args.workers,
            verbose=False
        )
        # collect predicted boxes
        dets = []
        if res and res[0].boxes.data is not None:
            for *xyxy, conf, cls in res[0].boxes.data.tolist():
                dets.append(xyxy)
        preds[img_id] = dets

    TP, FP, FN, prec, rec, f1 = evaluate(preds, gts)
    print(f"\nResults on {len(gts)} images:")
    print(f"  True Positives : {TP}")
    print(f"  False Positives: {FP}")
    print(f"  False Negatives: {FN}")
    print(f"\nMetrics:")
    print(f"  Precision: {prec:.4f}")
    print(f"  Recall   : {rec:.4f}")
    print(f"  F1 score : {f1:.4f}")

if __name__ == '__main__':
    main()
