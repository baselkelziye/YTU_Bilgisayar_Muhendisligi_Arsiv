clear all
clc
n=-20:1:20;
x1=sin((pi/6)*n)./(n*pi);
subplot(3,1,1);
stem(n,x1);
x2=(pi/6)./pi;
hold on
stem(0,x2);
title('w=pi/6');
hold off
n=-20:1:20;
x3=sin((pi/7)*n)./(n*pi);
subplot(3,1,2);
stem(n,x3);
x4=(pi/7)./pi;
hold on
stem(0,x4);
title('w=pi/7');
hold off
n=-20:1:20;
x5=sin((pi/3)*n)./(n*pi);
subplot(3,1,3);
stem(n,x5);
x6=(pi/3)./pi;
hold on
stem(0,x6);
title('w=pi/3');
hold off