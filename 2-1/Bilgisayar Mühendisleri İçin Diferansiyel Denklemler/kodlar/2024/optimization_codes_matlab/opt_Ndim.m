% optimization in n dimensions

% f(x)=(1/2) * xT * q * x + bT * x + c 
%f: Rn--> R
%q--> n*n
%b--> n*1
%c--> 1*1

clear all;
close all;
% n=2
q=[1 0.5; 0.5 2];
b=[-0.5 ;-0.5];
c=0.5;

%f(x1,x2) = (x1^2)/2 +(x1*x2)/2+x2^2-0.5*x1-0.5*x2+0.5
% dfdx1 = x1+x2/2-0.5
% dfdx2 = x1/2+2*x2-0.5

x1=-5:0.5:5;
x2=x1;
z=zeros(length(x1),length(x1));
for i=1:length(x1)
    for j=1:length(x2)
        x=[x1(i); x2(j)];
        z(j,i)=(1/2)*x'*q*x-b'*x+c;
    end
end

surfc(x1,x2,z)
figure;
contour(x1,x2,z)
axis equal

x_old = [0 ; 0];
x_new = [5 ; 3]; % The starting point 
eps = 0.1; % step size
precision = 0.0000000000000000000000001; % stopping condition1
max_iter=100; % stopping condition2
Xs=zeros(2,max_iter); % input has 2 dims.
Ys=zeros(1,max_iter); % output has 1 dim.
i=1;
while sum(abs(x_new - x_old)) > precision && max_iter>=i
    Xs(:,i)=x_new;
    Ys(i)=(1/2)*x_new'*q*x_new-b'*x_new+c;
    hold on;
    plot(Xs(1,i),Xs(2,i),'r*');
    text(Xs(1,i),Xs(2,i),int2str(i));

    x_old = x_new;
    dfdx1= x_old(1)+x_old(2)/2-0.5;
    dfdx2= x_old(1)/2+2*x_old(2)-0.5;
    
    df=[dfdx1 ; dfdx2];
    ddf=q;
    %x_new = x_old - eps * df; % gradient decent finds the point where f'(x)=0
    % [2,1] = [2,1] - [1,1]*[2,1]
    x_new = x_old - inv(ddf)*df; % newton raphson 2nd order finds the point where f'(x)=0 
    % [2,1] = [2,1] - [2,2]*[2,1]
    i=i+1;
end







