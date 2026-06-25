% 2 parameters vs error surface

clear all;
close all;
syms b1 b2 x y;

f=(y-exp(-(x-b1)^2/(2*b2^2)))^2;
fx=exp(-(x-b1)^2/(2*b2^2));

n=200;
d=1;
X=rand(n,d)*16-8; % X has d dimensions 
minmaxx=minmax(X');
B=[-0.2 ; 1.5];
E=randn(n,1)*0.01;
Y=subs(fx,{b1,b2,x},{B(1),B(2),X})+E;
ii=1;jj=1;
sR=zeros(41,41);
for i=-4:0.2:4
    for j=-4:0.2:4
        Bhat=[i;j];        
        R=subs(f,{b1,b2,x,y},{Bhat(1),Bhat(2),X,Y});
        sR(ii,jj)=sum(R)/n;
        jj=jj+1;
    end
    ii=ii+1;
    jj=1;
end
figure;
surfc(-4:0.2:4,-4:0.2:4,sR);
xlabel('B2'); ylabel('B1'); zlabel('error r^2');
