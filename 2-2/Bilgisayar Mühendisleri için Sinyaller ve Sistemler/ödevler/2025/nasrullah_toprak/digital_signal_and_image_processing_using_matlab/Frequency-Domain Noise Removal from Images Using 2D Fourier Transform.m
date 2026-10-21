clc;
clear;
close all;

% 1. Görüntünün okunması
img = imread('noisy_image.png');

if size(img, 3) == 3
    grayImg = rgb2gray(img);
else
    grayImg = img;
end

grayImg = im2double(grayImg);

[rows, cols] = size(grayImg);
minVal = min(grayImg(:));
maxVal = max(grayImg(:));

fprintf('Görüntü boyutu: %d x %d piksel\n', rows, cols);
fprintf('Piksel değer aralığı: [%.2f, %.2f]\n', minVal, maxVal);

figure;
imshow(grayImg, []);
title('Gürültülü Gri Seviye Görüntü');

% 2. 2B Fourier dönüşümünün hesaplanması
F = fft2(grayImg);
F_shifted = fftshift(F);

% 3. Genlik spektrumunun görselleştirilmesi
magnitudeSpectrum = abs(F_shifted);
logSpectrum = log(1 + magnitudeSpectrum);

figure;
imshow(magnitudeSpectrum, []);
title('Fourier Genlik Spektrumu');

figure;
imshow(logSpectrum, []);
title('Logaritmik Fourier Genlik Spektrumu');

% 4. Gürültü frekanslarının belirlenmesi
centerRow = floor(rows / 2) + 1;
centerCol = floor(cols / 2) + 1;

[X_grid, Y_grid] = meshgrid(1:cols, 1:rows);
tempSpectrum = logSpectrum;

centerMaskRadius = 25;
centerMask = sqrt((X_grid - centerCol).^2 + ...
                  (Y_grid - centerRow).^2) < centerMaskRadius;
tempSpectrum(centerMask) = 0;

thresholdValue = mean(tempSpectrum(:)) + 2.5 * std(tempSpectrum(:));
tempSpectrum(tempSpectrum < thresholdValue) = 0;

num_peak_pairs = 2;
peakRows = [];
peakCols = [];
fprintf('\n');
fprintf('Pik No\tSatir\tSutun\tKonum\t\t\tAciklama\n');

for i = 1:num_peak_pairs
    [maxValPeak, maxIdx] = max(tempSpectrum(:));
    
    if maxValPeak == 0
        break;
    end
    
    [p_row, p_col] = ind2sub([rows, cols], maxIdx);
    
    p2_row = 2 * centerRow - p_row;
    p2_col = 2 * centerCol - p_col;
    if p2_row < 1 || p2_row > rows || p2_col < 1 || p2_col > cols
        tempSpectrum(p_row, p_col) = 0;
        continue;
    end
    
    peakRows = [peakRows, p_row, p2_row];
    peakCols = [peakCols, p_col, p2_col];
    
    fprintf('%d\t%d\t%d\tGürültü Konumu\t\tGurultu bileseni\n', ...
        length(peakRows) - 1, p_row, p_col);
    fprintf('%d\t%d\t%d\tSimetrik Konum\t\tSimetrik gurultu bileseni\n', ...
        length(peakRows), p2_row, p2_col);
    suppressRadius = 12;
    
    localMask1 = sqrt((X_grid - p_col).^2 + ...
                      (Y_grid - p_row).^2) < suppressRadius;
                  
    localMask2 = sqrt((X_grid - p2_col).^2 + ...
                      (Y_grid - p2_row).^2) < suppressRadius;
                  
    tempSpectrum(localMask1 | localMask2) = 0;
end

figure;
imshow(logSpectrum, []);
title('Belirlenen Gürültü Frekansları');
hold on;

for k = 1:length(peakRows)
    plot(peakCols(k), peakRows(k), 'r*', 'MarkerSize', 12);
end

hold off;

% 5. Frekans alanında filtre tasarımı
radius = 7;

H = ones(rows, cols);

for k = 1:length(peakRows)
    D = sqrt((Y_grid - peakRows(k)).^2 + ...
             (X_grid - peakCols(k)).^2);
         
    H(D <= radius) = 0;
end

G_shifted = F_shifted .* H;

figure;
imshow(H, []);
colormap gray;
colorbar;
title('Frekans Alanı Filtre Maskesi');

filteredLogSpectrum = log(1 + abs(G_shifted));

figure;
imshow(filteredLogSpectrum, []);
title('Filtrelenmiş Logaritmik Fourier Spektrumu');

fprintf('\n');
fprintf('Filtre yaricapi: %d piksel\n', radius);
fprintf('Filtrelenen toplam pik sayisi: %d\n', length(peakRows));

% 6. Ters Fourier dönüşümü ile görüntünün geri oluşturulması
G = ifftshift(G_shifted);
restoredImg = ifft2(G);
restoredImg = real(restoredImg);

restoredImg = restoredImg - min(restoredImg(:));
maxValRestored = max(restoredImg(:));

if maxValRestored ~= 0
    restoredImg = restoredImg / maxValRestored;
end

figure;
imshow(restoredImg, []);
title('Temizlenmiş Görüntü');
