from helpers import get_eval_score, save_outputs


def test_rsicd(ds, processor, model, device):

    references = list()
    hypotheses = list()

    model.eval()
    model.to(device)

    for i in range(10): # ilk 10 veri için skor üretme
    # for i in range(len(ds)):
        image = ds[i]["image"] # image oku
        input = processor(images=image, return_tensors="pt").to(device) # image process et
        pixel_values = input.pixel_values # pixel değerlerini al
        generated_ids = model.generate(pixel_values=pixel_values, max_length=20)
        generated_caption = processor.batch_decode(generated_ids, skip_special_tokens=True)[0] # decode ile cümle üret
        print("image: ", i, "  ", generated_caption)
        hypotheses.append(generated_caption)
        print(ds[i]["captions"])
        references.append(ds[i]["captions"])

    hypotheses = [[item] for item in hypotheses]

    metrics = get_eval_score(references, hypotheses)

    print("BLEU-1 {} BLEU-2 {} BLEU-3 {} BLEU-4 {} ROUGE_L {} CIDEr {}, Meteor {}".format
          (metrics["Bleu_1"], metrics["Bleu_2"], metrics["Bleu_3"],
           metrics["Bleu_4"], metrics["ROUGE_L"], metrics["CIDEr"], metrics["METEOR"]))


    return metrics

def test_levir_cc(test_dataloader, processor, model, operation, device, epoch):

    references = list()
    hypotheses = list()

    references_change = list()
    hypotheses_change = list()

    references_no_change = list()
    hypotheses_no_change = list()

    model.eval()
    model.to(device)

    # These params can be used for generation. Best option is found as default.
    params = {
        "param": "default",
        #"num_beams": 2,
        #"num_beam_groups": 5,
        #"diversity_penalty": 1.0,
         #"do_sample": True,
        #"length_penalty": "-1.0",
        #"repetition_penalty": 0.8,
        #"top_k":4,
        #"penalty_alpha": 0.6,
        #"max_new_tokens": 100,
        #"assistant_early_exit": 4,
        #"dola_layers": "high",
        #"do_sample": False,
        #"max_length": 15,
        #"exponential_decay_length_penalty": "(10, 0.9)",
        #"max_new_tokens": "50",
        #"no_repeat_ngram_size": 2,
        "method": "Greedy Search decoding",
    }

    file_names = []
    generated_captions = []
    labels = []

    # for i in range(10): # ilk 10 veri için skor üretme

    for idx, batch in enumerate(test_dataloader):
        pixel_values_pre = batch.pop("pre_img").to(device)  # take imgs
        pixel_values_post = batch.pop("post_img").to(device)  # take imgs
        captions = batch.pop("captions")
        file_name = batch.pop("file_name")

        labels.append(captions)
        file_names.append(file_name)

        generated_ids = model.generate(pixel_values_pre=pixel_values_pre, pixel_values_post=pixel_values_post,
                                        operation=operation, max_length=20)
        generated_caption = processor.batch_decode(generated_ids, skip_special_tokens=True)[0] # decode ile cümle üret

        # If not, add dot to the end
        if not generated_caption.endswith("."):
          generated_caption += " ."

        generated_captions.append(generated_caption)


        print("image: ", idx, "  ", generated_caption)
        hypotheses.append(generated_caption)
        captions_str = []
        #  The captions are in a tuple in the captions list. Need to be converted to str.
        for caption in captions:
            captions_str.append(caption[0])
        print(captions_str)
        references.append(captions_str)

        if batch["change_flag"] == 0:
            hypotheses_no_change.append(generated_caption)
            references_no_change.append(captions_str)
        elif batch["change_flag"] == 1:
            hypotheses_change.append(generated_caption)
            references_change.append(captions_str)


    hypotheses = [[item] for item in hypotheses]
    hypotheses_change = [[item] for item in hypotheses_change]
    hypotheses_no_change = [[item] for item in hypotheses_no_change]

    metrics = get_eval_score(references, hypotheses)
    metrics_change = get_eval_score(references_change, hypotheses_change)
    metrics_no_change = get_eval_score(references_no_change, hypotheses_no_change)

    print("all")
    print("BLEU-1 {} BLEU-2 {} BLEU-3 {} BLEU-4 {} ROUGE_L {} CIDEr {}, Meteor {}".format
          (metrics["Bleu_1"], metrics["Bleu_2"], metrics["Bleu_3"],
           metrics["Bleu_4"], metrics["ROUGE_L"], metrics["CIDEr"], metrics["METEOR"]))
    print("no_change")
    print("BLEU-1 {} BLEU-2 {} BLEU-3 {} BLEU-4 {} ROUGE_L {} CIDEr {}, Meteor {}".format
          (metrics_no_change["Bleu_1"], metrics_no_change["Bleu_2"], metrics_no_change["Bleu_3"],
           metrics_no_change["Bleu_4"], metrics_no_change["ROUGE_L"], metrics_no_change["CIDEr"], metrics_no_change["METEOR"]))
    print("change")
    print("BLEU-1 {} BLEU-2 {} BLEU-3 {} BLEU-4 {} ROUGE_L {} CIDEr {}, Meteor {}".format
          (metrics_change["Bleu_1"], metrics_change["Bleu_2"], metrics_change["Bleu_3"],
           metrics_change["Bleu_4"], metrics_change["ROUGE_L"], metrics_change["CIDEr"], metrics_change["METEOR"]))

    model_name = "concat_eos_epoch_{}".format(epoch)
    save_outputs(file_names, generated_captions, labels, params, metrics, model_name)

    return metrics, metrics_no_change, metrics_change