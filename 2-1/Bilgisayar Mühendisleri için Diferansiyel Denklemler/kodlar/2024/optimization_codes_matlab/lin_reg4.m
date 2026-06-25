% The linear regression with least squares 
% real model Y=B0+B1*X
% estimated model1 Y=B0+B1*X
% estimated model2 Y=B0+B1*X+B2*X^2

clear all;
close all;
n=20;
d=1;
X=rand(n,d)*30-5;
X=[ones(n,1) X]; % first order model
B=randn(d+1,1); 
B=[2 ;-0.8];
E=randn(n,1)*5;
Y=X*B+E;
plot(X(:,2),Y,'*');

fXX=X; % first order model
fBhat=inv(fXX'*fXX)*(fXX'*Y);
sXX=[ones(n,1) X(:,2) X(:,2).*X(:,2)]; % second order model
sBhat=inv(sXX'*sXX)*(sXX'*Y);

[mima]=minmax(X(:,2)');
all_x=(mima(1):0.01:mima(2))';
sqr_all_x=all_x.*all_x;
all_x_f=[ones(size(all_x,1),1) all_x ];
all_x_s=[ones(size(all_x,1),1) all_x sqr_all_x];
all_Yreal=all_x_f*B;
all_Yhat_f=all_x_f*fBhat;
all_Yhat_s=all_x_s*sBhat;

Yhat_s=sXX*sBhat;
Yhat_f=X*fBhat;
MSE_s=sum((Y-Yhat_s).*(Y-Yhat_s))/n;
MSE_f=sum((Y-Yhat_f).*(Y-Yhat_f))/n;

hold on;
plot(all_x,all_Yreal,'r');
plot(all_x,all_Yhat_f,'g');
plot(all_x,all_Yhat_s,'b');
legend('data','real model', 'estimated first order model', 'estimated second order model');

title(['first order MSE=' num2str(MSE_f) ' second order MSE=' num2str(MSE_s)]);