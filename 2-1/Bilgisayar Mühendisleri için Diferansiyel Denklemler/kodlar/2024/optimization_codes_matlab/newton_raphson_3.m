% The Newton-Raphson algorithm 
% using approximated derivatives.

% f(x)=sin(x), with derivative f'(x)=cos(x) f''(x)=-sin(x).

clear all;
close all;

% plot objective function
x=-pi:0.25:pi;
y=zeros(1,length(x));
dfs=y; ddfs=y; n2=y;
for i=1:length(x)
    y(i)=sin(x(i)); 
    dfs(i)= cos(x(i));
    ddfs(i)= -sin(x(i));
    n2(i)=dfs(i)/ddfs(i);
end
plot(x,y);
hold on
plot(x,dfs,'r-');
plot(x,ddfs,'g-');
%plot(x(2:end-1),n2(2:end-1),'m-');
hold off

x_old = 0;
x_new = -0.5; % The starting point
eps = 0.05; % step size
h=0.5; % for approximation
precision = 0.00001; % stopping condition1
max_iter=200; % stopping condition2
Xs=zeros(1,max_iter);
Ys=zeros(1,max_iter);
i=1;
while abs(x_new - x_old) > precision && max_iter>=i
    Xs(i)=x_new;
    Ys(i)=sin(x_new); 
    hold on;
    plot(Xs(i),Ys(i),'r*');
    text(Xs(i),Ys(i),int2str(i));

    x_old = x_new;
    % real derivatives
    %df= cos(x_old);
    %ddf= -sin(x_old); 
    % approximated derivatives
    df= (sin(x_old+h/2)-sin(x_old-h/2))/h;
    ddf= (sin(x_old+h)-2*sin(x_old)+sin(x_old-h))/(h*h);
    %x_new = x_old - eps * df; % gradient decent % finds the point where f'(x)=0 
    x_new = x_old - df/ddf; % newton raphson 2nd order % finds the point where f'(x)=0 
    i=i+1;
end
figure;
plot(Xs(1:i-1));
xlabel('iteration');
ylabel('x values');