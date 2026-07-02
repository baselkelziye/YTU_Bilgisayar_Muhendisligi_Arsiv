import torch.nn as nn

class MLPClassifier(nn.Module):
    def __init__(self, input_dim, num_classes=200, hidden_dims=[512, 256]):
        super().__init__()
        layers = []
        in_dim = input_dim
        
        for h_dim in hidden_dims:
            layers.append(nn.Linear(in_dim, h_dim))
            layers.append(nn.ReLU())
            layers.append(nn.BatchNorm1d(h_dim))
            layers.append(nn.Dropout(0.5))
            in_dim = h_dim
            
        layers.append(nn.Linear(in_dim, num_classes))
        self.model = nn.Sequential(*layers)

    def forward(self, x):
        return self.model(x)

