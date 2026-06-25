% The multivariate linear regression with least squares 
% real model Y=B0+B1*X1+B2*X2+B3*X1^2+B4*X2^2+B5*X1*X2
% estimated model1 Y=B0+B1*X1+B2*X2+B3*X1^2+B4*X2^2+B5*X1*X2

clear all;
close all;
n=1000;
d=2;
X=rand(n,d)*1-0.5; % X has d dimensions 

X=[ones(n,1) X X(:,1).*X(:,1) X(:,2).*X(:,2) X(:,1).*X(:,2)]; % second order model
%B=randn(d+4,1) 
B=[ 1.3666; -0.2511; 0.5365; -0.4343; 1.4466; 0.8925]
E=randn(n,1)*0.05;
Y=X*B+E;
plot3(X(:,2),X(:,3),Y,'b.');
hold on;

[X1,X2] = meshgrid(-0.5:.1:0.5); 
nn=size(X1,1);
X11=reshape(X1,nn*nn,1);
X22=reshape(X2,nn*nn,1);
iY=[ones(nn*nn,1) X11 X22 X11.*X11 X22.*X22 X11.*X22 ]*B;
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