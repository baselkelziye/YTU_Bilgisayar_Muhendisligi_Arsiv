"""
Konfigürasyon ayarları
Tüm hyperparameter'lar ve model ayarları burada merkezileştirilmiştir.
"""

from dataclasses import dataclass
from typing import Optional


@dataclass
class ModelConfig:
    """Model konfigürasyonu"""
    model_name: str = "ytu-ce-cosmos/turkish-gpt2-large-750m-instruct-v0.1"
    use_cuda: bool = True
    dtype: str = "float16"  # float16, float32, bfloat16


@dataclass
class LoRAConfig:
    """LoRA konfigürasyonu"""
    r: int = 64  # LoRA rank (16 -> 64 artırıldı)
    lora_alpha: int = 128  # LoRA alpha (32 -> 128 artırıldı)
    lora_dropout: float = 0.05
    target_modules: list = None  # None ise otomatik belirlenir
    bias: str = "none"
    
    def __post_init__(self):
        if self.target_modules is None:
            # GPT-2 için varsayılan modüller
            self.target_modules = ["c_attn", "c_proj", "c_fc"]


@dataclass
class TrainingConfig:
    """GRPO eğitim konfigürasyonu"""
    # Generation ayarları
    num_generations: int = 4  # 4'ten 2'ye düşürüldü: daha hızlı eğitim, GRPO için yeterli çeşitlilik
    max_completion_length: int = 512
    temperature: float = 0.8
    top_p: float = 0.9
    
    # Training ayarları
    learning_rate: float = 2e-5  # 1e-5 -> 2e-5 artırıldı
    per_device_train_batch_size: int = 4
    gradient_accumulation_steps: int = 4
    num_train_epochs: int = 2 
    max_steps: Optional[int] = None
    
    # Logging ve kaydetme
    logging_steps: int = 20
    save_steps: int = 100
    save_total_limit: int = 3
    output_dir: str = "./grpo_simple_reward_model"
    report_to: str = "none"  # "wandb" yaparak WandB'ye log gönderebilirsiniz
    
    # Mixed precision
    bf16: bool = False  # Otomatik belirlenir
    fp16: bool = False  # Otomatik belirlenir
    
    # Dummy run için özel ayarlar
    dummy_max_steps: int = 1
    dummy_num_generations: int = 2
    dummy_max_completion_length: int = 256
    dummy_output_dir: str = "./grpo_dummy_checkpoints"


@dataclass
class DataConfig:
    """Veri seti konfigürasyonu"""
    train_dataset_path: str = "data/train_dataset"
    test_dataset_path: str = "data/test_dataset"
    results_dir: str = "results"
    models_dir: str = "./models"
    standard_reward_model_dir: str = "./models/simple_reward_model_v1"
    
    # Test modu: Veri setinin %10'u ile hızlı test
    use_test_mode: bool = False  # True ise veri setinin %10'unu kullan
    test_mode_fraction: float = 0.1  # Test modunda kullanılacak veri oranı


@dataclass
class EvaluationConfig:
    """Değerlendirme konfigürasyonu"""
    max_new_tokens: int = 768  # Baseline'da maksimum ~727 token görüldü, güvenli marj için 768
    temperature: float = 0.7
    baseline_summary_path: str = "results/baseline/baseline_summary.json"
    comparison_results_path: str = "results/training_comparison_results.json"
    trained_results_csv_path: str = "results/trained_model_results.csv"
    trained_results_json_path: str = "results/trained_model_results.json"


# Global config instance'ları
model_config = ModelConfig()
lora_config = LoRAConfig()
training_config = TrainingConfig()
data_config = DataConfig()
evaluation_config = EvaluationConfig()
