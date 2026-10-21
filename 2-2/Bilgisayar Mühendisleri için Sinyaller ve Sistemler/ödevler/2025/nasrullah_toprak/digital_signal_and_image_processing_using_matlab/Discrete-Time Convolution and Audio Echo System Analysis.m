clc;
clear;
close all;

% Kendi convolution hesaplamam
function [z, nz] = myConv(x, nx, y, ny)
    % Giriş  kontrolleri
    if isempty(x) || isempty(y) || isempty(nx) || isempty(ny)
        error('x, y, nx ve ny boş olamaz.');
    end
    if ~isvector(x) || ~isvector(y) || ~isvector(nx) || ~isvector(ny)
        error('x, y, nx ve ny vektör olmalıdır.');
    end
    if ~isnumeric(x) || ~isnumeric(y) || ~isnumeric(nx) || ~isnumeric(ny)
        error('x, y, nx ve ny sayısal olmalıdır.');
    end
    if length(x) ~= length(nx)
        error('x ve nx uzunlukları eşit olmalıdır');
    end
    if length(y) ~= length(ny)
        error('y ve ny uzunlukları eşit olmalıdır');
    end
    if any(diff(nx) ~= 1)
        error('nx ardışık (step=1) olmalıdır');
    end
    if any(diff(ny) ~= 1)
        error('ny ardışık (step=1) olmalıdır');
    end

    Nx = length(x);
    Ny = length(y);
    Nz = Nx + Ny - 1;
    z = zeros(1, Nz);
    nz = (nx(1) + ny(1)) : (nx(end) + ny(end));

    % Konvolüsyon Hesabı
    for k = 1:Nz
        for i=1:Nx
            j=k-i+1;
            if j>=1 && j<=Ny
                z(k)=z(k)+x(i)*y(j);
            end
        end
    end

    % n=0
    zero_index = find(nz == 0);
    if ~isempty(zero_index)
        fprintf('n=0, z dizisinin %d. elemanına karşılık gelmektedir.\n', zero_index);
    else
        fprintf('n=0 sonucu dizide bulunmamaktadır.\n');
    end
end

% Veri Seti 1 (Pozitif) x1, y1
x1 = [1 7 9];
nx1 = 0:2;
y1 = [2 3 1];
ny1 = 0:2;

[z1, nz1] = myConv(x1, nx1, y1, ny1);
z1_builtin = conv(x1, y1);
nz1_builtin = (nx1(1)+ny1(1)) : (nx1(end)+ny1(end));

mse1 = mean((z1 - z1_builtin).^2);

fprintf('\n--- Veri Seti 1 (Pozitif Değerler) ---\n');
disp('x1 =');  disp(x1);
disp('nx1 ='); disp(nx1);
disp('y1 =');  disp(y1);
disp('ny1 ='); disp(ny1);
disp('myConv sonucu z1 ='); disp(z1);
disp('z1 için indis vektörü nz1 ='); disp(nz1);
disp('Hazır conv sonucu ='); disp(z1_builtin);
disp('Hazır conv için indis vektörü ='); disp(nz1_builtin);
fprintf('MSE = %.10f\n', mse1);

figure;
stem(nx1, x1, 'filled'); hold on;
stem(ny1, y1, 'filled');
stem(nz1, z1, 'filled');
stem(nz1_builtin, z1_builtin, '--');
legend('x[n]', 'y[n]', 'myConv', 'conv');
title('Veri Seti 1 - Pozitif Değerler');
xlabel('n');
ylabel('Genlik');
grid on;

fprintf(['Yorum: myConv fonksiyonu ile elde edilen sonuçlar, MATLAB''ın hazır conv fonksiyonu ile tamamen örtüşmektedir. ' ...
         'Hesaplanan MSE değeri sıfıra eşit veya makine hassasiyeti seviyesinde çok küçüktür. ' ...
         'Bu durum geliştirilen algoritmanın doğru çalıştığını göstermektedir.\n']);

fprintf(['Grafik Yorumu: Aynı grafikte gösterilen işaretler tamamen çakışmaktadır. ' ...
         'Bu durum konvolüsyon işleminin doğru hesaplandığını görsel olarak doğrulamaktadır.\n']);

% Veri Seti 2 (Negatif & Sıfır) x2, y2
x2 = [3 -2 0 4];
nx2 = -1:2;
y2 = [1 0 -2];
ny2 = -1:1;

[z2, nz2] = myConv(x2, nx2, y2, ny2);
z2_builtin = conv(x2, y2);
nz2_builtin = (nx2(1)+ny2(1)) : (nx2(end)+ny2(end));

mse2 = mean((z2 - z2_builtin).^2);

