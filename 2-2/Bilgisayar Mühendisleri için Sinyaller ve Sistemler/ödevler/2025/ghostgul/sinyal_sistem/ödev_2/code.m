clc;
clear;
close all;
                %0    %5   %3   %4  %2   %3   %6   0     1    2    6
freq1 = [941 ,770 ,697 ,770 ,697 ,697 ,770 ,941 ,697 ,697 ,770];  
freq2 = [1336 ,1336 ,1477 ,1209 ,1336 ,1477 ,1477 ,1336 ,1209 ,1336 ,1477]; 
                %0     5      3     4     2     3     6     0      1    2 6
dur = 0.3;  
Fs = 8000;  
t = 0:1/Fs:dur;  

data = zeros(length(t), length(freq1)); 
for i = 1:length(freq1)
    data(:,i) = sin(2*pi*freq1(i)*t) + sin(2*pi*freq2(i)*t);
end

donedata = cat(1, data(:,1), data(:,2), data(:,3), data(:,4), data(:,5), data(:,6), data(:,7), data(:,8), data(:,9), data(:,10), data(:,11));  % Ses verilerini uç uca ekleme
disp(donedata)

filename = 'example.wav'; 
audiowrite(filename, donedata, Fs); 