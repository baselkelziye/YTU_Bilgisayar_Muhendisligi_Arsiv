% The Newton-Raphson algorithm 

% f(x)=x^4-3x^3+2, with derivative f'(x)=4x^3-9x^2.

clear all;
close all;

% plot objective function
x=-2:0.01:4;
y=zeros(1,length(x));
dfs=y; ddfs=y;
for i=1:length(x)
    y(i)=x(i)^4-3*x(i)^3+2;
    dfs(i)= 4 * x(i)^3 - 9 * x(i)^2;
    ddfs(i)= 12* x(i)^2 - 18 * x(i);
end
plot(x,y);
hold on
plot(x,dfs,'r-');
plot(x,ddfs,'g-');
hold off

x_old = 0;
x_new = -1.5; % The starting point 
eps = 0.05; % step size
precision = 0.00001; % stopping condition1
max_iter=200; % stopping condition2
Xs=zeros(1,max_iter);
Ys=zeros(1,max_iter);
i=1;
while abs(x_new - x_old) > precision && max_iter>=i
    Xs(i)=x_new;
    Ys(i)=x_new^4-3*x_new^3+2;
    hold on;
    plot(Xs(i),Ys(i),'r*');
    text(Xs(i),Ys(i),int2str(i));

    x_old = x_new;
    df= 4 * x_old^3 - 9 * x_old^2;
    ddf= 12* x_old^2 - 18 * x_old;
    %x_new = x_old - eps * df; % gradient decent % finds the point where f'(x)=0 
    x_new = x_old - df/ddf; % newton raphson 2nd order % finds the point where f'(x)=0 
    %x_new = x_old - (Ys(i)/df); % newton raphson 1st order % finds the point where f(x)=0
    i=i+1;
end
figure;
plot(Xs(1:i-1));
xlabel('iteration');
ylabel('x values');