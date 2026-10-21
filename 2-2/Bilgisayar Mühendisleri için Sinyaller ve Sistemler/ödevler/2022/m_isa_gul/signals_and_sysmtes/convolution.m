clc
clear
close all

x = input('x isaretinin degerlerini giriniz: ');
x_origin = input('0 noktasininin indexi: ');
n = length(x);
nx= ([1-x_origin:n-x_origin]);


y = input('y isaretinin degerlerini giriniz: ');
y_origin = input('0 noktasininin indexi: ');
m=length(y);
ny= ([1-y_origin:m-y_origin]);


X= [x,zeros(1,m)];
Y= [y,zeros(1,n)];

z = myconv(X,n,Y,m);
conv = conv(x,y);

disp('x =');
disp(x);
disp('y =');
disp(y);
disp('myconv =');
disp(z);
disp('conv =');
disp(conv);

nz = ([1-x_origin:m+n-1-x_origin]);

subplot(4,1,1);
stem(nx,x);
xlabel('n')
ylabel('x[n]')

subplot(4,1,2);
stem(ny,y);

xlabel('m');
ylabel('y[m]');

subplot(4,1,3);
stem(nz,z);
xlabel('m+n-1');
ylabel('myconv()');

subplot(4,1,4);
stem(nz,conv);
xlabel('m+n-1');
ylabel('conv()');

disp('Ses kayyitlari basliyor...');
pause(5);
recObj = audiorecorder;
disp('Start speaking. Sound 1');
recordblocking(recObj, 5);
disp('End of Recording.');
X1 = getaudiodata(recObj);


recObj2 = audiorecorder;
disp('Start speaking. Sound 2');
recordblocking(recObj2, 5);
disp('End of Recording.');
X2 = getaudiodata(recObj2);


%y[n] = x[n] + 0.4x[n-400] + 0.4x[n-800]
% x[]n yerine δ[n] yazariz.
%0 noktasinda 1 degerini alir.
%400 ve 800 noktalarinda 0.4 degerini alir.

h=zeros(1,length(X1));
h(400) = 0.4;
h(1) = 1;
h(800) = 0.4;

Y1 = conv(transpose(X1),h);
my_Y1 = myconv(X1,length(X1),h,length(h));


Y2 = conv(X2,h);
my_Y2 = myconv(transpose(X2),length(X2),h,length(h));


%SES 1
disp('Orijinal ses 1 oynatiliyor...');
sound(X1);
pause(5);

disp('myconv sonucu oynatiliyor...');
sound(my_Y1);
pause(5);

disp('conv sonucu oynatiliyor...');
sound(Y1);
pause(5);


%SES 2
disp('Orijinal ses 2 oynatiliyor...');
sound(X2);
pause(5);

disp('myconv sonucu oynatiliyor...');
sound(my_Y2);
pause(5);

disp('conv sonucu oynatiliyor...');
sound(Y2)

subplot(3,2,1);
plot(X1);
xlabel('t');
ylabel('X1');
subplot(3,2,3);
plot(my_Y1);
xlabel('t');
ylabel('myY1');
subplot(3,2,5);
plot(Y1);
xlabel('t');
ylabel('Y1');

subplot(3,2,2);
plot(X2);
xlabel('t');
ylabel('X2');
subplot(3,2,4);
plot(my_Y2);
xlabel('t');
ylabel('myY2');
subplot(3,2,6);
plot(Y2);
xlabel('t');
ylabel('Y2');


function [z]= myconv(x,n,y,m)
    z = zeros(1,m+n-1);
    for i=1:n+m-1          
        for j=1:m
            if(i-j+1>0 && i-j+1<40000)
                z(i) = z(i)+x(j)*y(i-j+1);
            end
        end
    end
end

