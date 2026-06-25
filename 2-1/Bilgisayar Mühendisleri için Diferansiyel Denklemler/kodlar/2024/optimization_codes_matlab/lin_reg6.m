% The linear regression with least squares 
% real model Y=B0+B1*X+B2*X^2
% estimated model1 Y=B0+B1*X
% estimated model2 Y=B0+B1*X+B2*X^2
% estimated model3 Y=B0+B1*X+B2*X^2+B3*X^3

% calculates training and test MSEs

clear all;
close all;
n=20;
d=1;
X=rand(n,d)*1-0.5;
X=[ones(n,1) X    X.*X   ]; % second order model
%B=randn(d+2,1); 
B=[1 ;-3; 3]
E=randn(n,1)*10;
Y=X*B+E;
trainIDs=1:2:n;
testIDs=2:2:n;
plot(X(trainIDs,2),Y(trainIDs),'b*');
hold on;
plot(X(testIDs,2),Y(testIDs),'r*');

fXX=X(trainIDs,1:2); % first order model   
fBhat=inv(fXX'*fXX)*(fXX'*Y(trainIDs))
sXX=X(trainIDs,1:3); % second order model
sBhat=inv(sXX'*sXX)*(sXX'*Y(trainIDs))
tXX=[X(trainIDs,:) X(trainIDs,2).*X(trainIDs,2).*X(trainIDs,2)]; % third order model
tBhat=inv(tXX'*tXX)*(tXX'*Y(trainIDs))

train_Yhat_f=fXX*fBhat;
train_Yhat_s=sXX*sBhat;
train_Yhat_t=tXX*tBhat;

test_fXX=X(testIDs,1:2);
test_sXX=X(testIDs,1:3); 
test_tXX=[X(testIDs,:) X(testIDs,2).*X(testIDs,2).*X(testIDs,2)];

test_Yhat_f=test_fXX*fBhat;
test_Yhat_s=test_sXX*sBhat;
test_Yhat_t=test_tXX*tBhat;

plot(fXX(:,2),train_Yhat_f,'b.');
plot(test_fXX(:,2),test_Yhat_f,'r.');
plot(fXX(:,2),train_Yhat_s,'b^');
plot(test_fXX(:,2),test_Yhat_s,'r^');
plot(fXX(:,2),train_Yhat_t,'bs');
plot(test_fXX(:,2),test_Yhat_t,'rs');

legend('train data', 'test data', 'first order train estimation', 'first order test estimation', ...
   'second order train estimation', 'second order test estimation', ... 
   'third order train estimation', 'third order test estimation');

train_MSE_f=sum((Y(trainIDs)-train_Yhat_f).*(Y(trainIDs)-train_Yhat_f))/size(trainIDs,1);
train_MSE_s=sum((Y(trainIDs)-train_Yhat_s).*(Y(trainIDs)-train_Yhat_s))/size(trainIDs,1);
train_MSE_t=sum((Y(trainIDs)-train_Yhat_t).*(Y(trainIDs)-train_Yhat_t))/size(trainIDs,1);

test_MSE_f=sum((Y(testIDs)-test_Yhat_f).*(Y(testIDs)-test_Yhat_f))/size(testIDs,1);
test_MSE_s=sum((Y(testIDs)-test_Yhat_s).*(Y(testIDs)-test_Yhat_s))/size(testIDs,1);
test_MSE_t=sum((Y(testIDs)-test_Yhat_t).*(Y(testIDs)-test_Yhat_t))/size(testIDs,1);

title({['first order train MSE=' num2str(train_MSE_f) ' second order train MSE=' num2str(train_MSE_s) ' third order train MSE=' num2str(train_MSE_t)] ; ...
       ['first order test MSE=' num2str(test_MSE_f) ' second order test MSE=' num2str(test_MSE_s) ' third order test MSE=' num2str(test_MSE_t)]});
xlabel('X');
ylabel('f(X)');