import torch
import torch.nn as nn
import open_clip
import timm
from transformers import AutoImageProcessor, AutoModel

class BaseExtractor(nn.Module):
    def __init__(self, device):
        super().__init__()
        self.device = device
        self.output_dim = 0

    def get_transform(self):
        raise NotImplementedError

    def forward(self, x):
        raise NotImplementedError

class Dinov3Extractor(BaseExtractor):
    def __init__(self, model_name="facebook/dinov3-vitl16-pretrain-lvd1689m", device="cpu"):
        super().__init__(device)
        self.processor = AutoImageProcessor.from_pretrained(model_name)
        self.model = AutoModel.from_pretrained(model_name).to(device)
        self.model.eval()
        self.output_dim = self.model.config.hidden_size

    def get_transform(self):
        # Wrapper to make AutoImageProcessor compatible with dataset transform
        def transform(image):
            # processor returns dict with 'pixel_values' (1, C, H, W)
            # we need (C, H, W)
            return self.processor(images=image, return_tensors="pt")['pixel_values'][0]
        return transform

    def forward(self, x):
        # x is (B, C, H, W)
        with torch.no_grad():
            outputs = self.model(x)
            # Use CLS token (first token) as embedding
            return outputs.last_hidden_state[:, 0, :]

class Dinov2Extractor(BaseExtractor):
    def __init__(self, model_name="dinov2_vitl14", device="cpu"):
        super().__init__(device)
        # Load from PyTorch Hub
        # repo_or_dir='facebookresearch/dinov2', model=model_name
        self.model = torch.hub.load('facebookresearch/dinov2', model_name).to(device)
        self.model.eval()
        self.output_dim = 1024 # ViT-L-14 DINOv2 output dim
        
        # DINOv2 Transforms
        # Usually standard ImageNet mean/std
        from torchvision import transforms
        self.transform = transforms.Compose([
            transforms.Resize(256, interpolation=3),
            transforms.CenterCrop(224),
            transforms.ToTensor(),
            transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
        ])

    def get_transform(self):
        return self.transform

    def forward(self, x):
        return self.model(x)

class OpenCLIPExtractor(BaseExtractor):
    def __init__(self, model_name="ViT-L-14", pretrained="datacomp_xl_s13b_b90k", device="cpu"):
        super().__init__(device)
        self.model, _, self.transform = open_clip.create_model_and_transforms(
            model_name, pretrained=pretrained, device=device
        )
        self.model.eval()
        self.output_dim = 768 # ViT-L-14 usually 768 or check model config
        # Let's check dynamically if possible, or assume 768 for Large
        # For ViT-L-14, embedding dim is 768 in CLIP.
        
    def get_transform(self):
        return self.transform

    def forward(self, x):
        with torch.no_grad():
            features = self.model.encode_image(x)
            return features

class ConvNeXtExtractor(BaseExtractor):
    def __init__(self, model_name="convnextv2_large.fcmae_ft_in22k_in1k", device="cpu"):
        super().__init__(device)
        # Load using timm, remove classifier (num_classes=0)
        self.model = timm.create_model(model_name, pretrained=True, num_classes=0).to(device)
        self.model.eval()
        
        data_config = timm.data.resolve_model_data_config(self.model)
        self.transform = timm.data.create_transform(**data_config, is_training=False)
        self.output_dim = self.model.num_features

    def get_transform(self):
        return self.transform

    def forward(self, x):
        return self.model(x)

def get_extractor(name, device):
    if name == "dinov2":
        return Dinov2Extractor(device=device)
    elif name == "dinov3":
        return Dinov3Extractor(device=device)
    elif name == "openclip":
        return OpenCLIPExtractor(device=device)
    elif name == "siglip":
        # SigLIP is supported by OpenCLIP
        return OpenCLIPExtractor(model_name="ViT-L-16-SigLIP-256", pretrained="webli", device=device)
    elif name == "convnext":
        return ConvNeXtExtractor(device=device)
    else:
        raise ValueError(f"Unknown extractor: {name}")

