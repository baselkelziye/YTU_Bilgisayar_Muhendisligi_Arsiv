from transformers.trainer_callback import ProgressCallback
import logging
import csv
import os

# Logları susturmak için
logging.getLogger("transformers.trainer").setLevel(logging.ERROR)

class CustomProgressCallback(ProgressCallback):
    """
    Standart ilerleme çubuğunu (tqdm) kullanır ancak metrikleri daha temiz gösterir.
    JSON logları basmaz.
    Ayrıca logları bir CSV dosyasına kaydeder.
    """
    def __init__(self, log_dir="logs"):
        super().__init__()
        self.log_dir = log_dir
        os.makedirs(log_dir, exist_ok=True)
        self.log_file = os.path.join(log_dir, "training_metrics.csv")
        self.completions_file = os.path.join(log_dir, "sample_completions.txt")
        
        # CSV dosyasını sıfırla ve başlıkları yaz
        with open(self.log_file, mode='w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["Step", "Loss", "Reward_Mean", "Reward_Std", "Format_Reward", "Accuracy_Reward"])

        # Completions dosyasını sıfırla
        with open(self.completions_file, mode='w') as f:
            f.write("=== SAMPLE COMPLETIONS ===\n\n")

    def on_log(self, args, state, control, logs=None, **kwargs):
        if self.training_bar is not None and logs is not None:
            # Metrikleri al (GRPO farklı isimler kullanabiliyor)
            loss = logs.get("loss", None)
            
            # Reward Mean bulma (Farklı olası anahtarları dene)
            reward_mean = logs.get("reward_mean", None)
            if reward_mean is None:
                reward_mean = logs.get("reward", None)
            if reward_mean is None:
                # rewards/grpo_reward_function/mean gibi uzun isimleri ara
                for key in logs.keys():
                    if "reward" in key and "mean" in key:
                        reward_mean = logs[key]
                        break
            
            # Reward Std bulma
            reward_std = logs.get("reward_std", None)
            if reward_std is None:
                 for key in logs.keys():
                    if "reward" in key and "std" in key:
                        reward_std = logs[key]
                        break
            
            # TODO: Eğer custom metrikler (format_reward, accuracy_reward) trainer'dan geliyorsa buraya ekle
            # Şimdilik placeholder
            format_reward = logs.get("format_reward", "")
            accuracy_reward = logs.get("accuracy_reward", "")

            # Açıklama metni
            desc = f"Step: {state.global_step} | "
            if loss is not None: desc += f"Loss: {loss:.4f} | "
            if reward_mean is not None: desc += f"R_Mean: {reward_mean:.4f}"

            self.training_bar.set_description(desc)

            # CSV'ye kaydet
            if loss is not None or reward_mean is not None:
                with open(self.log_file, mode='a', newline='') as f:
                    writer = csv.writer(f)
                    writer.writerow([
                        state.global_step, 
                        f"{loss:.4f}" if loss is not None else "", 
                        f"{reward_mean:.4f}" if reward_mean is not None else "",
                        f"{reward_std:.4f}" if reward_std is not None else "",
                        format_reward,
                        accuracy_reward
                    ])
        
        # Orijinal on_log metodunu çağırma (log basmaması için)
        # super().on_log(...) -> ÇAĞIRMIYORUZ
