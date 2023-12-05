import tensorflow as tf
import tensorflow_datasets as tfds
import numpy as np
from utils import load_data, load_tokenizers, create_tokenizers, prepare_data
from layers import CustomSchedule, Transformer, create_masks, loss_function
from get_reddit_data import get_data
from dataloader import loader
from nltk.translate.bleu_score import sentence_bleu
import os
import time
import yaml
from sklearn.metrics import f1_score
from sklearn.preprocessing import LabelEncoder
import random

print(f"using tensorflow v{tf.__version__}")
print(f"using tensorflow.keras v{tf.keras.__version__}")


class Chatbot(object):

    def __init__(self, config_path):

        with open(os.path.join(config_path,"config.yml")) as cf:
            config = yaml.load(cf, Loader=yaml.FullLoader)

        self.num_layers = config["num_layers"]
        self.d_model = config["d_model"]
        self.dff = config["dff"]
        self.num_heads = config["num_heads"]
        self.dropout_rate = config["dropout_rate"]
        self.max_length = config["max_length"]
        self.epochs = config["epochs"]
        self.batch_size = config["batch_size"]
        self.target_vocab_size = config["target_vocab_size"]
        self.checkpoint = config["checkpoint"]
        self.max_checkpoint = config["max_checkpoint"]
        self.custom_checkpoint = config["custom_checkpoint"]
        self.eval_limit = config["eval_limit"]
        self.exit_phrase = config["exit_phrase"]
        
        if config["storage_path"] != None:
            self.storage_path = config["storage_path"]
        else:
            self.storage_path = "./"
        
        if config["ckpt_path"] != None:
            self.ckpt_path = config["ckpt_path"]
        else:
            self.ckpt_path = "./"

        if not self.storage_path.endswith("/"):
            self.storage_path += "/"
        
        if not self.ckpt_path.endswith("/"):
            self.ckpt_path += "/"

        self.data_path = f"{self.storage_path}data"
        self.checkpoint_path = f"{self.ckpt_path}checkpoints/train"
        self.tokenizer_path = f"{self.storage_path}tokenizers"
        self.inputs_savepath = f"{self.tokenizer_path}/inputs_token"
        self.outputs_savepath = f"{self.tokenizer_path}/outputs_token"

        if not os.path.exists(f"{self.ckpt_path}checkpoints"):
            os.mkdir(f"{self.ckpt_path}checkpoints")
        if not os.path.exists(f"{self.ckpt_path}checkpoints/train"):
            os.mkdir(f"{self.ckpt_path}checkpoints/train")
        if not os.path.exists(f"{self.storage_path}tokenizers"):
            os.mkdir(f"{self.storage_path}tokenizers")
        if not os.path.exists(f"{self.storage_path}models"):
            os.mkdir(f"{self.storage_path}models")
        
        if config["mode"] in ["train" , "eval"]:
            if os.path.exists(os.path.join(config_path, "data/train.from")) and os.path.exists(os.path.join(config_path, "data/train.to")): 
                pass
            else:
                if config["reddit_data"]:
                    print("Starting to generate train data from Subreddits.")
                    get_data(config_path)
            loader(config_path)

        self.inputs, self.outputs = load_data(f"{self.data_path}/training_data.txt")
        try:
            self.inputs_tokenizer, self.outputs_tokenizer = load_tokenizers(
                inputs_outputs_savepaths=[self.inputs_savepath, self.outputs_savepath])
        except:
            print("No tokenizers has been created yet, creating new tokenizers...")
            self.inputs_tokenizer, self.outputs_tokenizer = create_tokenizers(
                inputs_outputs=[self.inputs, self.outputs],
                inputs_outputs_savepaths=[self.inputs_savepath, self.outputs_savepath],
                target_vocab_size=self.target_vocab_size)

        self.input_vocab_size = self.inputs_tokenizer.vocab_size + 2
        self.target_vocab_size = self.outputs_tokenizer.vocab_size + 2

        self.learning_rate = CustomSchedule(self.d_model)
        self.optimizer = tf.keras.optimizers.Adam(self.learning_rate, beta_1=0.9, beta_2=0.98, epsilon=1e-9)
        self.train_loss = tf.keras.metrics.Mean(name='train_loss')
        self.train_accuracy = tf.keras.metrics.SparseCategoricalAccuracy(name='train_accuracy')
        self.transformer = Transformer(
            self.num_layers, self.d_model,
            self.num_heads, self.dff,
            self.input_vocab_size,
            self.target_vocab_size,
            pe_input=self.input_vocab_size,
            pe_target=self.target_vocab_size,
            rate=self.dropout_rate)
            

        self.ckpt = tf.train.Checkpoint(transformer=self.transformer,
                                                             optimizer=self.optimizer)
        self.ckpt_manager = tf.train.CheckpointManager(self.ckpt, self.checkpoint_path, max_to_keep=self.max_checkpoint)

        if self.custom_checkpoint:
            self.ckpt.restore(self.custom_checkpoint)
            print(f"Custom checkpoint restored: {self.custom_checkpoint}")
        # if a checkpoint exists, restore the latest checkpoint.
        elif self.ckpt_manager.latest_checkpoint:
            self.ckpt.restore(self.ckpt_manager.latest_checkpoint)
            print (f"Latest checkpoint restored: {self.ckpt_manager.latest_checkpoint}")


             
        # Girdi cümleleri ve gerçek yanıtlar
        sentences = []  # Chatbotunuza vereceğiniz girdiler (sorular)
        true_replies = []  # Bu girdilere karşılık beklenen gerçek yanıtlar
        with open('./data/test.from','r') as file:
            for line in file:
                line = line.rstrip('/n')
                sentences.append(line)

        with open('./data/test.to','r') as file:
            for line in file:
                line = line.rstrip('/n')
                true_replies.append(line)

        predicted_replies = []
        for sentence in sentences:
            predicted_reply, _, _, _ = self.reply(sentence)
            predicted_replies.append(predicted_reply)

        # Yanıtları sayısal değerlere dönüştürmek için LabelEncoder kullanılır.
        le = LabelEncoder()
        true_encoded = le.fit_transform(true_replies)
        predicted_encoded = le.transform(predicted_replies)  # fit_transform() yerine sadece transform() kullanılır çünkü LabelEncoder zaten true_replies üzerinde eğitilmiştir.

        # F1 skoru hesaplanır
        f1 = f1_score(true_encoded, predicted_encoded, average='weighted')

        print('F1 Score: ', f1)


        predicted_replies = []
        for sentence in sentences:
            predicted_reply, _, _, _ = reply(sentence)
            predicted_replies.append(predicted_reply)

        # BLEU skorlarını toplamak için bir liste
        bleu_scores = []

        for true, pred in zip(true_replies, predicted_replies):
            # Her bir kelimeyi bir liste elemanı olarak ayırır
            true_split = true.split()
            pred_split = pred.split()

            # BLEU skoru hesaplanır
            bleu_score = sentence_bleu([true_split], pred_split)
            bleu_scores.append(bleu_score)

        # Ortalama BLEU skoru hesaplanır
        average_bleu = sum(bleu_scores) / len(bleu_scores)

        print('Average BLEU Score: ', average_bleu)


        if config["mode"] == "train":
            print("\nMODE: train\n===========\n")
            self.train_dataset = prepare_data(self.batch_size, [self.inputs, self.outputs],
                [self.inputs_tokenizer, self.outputs_tokenizer], self.max_length)

            self.train()
            eval_indexes = random.choices(range(len(self.inputs)), k = int(len(self.inputs) * 0.01))
            for i in eval_indexes:
                predicted_sentence, attention_weights, sentence, result = self.reply(self.inputs[i])
                print(f"\nInput: {self.inputs[i]}")
                print(f"Predicted: {predicted_sentence}")
                print(f"Sample output: {self.outputs[i]}")

        elif config["mode"] == "eval":
            print("\nMODE: eval\n==========\n")
            self.inputs = self.inputs[:self.eval_limit]
            self.outputs = self.outputs[:self.eval_limit]

            for (ins, outs) in zip(self.inputs, self.outputs):
                predicted_sentence, attention_weights, sentence, result = self.reply(ins)
                print(f"\nInput: {ins}")
                print(f"Predicted: {predicted_sentence}")
                print(f"Sample output: {outs}")

        elif config["mode"] == "test":
            print("\nMODE: test\n==========\n")
            while True:
                usr_input = input("[USER]: ")
                if usr_input == self.exit_phrase:
                    print("Exiting test mode...")
                    break
                else:
                    predicted_sentence, _, _, _ = self.reply(usr_input)
                    print(f"[BOT]: {predicted_sentence}")
        elif config["mode"] == "script":
            print("\nMODE: script\n==========\n")
        

    def train(self):
        # The @tf.function trace-compiles train_step into a TF graph for faster
        # execution. The function specializes to the precise shape of the argument
        # tensors. To avoid re-tracing due to the variable sequence lengths or variable
        # batch sizes (the last batch is smaller), use input_signature to specify
        # more generic shapes.

        train_step_signature = [
            tf.TensorSpec(shape=(None, None), dtype=tf.int64),
            tf.TensorSpec(shape=(None, None), dtype=tf.int64),
        ]

        @tf.function(input_signature=train_step_signature)
        def train_step(inp, tar):
            tar_inp = tar[:, :-1]
            tar_real = tar[:, 1:]
            
            enc_padding_mask, combined_mask, dec_padding_mask = create_masks(inp, tar_inp)
            
            with tf.GradientTape() as tape:
                predictions, _ = self.transformer(inp, tar_inp, 
                                                                         True, 
                                                                         enc_padding_mask, 
                                                                         combined_mask, 
                                                                         dec_padding_mask)
                loss = loss_function(tar_real, predictions)

            gradients = tape.gradient(loss, self.transformer.trainable_variables)        
            self.optimizer.apply_gradients(zip(gradients, self.transformer.trainable_variables))
            
            self.train_loss(loss)
            self.train_accuracy(tar_real, predictions)

        for epoch in range(self.epochs):
            start = time.time()
            
            self.train_loss.reset_states()
            self.train_accuracy.reset_states()
            
            batches_in, batches_out = self.train_dataset
            for (batch, (inp, tar)) in enumerate(zip(batches_in, batches_out)):
                train_step(inp, tar)
                
                if batch % 100 == 0:
                    print('Epoch {} Batch {} Loss {:.4f} Accuracy {:.4f}'.format(
                            epoch + 1, batch, self.train_loss.result(), self.train_accuracy.result()))
                    
            if (epoch + 1) % self.checkpoint == 0:
                ckpt_save_path = self.ckpt_manager.save()
                print (f"Saving checkpoint for epoch {epoch+1} at {ckpt_save_path}")

            print("Epoch {} Loss {:.4f} Accuracy {:.4f}".format(
                epoch + 1, self.train_loss.result(), self.train_accuracy.result()))
            print('Time taken for 1 epoch: {} secs\n'.format(time.time() - start))

    def evaluate(self, inp_sentence):
        start_token = [self.inputs_tokenizer.vocab_size]
        end_token = [self.inputs_tokenizer.vocab_size + 1]
        
        inp_sentence = start_token + self.inputs_tokenizer.encode(inp_sentence) + end_token
        encoder_input = tf.expand_dims(inp_sentence, 0)
        
        decoder_input = [self.outputs_tokenizer.vocab_size]
        output = tf.expand_dims(decoder_input, 0)
            
        for i in range(self.max_length):
            enc_padding_mask, combined_mask, dec_padding_mask = create_masks(
                    encoder_input, output)
        
            predictions, attention_weights = self.transformer(encoder_input, 
                                                                                                                output,
                                                                                                                False,
                                                                                                                enc_padding_mask,
                                                                                                                combined_mask,
                                                                                                                dec_padding_mask)
            
            predictions = predictions[: ,-1:, :]    # (batch_size, 1, vocab_size)

            predicted_id = tf.cast(tf.argmax(predictions, axis=-1), tf.int32)
            
            if predicted_id == self.outputs_tokenizer.vocab_size+1:
                return tf.squeeze(output, axis=0), attention_weights
            
            # concatentate the predicted_id to the output which is given to the decoder
            # as its input.
            output = tf.concat([output, predicted_id], axis=-1)

        return tf.squeeze(output, axis=0), attention_weights

    def reply(self, sentence):
        result, attention_weights = self.evaluate(sentence)
        
        predicted_sentence = self.outputs_tokenizer.decode([i for i in result 
                                                                                            if i < self.outputs_tokenizer.vocab_size])

        return predicted_sentence, attention_weights, sentence, result




if __name__ == "__main__":
    CONFIG_PATH = "."
    chatbot = Chatbot(CONFIG_PATH)
