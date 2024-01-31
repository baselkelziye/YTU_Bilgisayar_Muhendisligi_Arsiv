
%%
resim=(imread('mrImage.jpeg'));
[X,Y]=size(resim);
dftX= mydft(resim,X,Y);
idftX= myidft(dftX,X,Y);

subplot(1,2,1), imshow(dftX)
title( 'resim 1')
subplot(1,2,2), imshow(idftX,[])
title( 'resim 2')

sgtitle('resimler')

%%

% Birinci Sorunun Cevabı

resim=(imread('mrImage.jpeg'));
[X,Y]=size(resim);

sonuc= mydft(resim,X,Y);
sonuc2=myidft(sonuc,X,Y);


subplot(1,2,2), imshow(sonuc2,[])
subplot(1,2,1), imshow(sonuc)



%%

% İkinci Sorunun Cevabı

resim=(imread('mrImage.jpeg'));
[X,Y]=size(resim);

sonuc = mydft(resim,X,Y);

figure, imshow(log(abs(fftshift(sonuc))),[]);
figure, imshow(angle(fftshift(sonuc)),[]);
%%

% Üçüncü Sorunun Cevabı
resim=(imread('mrImage.jpeg'));
mask=(imread('mask.jpeg'));

[X,Y]=size(resim);

sonuc= mydft(resim,X,Y);
K=fftshift(sonuc).*double(mask);
K=ifftshift(K);

I=myidft(K,X,Y);
imshow (real(I),[]);
sgtitle('MASKELEME YAPILMIŞ IDFT')

%% 
function sonuc=mydft(resim,X,Y)
wX        = zeros(X, X);
wY        = zeros(Y, Y);


for m = 0 : (Y - 1)
    for n = 0 : (Y - 1)
        wY(n+1, m+1) = exp(-2 * pi * 1i / Y * n * m);
    end    
end

for i = 0 : (X - 1)
    for j = 0 : (X - 1)
        wX(i+1, j+1) = exp(-2 * pi * 1i / X * j * i);
    end    
end

sonuc = wX * double(resim)* wY;
end

%% 
function sonuc=myidft(resim,X,Y)
wX        = zeros(X, X);
wY        = zeros(Y, Y);

for a = 0 : (Y - 1)
    for b = 0 : (Y - 1)
        wY(b+1, a+1) = exp(-2 * pi * 1i / Y * b * a);
    end    
end

for i = 0 : (X - 1)
    for j = 0 : (X - 1)
        wX(i+1, j+1) = exp(2 * pi * 1i / X * j * i);
    end    
end


sonuc =(1/(X*Y))* wX * double(resim)* wY;
end