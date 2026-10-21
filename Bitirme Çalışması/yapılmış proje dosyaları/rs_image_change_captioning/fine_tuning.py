from transformers import AutoProcessor
from transformers import BlipForConditionalGeneration
import torch

from dataset import rsicd_data_loader, levir_cc_dataloader
from test import test_rsicd, test_levir_cc
from train import train_rsicd, train_levir_cc
from helpers import save_epoch_metrics, find_latest_model, combine_embeddings

class CustomBlipForConditionalGeneration(BlipForConditionalGeneration):
   def forward(self, pixel_values_pre, pixel_values_post, operation, input_ids=None, attention_mask=None, labels=None):

        vision_outputs_pre = self.vision_model(pixel_values=pixel_values_pre)
        image_embeds_pre = vision_outputs_pre.last_hidden_state
        vision_outputs_post = self.vision_model(pixel_values=pixel_values_post)
        image_embeds_post = vision_outputs_post.last_hidden_state

        image_embeds = combine_embeddings(image_embeds_pre, image_embeds_post, device=image_embeds_pre.device, operation=operation)
        batch_size, seq_length, _ = image_embeds.size()
        encoder_attention_mask = torch.ones((batch_size, seq_length), dtype=torch.long).to(image_embeds.device)

        if input_ids is not None:
            outputs = self.text_decoder(
                input_ids=input_ids,
                attention_mask=attention_mask,
                encoder_hidden_states=image_embeds,
                encoder_attention_mask=encoder_attention_mask,
                labels=labels,
            )
            return outputs
        else:
            generated_ids = self.generate(
                pixel_values_pre=pixel_values_pre,
                pixel_values_post=pixel_values_post,
                operation=operation,
                max_length=20,
                num_beams=1,
            )
            return generated_ids

   def generate(self, pixel_values_pre, pixel_values_post, operation, **generate_kwargs):

        vision_outputs_pre = self.vision_model(pixel_values=pixel_values_pre)
        image_embeds_pre = vision_outputs_pre.last_hidden_state

        vision_outputs_post = self.vision_model(pixel_values=pixel_values_post)
        image_embeds_post = vision_outputs_post.last_hidden_state

        image_embeds = combine_embeddings(image_embeds_pre, image_embeds_post, device=image_embeds_pre.device, operation=operation)

        batch_size, seq_length, _ = image_embeds.size()
        encoder_attention_mask = torch.ones((batch_size, seq_length), dtype=torch.long).to(image_embeds.device)

        generated_ids = self.text_decoder.generate(
            encoder_hidden_states=image_embeds,
            encoder_attention_mask=encoder_attention_mask,
            **generate_kwargs,
        )
        return generated_ids

def fine_tune():

    # model = BlipForConditionalGeneration.from_pretrained("Salesforce/blip-image-captioning-base")
    # optimizer = torch.optim.AdamW(model.parameters(), lr=5e-5)

    model = CustomBlipForConditionalGeneration.from_pretrained("Salesforce/blip-image-captioning-base")
    optimizer = torch.optim.AdamW(model.parameters(), lr=5e-5)

    processor = AutoProcessor.from_pretrained("Salesforce/blip-image-captioning-base")
    processor.tokenizer.add_special_tokens({'eos_token': '.'})

    device = "cuda" if torch.cuda.is_available() else "cpu"
    model.to(device)
    print("device:", device)


    #     Image Captioning Dataloader
    # train_dataloader = rsicd_data_loader("train", processor)
    # valid_dataloader = rsicd_data_loader("valid", processor)
    # test_dataset = rsicd_data_loader("test")

    #     Change Captioning Dataloader
    train_dataloader = levir_cc_dataloader("train", processor, batch_size=2)
    valid_dataloader = levir_cc_dataloader("valid", processor, batch_size=2)
    test_dataloader = levir_cc_dataloader("test", processor)  # sample_size=100

    #   Find from which epoch to start to train.
    latest_model = find_latest_model(folder_path="../saved_models")
    if latest_model is not None:
        checkpoint = torch.load('../saved_models/{}'.format(latest_model), weights_only=False)  # This model path should be CHANGED, it needs to be DYNAMIC
        model.load_state_dict(checkpoint['model_state_dict'])
        optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
        starting_epoch = checkpoint['epoch'] + 1  # Start from new epoch
        print(f"Resuming training from epoch {starting_epoch}...")
    else:
        print("No checkpoint found. Starting to train from scratch.")
        starting_epoch = 0  # Start from scratch

    # It's found that subtraction and hadamard methods are not good fit to use when fusing pre and post images.
    # operation = "subtraction"
    # operation = "hadamard"

    operation = "concatenation"
    model_name = "concatenation"
    for epoch in range(starting_epoch, 10):
        print("Epoch:", epoch)

        #       RS Change Captioning

        #  Train
        avg_train_loss, avg_valid_loss, avg_loss_0, avg_loss_1, avg_valid_loss_0, avg_valid_loss_1, model, optimizer = \
            train_levir_cc(valid_dataloader, valid_dataloader, operation, model, optimizer, device, epoch, model_name)

        # Test
        metrics, metrics_0, metrics_1 = test_levir_cc(valid_dataloader, operation, processor, model, device, epoch)

        save_epoch_metrics(epoch, "all", avg_train_loss, avg_valid_loss, metrics["Bleu_1"],
                           metrics["Bleu_2"], metrics["Bleu_3"], metrics["Bleu_4"],
                           metrics["ROUGE_L"], metrics["CIDEr"], metrics["METEOR"])
        save_epoch_metrics(epoch, "no change", avg_loss_0, avg_valid_loss_0, metrics_0["Bleu_1"],
                           metrics_0["Bleu_2"], metrics_0["Bleu_3"], metrics_0["Bleu_4"],
                           metrics_0["ROUGE_L"], metrics_0["CIDEr"], metrics_0["METEOR"])
        save_epoch_metrics(epoch, "change", avg_loss_1, avg_valid_loss_1, metrics_1["Bleu_1"],
                           metrics_1["Bleu_2"], metrics_1["Bleu_3"], metrics_1["Bleu_4"],
                           metrics_1["ROUGE_L"], metrics_1["CIDEr"], metrics_1["METEOR"])


        #       RS Image Captioning

        # avg_train_loss, avg_valid_loss, model, optimizer = train_rsicd(train_dataloader, valid_dataloader, model, optimizer, device, epoch)
        # metrics = test_rsicd(test_dataset, processor, model, device)
        # save_epoch_metrics(epoch, avg_train_loss, avg_valid_loss, metrics["Bleu_1"],
        #                    metrics["Bleu_2"], metrics["Bleu_3"], metrics["Bleu_4"],
        #                    metrics["ROUGE_L"], metrics["CIDEr"], metrics["METEOR"])

        # avg_train_loss, avg_valid_loss, model, optimizer = train_levir_cc(train_dataloader, valid_dataloader, operation, model, optimizer, device, epoch)
        # metrics = test_levir_cc(test_dataloader, processor, model, operation, device)

fine_tune()