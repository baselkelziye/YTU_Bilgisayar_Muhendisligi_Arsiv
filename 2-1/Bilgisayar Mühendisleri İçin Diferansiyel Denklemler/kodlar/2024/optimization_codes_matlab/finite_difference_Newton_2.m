% The central difference Newton method  

% f(x)=x^4-3x^3+2, with derivative f'(x)=4x^3-9x^2.

clear all;
close all;

% plot objective function
x=-2:0.05:4;
y=zeros(1,length(x));
dfs=y; % holds real derivative values
fdfs=y; % holds forward approximated derivates values
cdfs=y; % holds central approximated derivates values
fedfs=y; % holds the difference between fdfs and dfs
cedfs=y; % holds the difference between cdfs and dfs

delta=2;
for i=1:length(x)
    y(i)=x(i)^4-3*x(i)^3+2;
    dfs(i)= 4 * x(i)^3 - 9 * x(i)^2;
    % forward difference
    fxplusdelta=(x(i)+delta)^4-3*(x(i)+delta)^3+2;
    fdfs(i)=(fxplusdelta-y(i))/ delta;
    fedfs(i)=fdfs(i)-dfs(i);
    % central difference
    fxplushalfdelta=(x(i)+delta/2)^4-3*(x(i)+delta/2)^3+2;
    fxminushalfdelta=(x(i)-delta/2)^4-3*(x(i)-delta/2)^3+2;
    cdfs(i)=(fxplushalfdelta-fxminushalfdelta)/delta;
    cedfs(i)=cdfs(i)-dfs(i);
end
plot(x,y);
hold on
plot(x,dfs,'r-');
plot(x,fedfs,'g-');
plot(x,cedfs,'m-');
hold off