#!/usr/bin/python3

import unittest

import compressor

from PIL import Image
import os


class TestCompressor(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        print("setUpClass method called!")

    @classmethod
    def tearDownClass(cls):
        print("tearDownClass method called!")

    def setUp(self):
        print('setUp method called!')

    def tearDown(cls):
        print("tearDown method called!")

    def test_compress_row(self):
        print("Test compress_row() function starting...")

        # Tüm pixellerin aynı değerden oluştuğu durum
        original_row = bytearray([50, 50, 50, 50, 50, 50, 50, 50])
        expected_compressed_row = bytearray([0x80, 0, 0, 0, 0, 0, 0, 0, 8, 50])

        self.assertEqual(compressor.Compressor.compress_row(original_row),
                         expected_compressed_row)

        # Son pixel farklı olduğu durum
        original_row = bytearray([50, 50, 50, 50, 50, 50, 50, 60])
        expected_compressed_row = bytearray(
            [0x80, 0, 0, 0, 0, 0, 0, 0, 7, 50, 60])
        self.assertEqual(
            compressor.Compressor.compress_row(original_row).hex(),
            expected_compressed_row.hex())

        # Son iki pixelin aynı olduğu durum
        original_row = bytearray([50, 50, 40, 50, 50, 50, 60, 60])
        expected_compressed_row = bytearray(
            [0x94, 0, 0, 0, 0, 0, 0, 0, 2, 50, 40, 3, 50, 2, 60])
        self.assertEqual(
            compressor.Compressor.compress_row(original_row).hex(),
            expected_compressed_row.hex())

        # 255 pixelin aynı olduğu durum
        original_row = bytearray([100] * 255)
        expected_compressed_row = bytearray(
            [0x80, 0, 0, 0, 0, 0, 0, 0, 255, 100])
        self.assertEqual(
            compressor.Compressor.compress_row(original_row).hex(),
            expected_compressed_row.hex())

        # 300 pixelin aynı olduğu durum
        original_row = bytearray([100] * 300)
        expected_compressed_row = bytearray(
            [0xA0, 0, 0, 0, 0, 0, 0, 0, 255, 100, 45, 100])
        self.assertEqual(
            compressor.Compressor.compress_row(original_row).hex(),
            expected_compressed_row.hex())

        # 800 pixelin aynı olduğu durum, for döngüsü içindeki if bloğu çalışsın diye
        original_row = bytearray([100] * 800)
        expected_compressed_row = bytearray(
            [0xAA, 0, 0, 0, 0, 0, 0, 0, 255, 100, 255, 100, 255, 100, 35, 100])
        self.assertEqual(
            compressor.Compressor.compress_row(original_row).hex(),
            expected_compressed_row.hex())

        # 800 pixelin aynı olduğu durum, for döngüsü dışındaki if bloğu çalışsın diye
        original_row = bytearray([100] * 800) + bytearray([50, 70, 60])
        expected_compressed_row = bytearray([
            0xAA, 0, 0, 0, 0, 0, 0, 0, 255, 100, 255, 100, 255, 100, 35, 100,
            50, 70, 60
        ])
        self.assertEqual(
            compressor.Compressor.compress_row(original_row).hex(),
            expected_compressed_row.hex())

        # 1'den 300'e kadar olan sayıların olduğu durum
        original_row = bytearray(range(0, 256)) + bytearray(range(0, 44))
        expected_compressed_row = bytearray(
            [0, 0, 0, 0, 0, 0, 0, 0]) + bytearray(range(0, 64)) + bytearray([
                0, 0, 0, 0, 0, 0, 0, 0
            ]) + bytearray(range(64, 128)) + bytearray([
                0, 0, 0, 0, 0, 0, 0, 0
            ]) + bytearray(range(128, 192)) + bytearray([
                0, 0, 0, 0, 0, 0, 0, 0
            ]) + bytearray(range(192, 256)) + bytearray(
                [0, 0, 0, 0, 0, 0, 0, 0]) + bytearray(range(0, 44))
        self.assertEqual(
            compressor.Compressor.compress_row(original_row).hex(),
            expected_compressed_row.hex())

        # TODO: Arka arkaya 255 ten fazla tane aynı değer gelirse kalanı farklı bir sayı gelmiş gibi işlemeye devam et
        # TODO: 64. byte ın rle sayısal değeri olmasına izin vermeli miyiz?
        #       Sonrasında gelen değerlerin sayısını temsil edebilir gibi sanki

        print("Test compress_row() function finished successfully!")

    def test_black_and_white(self):
        print("Test test_black_and_white() function starting...")
        IMAGE_PATH = '/home/onder/Repos/BLM6106_Data_Compression/02-Homeworks/Homework1/images/black_and_white.bmp'

        compressor.Compressor.compress_image(IMAGE_PATH)

        print("Test test_black_and_white() function finished successfully!")

    def test_black_and_white_1(self):
        print("Test test_black_and_white_1() function starting...")
        IMAGE_PATH = '/home/onder/Repos/BLM6106_Data_Compression/02-Homeworks/Homework1/images/black_and_white_1.bmp'

        compressor.Compressor.compress_image(IMAGE_PATH)

        print("Test test_black_and_white_1() function finished successfully!")

    def test_lenna(self):
        print("Test test_lenna() function starting...")

        IMAGE_PATH = '/home/onder/Repos/BLM6106_Data_Compression/02-Homeworks/Homework1/images/lenna.bmp'
        print('Image path: ' + IMAGE_PATH)
        orginal_image = Image.open(IMAGE_PATH)

        width, height = orginal_image.size
        print('width: ' + str(width))
        print('height: ' + str(height))

        data = orginal_image.getdata()
        pixel_list = bytearray(data)
        print('Pixel list: ' + str(len(pixel_list)))

        compressor.Compressor.compress_row(pixel_list)

        print("Test test_lenna() function finished successfully!")


if __name__ == '__main__':
    unittest.main()
    # Run only specific test method
    # unittest.main(argv=[''],
    #               defaultTest='TestCompressor.test_black_and_white_1')
