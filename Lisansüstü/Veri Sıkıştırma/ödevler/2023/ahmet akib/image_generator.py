import cv2
import numpy as np
img_name = "odev/lion"
def quantize_image(image, max_value, levels):
    # Ölçekleme faktörünü hesapla
    factor = max_value / levels
    
    # Ölçekleme işlemi
    quantized_image = (image / (256 / max_value))
    quantized_image = (quantized_image / factor)
    
    quantized_image = np.floor(quantized_image).astype(np.uint8)
    quantized_image *= int(factor)
    
    return quantized_image

# PNG resmini yükleyin
png_image = cv2.imread('odev/lion.png', cv2.IMREAD_UNCHANGED)

# Eşik değerini ayarlayın (örneğin, 128)
threshold_value = 128

# İlk resmi gri tonlama yapın
gray_image = cv2.cvtColor(png_image, cv2.COLOR_BGR2GRAY)
quantized_image = quantize_image(gray_image, 256, 16)

# Eşikleme işlemini uygulayın
_, bw_image = cv2.threshold(gray_image, threshold_value, 255, cv2.THRESH_BINARY)

# Siyah-Beyaz resmi BMP olarak kaydedin
cv2.imwrite(img_name+'bw_image.bmp', bw_image)

# 2. Gri Tonlamalı (Grayscale) Sürüm Oluşturun ve BMP olarak kaydedin
gray_image = cv2.cvtColor(png_image, cv2.COLOR_BGR2GRAY)
cv2.imwrite(img_name+'gray_image.bmp', gray_image)
cv2.imwrite(img_name+'gray_image_q.bmp', quantized_image)

# 3. Renk Paletli (Color Table) Sürüm Oluşturun ve BMP olarak kaydedin
color_table_image = cv2.cvtColor(png_image, cv2.COLOR_BGR2RGB)
cv2.imwrite(img_name+'color_table_image.bmp', color_table_image)

print("Sürümler BMP formatında başarıyla kaydedildi.")
