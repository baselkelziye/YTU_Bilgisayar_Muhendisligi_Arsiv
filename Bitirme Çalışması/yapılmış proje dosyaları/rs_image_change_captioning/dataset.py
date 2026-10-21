from PIL import Image
from torch.utils.data import Dataset, DataLoader
from datasets import load_dataset
import h5py
import json
import random

class ImageCaptioningDataset(Dataset):
    def __init__(self, dataset, processor):

        self.dataset = dataset
        self.processor = processor

    def __len__(self):
        return len(self.dataset)
        # return 5

    def __getitem__(self, idx):
        item = self.dataset[idx]
        encoding = self.processor(images=item["image"], text=item["captions"], padding="max_length", return_tensors="pt")
        # remove batch dimension
        encoding = {k:v.squeeze() for k,v in encoding.items()}
        labels = encoding["input_ids"].clone()
        labels[labels == self.processor.tokenizer.pad_token_id] = -100
        encoding["labels"] = labels
        return encoding

class ChangeCaptioningDataset(Dataset):
    def __init__(self, dataset, processor, sample_size=None):

        self.dataset = dataset
        self.processor = processor
        hdf5_path = f"C:/Users/erend/OneDrive/Masaüstü/ders/Datasets/levir-cc/data_yeni/{dataset}_IMAGES_LEVIR_CC.hdf5"
        json_path = f"C:/Users/erend/OneDrive/Masaüstü/ders/Datasets/levir-cc/data_yeni/{dataset}_CAPTIONS_LEVIR_CC.json"
        self.dataset = []
        self.dataset_len = 0

        with (h5py.File(hdf5_path, 'r') as h5_file, open(json_path, 'r') as json_file):
            captions_data = json.load(json_file)
            images = h5_file['images']
            self.dataset_len = len(images)
            for i in range(len(images)):
                pre_img, post_img = images[i][0], images[i][1]  # A and B images
                pre_img = Image.fromarray(pre_img.transpose(1, 2, 0))
                post_img = Image.fromarray(post_img.transpose(1, 2, 0))
                self.dataset.append(
                    {
                        "pre_img": pre_img,
                        "post_img": post_img,
                        "captions": captions_data[f"image_{i}"]["captions"],
                        "file_name": captions_data[f"image_{i}"]["filename"],
                        "change_flag": captions_data[f"image_{i}"]["changeflag"]
                    }
                )

        if sample_size is not None:
            random.seed(42)
            self.dataset = random.sample(self.dataset, min(sample_size, len(self.dataset)))
            self.dataset_len = len(self.dataset)

    def __getitem__(self, idx):
        item = self.dataset[idx]
        encoding_pre = self.processor(images=item["pre_img"], text=item["captions"], padding="max_length", return_tensors="pt")
        encoding_post = self.processor(images=item["post_img"], text=item["captions"], padding="max_length", return_tensors="pt")
        # remove batch dimension
        encoding_pre = {k:v.squeeze() for k,v in encoding_pre.items()}
        labels = encoding_pre["input_ids"].clone()
        labels[labels == self.processor.tokenizer.pad_token_id] = -100
        encoding_pre["labels"] = labels
        # remove batch dimension
        encoding_post = {k:v.squeeze() for k,v in encoding_post.items()}
        labels = encoding_post["input_ids"].clone()
        labels[labels == self.processor.tokenizer.pad_token_id] = -100
        encoding_post["labels"] = labels
        encoding = dict()
        encoding["pre_img"] = encoding_pre["pixel_values"]
        encoding["post_img"] = encoding_post["pixel_values"]
        encoding["input_ids"] = encoding_post["input_ids"] # post ya da pre olabilir
        encoding["labels"] = encoding_post["labels"]
        encoding["attention_mask"] = encoding_post["attention_mask"]
        encoding["file_name"] = item["file_name"]
        encoding["change_flag"] = item["change_flag"]
        encoding["captions"] = item["captions"]
        return encoding

    def __len__(self):
        return 4
        # return self.dataset_len

def rsicd_data_loader(ds_type, processor=None):
    dataset = load_dataset("arampacha/rsicd", split="{}".format(ds_type))
    if ds_type == 'test':
        return dataset
    else:
        dataset = ImageCaptioningDataset(dataset, processor)
        if ds_type == 'train':
            dataloader = DataLoader(dataset, shuffle=True, batch_size=2)
        else: # if valid
            dataloader = DataLoader(dataset, shuffle=False, batch_size=2)
    return dataloader

def levir_cc_dataloader(dataset_choice, processor, batch_size = None, sample_size=None):
    # dataset = load_dataset("C:/Users/erend/OneDrive/Masaüstü/ders/Datasets/levir-cc/data_yeni", split="{}".format(dataset))
    if dataset_choice == 'train':
        dataset = ChangeCaptioningDataset("TRAIN", processor)
    elif dataset_choice == 'valid':
        dataset = ChangeCaptioningDataset("VAL", processor)
    else:
        dataset = ChangeCaptioningDataset("TEST", processor, sample_size)

    if dataset_choice == 'test':
        dataloader = DataLoader(dataset, shuffle=False, batch_size=1)
    else:
        dataloader = DataLoader(dataset, shuffle=True, batch_size=batch_size)

    return dataloader