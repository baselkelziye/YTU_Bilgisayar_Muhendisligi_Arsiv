#!/usr/bin/python3

import math
import random
from bitarray import bitarray

import compressor

import logging
import logging.config
import yaml

from PIL import Image
import os

import cv2

# Logger Configurations Part
# TODO: Make path relative to portability
with open(
        '/home/onder/Repos/BLM6106_Data_Compression/02-Homeworks/Homework1/logger_config.yaml',
        'r') as file:
    config = yaml.safe_load(file.read())
    logging.config.dictConfig(config)

logger = logging.getLogger(__name__)


class Compressor:
    """Compressor"""

    EIGHT_BIT = 8
    EIGHT_BYTE = 8
    SIXTY_FOUR_BIT = 64

    temp_byte_array = bytearray()
    compressed_row = bytearray(0)
    counter = 0
    is_pixel_contains_run_value = bitarray(EIGHT_BIT * EIGHT_BYTE)
    is_pixel_contains_run_value.setall(False)
    pixel_repetition_count = 1
    previous_pixel = 0

    @staticmethod
    def check_counter_one_byte_left():
        if (Compressor.counter == (Compressor.SIXTY_FOUR_BIT - 1)):
            # Sadece tek byte sonda boş kalmıştır. Buna da run yazıp devam edemeyiz.
            # Sonrasında da 0 değerini value olarak yazıyoruz.
            # Dolayısıyla buna pixel değerini yazıp tekrar sayısını 1 azaltıyoruz.

            Compressor.temp_byte_array += Compressor.previous_pixel.to_bytes(
                1, 'big')
            Compressor.pixel_repetition_count -= 1

            Compressor.compressed_row += Compressor.is_pixel_contains_run_value.tobytes(
            )
            Compressor.is_pixel_contains_run_value.setall(False)
            Compressor.counter = 0

            Compressor.compressed_row += Compressor.temp_byte_array
            Compressor.temp_byte_array.clear()

    @staticmethod
    def check_counter_overflow():

        # Bir sonraki işlemde Compressor.counter nedeniyle overflow olmaması için
        if (Compressor.counter == Compressor.SIXTY_FOUR_BIT):
            Compressor.compressed_row += Compressor.is_pixel_contains_run_value.tobytes(
            )
            Compressor.is_pixel_contains_run_value.setall(False)
            Compressor.counter = 0

            Compressor.compressed_row += Compressor.temp_byte_array
            Compressor.temp_byte_array.clear()

        # TODO: test için sil.
        if (Compressor.pixel_repetition_count < 1):
            print('Wrong logic: pixel_repetition_count < 1')

        if (Compressor.counter < 0):
            print('Wrong logic: counter < 0')

        if (Compressor.counter > 63):
            print('Wrong logic: counter > 63')

    @staticmethod
    def compress_row(original_row):

        logger.info('original_row: ' + original_row.hex())
        logger.warning('original_row length: ' + str(len(original_row)))

        global EIGHT_BIT
        global EIGHT_BYTE
        global SIXTY_FOUR_BIT

        global temp_byte_array
        Compressor.temp_byte_array = bytearray()
        global compressed_row
        Compressor.compressed_row = bytearray(0)

        # TODO: Anlamlı bir isim ver
        global counter
        Compressor.counter = 0

        # 64 bitlik bir sayıyı tutacak
        global is_pixel_contains_run_value
        Compressor.is_pixel_contains_run_value.setall(False)
        # TODO: 8 bite tamamlanacak şekilde doldurulacak

        global pixel_repetition_count
        Compressor.pixel_repetition_count = 1
        global previous_pixel
        Compressor.previous_pixel = 0

        for idx in range(len(original_row) - 1):
            Compressor.previous_pixel = original_row[idx]
            current_pixel = original_row[idx + 1]

            if (current_pixel == Compressor.previous_pixel):
                Compressor.pixel_repetition_count += 1
            else:
                if (Compressor.pixel_repetition_count > 1):
                    # TODO: Bu değeri her 8 bit te tekrar başa yaz. Sonra da burdan okunarak işlem yapılacak.
                    # Compressor.is_pixel_contains_run_value.append(True)
                    # TODO: Compressor.counter 64 ü geçince başa döndürecek bir mekanizma kur.

                    while (Compressor.pixel_repetition_count > 255):
                        # Compressor.pixel_repetition_count = 135780 gibi çok büyük bir değer aldığında, Compressor.previous_pixel 0 değerinde olsun
                        # Bu koşulda sırayla şu şekilde yazılıyor: 255, 0, 255, 0, 255, 0 gibi
                        # bu sayıların toplamının 64 bit i geçmediğinden emin olmak için aşağıdaki kontrol yapılmak zorunda.

                        Compressor.check_counter_one_byte_left()

                        # Bir sonraki işlemde counter nedeniyle overflow olmaması için
                        Compressor.check_counter_overflow()

                        Compressor.is_pixel_contains_run_value[
                            Compressor.counter] = True
                        Compressor.counter += 1
                        Compressor.temp_byte_array += (255).to_bytes(1, 'big')
                        Compressor.counter += 1
                        Compressor.temp_byte_array += Compressor.previous_pixel.to_bytes(
                            1, 'big')
                        Compressor.pixel_repetition_count -= 255

                    # TODO: Burada 63
                    Compressor.check_counter_one_byte_left()

                    # Bir sonraki işlemde counter nedeniyle overflow olmaması için
                    Compressor.check_counter_overflow()

                    Compressor.is_pixel_contains_run_value[
                        Compressor.counter] = True
                    Compressor.counter += 1
                    Compressor.temp_byte_array += Compressor.pixel_repetition_count.to_bytes(
                        1, 'big')
                    Compressor.pixel_repetition_count = 1

                Compressor.counter += 1
                Compressor.temp_byte_array += Compressor.previous_pixel.to_bytes(
                    1, 'big')

                # TODO: Bu işin if içerisinde temp byte array e atama yapılırken son buluyor olması da kontrol ediliyor olabilir.
                # Yani else durumda da çalışıyor olması gerekiyor belki de.
                # 8 byte tamamlandığında Compressor.compressed_row içerisine baştaki 8 bitlik değer ve 8 byte lık data yazılır.
                # Son byte RLE nin byte ise nasıl olacak? orasını bi düşün.

                # Bir sonraki işlemde counter nedeniyle overflow olmaması için
                Compressor.check_counter_overflow()

        # Son pixel bir önceki pixel ile aynı ise for dan çıkıldığında yazma işleminin yapılması için kondu.
        if (Compressor.pixel_repetition_count > 1):
            # TODO: Bu değeri her 8 bit te tekrar başa yaz. Sonra da burdan okunarak işlem yapılacak.
            # Compressor.is_pixel_contains_run_value.append(True)
            # TODO: Compressor.is_pixel_contains_run_value[idx % 8] = True
            # Compressor.compressed_row.append(Compressor.pixel_repetition_count)
            # Compressor.compressed_row.append(Compressor.previous_pixel)
            while (Compressor.pixel_repetition_count > 255):
                # Compressor.pixel_repetition_count = 135780 gibi çok büyük bir değer aldığında, Compressor.previous_pixel 0 değerinde olsun
                # Bu koşulda sırayla şu şekilde yazılıyor: 255, 0, 255, 0, 255, 0 gibi
                # bu sayıların toplamının 64 bit i geçmediğinden emin olmak için aşağıdaki kontrol yapılmak zorunda.

                Compressor.check_counter_one_byte_left()

                # Bir sonraki işlemde counter nedeniyle overflow olmaması için
                Compressor.check_counter_overflow()

                Compressor.is_pixel_contains_run_value[
                    Compressor.counter] = True
                Compressor.counter += 1
                Compressor.temp_byte_array += (255).to_bytes(1, 'big')
                Compressor.counter += 1
                Compressor.temp_byte_array += Compressor.previous_pixel.to_bytes(
                    1, 'big')
                Compressor.pixel_repetition_count -= 255

            Compressor.check_counter_one_byte_left()

            # Bir sonraki işlemde counter nedeniyle overflow olmaması için
            Compressor.check_counter_overflow()

            Compressor.is_pixel_contains_run_value[Compressor.counter] = True
            Compressor.counter += 1
            Compressor.temp_byte_array += Compressor.pixel_repetition_count.to_bytes(
                1, 'big')
            Compressor.temp_byte_array += Compressor.previous_pixel.to_bytes(
                1, 'big')
        else:
            # Bir sonraki işlemde counter nedeniyle overflow olmaması için
            Compressor.check_counter_overflow()

            # Tek pixel kalmış demektir ve bu da current_pixel içerisindedir
            Compressor.temp_byte_array += current_pixel.to_bytes(1, 'big')

        Compressor.compressed_row += Compressor.is_pixel_contains_run_value.tobytes(
        )
        Compressor.compressed_row += Compressor.temp_byte_array

        logger.info('Compressor.compressed_row: ' +
                    Compressor.compressed_row.hex())
        logger.warning('Compressor.compressed_row length: ' +
                       str(len(Compressor.compressed_row)))

        return Compressor.compressed_row

    @staticmethod
    def compress_image(image_path):

        print('Image path: ' + image_path)
        orginal_image = Image.open(image_path)
        orginal_image_stats = os.stat(image_path)

        print('')
        print('Image total size in bytes is: ' +
              str(orginal_image_stats.st_size) + ' B')
        print('Image total size in  kilobytes is: ' +
              str(orginal_image_stats.st_size / 1000) + ' KB')
        print('Image total size in  megabyte is: ' +
              str(orginal_image_stats.st_size / (1000 * 1000)) + ' MB')

        width, height = orginal_image.size
        print('')
        print('width: ' + str(width))
        print('height: ' + str(height))

        data = orginal_image.getdata()

        gray_scale = 'L'
        rgb_mode = 'RGB'
        pixel_list = bytearray()
        if (orginal_image.mode == gray_scale):
            pixel_list = bytearray(data)
        elif (orginal_image.mode == rgb_mode):
            img = cv2.imread(image_path)
            blue, green, red = cv2.split(img)
            pixel_list = bytearray(red) + bytearray(green) + bytearray(blue)

        print('Pixel count: ' + str(len(pixel_list)))

        header_size = orginal_image_stats.st_size - len(pixel_list)
        print('Header size: ' + str(orginal_image_stats.st_size) + ' - ' +
              str(len(pixel_list)) + ' = ' + str(header_size))

        compressed_row = compressor.Compressor.compress_row(pixel_list)

        compressed_pixel_size = len(compressed_row)
        input_stream_size = orginal_image_stats.st_size
        output_stream_size = header_size + compressed_pixel_size
        compression_ratio = output_stream_size / input_stream_size

        print('')
        print(
            'compression ratio = (header size + compressed pixel size) / image total size'
        )
        print('compression ratio = (' + str(header_size) + ' + ' +
              str(compressed_pixel_size) + ') / ' + str(input_stream_size) +
              ' = ' + str(compression_ratio))

        print('')
        compression_performance = 100 * (1 - compression_ratio)
        print('Compression Performance = 100 * (1 - Compression Ratio)')
        print('Compression Performance = ' +
              "{:.2f}".format(compression_performance) + '%')

        print('')