fprintf('\n--- Veri Seti 2 (Negatif ve Sıfır İçeren Değerler) ---\n');
disp('x2 =');  disp(x2);
disp('nx2 ='); disp(nx2);
disp('y2 =');  disp(y2);
disp('ny2 ='); disp(ny2);
disp('myConv sonucu z2 ='); disp(z2);
disp('z2 için indis vektörü nz2 ='); disp(nz2);
disp('Hazır conv sonucu ='); disp(z2_builtin);
disp('Hazır conv için indis vektörü ='); disp(nz2_builtin);
fprintf('MSE = %.10f\n', mse2);

figure;
stem(nx2, x2, 'filled'); hold on;
stem(ny2, y2, 'filled');
stem(nz2, z2, 'filled');
stem(nz2_builtin, z2_builtin, '--');
legend('x[n]', 'y[n]', 'myConv', 'conv');
title('Veri Seti 2 - Negatif ve Sıfır İçeren Değerler');
xlabel('n');
ylabel('Genlik');
grid on;

fprintf(['Grafik Yorumu: Tüm sinyaller grafik üzerinde çakışmaktadır. ' ...
         'Bu da elde edilen konvolüsyon sonuçlarının doğruluğunu görsel olarak desteklemektedir.\n']);

% Ses Kaydı
fs = 8000;  % örnekleme frekansı
fprintf('\nKullanılan örnekleme frekansı: %d Hz\n', fs);

% 5 saniye kayıt
recObj1 = audiorecorder(fs, 16, 1);
disp('5 saniyelik kayıt başlıyor...');
recordblocking(recObj1, 5);
disp('Kayıt tamamlandı.');
X1 = getaudiodata(recObj1);
% 10 saniyelik kayıt
recObj2 = audiorecorder(fs, 16, 1);
disp('10 saniyelik kayıt başlıyor...');
recordblocking(recObj2, 10);
disp('Kayıt tamamlandı.');
X2 = getaudiodata(recObj2);

X1 = X1(:).';
X2 = X2(:).';
audiowrite('X1.wav', X1, fs);
audiowrite('X2.wav', X2, fs);
disp('Ses kayıtları başarıyla alındı.');


%% 6,1 
disp('--- 6.1 Dürtü Cevabı ---');
disp('Analitik olarak sistemin dürtü cevabı:');
disp('h[n] = δ[n] + Σ_{k=1}^{M} (A*k)*δ[n - 400k]');

disp('Sistem LTI''dir.');
disp(['Gerekçe: Sistem, girişin ölçeklenmesi ve toplanması altında lineerdir. ' ...
      'Ayrıca sadece gecikmiş örneklerin ağırlıklı toplamı olduğundan zamanla değişmezdir.']);


% 6.2 Doğrudan Denklem ile Hesaplama
A = 0.5;
M = 3;

function y = system_direct(x, M, A)
    x = x(:).';              % satır vektörüne çevir
    N = length(x);
    y = zeros(1, N);

    for n = 1:N
        y(n) = x(n);         % x[n] terimi
        for k = 1:M
            if (n - 400*k) > 0
                y(n) = y(n) + A*k*x(n - 400*k);
            end
        end
    end
end

