% The non linear regression with least squares 
% real model Y=exp(-(X-B1)^2/(2*B2^2)) 
% estimated model Y=exp(-(X-B1)^2/(2*B2^2)) 

%where b1 is the time shift, and b2 determines
%the width of the Gaussian function.

clear all;
close all;
syms b1 b2 x y;

f=(y-exp(-(x-b1)^2/(2*b2^2)))^2;
fx=exp(-(x-b1)^2/(2*b2^2));
r=(y-exp(-(x-b1)^2/(2*b2^2)));

dfdb1=diff(r,1,b1);
dfdb2=diff(r,1,b2);
df=[dfdb1 dfdb2];
n=300;
d=1;
X=rand(n,d)*16-8; % X has d dimensions 
minmaxx=minmax(X');
%B=randn(d+1,1) 
B=[-0.2 ; 1.5]
E=randn(n,1)*0.01;
Y=subs(fx,{b1,b2,x},{B(1),B(2),X})+E;
plot(X,Y,'b.');
hold on;
Bhat=[-2; -0.2]; % initial guess
fxhat=subs(fx,{b1,b2,x},{Bhat(1),Bhat(2),minmaxx(1):0.1:minmaxx(2)});
plot(minmaxx(1):0.1:minmaxx(2),fxhat,'g-');
max_iter=10;
i=1;
precision=0.0001;
eps=1;%0.001;
MSE_y=zeros(1,max_iter);
MSE_y(1)=3;
while (max_iter>i) && (MSE_y(i)>precision)
    dfV=subs(df,{b1,b2,x,y},{Bhat(1),Bhat(2),X,Y});
    R=subs(r,{b1,b2,x,y},{Bhat(1),Bhat(2),X,Y});
    %fdx=dfV'*R; % improve Bhat with Grad Desc
    fdx=pinv(dfV)*R; % improve Bhat with Newton
    Bhat = Bhat - eps * fdx; 
    i=i+1;
    MSE_y(i)=sum(R.^2)/n;
    fxhat=subs(fx,{b1,b2,x},{Bhat(1),Bhat(2),minmaxx(1):0.1:minmaxx(2)});
    plot(minmaxx(1):0.1:minmaxx(2),fxhat); % plot current fx estimate
    pause(0.5); % wait 0.5 sec
end
plot(minmaxx(1):0.1:minmaxx(2),fxhat,'r-');
xlabel('X'); ylabel('fX');
Bhat
figure;plot(MSE_y(1:i));
xlabel('iteration number'); ylabel('MSE');
optMSE_y=sum(Y-exp(-(X-B(1)).^2/(2*B(2).^2)))^2/n;
title(['optimal MSE=' num2str(optMSE_y) ' current MSE=' num2str(MSE_y(i)) ...
     ' B=[' num2str(B(1)) ' ' num2str(B(2)) ']' ...
     ' Bhat=[' num2str(Bhat(1)) ' ' num2str(Bhat(2)) ']']);
