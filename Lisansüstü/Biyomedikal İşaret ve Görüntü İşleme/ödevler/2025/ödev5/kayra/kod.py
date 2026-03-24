import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

# Klasör yapısını oluştur
os.makedirs('dest', exist_ok=True)

def calculate_and_plot_histogram(image_path, output_name):
    """
    Bir gray-level görüntünün histogramını ve log histogramını hesaplayıp kaydeder
    """
    # Görüntüyü oku
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    
    if img is None:
        print(f"Hata: {image_path} dosyası okunamadı!")
        return
    
    # Histogram hesapla
    hist = cv2.calcHist([img], [0], None, [256], [0, 256])
    hist = hist.flatten()
    
    # Log histogram hesapla (0 değerlerini önlemek için +1 ekliyoruz)
    log_hist = np.log(hist + 1)
    
    # Normalize et (aynı grafikte göstermek için)
    hist_normalized = hist / hist.max()
    log_hist_normalized = log_hist / log_hist.max()
    
    # Grafik oluştur
    plt.figure(figsize=(15, 5))
    
    # Orijinal görüntü
    plt.subplot(1, 3, 1)
    plt.imshow(img, cmap='gray')
    plt.title(f'Orijinal Görüntü\n{output_name}')
    plt.axis('off')
    
    # Histogram ve Log Histogram
    plt.subplot(1, 3, 2)
    plt.plot(hist_normalized, color='blue', label='Histogram (Normalized)')
    plt.plot(log_hist_normalized, color='red', label='Log Histogram (Normalized)')
    plt.title('Histogram ve Log Histogram')
    plt.xlabel('Piksel Değeri')
    plt.ylabel('Normalize Edilmiş Frekans')
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    # Sadece histogram
    plt.subplot(1, 3, 3)
    plt.bar(range(256), hist, color='gray', alpha=0.7)
    plt.title('Histogram (Orijinal)')
    plt.xlabel('Piksel Değeri')
    plt.ylabel('Frekans')
    plt.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(f'dest/{output_name}_histogram.png', dpi=300, bbox_inches='tight')
    plt.close()
    
    print(f"✓ {output_name} için histogram kaydedildi: dest/{output_name}_histogram.png")

