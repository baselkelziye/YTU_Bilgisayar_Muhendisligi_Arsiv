# backend/main.py
import os, shutil, tempfile, uuid, asyncio, sys, pathlib
import cv2, numpy as np
import torch
from PIL import Image
from torchvision import transforms
import torchvision

from fastapi import FastAPI, File, UploadFile, HTTPException, BackgroundTasks, Form
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from ultralytics import YOLO

# ────────────────────────── Sabitler ──────────────────────────
IMAGE_EXTS = {'.jpg', '.jpeg', '.png', '.bmp', '.tiff'}
STATIC_DIR = "static"
os.makedirs(STATIC_DIR, exist_ok=True)
CHECKPOINT = "checkpoint.pth"   # ResNet-18 DETR çıktınız
NUM_CLASSES = 2                 # 0 = bg, 1 = person

# ────────────────────────── FastAPI ──────────────────────────
app = FastAPI()
app.add_middleware(
    CORSMiddleware, allow_origins=["*"], allow_methods=["*"], allow_headers=["*"]
)
app.mount("/static", StaticFiles(directory=STATIC_DIR), name="static")

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# ────────────────────────── YOLOv8 ───────────────────────────
yolo_model = YOLO("best.pt")

# ─────────────────────── DETR (ResNet-18) ─────────────────────
def load_detr():
    """TorchVision >=0.15 varsa detr_resnet50; yoksa repo + ResNet-18."""
    try:
        return torchvision.models.detection.detr_resnet50(
            num_classes=NUM_CLASSES, pretrained=False
        )
    except AttributeError:
        repo_path = pathlib.Path(__file__).parent / "detr"
        if not repo_path.exists():
            raise RuntimeError(
                "TorchVision'da DETR yok ve 'backend/detr' klasörü bulunamadı.\n"
                "Repo'yu klonlayın: git clone https://github.com/facebookresearch/detr.git backend/detr"
            )
        sys.path.append(str(repo_path))
        from models import build_model                          # ✔ doğru modül
        from util.misc import nested_tensor_from_tensor_list    # ✔ helper

        # ▶ konfig nesnesi (tüm gerekli alanlar)
        args = type("Cfg", (), {})()
        args.backbone = "resnet18"
        args.num_classes = NUM_CLASSES
        args.position_embedding = "sine"
        args.hidden_dim = 256
        args.dropout = 0.1
        args.nheads = 8
        args.dim_feedforward = 2048
        args.enc_layers = 6
        args.dec_layers = 6
        args.pre_norm = False
        args.dilation = False
        args.masks = False
        args.aux_loss = False
        args.num_queries = 100
        args.device = "cuda" if torch.cuda.is_available() else "cpu"
        args.dataset_file = "custom"
        args.lr_backbone = 0
        args.pretrained_backbone = False   
        args.pretrained = False            


        # 2) CHECKPOINT’te kayıtlı arg’ları içe aktar
        ckpt_args = torch.load(CHECKPOINT, map_location="cpu").get("args")
        if ckpt_args:
            args.__dict__.update(ckpt_args.__dict__)
            print("[INFO] Checkpoint’ten argümanlar yüklendi")

        # ──▶ CUDA’sız ortam: kesin CPU’ya geçir ve indirmeyi kapat
        if not torch.cuda.is_available():
            args.device = "cpu"
        args.pretrained_backbone = False   # ✔ indirme durur
        args.pretrained = False            # ✔ (bazı sürümler bunu kullanıyor)

        # global device da tutarlı kalsın
        global device
        device = torch.device(args.device)


        # 3) model inşa
        model, _, _ = build_model(args)   # yalnız model'i al
        global nt_helper
        nt_helper = nested_tensor_from_tensor_list
        return model


print("[INFO] DETR modeli yükleniyor...")
detr_model = load_detr()
state = torch.load(CHECKPOINT, map_location="cpu")
state = state.get("model", state)
missing, unexpected = detr_model.load_state_dict(state, strict=False)
print(f"[INFO] DETR parametreleri yüklendi (missing={len(missing)}, unexpected={len(unexpected)})")

detr_model.to(device).eval()

# ─────────────────────── Inference Yardımcıları ───────────────────
transform = transforms.Compose(
    [
        transforms.ToTensor(),
        transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225]),
    ]
)

@torch.no_grad()
def detr_infer(bgr: np.ndarray, thr: float = 0.6) -> np.ndarray:
    rgb = cv2.cvtColor(bgr, cv2.COLOR_BGR2RGB)
    tensor = transform(Image.fromarray(rgb)).to(device)

    # TorchVision yolu
    if hasattr(torchvision.models.detection, "detr_resnet50"):
        out = detr_model([tensor])[0]
        scores = out["scores"].cpu().numpy()
        boxes = out["boxes"].cpu().numpy()[scores >= thr].astype(int)
    else:
        nt = nt_helper([tensor])
        outputs = detr_model(nt)
        prob = outputs["pred_logits"].softmax(-1)[0, :, 1]          # person skoru
        keep = prob >= thr
        boxes = outputs["pred_boxes"][0, keep].cpu()                # cxcywh 0–1
        boxes = torchvision.ops.box_convert(boxes, "cxcywh", "xyxy")
        h, w = bgr.shape[:2]
        boxes = (boxes * torch.tensor([w, h, w, h])).int().numpy()  # piksel

    for x1, y1, x2, y2 in boxes:
        cv2.rectangle(bgr, (x1, y1), (x2, y2), (0, 255, 0), 2)
    return bgr

