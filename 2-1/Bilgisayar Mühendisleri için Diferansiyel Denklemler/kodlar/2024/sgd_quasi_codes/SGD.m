% optimization in n dimensions
% stochastic GD
% ve Adagrad 
clear all;
close all;

syms x1 x2;
% diff(f,n,v) differentiate f n times with respect to v .
f=(x1^2)/2 +(x1*x2)/2+x2^2-0.5*x1-0.5*x2+0.5;
%f=( -20*exp(-0.2*sqrt((1/2)*(x1.^2+x2.^2))) - ...
%    exp((1/2)*(cos(2*pi*x1) + cos(2*pi*x2))) + ...
%    20 + exp(1) + 5.7); % acckley
%f=((x1^2/4000)+(x2^2/4000))-(cos(x1)*cos(x2/(sqrt(2)))); % griewank 
%f=10*2 + x1.^2 + x2.^2 - 10*cos(2*pi*x1) - 10*cos(2*pi*x2); % rastrigin 
%f=100*(x1^2-x2)^2+(x1-1)^2; % rosen 
%f=(abs(x1)+abs(x2))+(abs(x1)*abs(x2)); % schwell 
%f=(x1*x1)+(x2*x2); % sphere 
f=(x1*x1)+(8*x2*x2); % valley 
%f=(x1*x1*x1*x1)+(2*x2*x2); % valley 

dfdx1=diff(f,1,x1);
dfdx2=diff(f,1,x2);
dfdx1dx2=diff(dfdx1,1,x2);
dfdx2dx1=dfdx1dx2;
dfdx1dx1=diff(f,2,x1);
dfdx2dx2=diff(f,2,x2);
df=[dfdx1 ; dfdx2];
ddf=[dfdx1dx1 dfdx1dx2; dfdx2dx1 dfdx2dx2];

% plot function f
m1=-3:0.1:3;
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
%x_new = [-2 ; 1.5]; % The starting point 
x_new = [-2.9 ; 2.5]; % The starting point 
%x_new = [0.01 ; 2.5]; % The starting point 


eps = 0.1; % step size
precision = 0.0001; % stopping condition1
max_iter=100; % stopping condition2
Xs=zeros(2,max_iter); % input has 2 dims.
Ys=zeros(1,max_iter); % output has 1 dim.
gds=zeros(2,max_iter); % her noktadaki gradyanlarý tutar
gds_op_sum=zeros(4,max_iter); % gradyanlarýn outer product larýnýn i. ana kadarki toplamýný tutar
hes=zeros(4,max_iter); % her noktadaki hessian lari tutar
ap_Hs=zeros(4,max_iter); % her noktadaki approx. hessian lari tutar
i=1;
g_top=[1 0 0 1]';%zeros(4,1);
while sum(abs(x_new - x_old)) > precision && max_iter>=i
    Xs(:,i)=x_new;
    Ys(i)=subs(f,{x1,x2},{x_new(1),x_new(2)});
    x_old = x_new;
   
    dfV=subs(df,{x1,x2},{x_old(1),x_old(2)});
    dfV=dfV+randn(2,1); % daha cok bozuyor rand a göre
    %dfV=dfV+(rand(2,1)*2)-1; 
    %z=1+exp(-i/5);
    %dfV=dfV+z*randn(2,1); % boyle olmaz -- zordan kolaya için once buyuk varyanslý sonra kucuk varyanslý gürültü ekleniyor
    
    ddfV=subs(ddf,{x1,x2},{x_old(1),x_old(2)});
    %x_new = x_old - eps * dfV; % gradient decent finds the point where f'(x)=0
    % [2,1] = [2,1] - [1,1]*[2,1]
 
    %x_new = x_old - inv(ddfV)*dfV; % newton raphson 2nd order finds the point where f'(x)=0 
    % [2,1] = [2,1] - [2,2]*[2,1]
    
    % Adagrad
    gds(:,i)=double(dfV);
    g_top=g_top+reshape(double(dfV)*double(dfV)',4,1);
    g_top(2)=0;g_top(3)=0; % diagonal matris haline getir
    gds_op_sum(:,i)=g_top; % /i yapip ortalama alýnca yön deðiþmiyor adýmlar küçülüp adým sayýsý artýyor
    ap_H=sqrtm(reshape(g_top,2,2));
    hes(:,i)=reshape(double(ddfV),4,1);
    ap_Hs(:,i)=reshape(ap_H,4,1);
    x_new = x_old - ap_H\dfV; % approx hessian: outer products of gradyan kullanan
    
    i=i+1;
end
hold on;
plot(Xs(1,1:i-1),Xs(2,1:i-1),'r');
text(Xs(1,1:i-1),Xs(2,1:i-1),cellstr(int2str([1:i-1]')));


figure; plot(Xs(1,1:i-1)); hold on; plot(Xs(2,1:i-1));
xlabel('iteration'); ylabel('values');
legend('x','y');

Xs(:,i-1) % son deðer
mean(Xs(:,1:i-1)') % tüm degerlerin ortalamasý



