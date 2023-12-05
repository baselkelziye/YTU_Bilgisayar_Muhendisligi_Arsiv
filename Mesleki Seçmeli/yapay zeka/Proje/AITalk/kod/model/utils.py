from tqdm import tqdm
import os
import numpy as np
import tensorflow_datasets as tfds
from tensorflow.keras.preprocessing.sequence import pad_sequences
import random
import html
import tensorflow as tf

def load_data(filepath, shuffle=True):
  with open(filepath, "r", encoding="utf-8") as f:
    lines = f.read().split("\n")

  inputs, outputs = list(), list()
  for i, l in enumerate(tqdm(lines)):
    if i % 2 == 0:
      inputs.append(str.encode(html.unescape(l).lower(), "utf-8"))
    else:
      outputs.append(str.encode(html.unescape(l).lower(), "utf-8"))

  popped = 0
  for i, (ins, outs) in enumerate(zip(inputs, outputs)):
    if not ins or not outs:
      inputs.pop(i)
      outputs.pop(i)
      popped += 1

  print(f"Pairs popped: {popped}")
  if shuffle:
    print("\nShuffling...")
    inputs, outputs = shuffle_inputs_outputs(inputs, outputs)

  return inputs, outputs

def shuffle_inputs_outputs(inputs, outputs):
  inputs_outputs = list(zip(inputs, outputs))
  random.shuffle(inputs_outputs)
  inputs, outputs = zip(*inputs_outputs)
  return inputs, outputs

def create_tokenizers(inputs_outputs, inputs_outputs_savepaths, target_vocab_size):
  inputs, outputs = inputs_outputs
  inputs_savepath, outputs_savepath = inputs_outputs_savepaths
  inputs_tokenizer = tfds.deprecated.text.SubwordTextEncoder.build_from_corpus(
    inputs, target_vocab_size=target_vocab_size)
  outputs_tokenizer = tfds.deprecated.text.SubwordTextEncoder.build_from_corpus(
    outputs, target_vocab_size=target_vocab_size)
  print("Saving tokenizers...")
  inputs_tokenizer.save_to_file(inputs_savepath)
  outputs_tokenizer.save_to_file(outputs_savepath)

  return inputs_tokenizer, outputs_tokenizer

def load_tokenizers(inputs_outputs_savepaths):
  print("Loading tokenizers...")
  inputs_savepath, outputs_savepath = inputs_outputs_savepaths
  inputs_tokenizer = tfds.deprecated.text.SubwordTextEncoder.load_from_file(inputs_savepath)
  outputs_tokenizer = tfds.deprecated.text.SubwordTextEncoder.load_from_file(outputs_savepath)

  return inputs_tokenizer, outputs_tokenizer

def encode(inputs_outputs, inputs_outputs_tokenizer):
  inputs, outputs = inputs_outputs
  inputs_tokenizer, outputs_tokenizer = inputs_outputs_tokenizer

  inputs = [inputs_tokenizer.vocab_size] + inputs_tokenizer.encode(
      inputs) + [inputs_tokenizer.vocab_size+1]

  outputs = [outputs_tokenizer.vocab_size] + outputs_tokenizer.encode(
      outputs) + [outputs_tokenizer.vocab_size+1]
  
  return inputs, outputs

def tf_encode(inputs_outputs, inputs_outputs_tokenizer):
  result_in, result_out = tf.py_function(encode, [inputs_outputs, inputs_outputs_tokenizer], [tf.int64, tf.int64])
  result_in.set_shape([None])
  result_out.set_shape([None])

  return result_in, result_out

def prepare_data(batch_size, inputs_outputs, inputs_outputs_tokenizer, max_length):
  print("Preparing data...")
  inputs, outputs = inputs_outputs
  if len(inputs) == len(outputs):
    batches_in = list()
    batches_out = list()
    curr_batch_in = list()
    curr_batch_out = list()
    skipped = 0
    for (ins, outs) in zip(inputs, outputs):
      ins, outs = encode([ins, outs], inputs_outputs_tokenizer)
      if len(ins) > max_length or len(outs) > max_length:
        skipped += 1
        continue
      else:
        ins = pad_sequences(sequences=[ins], maxlen=max_length,
          padding="post", truncating='post', value=0.0)[0]
        outs = pad_sequences(sequences=[outs], maxlen=max_length,
          padding="post", truncating='post', value=0.0)[0]
        curr_batch_in.append(ins)
        curr_batch_out.append(outs)

        if len(curr_batch_in) % batch_size == 0:
          batches_in.append(tf.convert_to_tensor(curr_batch_in, dtype=tf.int64))
          batches_out.append(tf.convert_to_tensor(curr_batch_out, dtype=tf.int64))
          curr_batch_in = list()
          curr_batch_out = list()

    if curr_batch_in:
      batches_in.append(tf.convert_to_tensor(curr_batch_in, dtype=tf.int64))
      batches_out.append(tf.convert_to_tensor(curr_batch_out, dtype=tf.int64))

    print(f"Total batches per epoch: {len(batches_in)}")
    print(f"Total pairs skipped: {skipped}")

    return batches_in, batches_out

  else:
    print("Given `inputs` length is not same as `outputs` length")
