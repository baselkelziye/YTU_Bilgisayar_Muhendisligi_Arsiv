% 1 parameter vs error surface

clear all;
close all;

syms b1 x y;
f=(y-sin(b1*x))^2;
fx=sin(b1*x);

n=1000;
d=1;
X=rand(n,d)*16-8; % X has d dimensions 
minmaxx=minmax(X');
B=-0.5;
E=randn(n,1)*0.01;
Y=subs(fx,{b1,x},{B,X})+E;
ii=1;jj=1;
sR=zeros(1,81);
for i=-4:0.1:4
    Bhat=i;        
    R=subs(f,{b1,x,y},{Bhat,X,Y});
    sR(ii)=sum(R)/n;
    ii=ii+1;
end
figure;
plot(-4:0.1:4,sR);
xlabel('B'); ylabel('error r^2');
