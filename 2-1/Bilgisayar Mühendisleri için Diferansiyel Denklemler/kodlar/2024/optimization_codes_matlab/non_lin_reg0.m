% The non linear regression with least squares 
% real model Y=sin(B1*X) 
% estimated model Y=sin(B1*X)

clear all;
close all;
syms b1 x y;
f=(y-sin(b1*x))^2;
r=(y-sin(b1*x));
fx=sin(b1*x);
df=diff(r,1,b1);
n=200;
d=1;
X=rand(n,d)*16-8; % X has d dimensions 
minmaxx=minmax(X');
B=-0.5;
E=randn(n,1)*0.1;
Y=subs(fx,{b1,x},{B,X})+E;
plot(X,Y,'b.');
hold on;
Bhat=-2; % initial guess
fxhat=subs(fx,{b1,x},{Bhat,minmaxx(1):0.1:minmaxx(2)});
plot(minmaxx(1):0.1:minmaxx(2),fxhat,'g-');
max_iter=20;
i=1;
precision=0.0001;
eps=1;%0.0005;
MSE_y=zeros(1,max_iter);
MSE_y(1)=3;
while (max_iter>i) && (MSE_y(i)>precision)
    dfV=subs(df,{b1,x,y},{Bhat,X,Y});
    R=subs(r,{b1,x,y},{Bhat,X,Y});
    %fdx=dfV'*R; % improve Bhat with Grad Desc
    fdx=pinv(dfV)*R; % improve Bhat with Newton Raphson
    Bhat = Bhat - eps * fdx; 
    i=i+1;
    MSE_y(i)=sum((R.^2))/n;
    fxhat=subs(fx,{b1,x},{Bhat,minmaxx(1):0.1:minmaxx(2)});
    plot(minmaxx(1):0.1:minmaxx(2),fxhat); % plot current fx estimate
    pause(0.5); % wait 0.5 sec
end
plot(minmaxx(1):0.1:minmaxx(2),fxhat,'r-');
xlabel('X'); ylabel('fX');

figure;plot(MSE_y(1:i));
xlabel('iteration number'); ylabel('MSE');
optMSE_y=sum((Y-sin(B*X)).^2)/n;
title(['optimal MSE=' num2str(optMSE_y) ' current MSE=' num2str(MSE_y(i)) ...
    ' B=[' num2str(B) '] Bhat=[' num2str(Bhat)  ']']);
