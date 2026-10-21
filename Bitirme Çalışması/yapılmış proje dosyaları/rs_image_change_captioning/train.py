import torch
from helpers import save_batch_metrics


def train_rsicd(train_dataloader, valid_dataloader, model, optimizer, device, epoch, model_name):

    model.train()  # Training mode of model for training dataset
    total_train_loss = 0
    avg_train_loss = 0
    #       Training Section
    for idx, batch in enumerate(train_dataloader):
        input_ids = batch.pop("input_ids").to(device)  # take captions, it has 5 captions
        pixel_values = batch.pop("pixel_values").to(device)  # take imgs
        labels = batch["labels"].to(device)
        attention_mask = batch["attention_mask"].to(device)

        split_input_ids = torch.unbind(input_ids, dim=1)  # split tensor into 5 chunks to separate captions
        split_labels = torch.unbind(labels, dim=1)
        split_attention_mask = torch.unbind(attention_mask, dim=1)

        batch_num = idx * 5 # her batch'de 5 adet görsel eğitildiği için batch number 5'in katları olarak artar

        optimizer.zero_grad()
        for input_id, labels, attention_mask in zip(split_input_ids, split_labels, split_attention_mask):  #input_id is each caption
            outputs = model(input_ids=input_id, pixel_values=pixel_values, labels=labels, attention_mask=attention_mask)

            loss = outputs.loss
            total_train_loss += loss.item()

            batch_num += 1

            avg_train_loss = total_train_loss / batch_num

            print("Current Training Loss: {}, Average Training Loss: {}".format(loss.item(), avg_train_loss))

            loss.backward()
            save_batch_metrics(epoch, idx+1, loss.item(), avg_train_loss, model_name)

        optimizer.step() # bir tab boslugu geri gidebilir

        print("Batch number {} is finished".format(idx + 1))


    #       Validation Section
    model.eval()  # Evaluation mode of model for validation dataset
    total_valid_loss = 0
    avg_valid_loss = 0

    with torch.no_grad():
        for idx, batch in enumerate(valid_dataloader):
            input_ids = batch.pop("input_ids").to(device)
            pixel_values = batch.pop("pixel_values").to(device)
            labels = batch["labels"].to(device)
            attention_mask = batch["attention_mask"].to(device)

            split_input_ids = torch.unbind(input_ids, dim=1)
            split_labels = torch.unbind(labels, dim=1)
            split_attention_mask = torch.unbind(attention_mask, dim=1)

            # batch_num = idx+1
            batch_num = idx * 5  # her batch'de 5 adet görsel eğitildiği için batch number 5'in katları olarak artar

            for input_id, labels, attention_mask in zip(split_input_ids, split_labels, split_attention_mask):
                outputs = model(input_ids=input_id, pixel_values=pixel_values, labels=labels, attention_mask=attention_mask)

                loss = outputs.loss
                total_valid_loss += loss.item()

                batch_num += 1
                avg_valid_loss = total_valid_loss / batch_num

                print("Current Validation Loss: {}, Average Validation Loss: {}".format(loss.item(), avg_valid_loss))


    #  Save model after each epoch
    torch.save({
        'epoch': epoch,
        'model_state_dict': model.state_dict(),
        'optimizer_state_dict': optimizer.state_dict(),
    }, f'../saved_models/rsicd/{model_name}model_epoch_{epoch}.pth')


    print("Epoch {} finished. Train loss: {} and Validation loss: {}".format(epoch, avg_train_loss, avg_valid_loss))
    return avg_train_loss, avg_valid_loss, model, optimizer

def train_levir_cc(train_dataloader, valid_dataloader, operation, model, optimizer, device, epoch, model_name):
    model.train()  # Training mode of model for training dataset
    total_train_loss = 0
    avg_train_loss = 0

    #       Training Section
    for idx, batch in enumerate(train_dataloader):
        input_ids = batch.pop("input_ids").to(device)  # take captions, it has 5 captions
        pixel_values_pre = batch.pop("pre_img").to(device)  # take imgs
        pixel_values_post = batch.pop("post_img").to(device)  # take imgs
        labels = batch["labels"].to(device)
        attention_mask = batch["attention_mask"].to(device)

        split_input_ids = torch.unbind(input_ids, dim=1)  # split tensor into 5 chunks to separate captions
        split_labels = torch.unbind(labels, dim=1)
        split_attention_mask = torch.unbind(attention_mask, dim=1)

        batch_num = idx * 5 # her batch'de 5 adet görsel eğitildiği için batch number 5'in katları olarak artar

        optimizer.zero_grad()
        for input_id, labels, attention_mask in zip(split_input_ids, split_labels, split_attention_mask):
            outputs = model(pixel_values_pre=pixel_values_pre, pixel_values_post=pixel_values_post, operation=operation,
                                        input_ids=input_id, labels=labels, attention_mask=attention_mask) # , device=device

            loss = outputs.loss
            total_train_loss += loss.item()

            batch_num += 1

            avg_train_loss = total_train_loss / batch_num

            print("Current Training Loss: {}, Average Training Loss: {}".format(loss.item(), avg_train_loss)) # flush true dene

            loss.backward()
            save_batch_metrics(epoch, idx+1, loss.item(), avg_train_loss, model_name)

        optimizer.step() # bir tab boslugu geri gidebilir

        print("Batch number {} is finished".format(idx + 1))

    #       Validation Section
    model.eval()  # Evaluation mode of model for validation dataset
    total_valid_loss = 0
    avg_valid_loss = 0

    with torch.no_grad():
        for idx, batch in enumerate(valid_dataloader):
            input_ids = batch.pop("input_ids").to(device)  # take captions, it has 5 captions
            pixel_values_pre = batch.pop("pre_img").to(device)  # take imgs
            pixel_values_post = batch.pop("post_img").to(device)  # take imgs
            labels = batch["labels"].to(device)
            attention_mask = batch["attention_mask"].to(device)

            split_input_ids = torch.unbind(input_ids, dim=1)
            split_labels = torch.unbind(labels, dim=1)
            split_attention_mask = torch.unbind(attention_mask, dim=1)

            batch_num = idx * 5  # her batch'de 5 adet görsel eğitildiği için batch number 5'in katları olarak artar

            for input_id, labels, attention_mask in zip(split_input_ids, split_labels, split_attention_mask):
                outputs = model(pixel_values_pre=pixel_values_pre, pixel_values_post=pixel_values_post, operation=operation,
                                input_ids=input_id, labels=labels, attention_mask=attention_mask)

                loss = outputs.loss
                total_valid_loss += loss.item()

                batch_num += 1
                avg_valid_loss = total_valid_loss / batch_num

                print("Current Validation Loss: {}, Average Validation Loss: {}".format(loss.item(), avg_valid_loss))

    #  Save model after each epoch
    torch.save({
        'epoch': epoch,
        'model_state_dict': model.state_dict(),
        'optimizer_state_dict': optimizer.state_dict(),
    }, f'../saved_models/levir_cc/{model_name}_epoch_{epoch}.pth')


    print("Epoch {} finished. Train loss: {}, Validation loss: {}".format(epoch, avg_train_loss, avg_valid_loss))

    return avg_train_loss, avg_valid_loss, model, optimizer