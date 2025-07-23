% The finite difference Newton method  

% f(x)=x^4-3x^3+2, with derivative f'(x)=4x^3-9x^2.

clear all;
close all;

% plot objective function
x=-2:0.01:4;
y=zeros(1,length(x));
dfs=y; % holds real derivative values
adfs=y; % holds approximated derivates values
edfs=y; % holds the difference between dfs and adfs
delta=0.05;
for i=1:length(x)
    y(i)=x(i)^4-3*x(i)^3+2;
    dfs(i)= 4 * x(i)^3 - 9 * x(i)^2;
    fxplusdelta=(x(i)+delta)^4-3*(x(i)+delta)^3+2;
    adfs(i)=(fxplusdelta-y(i))/ delta;
    edfs(i)=adfs(i)-dfs(i);
end
plot(x,y);
hold on
plot(x,dfs,'r-');
plot(x,adfs,'g-');
plot(x,edfs,'m-');
hold off