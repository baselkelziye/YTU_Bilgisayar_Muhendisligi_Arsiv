clear;
clc;
[y,Fs] = audioread('05511129859.wav');
N = 100;
t = (0:1/Fs:(length(y)-1)/Fs)';
frekanslar = [697,770,852,941,1209,1336,1477];
numaralar = [1,2,3;4,5,6;7,8,9;0,0,0];

figure(1);
plot(t,y);
grid on
title('Ses Kaydi');
xlabel('Zaman');
ylabel('Genlik');

figure(2);
stem(t,y);
grid on
title('Ses Kaydi');
xlabel('Zaman');
ylabel('Genlik');

inst_power = filter(ones(1,N)/N,1,y.*y);
esikdeger = 0.5*max(inst_power);
hane = zeros(1,length(y));

for i = (1:length(y))                      % 1 degerlerinin oldugu yerlerde sinyal vardir            
    if(inst_power(i)>esikdeger)
        hane(i) = 1;
    else
        hane(i) = 0;
    end
end

baslangic = find(hane(2:length(y)) - hane(1:length(y)-1)== 1);    % 1lerin basladigi konumlar
son = find(hane(2:length(y)) - hane(1:length(y)-1)== -1);      % 1lerin sonlandigi konumlar

len = son - baslangic + 1;
s = ceil(frekanslar' * len/Fs);                                     % matris carpimi

num = 0;
for n = 1:length(baslangic)
    x = y(baslangic(n):son(n));                            % sinyal araligi
    spektrum = abs(fft(x));
    a = find(spektrum(s(1:4,n)) == max(spektrum(s(1:4,n))));
    b = find(spektrum(s(5:7,n)) == max(spektrum(s(5:7,n))));
    num = numaralar(a,b);
    p(n) = num;

end
p
