close all
clear all

x=[1,2,3]
y=[1,2,3]
n=length(x);
m=length(y);

figure(1)
MY_C=myconv(x,y,n,m)
my_c=stem(MY_C);
    set(my_c,'LineWidth',1.5);
    grid on;
    set(my_c,'Color','r');
    ylabel('C[n]'); 
    xlabel('n');
    title('MY Convolution of Two Signals');

C=conv(x,y)
figure(2);
c=stem(C);
    set(c,'LineWidth',1.5);
    set(c,'Color','g');
    ylabel('C[n]');
    xlabel('[n]');
    title('Convolution Function');
    grid on;
figure(3);
X=stem(x);
    set(X,'LineWidth',1.5);
    grid on;
    ylabel('X[n]'); 
    xlabel('n');
    title('X signal');
figure(4);
Y=stem(y);
    set(Y,'LineWidth',1.5);
    grid on;
    ylabel('Y[n]'); 
    xlabel('n');
    title('Y Signal');

