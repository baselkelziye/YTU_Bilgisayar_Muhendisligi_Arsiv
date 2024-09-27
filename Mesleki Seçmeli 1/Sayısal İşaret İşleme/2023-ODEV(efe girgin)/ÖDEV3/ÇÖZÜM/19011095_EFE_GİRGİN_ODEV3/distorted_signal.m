% Veriyi yükle
load prodoftwo.mat

% 2D Fourier Dönüşümünü uygula
FT_prod = fft2(prodoftwo);

% Bileşenleri izole et
FT_comp1 = zeros(size(FT_prod)); % İlk bileşen için yer tutucu
FT_comp2 = zeros(size(FT_prod)); % İkinci bileşen için yer tutucu

% Maskeleri, bireysel spektraların özelliklerine göre değiştir
% Örneğin:
FT_comp1(1:50, 1:50) = FT_prod(1:50, 1:50); % Örnek varsayım
FT_comp2(51:100, 51:100) = FT_prod(51:100, 51:100); % Örnek varsayım

% Ters DFT ile mekansal alan sinyallerini geri kazan
component1 = ifft2(FT_comp1);
component2 = ifft2(FT_comp2);

% Sonuçları göster
figure; 
subplot(2,2,1); imagesc(prodoftwo); 
title('Orijinal Çarpım Sinyali');

subplot(2,2,2); imagesc(abs(component1)); 
title('İzolasyon Bileşeni 1');

subplot(2,2,3); imagesc(abs(component2)); 
title('İzolasyon Bileşeni 2');
