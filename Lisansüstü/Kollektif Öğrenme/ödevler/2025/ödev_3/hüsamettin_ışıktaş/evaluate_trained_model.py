#!/usr/bin/env python3
"""
Sadece EĞİTİLMİŞ modeli değerlendiren script.

Bu script:
1. Base modeli ve tokenizer'ı yükler
2. Kaydedilmiş LoRA adaptörlerini (`standard_reward_model_v1`) modele uygular
3. Test setini yükleyip `evaluate_model` ile değerlendirir
4. Sonuçları CSV/JSON olarak kaydeder
"""

import torch
from peft import PeftModel

from src.config import data_config, model_config
from src.model_setup import setup_model_and_data
from src.evaluation import evaluate_model, compare_with_baseline


def main():
    print("=" * 60)
    print("EĞİTİLMİŞ MODEL DEĞERLENDİRME (EĞİTİM YOK)")
    print("=" * 60)

    # 1) Base model, tokenizer ve test setini yükle
    base_model, tokenizer, _formatted_train_dataset, test_dataset = setup_model_and_data()

    # 2) Kaydedilmiş LoRA adaptörlerini yükle
    print("\nEğitilmiş LoRA adaptörleri yükleniyor...")
    dtype = torch.float16 if (model_config.use_cuda and torch.cuda.is_available()) else torch.float32

    trained_model = PeftModel.from_pretrained(
        base_model,
        data_config.standard_reward_model_dir,
        dtype=dtype,
    )
    trained_model.eval()

    # 3) Değerlendirme
    trained_results, trained_accuracy, trained_format_accuracy = evaluate_model(
        trained_model, tokenizer, test_dataset
    )

    # 4) Baseline ile karşılaştırma
    compare_with_baseline(trained_accuracy, trained_format_accuracy)

    print("\n" + "=" * 60)
    print("EĞİTİLMİŞ MODEL DEĞERLENDİRME TAMAMLANDI")
    print("=" * 60)


if __name__ == "__main__":
    main()


