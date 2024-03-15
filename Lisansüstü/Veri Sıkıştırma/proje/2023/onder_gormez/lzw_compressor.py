import logging
import logging.config
import yaml
import os
from struct import pack

# Reload logging just needed for jupyter notebook for proper logging
from importlib import reload
reload(logging)

ROOT_PATH = '/home/onder/Repos/BLM6106_Data_Compression/03-Project'
LOGGER_CONFIG_PATH = ROOT_PATH + '/logger_config.yaml'

# Logger Configurations Part
# TODO: Make path relative to portability
with open(LOGGER_CONFIG_PATH, 'r') as file:
    config = yaml.safe_load(file.read())
    logging.config.dictConfig(config)

logger = logging.getLogger(__name__)

def compress(file_path, max_codebook_size):
    input_file = open(file_path)
    uncompressed_data = input_file.read()

    logger.debug("max_codebook_size: {0}".format(max_codebook_size))

    codebook_size = 256
    dictionary = {chr(i): i for i in range(codebook_size)}
    logger.debug('Dictionary: {0}'.format(dictionary))
    compressed_data = []
    code_word = ""

    for character in uncompressed_data:
        
        new_sequence = code_word + character
        if new_sequence in dictionary:
            code_word = new_sequence
        else:
            compressed_data.append(dictionary[code_word])
            if(len(dictionary) <= max_codebook_size):
                dictionary[new_sequence] = codebook_size
                codebook_size += 1
            code_word = character

    if code_word in dictionary:
        compressed_data.append(dictionary[code_word])

    logger.warning('Final codebook size: {0}'.format(codebook_size))

    file_name, file_extension = os.path.splitext(os.path.basename(file_path))
    compressed_file_path = ROOT_PATH + "/" + file_name + '.lzw'
    output_file = open(compressed_file_path, "wb")
    
    for data in compressed_data:
        output_file.write(pack('>H',int(data)))

    output_file.close()
    input_file.close()
