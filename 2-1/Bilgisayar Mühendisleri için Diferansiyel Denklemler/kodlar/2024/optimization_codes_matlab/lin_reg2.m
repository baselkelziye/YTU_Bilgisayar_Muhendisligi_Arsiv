% The linear regression with least squares 
% model Y=B0+B1*X+B2*X^2
clear all;
close all;
n=20;
d=1;
X=rand(n,d)*10-5;
sqrX=X.*X;
X=[ones(n,1) X sqrX];
B=randn(d+2,1); 
B=[2 ;-0.2 ;0.3];
E=randn(n,1)*2;
Y=X*B+E;
plot(X(:,2),Y,'*');
Bhat=inv(X'*X)*(X'*Y);

[mima]=minmax(X(:,2)');
all_x=(mima(1):0.01:mima(2))';
sqr_all_x=all_x.*all_x;
all_x=[ones(size(all_x,1),1) all_x sqr_all_x];
all_Yreal=all_x*B;
all_Yhat=all_x*Bhat;

Yhat=X*Bhat;
MSE=sum((Y-Yhat).*(Y-Yhat))/n;

hold on;
plot(all_x(:,2),all_Yreal,'r');
plot(all_x(:,2),all_Yhat,'g');
legend('data','real model', 'estimated model');

title(['real B=[' num2str(B(1)) ';' num2str(B(2)) ';' num2str(B(3)) ...
    '] estimated B=[' num2str(Bhat(1)) ';' num2str(Bhat(2)) ...
    ';' num2str(Bhat(3)) ']  MSE=' num2str(MSE)]);
