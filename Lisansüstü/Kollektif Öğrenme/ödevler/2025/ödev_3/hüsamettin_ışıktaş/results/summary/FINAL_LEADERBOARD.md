# 🏆 Model Liderlik Tablosu

Oluşturulma Tarihi: 2025-12-19

| Sıra | Model | Reward Function | Accuracy (%) | Format Compliance (%) | Diff (Acc) |
|:----:|:---------------------|:------------------|---------------:|------------------------:|-------------:|
| 🥇 1 | simple               | simple            |            6.8 |                     1.6 |        +3.4 |
| 🥈 2 | long                 | long              |            4.4 |                     0.2 |        +1.0 |
| 🥉 3 | merged_simple_long   | merged            |            4.0 |                     0.6 |        +0.6 |
| 🔴 4 | Baseline (Eğitimsiz) | -                 |            3.4 |                     1.2 |         0.0 |
| 5 | turkish              | turkish           |            3.2 |                     0.0 |        -0.2 |
| 6 | short                | short             |            3.0 |                     0.4 |        -0.4 |
| 🔴 7 | connectives          | connectives       |            1.4 |                     0.0 |        -2.0 |

*Diff (Acc): Baseline modele göre doğruluk farkı.*

## Özet

- **En İyi Tekil Model:** simple (+3.4%)
- **En İyi Merged Model:** simple_long (+0.6%)
- **Baseline'ı Geçen:** 3 model (simple, long, merged_simple_long)
- **Baseline'ın Altında:** 3 model (turkish, short, connectives)
