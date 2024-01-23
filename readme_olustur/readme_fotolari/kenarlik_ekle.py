import sys
from PIL import Image, ImageOps

def add_border_to_image(image_path, border_size=10):
    with Image.open(image_path) as img:
        new_img = ImageOps.expand(img, border=border_size, fill='black')
        new_img.save(image_path)

def resize_image(image_path, new_width, new_height):
    with Image.open(image_path) as img:
        img.thumbnail((new_width, new_height))
        img.save(image_path)

def process_images(images, border_size=10, new_width=800, new_height=600):
    for image_path in images:
        add_border_to_image(image_path, border_size)
        resize_image(image_path, new_width, new_height)

# Komut satırı argümanları
if len(sys.argv) < 2:
    print("Usage: python3 kenarlik_ekle.py [image1 image2 ...]")
else:
    images = sys.argv[1:]

    process_images(images)
