clc;
clear all;
close all;

%telefonun sahip olduğu tuşları 2 boyutlu dizide tutma
karakterler = ['1','2','3' ; '4','5','6' ; '7','8','9' ; '*','0','#'];
%Telefon numarası 11 basamaklı
n = 11;
% Örnekleme frekansı (Hz)
fs = 8000;

telefonNumaram = '05464952001';
telefonSesim = dtmfKullanarakSesUret(telefonNumaram, fs);

% Genlikle oynanabilir
telefonSesim = telefonSesim * 0.5;
% Ses dosyasına yazma
audiowrite('05464952001.wav', telefonSesim,fs);
%ürettiğim sesi seslendirme
sound(telefonSesim)

figure('name','Telefon Numaram')
subplot(2,1,1)
stem(telefonSesim)
title('Stem')
subplot(2,1,2)
plot(telefonSesim)
title('Plot')
frekansSpektrumGosterimi(telefonSesim,n,karakterler,fs)
pause(5)

%Ornek.wav dosyasını okuyor
[tel,fs] = audioread('Ornek.wav');
%okunan sesi seslendirme
sound(tel)
%aralıkların uzunluğu
d = floor(length(tel)/n);

figure('name','Dosyadan Okunan Ses')
subplot(2,1,1)
stem(tel)
title('Stem')
subplot(2,1,2)
plot(tel)
title('Plot')

figure('name','Ornek.wav Frekans Spektrum Gösterimi')
telefonNumarasi=char(zeros(1,11));
for sesAraligi = 1 : n
    %tek bir karakter aralığına fourier dönüşümü uygulama
    bolunmusNumara = tel((sesAraligi-1)*d+1:sesAraligi*d);
    bolunmusNumaraSpektrum = abs(fft(bolunmusNumara,fs));
    
    %yatay için frekans tepe noktası bulma
    max = 0;
    for i=690:950
        if bolunmusNumaraSpektrum(i) > max
            max = bolunmusNumaraSpektrum(i);
            yatayFrekans = i;
        end
    end
    %dikey için frekans tepe noktası bulma
    max = 0;
    for i=1200:1500
        if bolunmusNumaraSpektrum(i) > max
            max = bolunmusNumaraSpektrum(i);
            dikeyFrekans = i;
        end
    end

     %aralıkları kontrol ederek uygun indisi verme işlemi
    if yatayFrekans < 769
        i=1;
    elseif yatayFrekans < 851
        i=2;
    elseif yatayFrekans < 940
        i=3;
    else
        i=4;
    end
    
    if dikeyFrekans < 1337
        j=1;
    elseif dikeyFrekans < 1475
        j=2;
    else 
        j=3;
    end
    
    %iki boyutlu karakter dizisinden yatay ve dikey frekansa uygun olanı
    %alıp numara dizisinin indisine yerleştirme
    telefonNumarasi(sesAraligi) = karakterler(i,j);
    
    subplot(n,1,sesAraligi);
    plot(bolunmusNumaraSpektrum(1:1600));
    title(telefonNumarasi(sesAraligi));
    
end


disp('Dosyadaki telefon numarasının çözülmüş hali')
disp(telefonNumarasi)


function telefonSes = dtmfKullanarakSesUret(telefonNumarasi, fs)
    % Ses verilerini tutan array
    telefonSes = [];
    
    % Telefon numarasındaki tüm rakamlar için döngü
    for i = 1:length(telefonNumarasi)
        t=0:1/fs:(1200-1)/fs;
        % Rakamın karşılığı olan yatay frekans(düşük frekans)
        if telefonNumarasi(i) == '1' || telefonNumarasi(i) == '2' || telefonNumarasi(i) == '3'
            yataySinyal = sin(2*pi*697*t);
        elseif telefonNumarasi(i) == '4' || telefonNumarasi(i) == '5' || telefonNumarasi(i) == '6'
            yataySinyal = sin(2*pi*770*t);
        elseif telefonNumarasi(i) == '7' || telefonNumarasi(i) == '8' || telefonNumarasi(i) == '9'
            yataySinyal = sin(2*pi*852*t);
        else
            yataySinyal = sin(2*pi*941*t);
        end
        
        % Rakamın karşılığı dikey frekans(yüksek frekans)
        if telefonNumarasi(i) == '1' || telefonNumarasi(i) == '4' || telefonNumarasi(i) == '7' ||telefonNumarasi(i)== '*'
            dikeySinyal = sin(2*pi*1209*t);
        elseif telefonNumarasi(i) == '2' || telefonNumarasi(i) == '5' || telefonNumarasi(i) == '8' || telefonNumarasi(i) == '0'
            dikeySinyal = sin(2*pi*1336*t);
        else
            dikeySinyal = sin(2*pi*1477*t);
        end
        
        %karaktere karşılık gelen iki sinyalin toplamı
        toplam = yataySinyal + dikeySinyal;
        %her numaranın sonuna biraz duraklama ekliyorum ki daha iyi
        %anlaşılsın
        sifirlar=zeros(1,400);
        telefonSes = [telefonSes toplam sifirlar];
    end
end
function frekansSpektrumGosterimi(tel,n,karakterler,fs)

figure('name','Kendi Numaramın Frekans Spektrum Gösterimi')
d = floor(length(tel)/n);
telefonNumarasi=char(zeros(1,11));

for sesAraligi = 1 : n
    %tek bir karakter aralığına fourier dönüşümü uygulama
    bolunmusNumara = tel((sesAraligi-1)*d+1:sesAraligi*d);
    bolunmusNumaraSpektrum = abs(fft(bolunmusNumara,fs));
    
    %yatay için frekans tepe noktası bulma
    max = 0;
    for i=690:950
        if bolunmusNumaraSpektrum(i) > max
            max = bolunmusNumaraSpektrum(i);
            yatayFrekans = i;
        end
    end
    %dikey için frekans tepe noktası bulma
    max = 0;
    for i=1200:1500
        if bolunmusNumaraSpektrum(i) > max
            max = bolunmusNumaraSpektrum(i);
            dikeyFrekans = i;
        end
    end

    %aralıkları kontrol ederek uygun indisi verme işlemi
    if yatayFrekans < 769
        i=1;
    elseif yatayFrekans < 851
        i=2;
    elseif yatayFrekans < 940
        i=3;
    else
        i=4;
    end
    
    if dikeyFrekans < 1337
        j=1;
    elseif dikeyFrekans < 1475
        j=2;
    else 
        j=3;
    end
    
    %iki boyutlu karakter dizisinden yatay ve dikey frekansa uygun olanı
    %alıp numara dizisinin indisine yerleştirme
    telefonNumarasi(sesAraligi) = karakterler(i,j);
    
    subplot(n,1,sesAraligi);
    plot(bolunmusNumaraSpektrum(1:1600));
    title(telefonNumarasi(sesAraligi));
    
end

end
