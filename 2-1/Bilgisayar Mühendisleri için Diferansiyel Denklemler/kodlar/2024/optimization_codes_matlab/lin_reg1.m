% The linear regression with least squares 
% model Y=B0+B1*X
clear all;
close all;
n=20;
d=1;
X=[ones(n,1) rand(n,d)];
B=randn(d+1,1); % B0(intercept) B1(slope)
B=[5 ;0.8];
E=randn(n,1)/2;
Y=X*B+E;
plot(X(:,2),Y,'*');
Bhat=inv(X'*X)*(X'*Y);
Yhat=X*Bhat;
MSE=sum((Y-Yhat).*(Y-Yhat))/n;
y0hat=[1 0]*Bhat;
y0real=[1 0]*B;
y1hat=[1 1]*Bhat;
y1real=[1 1]*B;

hold on;
plot([0 1],[y0real y1real],'r');
plot([0 1],[y0hat y1hat],'g');
legend('data','real model', 'estimated model');
title(['real B=[' num2str(B(1)) ';' num2str(B(2)) ...
    '] estimated B=[' num2str(Bhat(1)) ';' num2str(Bhat(2)) '] MSE=' num2str(MSE) ]);


