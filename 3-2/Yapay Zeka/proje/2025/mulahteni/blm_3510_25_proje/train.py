# train.py
import argparse
from train_utils import load_data, train_model

def main():
    parser = argparse.ArgumentParser(description="YSA Eğitim Aracı")
    parser.add_argument('--task', type=int, required=True, choices=[1, 2, 3, 4, 5],
                        help='Görev numarası (1-5)')
    parser.add_argument('--model', type=str, required=True, choices=["mlp", "cnn"],
                        help='Kullanılacak model tipi')
    parser.add_argument('--portion', type=int, required=True, choices=[25, 50, 100],
                        help='Verinin ne kadarı kullanılacak (yüzde)')
    parser.add_argument('--dropout', type=float, default=0.0,
                        help='Dropout oranı (varsayılan: 0.0)')
    parser.add_argument('--wd', type=float, default=0.0,
                        help='Weight decay (L2) oranı (varsayılan: 0.0)')
    parser.add_argument('--epochs', type=int, default=50,
                        help='Eğitim için epoch sayısı (varsayılan: 20)')
    parser.add_argument('--lr', type=float, default=1e-3,
                        help='Öğrenme oranı (varsayılan: 0.001)')

    args = parser.parse_args()

    # Veri yükle ve parçala
    X_train, X_test, y_train, y_test = load_data(
        task_id=args.task,
        portion=args.portion
    )

    # Model eğitimi
    train_model(
        model_type=args.model,
        X_train=X_train,
        y_train=y_train,
        X_test=X_test,
        y_test=y_test,
        task_id=args.task,
        portion=args.portion,
        dropout=args.dropout,
        weight_decay=args.wd,
        epochs=args.epochs,
        lr=args.lr
    )

if __name__ == "__main__":
    main()