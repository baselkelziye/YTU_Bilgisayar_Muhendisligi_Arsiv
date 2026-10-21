import os
import re

import torch

import csv
import json
from eval_func.bleu.bleu import Bleu
from eval_func.rouge.rouge import Rouge
from eval_func.cider.cider import Cider
from eval_func.meteor.meteor import Meteor

def get_eval_score(references, hypotheses):
    scorers = [
        (Bleu(4), ["Bleu_1", "Bleu_2", "Bleu_3", "Bleu_4"]),
        (Meteor(), "METEOR"),
        (Rouge(), "ROUGE_L"),
        (Cider(), "CIDEr")
    ]

    score = []
    method = []
    for scorer, method_i in scorers:
        score_i, scores_i = scorer.compute_score(references, hypotheses)
        score.extend(score_i) if isinstance(score_i, list) else score.append(score_i)
        method.extend(method_i) if isinstance(method_i, list) else method.append(method_i)
        print("{} {}".format(method_i, score_i))
    score_dict = dict(zip(method, score))

    return score_dict

def find_latest_model(folder_path):
    files = os.listdir(folder_path)
    model_files = [f for f in files if re.match(r'model_epoch_\d+', f)]

    if not model_files:
        return None

    model_numbers = [int(re.search(r'\d+', f).group()) for f in model_files]
    highest_number = max(model_numbers)

    latest_model = "model_epoch_{}.pth".format(highest_number)
    print(latest_model)
    return latest_model

def save_batch_metrics(epoch_num, batch_num, current_training_loss, avg_training_loss, model_name):
    with open(f"../metrics/{model_name}_batch_metrics.csv", mode="a", newline="") as file:
        writer = csv.writer(file)
        if file.tell() == 0:  # Create file with headers if not created before.
            writer.writerow(["Epoch Number", "Batch Number", "Current Training Loss", "Average Training Loss"])
        writer.writerow([epoch_num, batch_num, current_training_loss, avg_training_loss])

def save_epoch_metrics(epoch_num, change_status, training_loss, validation_loss, bleu_1, bleu_2, bleu_3, bleu_4, rouge_l, cider, meteor, model_name):
    with open(f"../metrics/{model_name}_epoch_metrics.csv", mode="a", newline="") as file:
        writer = csv.writer(file)
        if file.tell() == 0:  # Create file with headers if not created before.
            writer.writerow(["Epoch Number", "Change Status", "Training Loss", "Validation Loss", "BLEU-1", "BLEU-2", "BLEU-3", "BLEU-4", "ROUGE_L", "CIDEr", "METEOR"])
        writer.writerow([epoch_num, change_status, training_loss, validation_loss, bleu_1, bleu_2, bleu_3, bleu_4, rouge_l, cider, meteor])

def combine_embeddings(pre_emb, post_emb, operation, device):
    if operation == "concatenation":
        concatenated = torch.cat((pre_emb, post_emb), dim=1).to(device)
        return concatenated
    elif operation == "subtraction":
        return post_emb - pre_emb
    elif operation == "hadamard":
        return pre_emb * post_emb
    else:
        raise ValueError("Unsupported operation")

def save_outputs(file_names, generated_captions, labels, params, metrics, model_name):

    captions = []
    for generated_caption, label, file_name in zip(generated_captions, labels, file_names):
        caption = {
        "file_name": file_name,
        "generated_caption": generated_caption,
        "labels": label
        }
        captions.append(caption)

    data = {
        "params": params,
        "model": model_name,
        "metrics": metrics,
        "caption_dict": captions
    }

    file_eos = "../metrics/generated_captions_eos_new.json"
    # file_concat = "/content/drive/MyDrive/metrics/generated_captions.json"

    with open(file_eos, mode="a") as json_file:
        json.dump(data, json_file, indent=4)