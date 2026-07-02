kullanılacak veriseti: CUB-200-2011
kaggle: https://www.kaggle.com/datasets/wenewone/cub2002011

ilk adım verisetini indirmek ve verisetinin nasıl kaydedildiğini ve veriseti üzerinde eda yapmamız gerek. hangi sınıftan kaç tane veri var vs bunu görmemiz gerek.

modeller:
DINOv2 (Large) - Model Kodu: dinov2_vitl14 - Kütüphane: PyTorch Hub / Facebook Research
OpenCLIP (Large) - Model Kodu: ViT-L-14 - Kütüphane: open_clip
ConvNeXt V2 (Large) - Model Kodu: convnextv2_large - Kütüphane: timm (Hugging Face)

projenin amacı:
bu projenin amacı zor bir veriseti üzerinde image encoder'ların performanslarını ölçmek. Yöntem şu olacak: verisetini her model ile ayrı ayrı embedding'e dönüştür. Bu embedding'leri önce ayrı ayrı olacak şekilde aynı mimarideki bir MLP'ye bağla. yani şöyle olacak. model1-2-3 için embedding oluştur ve kaydet, bu embeddingler ile ayrı ayrı embeddingleri eğit. 

todo:
- verisetini indir ve eda analizini yap
- modelleri indir ve test etmek için gpu üzerinde çalıştıran kodu yaz.
- her model için verisetinden embedding oluştur. 
- embedding'leri kullanarak mlp modellerini eğit. 