y1_direct = system_direct(X1', M, A);
y2_direct = system_direct(X2', M, A);
n1 = 0:length(y1_direct)-1;
n2 = 0:length(y2_direct)-1;

figure;
plot(y1_direct);
title('X1 için sistem çıktısı (Doğrudan Denklem)');
xlabel('n');
ylabel('Genlik');
grid on;

figure;
plot(y2_direct);
title('X2 için sistem çıktısı (Doğrudan Denklem)');
xlabel('n');
ylabel('Genlik');
grid on;


% 6.3 Konvolüsyon ile Hesaplama
function [h, nh] = create_h(M, A)
    nh = 0:400*M;                  % h[n] sadece bu aralıkta sıfırdan farklı
    h = zeros(1, length(nh));

    h(1) = 1;                      % delta[n]
    for k = 1:M
        h(400*k + 1) = A * k;      % delta[n - 400k] katsayıları
    end
end

[h, nh] = create_h(M, A);

nx1 = 0:length(X1)-1;
nx2 = 0:length(X2)-1;

[y1_conv, ny1] = myConv(X1', nx1, h, nh);
[y2_conv, ny2] = myConv(X2', nx2, h, nh);

figure;
plot(ny1, y1_conv);
title('X1 için Konvolüsyon Sonucu');

figure;
plot(ny2, y2_conv);
title('X2 için Konvolüsyon Sonucu');

% 6.4 Hazır Fonksiyon ile Karşılaştırma
y1_builtin = conv(X1, h);
y2_builtin = conv(X2, h);
y1_builtin = y1_builtin(:).';
y2_builtin = y2_builtin(:).';
ny1_builtin = (0:length(y1_builtin)-1);
ny2_builtin = (0:length(y2_builtin)-1);
mse_y1 = mean((y1_conv - y1_builtin).^2);
mse_y2 = mean((y2_conv - y2_builtin).^2);

fprintf('\n--- Karşılaştırma ---\n');
fprintf('X1 için MSE = %.10f\n', mse_y1);
fprintf('X2 için MSE = %.10f\n', mse_y2);

figure;
plot(ny1, y1_conv); hold on;
plot(ny1_builtin, y1_builtin, '--');
legend('myConv', 'conv');
title('X1 Karşılaştırma');

figure;
plot(ny2, y2_conv); hold on;
plot(ny2_builtin, y2_builtin, '--');
legend('myConv', 'conv');
title('X2 Karşılaştırma');
fprintf(['Yorum: myConv ile elde edilen sonuçlar, hazır conv fonksiyonu ile elde edilen sonuçlarla aynıdır. ' ...
         'MSE değerlerinin sıfır ya da sıfıra çok yakın çıkması, yazılan myConv fonksiyonunun doğru çalıştığını göstermektedir.\n']);

% 6.5 Seslendirme
disp('--- 6.5 Seslendirme ---');
disp('Giriş işareti X1 dinletiliyor...');
sound(X1, fs);
pause(length(X1)/fs + 1);

disp('Giriş işareti X2 dinletiliyor...');
sound(X2, fs);
pause(length(X2)/fs + 1);

disp('myConv ile elde edilen X1 çıktısı dinletiliyor...');
sound(y1_conv, fs);
pause(length(y1_conv)/fs + 1);

disp('myConv ile elde edilen X2 çıktısı dinletiliyor...');
sound(y2_conv, fs);
pause(length(y2_conv)/fs + 1);

disp('Hazır conv ile elde edilen X1 çıktısı dinletiliyor...');
sound(y1_builtin, fs);
pause(length(y1_builtin)/fs + 1);

disp('Hazır conv ile elde edilen X2 çıktısı dinletiliyor...');
sound(y2_builtin, fs);
pause(length(y2_builtin)/fs + 1);

disp('Tüm seslendirme işlemleri tamamlandı.');

%6,6

disp('--- 6.6 Parametrik Analiz ve Yorum ---');
M_values = [3 4 5];
A_fixed = 0.5;

for i = 1:length(M_values)
    M_current = M_values(i);

    [hM, nhM] = create_h(M_current, A_fixed);
    [y1_M, ny1_M] = myConv(X1, 0:length(X1)-1, hM, nhM);
    [y2_M, ny2_M] = myConv(X2, 0:length(X2)-1, hM, nhM);

    figure;
    plot(ny1_M, y1_M);
    title(['X1 için Sistem Çıkışı (A = 0.5, M = ', num2str(M_current), ')']);
    xlabel('n');
    ylabel('Genlik');
    grid on;

    figure;
    plot(ny2_M, y2_M);
    title(['X2 için Sistem Çıkışı (A = 0.5, M = ', num2str(M_current), ')']);
    xlabel('n');
    ylabel('Genlik');
    grid on;
end

fprintf('\nM parametresi için yorum:\n');
fprintf(['M arttıkça sisteme eklenen gecikmeli terim sayısı artar. ' ...
         'Bu nedenle çıkış sinyalinde daha fazla yankı bileşeni oluşur.\n']);
fprintf(['M büyüdükçe yankı sayısı artar ve sistem çıktısı zaman olarak daha uzun bir yapıya yayılır.\n']);
fprintf(['Dolayısıyla M arttıkça yankı etkisi daha belirgin hale gelir.\n']);

A_values = [0.3 0.8];
M_fixed = 3;

for i = 1:length(A_values)
    A_current = A_values(i);

    [hA, nhA] = create_h(M_fixed, A_current);
    [y1_A, ny1_A] = myConv(X1, 0:length(X1)-1, hA, nhA);
    [y2_A, ny2_A] = myConv(X2, 0:length(X2)-1, hA, nhA);

    figure;
    plot(ny1_A, y1_A);
    title(['X1 için Sistem Çıkışı (M = 3, A = ', num2str(A_current), ')']);
    xlabel('n');
    ylabel('Genlik');
    grid on;

    figure;
    plot(ny2_A, y2_A);
    title(['X2 için Sistem Çıkışı (M = 3, A = ', num2str(A_current), ')']);
    xlabel('n');
    ylabel('Genlik');
    grid on;
end

fprintf('\nA parametresi için yorum:\n');
fprintf(['A küçük olduğunda (örneğin A = 0.3), yankıların genliği daha düşük olur ve etkisi daha zayıf hissedilir.\n']);
fprintf(['A büyük olduğunda (örneğin A = 0.8), gecikmiş bileşenlerin genliği artar.\n']);
fprintf(['Bu nedenle yankılar daha güçlü, daha belirgin ve daha baskın hale gelir.\n']);
