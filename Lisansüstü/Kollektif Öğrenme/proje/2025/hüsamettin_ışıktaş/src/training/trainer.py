import torch
import torch.nn as nn
from tqdm import tqdm
import os

def train_model(model, train_loader, val_loader, epochs, lr, device, save_path):
    model = model.to(device)
    optimizer = torch.optim.Adam(model.parameters(), lr=lr)
    criterion = nn.CrossEntropyLoss()
    
    best_acc = 0.0
    
    for epoch in range(epochs):
        model.train()
        running_loss = 0.0
        correct = 0
        total = 0
        
        pbar = tqdm(train_loader, desc=f"Epoch {epoch+1}/{epochs}")
        for batch in pbar:
            # Move inputs to device
            # Batch is a dict from loader
            labels = batch['labels'].to(device)
            
            # Prepare inputs for model
            inputs = {}
            for k, v in batch.items():
                if k != 'labels':
                    inputs[k] = v.to(device)
            
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            
            running_loss += loss.item()
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
            
            pbar.set_postfix({'loss': running_loss/total, 'acc': correct/total})
            
        # Validation
        val_acc = evaluate_model(model, val_loader, device)
        print(f"Validation Accuracy: {val_acc:.4f}")
        
        if val_acc > best_acc:
            best_acc = val_acc
            torch.save(model.state_dict(), save_path)
            print(f"Saved best model to {save_path}")

def evaluate_model(model, loader, device):
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for batch in loader:
            labels = batch['labels'].to(device)
            inputs = {}
            for k, v in batch.items():
                if k != 'labels':
                    inputs[k] = v.to(device)
            
            outputs = model(inputs)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
            
    return correct / total

