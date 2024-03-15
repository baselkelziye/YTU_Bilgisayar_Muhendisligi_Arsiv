import logging
import logging.config
import yaml

from struct import unpack
import os

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

def decompress(file_path):
    input_file = open(file_path, "rb")
    compressed_data = []

    while True:
        rec = input_file.read(2)
        if len(rec) != 2:
            break
        (data, ) = unpack('>H', rec)
        compressed_data.append(data)

    # Init codebook
    codebook_size = 256
    dictionary = dict([(x, chr(x)) for x in range(codebook_size)])
    logger.debug('Dictionary: {0}'.format(dictionary))

    code_word = ""
    decompressed_data = ""
    string = ""
    for character in compressed_data:
        if not (character in dictionary):
            dictionary[character] = string + (string[0])
        
        decompressed_data += dictionary[character]
        
        if not(len(string) == 0):
            dictionary[codebook_size] = string + (dictionary[character][0])
            codebook_size += 1
        string = dictionary[character]

    file_name, file_extension = os.path.splitext(os.path.basename(file_path))
    uncompressed_file_path = ROOT_PATH + "/" + file_name + '_decoded.txt'
    output_file = open(uncompressed_file_path, "w")

    for data in decompressed_data:
        output_file.write(data)

    output_file.close()
    input_file.close()
