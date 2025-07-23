% The linear regression with least squares 
% real model Y=B0+B1*X+B2*X^2+B3*X^3
% estimated model1 Y=B0+B1*X
% estimated model2 Y=B0+B1*X+B2*X^2
% estimated model3 Y=B0+B1*X+B2*X^2+B3*X^3

clear all;
close all;
n=100;
d=1;
X=rand(n,d)*8-3;
X=[ones(n,1) X    X.*X    X.*X.*X ]; % third order model
%B=randn(d+3,1); 
B=[1 ;-4; 4; -1]
E=randn(n,1)*2;
Y=X*B+E;
plot(X(:,2),Y,'*');

fXX=X(:,1:2); % first order model   
fBhat=inv(fXX'*fXX)*(fXX'*Y)
sXX=X(:,1:3); % second order model
sBhat=inv(sXX'*sXX)*(sXX'*Y)
tXX=X; % third order model
tBhat=inv(tXX'*tXX)*(tXX'*Y)

Yhat_f=fXX*fBhat;
Yhat_s=sXX*sBhat;
Yhat_t=tXX*tBhat;

MSE_f=sum((Y-Yhat_f).*(Y-Yhat_f))/n;
MSE_s=sum((Y-Yhat_s).*(Y-Yhat_s))/n;
MSE_t=sum((Y-Yhat_t).*(Y-Yhat_t))/n;

e_f=Y-Yhat_f;
e_s=Y-Yhat_s;
e_t=Y-Yhat_t;

[D I]=sort(X(:,2));
figure;
plot(X(I,2),e_f(I),'r');
hold on
plot(X(I,2),e_s(I),'g');
plot(X(I,2),e_t(I),'b');
legend('first order errors', 'second order errors','third order errors');

title(['first order MSE=' num2str(MSE_f) ' second order MSE=' num2str(MSE_s) ' third order MSE=' num2str(MSE_t)]);
xlabel('X');
ylabel('error');