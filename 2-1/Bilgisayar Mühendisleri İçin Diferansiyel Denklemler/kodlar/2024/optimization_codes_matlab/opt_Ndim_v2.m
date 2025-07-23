% optimization in n dimensions

% f(x)=(1/2) * xT * q * x + bT * x + c 
%f: Rn--> R
%q--> n*n
%b--> n*1
%c--> 1*1
%x--> n*1

%df=q*x+b
%ddf=q

clear all;
close all;
n=13;
q=rand(n,n);
q=q'*q;
b=rand(n,1);
c=5;

x_old = rand(n,1);
x_new = rand(n,1); % The starting point
eps = 0.001; % step size
precision = 0.000000001; % stopping condition1
max_iter=1000; % stopping condition2
Xs=zeros(n,max_iter); % input has n dims.
Ys=zeros(1,max_iter); % output has 1 dim.
i=1;
while sum(abs(x_new - x_old)) > precision && max_iter>=i
    Xs(:,i)=x_new;
    Ys(i)=(1/2)*x_new'*q*x_new+b'*x_new+c;

    x_old = x_new;
    df=q*x_old+b;
    ddf=q;
    %x_new = x_old - eps * df; % gradient decent finds the point where f'(x)=0
    % [n,1] = [n,1] - [1,1]*[n,1]
    x_new = x_old - inv(ddf)*df; % newton raphson 2nd order finds the point where f'(x)=0 
    % [n,1] = [n,1] - [n,n]*[n,1]
    i=i+1;
end
plot(Ys(1:i-1));






