import tensorflow as tf
import tensorflow_datasets as tfds
import numpy as np
from utils import load_data, load_tokenizers, create_tokenizers
from layers import CustomSchedule, Transformer, create_masks
import os
import yaml

print(f"using tensorflow v{tf.__version__}")
print(f"using tensorflow.keras v{tf.keras.__version__}")

class ExportModel():
    def __init__(self,config_path):
        self.readConfig(config_path)
        self.tokenizeData()
        self.learning_rate = CustomSchedule(self.d_model)
        self.optimizer = tf.keras.optimizers.Adam(self.learning_rate, beta_1=0.9, beta_2=0.98, epsilon=1e-9)
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

        if self.custom_checkpoint != None:
            self.ckpt.restore(self.custom_checkpoint)
            print(f"Selected Check Point: {self.custom_checkpoint}")

    
    def replyForGui(self,usr_input):
        print(usr_input)
        predicted_sentence, _, _, _ = self.reply(usr_input)
        print(f"[BOT]: {predicted_sentence}")
        return predicted_sentence

    def reply(self, sentence):
        result, attention_weights = self.evaluate(sentence)
        
        predicted_sentence = self.outputs_tokenizer.decode([i for i in result 
                                                if i < self.outputs_tokenizer.vocab_size])

        return predicted_sentence, attention_weights, sentence, result

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
        
            predictions = predictions[: ,-1:, :]  # (batch_size, 1, vocab_size)

            predicted_id = tf.cast(tf.argmax(predictions, axis=-1), tf.int32)
            
            if predicted_id == self.outputs_tokenizer.vocab_size+1:
                return tf.squeeze(output, axis=0), attention_weights
            
            # concatentate the predicted_id to the output which is given to the decoder
            # as its input.
            output = tf.concat([output, predicted_id], axis=-1)

        return tf.squeeze(output, axis=0), attention_weights




    def readConfig(self, config_path):
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
        self.storage_path = config["storage_path"] if config["storage_path"] != None else "./"
        self.ckpt_path = config["ckpt_path"] if config["ckpt_path"] != None else "./"
        self.mode = config["mode"]
        self.isRedditData = config["reddit_data"]
        self.data_path = f"{self.storage_path}data"
        self.checkpoint_path = f"{self.ckpt_path}checkpoints/train"
        self.tokenizer_path = f"{self.storage_path}tokenizers"
        self.inputs_savepath = f"{self.tokenizer_path}/inputs_token"
        self.outputs_savepath = f"{self.tokenizer_path}/outputs_token"
        if not self.storage_path.endswith("/"):
            self.storage_path += "/"
        
        if not self.ckpt_path.endswith("/"):
            self.ckpt_path += "/"
    def tokenizeData(self):
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

if __name__ == "__main__":
    export = ExportModel(".")
