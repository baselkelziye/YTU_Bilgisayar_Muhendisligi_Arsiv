% The multivariate linear regression with least squares 
% real model Y=B0+B1*X1+B2*X2
% estimated model1 Y=B0+B1*X1+B2*X2

% calculates training and test MSEs

clear all;
close all;
n=100;
d=2;
X=rand(n,d)*1-0.5; % X has d dimensions 

X=[ones(n,1) X]; % first order model
%B=randn(d+1,1); 
B=[3 ;-3; 1]
E=randn(n,1)*0.5;
Y=X*B+E;
plot3(X(:,2),X(:,3),Y,'b*');
hold on;

[X1,X2] = meshgrid(-0.5:.1:0.5);
nn=size(X1,1);
X11=reshape(X1,nn*nn,1);
X22=reshape(X2,nn*nn,1);
iY=[ones(nn*nn,1) X11 X22]*B;
iY=reshape(iY,nn,nn);
surf(X1,X2,iY);

fBhat=inv(X'*X)*(X'*Y)
Yhat_f=X*fBhat;
plot3(X(:,2),X(:,3),Yhat_f,'r*'); 

legend('real Ys','estimated surface','estimated Ys');
MSE_f=sum((Y-Yhat_f).*(Y-Yhat_f))/n;
title(['first order MSE=' num2str(MSE_f)]);
xlabel('X1');
ylabel('X2');
zlabel('f(X1,X2)');