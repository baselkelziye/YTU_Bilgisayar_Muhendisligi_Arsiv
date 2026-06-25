% quadratic functions in n dimensions

% f(x)=(1/2) * xT * q * x + bT * x + c 
%f: Rn--> R
%q--> n*n
%b--> n*1
%c--> 1*1

clear all;
close all;
% n=2
q=[1 0.5; 0.5 -2];
b=[0.1 ;1];
c=0.5;

x1=-5:0.5:5;
x2=x1;
z=zeros(length(x1),length(x1));
for i=1:length(x1)
    for j=1:length(x2)
        x=[x1(i); x2(j)];
        z(j,i)=(1/2)*x'*q*x+b'*x+c;
    end
end

surfc(x1,x2,z)
figure;
contour(x1,x2,z)
