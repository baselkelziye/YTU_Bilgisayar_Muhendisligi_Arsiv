import torch
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from torch.optim import AdamW
from torch.utils.data import TensorDataset, DataLoader
from transformers import BertTokenizer, BertForSequenceClassification

from ai.utils import load_data, convert_labels_to_numerical

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(device)

# Load data
data, labels = load_data("data", group=False, group_size=2, unique=True)

# Split data into train and test sets
train_data, test_data, train_labels, test_labels = train_test_split(data, labels, test_size=0.3, random_state=42)

# Convert labels to numerical form
labels_dict = sorted(list(dict.fromkeys(train_labels)))
label_mapping = {label: i for i, label in enumerate(labels_dict)}
train_labels = convert_labels_to_numerical(train_labels, label_mapping)
test_labels = convert_labels_to_numerical(test_labels, label_mapping)

# Load pre-trained BERT model and tokenizer
tokenizer = BertTokenizer.from_pretrained('ytu-ce-cosmos/turkish-base-bert-uncased')
model = BertForSequenceClassification.from_pretrained('ytu-ce-cosmos/turkish-base-bert-uncased', num_labels=10).to(
    device)

# Tokenize and prepare input data
MAX_LENGTH = max(len(max(train_data, key=len).split()), len(max(test_data, key=len).split()))
encoded_data_train = tokenizer(train_data, padding=True, truncation=True, max_length=MAX_LENGTH,
                               return_tensors='pt')

train_labels_tensor = torch.tensor(train_labels)
train_dataset = TensorDataset(encoded_data_train['input_ids'], encoded_data_train['attention_mask'],
                              train_labels_tensor)
train_loader = DataLoader(train_dataset, batch_size=128, shuffle=True)

# Training loop
optimizer = AdamW(model.parameters(), lr=5e-5)
loss_fn = torch.nn.CrossEntropyLoss()

model.train()
for epoch in range(10):
    total_loss = 0
    for i, batch in enumerate(train_loader):
        input_ids, attention_mask, labels = (t.to(device) for t in batch)
        optimizer.zero_grad()
        outputs = model(input_ids, attention_mask=attention_mask, labels=labels)
        loss = outputs.loss
        total_loss += loss.item()
        loss.backward()
        optimizer.step()
        # print(f"Batch: {i + 1}, Loss: {total_loss / len(train_loader)}")
    print(f"Epoch {epoch + 1}, Average Loss: {total_loss / len(train_loader)}")

encoded_data_test = tokenizer(test_data, padding=True, truncation=True, max_length=128, return_tensors='pt')

test_labels_tensor = torch.tensor(test_labels)
test_dataset = TensorDataset(encoded_data_test['input_ids'], encoded_data_test['attention_mask'],
                             test_labels_tensor)
test_loader = DataLoader(test_dataset, batch_size=128, shuffle=True)

model.eval()
total_correct = 0
total_samples = 0
predicted_labels = []
true_labels = []

with torch.no_grad():
    for batch in test_loader:
        input_ids, attention_mask, labels = (t.to(device) for t in batch)
        outputs = model(input_ids, attention_mask=attention_mask)
        _, predicted = torch.max(outputs.logits, 1)

        predicted_labels.extend(predicted.cpu().numpy())
        true_labels.extend(labels.cpu().numpy())

        total_samples += labels.size(0)
        total_correct += (predicted == labels).sum().item()
        print(f"Accuracy: {total_correct / total_samples}")

accuracy = total_correct / total_samples
print(f"Accuracy: {accuracy}")

# Compute confusion matrix
conf_matrix = confusion_matrix(true_labels, predicted_labels)
print("Confusion Matrix:")
print(conf_matrix)
