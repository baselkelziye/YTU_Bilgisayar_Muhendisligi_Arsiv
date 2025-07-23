% steepest descent in 2 dimensions

clear all;
close all;

syms x1 x2;
f=(x1*x1)-(x2);  

% diff(f,n,v) differentiate f n times with respect to v .
dfdx1=diff(f,1,x1);
dfdx2=diff(f,1,x2);
df=[dfdx1 ; dfdx2];

% plot function f
m1=-5:0.2:5;
m2=m1;
z=zeros(length(m1),length(m1));
for i=1:length(m1)
    for j=1:length(m2)
        %z(j,i)=subs(f,{x1,x2},{m1(i),m2(j)}); 
        z(j,i)=(m1(i)*m1(i))-(m2(j));  
    end
end

surfc(m1,m2,z)
figure;
contour(m1,m2,z)
axis equal

x_old = [0 ; 0];
x_new = [4 ; -4]; % The starting point 
eps = 0.05; % step size
precision = 0.0001; % stopping condition1
max_iter=50; % stopping condition2
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
    %x_new = x_old - eps * dfV; % gradient decent finds the point where f'(x)=0
    %eps= ((x_old(1)^2)+(x_old(2)^2)) / ( 2*(x_old(1)^2)-(x_old(2)^2) );
    eps= 1/2 + 1/(8*(x_old(1)^2)); 
    x_new = x_old - eps * dfV; % steepest decent finds the point where f'(x)=0
    
    i=i+1;
end
