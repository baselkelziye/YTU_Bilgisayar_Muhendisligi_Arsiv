import gradio

from PIL import Image

import logging
import logging.config
import yaml

# Logger Configurations Part
# TODO: Make path relative to portability
with open(
        '/home/onder/Repos/BLM6106_Data_Compression/02-Homeworks/Homework1/logger_config.yaml',
        'r') as file:
    config = yaml.safe_load(file.read())
    logging.config.dictConfig(config)

logger = logging.getLogger(__name__)


def compress(image_path):
    # TODO: Add input validation part
    # TODO:  'None' file was read successfully. Features; ise hata ver.
    logger.info(
        'The \'{0}\' file was read successfully. Features;'.format(image_path))

    orginal_image = Image.open(
        '/home/onder/Repos/BLM6106_Data_Compression/02-Homeworks/Homework1/images/lenna.bmp'
    )

    width, height = orginal_image.size

    # for i

    # TODO: Buraları düzelt
    size_of_the_input_stream = 1000.0
    size_of_the_output_stream = 600.0

    compression_ratio = size_of_the_output_stream / size_of_the_input_stream
    compression_performance = str(100 * (1 - compression_ratio)) + '%'

    return size_of_the_input_stream, size_of_the_output_stream, compression_ratio, compression_performance


def extract(public_exponent, modulus, shift, plaintext):
    # TODO: Add input validation part

    return 'TODO: 1', 'TODO: 2', 'TODO: 3', 'TODO: 4'


# Graphical User Interface (GUI) Part
with gradio.Blocks() as demo:
    with gradio.Tab("Compressor"):
        with gradio.Row():
            with gradio.Column():
                image_path = gradio.Image(type='filepath')
                key_size_textbox = gradio.Textbox(
                    label="Key Size (bit length)",
                    placeholder="Enter the key size (in bits)...\nDefault: 8")
                public_exponent_textbox_for_generation_input = gradio.Textbox(
                    label="Public Exponent (e)",
                    placeholder=
                    "Enter the public exponent (e)...\nDefault: 65537")

            with gradio.Column():
                size_of_the_input_stream_textbox = gradio.Textbox(
                    label="Size of the Input Stream",
                    placeholder="The result will be here after generation...")
                size_of_the_output_stream_textbox = gradio.Textbox(
                    label="Size of the Output Stream",
                    placeholder="The result will be here after generation...")
                compression_ratio_textbox = gradio.Textbox(
                    label="Compression Ratio",
                    placeholder="The result will be here after generation...")
                compression_performance_textbox = gradio.Textbox(
                    label="Compression Performance",
                    placeholder="The result will be here after generation...")

        compress_button = gradio.Button("Compress")

    with gradio.Tab("Decompressor"):
        with gradio.Row():
            with gradio.Column():
                public_exponent_textbox_for_encryption = gradio.Textbox(
                    label="Public Exponent (e)",
                    placeholder=
                    "Enter the public exponent (e)...\nDefault: 65537")
                modulus_textbox_for_encryption = gradio.Textbox(
                    label="Modulus (n)",
                    placeholder="Enter the modulus (n)...")
                shift_textbox_for_encryption = gradio.Textbox(
                    label="Shift Key", placeholder="Enter the shift value...")
                # Plaintext: Text that is not computationally tagged, specially formatted, or written in code.
                plaintext_textbox_for_encryption = gradio.Textbox(
                    label="Plaintext (Unencrypted Text)",
                    placeholder="Enter the words to be encrypted...")

            with gradio.Column():
                plaintext_hex_string_textbox_for_encryption = gradio.Textbox(
                    label="Plaintext Hex String",
                    placeholder="The result will be here after encryption...")
                # Ciphertext: Encrypted text transformed from plaintext using an encryption algorithm.
                ciphertext_textbox_for_encryption = gradio.Textbox(
                    label="Ciphertext (Encrypted Text)",
                    placeholder="The result will be here after encryption...")
                ciphertext_hex_string_textbox_for_encryption = gradio.Textbox(
                    label="Ciphertext Hex String",
                    placeholder="The result will be here after encryption...")
                ciphertext_hex_string_textbox_for_caesar = gradio.Textbox(
                    label="Ciphertext Hex String After Caesar",
                    placeholder=
                    "The result will be here after Caesar encryption...")

        extract_button = gradio.Button("Extract")

    compress_button.click(compress,
                          inputs=[image_path],
                          outputs=[
                              size_of_the_input_stream_textbox,
                              size_of_the_output_stream_textbox,
                              compression_ratio_textbox,
                              compression_performance_textbox
                          ])

    extract_button.click(extract,
                         inputs=[
                             public_exponent_textbox_for_encryption,
                             modulus_textbox_for_encryption,
                             shift_textbox_for_encryption,
                             plaintext_textbox_for_encryption
                         ],
                         outputs=[
                             ciphertext_textbox_for_encryption,
                             ciphertext_hex_string_textbox_for_encryption,
                             plaintext_hex_string_textbox_for_encryption,
                             ciphertext_hex_string_textbox_for_caesar
                         ])

# TODO: Uncomment demo.launch(share=True)
# demo.launch(share=True)
# server_port=8080
demo.launch()
