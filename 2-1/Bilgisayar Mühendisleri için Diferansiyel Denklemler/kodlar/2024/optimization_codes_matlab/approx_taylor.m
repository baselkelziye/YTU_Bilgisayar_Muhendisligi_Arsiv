% function approximation with taylor

clear all;
close all;
syms x;
f=exp(x);
N=5;
domX=-4:0.1:4;  
X=1.25;
X=ones(1,size(domX,1))*X;
dX=domX-X;  % domX=X+dX --> dX=domX-X 
Y=zeros(1,size(domX,1));
rY=subs(f,{x},{domX});
plot(domX,rY,'r');
hold on;
for i=0:N
dfi=diff(f,i,x);
Y1=subs(dfi,{x},{X}); % one value
Y2=dX.^i;
Y3=Y1*Y2/factorial(i);
Y=Y+Y3;
if i==N 
   plot(domX,Y,'g');
else
   plot(domX,Y);
end
end
xlabel('x');
ylabel(['Taylor approximations of   ' char(f)]);
axis equal