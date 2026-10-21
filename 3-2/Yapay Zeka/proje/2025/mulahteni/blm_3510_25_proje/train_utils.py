# train_utils.py
def get_model(model_type, input_shape, dropout):
    import torch.nn as nn

    class SimpleCNN(nn.Module):
        def __init__(self, dropout=0.0):
            super().__init__()
            self.conv = nn.Sequential(
                nn.Conv2d(1, 16, kernel_size=3, padding=1),
                nn.ReLU(),
                nn.MaxPool2d(2),
                nn.Conv2d(16, 32, kernel_size=3, padding=1),
                nn.ReLU(),
                nn.MaxPool2d(2)
            )
            self.fc = nn.Sequential(
                nn.Linear(32 * 6 * 6, 128),
                nn.ReLU(),
                nn.Dropout(dropout),
                nn.Linear(128, 1)
            )

        def forward(self, x):
            x = self.conv(x)
            x = x.view(x.size(0), -1)
            return self.fc(x)

    class MLP(nn.Module):
        def __init__(self, input_size, hidden_size=128, dropout=0.0):
            super().__init__()
            self.model = nn.Sequential(
                nn.Linear(input_size, hidden_size),
                nn.ReLU(),
                nn.Dropout(dropout),
                nn.Linear(hidden_size, hidden_size),
                nn.ReLU(),
                nn.Dropout(dropout),
                nn.Linear(hidden_size, 1)
            )

        def forward(self, x):
            return self.model(x)

    if model_type == "cnn":
        return SimpleCNN(dropout=dropout)
    elif model_type == "mlp":
        return MLP(input_size=input_shape, dropout=dropout)
    else:
        raise ValueError("Geçersiz model tipi")

def load_data(task_id, portion):
    from pathlib import Path
    import numpy as np
    from sklearn.model_selection import train_test_split

    path = f"tasks/task_{task_id}/data.npz"
    if not Path(path).exists():
        raise FileNotFoundError(f"{path} bulunamadı")

    data = np.load(path)
    X, y = data["X"], data["y"]

    used = int(len(X) * (portion / 100))
    X, y = X[:used], y[:used]

    return train_test_split(X, y, test_size=0.2, random_state=42)

def train_model(model_type, X_train, y_train, X_test, y_test,
                task_id, portion, dropout=0.0, weight_decay=0.0,
                epochs=20, lr=1e-3):

    import torch
    from torch.utils.data import DataLoader, TensorDataset
    import torch.nn as nn
    import matplotlib.pyplot as plt
    import pandas as pd
    from pathlib import Path

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    if model_type == "mlp":
        X_train = X_train.reshape(len(X_train), -1)
        X_test = X_test.reshape(len(X_test), -1)
        input_shape = X_train.shape[1]
    else:
        X_train = X_train[:, None, :, :]
        X_test = X_test[:, None, :, :]
        input_shape = None

    X_train, y_train = torch.tensor(X_train, dtype=torch.float32), torch.tensor(y_train, dtype=torch.float32).unsqueeze(1)
    X_test, y_test = torch.tensor(X_test, dtype=torch.float32), torch.tensor(y_test, dtype=torch.float32).unsqueeze(1)

    train_ds = TensorDataset(X_train, y_train)
    train_dl = DataLoader(train_ds, batch_size=32, shuffle=True)

    model = get_model(model_type, input_shape, dropout).to(device)
    optimizer = torch.optim.Adam(model.parameters(), lr=lr, weight_decay=weight_decay)
    loss_fn = nn.MSELoss()

    losses = []
    for epoch in range(epochs):
        model.train()
        epoch_loss = 0.0
        for xb, yb in train_dl:
            xb, yb = xb.to(device), yb.to(device)
            loss = loss_fn(model(xb), yb)

            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            epoch_loss += loss.item()

        losses.append(epoch_loss / len(train_dl))
        print(f"[Epoch {epoch+1}] Loss: {losses[-1]:.4f}")

    model.eval()
    with torch.no_grad():
        preds = model(X_test.to(device)).cpu().squeeze()
        true_vals = y_test.cpu().squeeze()
        mse = ((preds - true_vals) ** 2).mean().item()
        print(f"\n📊 Test MSE: {mse:.4f}")

    Path("outputs").mkdir(exist_ok=True)
    name_suffix = f"task{task_id}_{model_type}_{portion}pct_d{dropout}_wd{weight_decay}_lr{lr}"

    torch.save(model.state_dict(), f"outputs/{name_suffix}_model.pt")
    plt.figure()
    plt.plot(losses, label="Loss")
    plt.xlabel("Epoch")
    plt.ylabel("MSE")
    plt.title("Eğitim Kaybı")
    plt.legend()
    plt.savefig(f"outputs/{name_suffix}_loss.png")

    df = pd.DataFrame({"Gerçek": true_vals.numpy(), "Tahmin": preds.numpy()})
    df["Hata"] = (df["Tahmin"] - df["Gerçek"]).abs()
    df.to_csv(f"outputs/{name_suffix}_preds.csv", index=False)