def histogram_equalization_custom_range(image_path, min_val, max_val, range_name):
    """
    Belirli bir aralık için histogram eşitleme yapar
    """
    # Görüntüyü oku
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    
    if img is None:
        print(f"Hata: {image_path} dosyası okunamadı!")
        return
    
    # Orijinal histogram
    hist_original = cv2.calcHist([img], [0], None, [256], [0, 256]).flatten()
    
    # Belirli aralıkta histogram eşitleme
    img_clipped = np.clip(img, min_val, max_val)
    
    # Aralığı 0-255'e normalize et
    img_normalized = ((img_clipped - min_val) / (max_val - min_val) * 255).astype(np.uint8)
    
    # Histogram eşitleme uygula
    img_equalized = cv2.equalizeHist(img_normalized)
    
    # Histogram hesapla
    hist_equalized = cv2.calcHist([img_equalized], [0], None, [256], [0, 256]).flatten()
    
    # Grafik oluştur
    plt.figure(figsize=(18, 6))
    
    # Orijinal görüntü
    plt.subplot(2, 4, 1)
    plt.imshow(img, cmap='gray')
    plt.title('Orijinal Görüntü')
    plt.axis('off')
    
    # Orijinal histogram
    plt.subplot(2, 4, 2)
    plt.bar(range(256), hist_original, color='blue', alpha=0.7)
    plt.title('Orijinal Histogram')
    plt.xlabel('Piksel Değeri')
    plt.ylabel('Frekans')
    plt.grid(True, alpha=0.3)
    
    # Kırpılmış görüntü
    plt.subplot(2, 4, 3)
    plt.imshow(img_normalized, cmap='gray')
    plt.title(f'Aralık: [{min_val}, {max_val}]')
    plt.axis('off')
    
    # Eşitlenmiş görüntü
    plt.subplot(2, 4, 4)
    plt.imshow(img_equalized, cmap='gray')
    plt.title(f'Eşitlenmiş Görüntü\n({range_name})')
    plt.axis('off')
    
    # Karşılaştırmalı histogramlar
    plt.subplot(2, 4, 5)
    plt.bar(range(256), hist_original, color='blue', alpha=0.5, label='Orijinal')
    plt.title('Orijinal Histogram')
    plt.xlabel('Piksel Değeri')
    plt.ylabel('Frekans')
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    plt.subplot(2, 4, 6)
    plt.bar(range(256), hist_equalized, color='green', alpha=0.5, label='Eşitlenmiş')
    plt.title('Eşitlenmiş Histogram')
    plt.xlabel('Piksel Değeri')
    plt.ylabel('Frekans')
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    # Kümülatif dağılım fonksiyonları
    plt.subplot(2, 4, 7)
    cdf_original = np.cumsum(hist_original)
    cdf_original = cdf_original / cdf_original.max()
    plt.plot(cdf_original, color='blue', label='Orijinal CDF')
    plt.title('Kümülatif Dağılım (Orijinal)')
    plt.xlabel('Piksel Değeri')
    plt.ylabel('Kümülatif Olasılık')
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    plt.subplot(2, 4, 8)
    cdf_equalized = np.cumsum(hist_equalized)
    cdf_equalized = cdf_equalized / cdf_equalized.max()
    plt.plot(cdf_equalized, color='green', label='Eşitlenmiş CDF')
    plt.title('Kümülatif Dağılım (Eşitlenmiş)')
    plt.xlabel('Piksel Değeri')
    plt.ylabel('Kümülatif Olasılık')
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(f'dest/low_contrast_equalized_{range_name}.png', dpi=300, bbox_inches='tight')
    plt.close()
    
    # Eşitlenmiş görüntüyü kaydet
    cv2.imwrite(f'dest/low_contrast_equalized_{range_name}_image.jpg', img_equalized)
    
    print(f"✓ {range_name} aralığı için histogram eşitleme tamamlandı")
    print(f"  - Grafik: dest/low_contrast_equalized_{range_name}.png")
    print(f"  - Görüntü: dest/low_contrast_equalized_{range_name}_image.jpg")

# Ana program
if __name__ == "__main__":
    print("=" * 60)
    print("ÖDEV 5: Histogram Analizi ve Eşitleme")
    print("=" * 60)
    
    # A) Gray-scale görüntülerin histogramlarını çıkar
    print("\n[A] Gray-scale görüntülerin histogramları hesaplanıyor...\n")
    
    gray_images = [
        'src/gray_scale_1.jpg',
        'src/gray_scale_2.jpg',
        'src/gray_scale_3.jpg'
    ]
    
    for i, img_path in enumerate(gray_images, 1):
        if os.path.exists(img_path):
            calculate_and_plot_histogram(img_path, f'gray_scale_{i}')
        else:
            print(f"⚠ Uyarı: {img_path} bulunamadı!")
    
    # B) Düşük kontrastlı görüntü için histogram eşitleme
    print("\n" + "=" * 60)
    print("[B] Düşük kontrastlı görüntü için histogram eşitleme yapılıyor...\n")
    
    low_contrast_path = 'src/low_contrast.jpg'
    
    if os.path.exists(low_contrast_path):
        # Düşük aralık (0-130)
        print("\n1. Düşük Kontrast Aralığı (0-130):")
        histogram_equalization_custom_range(low_contrast_path, 0, 130, 'dusuk_aralik')
        
        # Orta aralık (100-170)
        print("\n2. Orta Kontrast Aralığı (100-170):")
        histogram_equalization_custom_range(low_contrast_path, 100, 170, 'orta_aralik')
        
        # Yüksek aralık (170-255)
        print("\n3. Yüksek Kontrast Aralığı (170-255):")
        histogram_equalization_custom_range(low_contrast_path, 130, 255, 'yuksek_aralik')
    else:
        print(f"⚠ Uyarı: {low_contrast_path} bulunamadı!")
    
    print("\n" + "=" * 60)
    print("✓ Tüm işlemler tamamlandı!")
    print("✓ Sonuçlar 'dest' klasörüne kaydedildi.")
    print("=" * 60)
