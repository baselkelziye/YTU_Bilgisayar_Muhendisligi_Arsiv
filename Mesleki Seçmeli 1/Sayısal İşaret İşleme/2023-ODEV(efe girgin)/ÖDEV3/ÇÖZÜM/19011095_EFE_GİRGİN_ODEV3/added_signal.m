% Veriyi yükle
load sumofthree.mat


%fft2 fonksiyonu 2 boyutlu fouier dönüşümü uygular
% Toplam sinyalin 2D Fourier Dönüşümünü hesapla
F = fft2(sumofthree);

% Orijinal sinyallerin frekans alanındaki konumları veya doğaları hakkında bilgi varsayılarak,
% her bir bileşeni izole ederiz. Örneğin:
F1 = zeros(size(F)); % İlk bileşen için yer tutucu
F2 = zeros(size(F)); % İkinci bileşen için yer tutucu
F3 = zeros(size(F)); % Üçüncü bileşen için yer tutucu

% Bu maskeleri, bireysel spektraların bilinen veya varsayılan özelliklerine göre değiştirin
F1(1:50, 1:50) = F(1:50, 1:50); % Örnek varsayım
F2(51:100, 51:100) = F(51:100, 51:100); % Örnek varsayım
F3(101:end, 101:end) = F(101:end, 101:end); % Örnek varsayım

% Ters DFT ile mekansal alan sinyallerini geri kazan
signal1 = ifft2(F1);
signal2 = ifft2(F2);
signal3 = ifft2(F3);

% Sonuçları göster
figure; subplot(2,2,1); imagesc(sumofthree); 
title('Orjinal Toplam Sinyal');

subplot(2,2,2); imagesc(abs(signal1)); 
title('Kazanılan Sinyal 1');

subplot(2,2,3); imagesc(abs(signal2)); 
title('Kazanılan Sinyal 2');

subplot(2,2,4); imagesc(abs(signal3)); 
title('Kazanılan Sinyal 3');
