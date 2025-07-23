% optimization in n dimensions

clear all;
close all;

syms x1 x2;
% diff(f,n,v) differentiate f n times with respect to v .
%f=(x1^2)/2 +(x1*x2)/2+x2^2-0.5*x1-0.5*x2+0.5;
%f=( -20*exp(-0.2*sqrt((1/2)*(x1.^2+x2.^2))) - ...
%    exp((1/2)*(cos(2*pi*x1) + cos(2*pi*x2))) + ...
%    20 + exp(1) + 5.7); % acckley
f=((x1^2/4000)+(x2^2/4000))-(cos(x1)*cos(x2/(sqrt(2)))); % griewank 
%f=10*2 + x1.^2 + x2.^2 - 10*cos(2*pi*x1) - 10*cos(2*pi*x2); % rastrigin 
%f=100*(x1^2-x2)^2+(x1-1)^2; % rosen 
%f=(abs(x1)+abs(x2))+(abs(x1)*abs(x2)); % schwell 
%f=(x1*x1)+(x2*x2); % sphere 
%f=(x1*x1)+(2*x2*x2); % valley 



dfdx1=diff(f,1,x1);
dfdx2=diff(f,1,x2);
dfdx1dx2=diff(dfdx1,1,x2);
dfdx2dx1=dfdx1dx2;
dfdx1dx1=diff(f,2,x1);
dfdx2dx2=diff(f,2,x2);
df=[dfdx1 ; dfdx2];
ddf=[dfdx1dx1 dfdx1dx2; dfdx2dx1 dfdx2dx2];

% plot function f
m1=-3:0.5:3;
m2=m1;
z=zeros(length(m1),length(m1));
for i=1:length(m1)
    for j=1:length(m2)
        z(j,i)=subs(f,{x1,x2},{m1(i),m2(j)}); 
    end
end

surfc(m1,m2,z)
figure;
[C,h]=contour(m1,m2,z);
%set(h,'ShowText','on');
axis equal

x_old = [0 ; 0];
x_new = [-1 ; 1.7]; % The starting point 
eps = 0.1; % step size
precision = 0.0001; % stopping condition1
max_iter=1000; % stopping condition2
Xs=zeros(2,max_iter); % input has 2 dims.
Ys=zeros(1,max_iter); % output has 1 dim.
i=1;
while sum(abs(x_new - x_old)) > precision && max_iter>=i
    Xs(:,i)=x_new;
    Ys(i)=subs(f,{x1,x2},{x_new(1),x_new(2)});
    hold on;
    plot(Xs(1,i),Xs(2,i),'r*');
    text(Xs(1,i),Xs(2,i),int2str(i));

    x_old = x_new;
   
    dfV=subs(df,{x1,x2},{x_old(1),x_old(2)});
    ddfV=subs(ddf,{x1,x2},{x_old(1),x_old(2)});
    %x_new = x_old - eps * dfV; % gradient decent finds the point where f'(x)=0
    % [2,1] = [2,1] - [1,1]*[2,1]
    x_new = x_old - inv(ddfV)*dfV; % newton raphson 2nd order finds the point where f'(x)=0 
    %x_new = x_old - (dfV'/ddfV)'; % newton raphson 2nd order finds the point where f'(x)=0 
    
    % [2,1] = [2,1] - [2,2]*[2,1]
    i=i+1;
end

%figure;
%plot(Xs(1:i-1));
%xlabel('iteration');
%ylabel('x values');





