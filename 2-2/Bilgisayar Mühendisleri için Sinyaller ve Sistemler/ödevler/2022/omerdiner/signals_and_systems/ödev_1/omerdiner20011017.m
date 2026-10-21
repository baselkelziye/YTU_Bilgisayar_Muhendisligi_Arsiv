clc;
clear all;
close all;

x = input('Enter the X signal: ');
xStartIndex=input('Enter the start index of X:');
xIndexes = zeros(1,length(x));


y = input('Enter the Y signal: ');
yStartIndex=input('Enter the start index of Y:');
yIndexes = zeros(1,length(y));

M=input('Enter the M value(last question) :');

%alınan başlangıc indisine göre x sinyalinin x indislerini otomatik dolduruyor
for i=1:length(x)
    xIndexes(i)=xStartIndex;
    xStartIndex=xStartIndex+1;
end

%alınan başlangıc indisine göre y sinyalinin x indislerini otomatik dolduruyor
for i=1:length(y)
    yIndexes(i)=yStartIndex;
    yStartIndex=yStartIndex+1;
end

  
% x ve y sinyallerinin x indexlerini yollayarak ,konvolusyondan gelecek x indislerini fonksiyonla çağırıyoruz
[xIndexesOfConv] = findIndexes( xIndexes, yIndexes);

%uygulamanın hazır konvolüsyon fonksiyonundan gelen sonuç
DefaultConv=conv(x,y);

% konvolüsyon işleminin yapılması için iki sinyali myConvfonksiyonuna yolluyoruz
MyConv = myConv(x,length(x), y,length(y));

%--------2.soru----------
%grafiksel gösterim
tiledlayout(4,1)
nexttile
stem(xIndexes,x, 'LineWidth',2)
title('X signal')

nexttile
stem(yIndexes,y, 'LineWidth',2)
title('Y signal')

nexttile
stem(xIndexesOfConv,MyConv, 'LineWidth',2)
title('Discrete Convolution using myConv');

nexttile
stem(xIndexesOfConv,DefaultConv, 'LineWidth',2)
title('Discrete Convolution using mathlab conv func');

%vektörel gösterim
disp('X signal')
disp(x)
disp('Y signal')
disp(y)
disp('myConv signal')
disp(MyConv)
disp('default mathlab convolution signal')
disp(DefaultConv)


%  ----3.soru-----
% 5 Saniye Ses kaydetme
recObj = audiorecorder; %% kayıt başlatma nesnesi
disp('Start speaking(5 seconds)') 
recordblocking(recObj, 5); 
disp('End of Recording.'); 
X1 = getaudiodata(recObj); %% kaydedilen sesi X1 değişkenine saklama

%10 sn ses kaydetme
disp('Start speaking(10 seconds)') 
recordblocking(recObj, 10);
disp('End of Recording.'); 
X2 = getaudiodata(recObj); %% kaydedilen sesi X2 değişkenine saklama

%----4.soru------
%dürtü fonksiyonunun uygulanması
H=makeH(M);
% iki ayrı ses için benim yazdığım ve hazır olan konvolüsyon
% fonksiyonlarına giriyor
myY1=myConv(X1,length(X1),H,length(H));
DefaultY1=conv(X1,H);

myY2=myConv(X2,length(X2),H,length(H));
DefaultY2=conv(X2,H);

%konvolüsyon sonucu oluşan sesleri seslendirme
sound(myY1)
pause(5)
sound(DefaultY1)
pause(5)
sound(myY2)
pause(5)
sound(DefaultY2)

% y fonksiyonun x ekseninin bilgileri buradan dönüyor
function [xIndexesFromY] = findIndexes( x,  y)
    begin = x(1) + y(1);
    end_ = x(length(x)) + y(length(y));
    xIndexesFromY = begin : end_;    
end

%------1.soru--------
% ayrık konvolüsyon burada yapılıyor
function [y] = myConv(x,n, h,m)
    times = n + m - 1;
    for i = 1 : 1 : times
        y(i) = 0;
        for j = 1 : 1 : n
            if(i - j + 1 >= 1 && i - j + 1 <= m)
                y(i) = y(i) + x(j) * h(i - j + 1);
            end
        end
    end
end

% son sorudaki  h fonksiyonunu bulmak için fonksiyon
function [h] = makeH(M)
    
    h=[1,zeros(1,M*400-1)];
    A=0.8;
    for i=1:1:M
        h(i*400)=A*i*1;
    end

end