def open_writer(path: str, fps: int, size: tuple[int, int]):
    w = cv2.VideoWriter(path, cv2.VideoWriter_fourcc(*"avc1"), fps, size)
    if not w.isOpened():
        w = cv2.VideoWriter(path, cv2.VideoWriter_fourcc(*"mp4v"), fps, size)
    if not w.isOpened():
        raise RuntimeError("VideoWriter açılamadı (avc1/mp4v).")
    return w

tasks: dict[str, dict] = {}

# ────────────────────────── /infer ────────────────────────────
@app.post("/infer")
async def infer(
    background_tasks: BackgroundTasks,
    media: UploadFile = File(...),
    useYolo: str = Form("0"),
    useDetr: str = Form("0"),
):
    useYolo = useYolo in {"1", "true", "True", "yes"}
    useDetr = useDetr in {"1", "true", "True", "yes"}

    print(f"[API] /infer  useYolo={useYolo}  useDetr={useDetr}  fname={media.filename}")
    suffix = os.path.splitext(media.filename)[1].lower() or ".mp4"
    tmp = tempfile.NamedTemporaryFile(delete=False, suffix=suffix)
    shutil.copyfileobj(media.file, tmp)
    tmp_path = tmp.name

    task_id = uuid.uuid4().hex
    tasks[task_id] = {"progress": 0, "outputs": {}}

    background_tasks.add_task(
        process_media, task_id, tmp_path, suffix, useYolo, useDetr
    )
    return {"task_id": task_id}

# ───────────────────── Arka plan işleme ──────────────────────
async def process_media(task_id, tmp_path, suffix, useYolo, useDetr):
    outs = {}
    try:
        # ─── resim
        if suffix in IMAGE_EXTS:
            img = cv2.imdecode(np.fromfile(tmp_path, np.uint8), cv2.IMREAD_COLOR)
            if useYolo:
                print(f"[TASK {task_id}] YOLO image infer")
                fn = f"{uuid.uuid4().hex}_yolo.png"
                cv2.imwrite(os.path.join(STATIC_DIR, fn), yolo_model(img)[0].plot())
                outs["yolo_output"] = f"/static/{fn}"
            if useDetr:
                print(f"[TASK {task_id}] DETR image infer")
                fn2 = f"{uuid.uuid4().hex}_detr.png"
                cv2.imwrite(os.path.join(STATIC_DIR, fn2), detr_infer(img))
                outs["detr_output"] = f"/static/{fn2}"
            print(f"[TASK {task_id}] outs={outs}")
            tasks[task_id].update(progress=100, outputs=outs)
            return

        # ─── video
        cap = cv2.VideoCapture(tmp_path)
        fps = cap.get(cv2.CAP_PROP_FPS) or 25
        w, h = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)), int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        total = int(cap.get(cv2.CAP_PROP_FRAME_COUNT)) or 1

        passes = int(useYolo) + int(useDetr)
        idx_pass = 0

        async def run_pass(writer, rel_path, fn, key):
            nonlocal idx_pass
            cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
            for i in range(total):
                ok, frame = cap.read()
                if not ok:
                    break
                writer.write(fn(frame))
                pct = ((idx_pass * total + i + 1) / (total * passes)) * 100
                tasks[task_id]["progress"] = int(pct)
                if i % 30 == 0:                     # ← LOG: her 30 karede bir
                    print(f"[{task_id}] {key} frame {i}/{total}  pct={pct:.1f}")
                await asyncio.sleep(0)
            writer.release()

            outs[key] = rel_path                   # ► önce çıktı kaydı
            tasks[task_id]["progress"] = 100       # ► sonra %100
            print(f"[{task_id}] {key} done, url={rel_path}")
            idx_pass += 1


        if useYolo:
            yfn = f"{uuid.uuid4().hex}_yolo.mp4"
            await run_pass(
                open_writer(os.path.join(STATIC_DIR, yfn), int(fps), (w, h)),
                f"/static/{yfn}",
                lambda f: yolo_model(f)[0].plot(),
                "yolo_output",
            )

        if useDetr:
            dfn = f"{uuid.uuid4().hex}_detr.mp4"
            await run_pass(
                open_writer(os.path.join(STATIC_DIR, dfn), int(fps), (w, h)),
                f"/static/{dfn}",
                detr_infer,
                "detr_output",
            )

        tasks[task_id].update(progress=100, outputs=outs)
        print(f"[TASK {task_id}] outs={outs}")
    finally:
        print(f"[TASK {task_id}] finished")
        try:
            os.remove(tmp_path)
        except PermissionError:
            print("[WARN] tmp dosyası kilitli, geç silinecek")

# ────────────────────────── /progress ─────────────────────────
@app.get("/progress/{task_id}")
def progress(task_id: str):
    d = tasks.get(task_id)
    if not d:
        raise HTTPException(404, "Görev bulunamadı")
    return d

# ─────────────────────────── Run ────────────────────────────
if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
