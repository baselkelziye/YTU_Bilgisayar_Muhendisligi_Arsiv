% stochastic GD neden calisir?
clear all;
close all;

w = 1; % gercek w
n=8; % sample size
gr=2*(2*rand(n,1)-1); % gurultu
ww=w+gr; % uretecegimiz orneklerin x leri
ai=2*rand(n,1)-1; % input (-1,+1) arasý
%ai=2*rand(n,1)+1; % input (+1,+3) arasý

bi=ai.*ww; % output
plot(ai,bi,'*');
text(ai,bi,cellstr(int2str([1:n]')),'FontSize',14);
hold on;
plot([-1 1],w*[-1 1]);
plot([-1 1],-10*[-1 1],'--m');



figure;
hold on;
x=-10:0.1:10;
fi=zeros(n,size(x,2));
for i=1:n
    fi(i,:)=0.5*(ai(i)*x-bi(i)).^2; % MSE
    %fi(i,:)=abs(ai(i)*x-bi(i)); % MAE
    plot(x,fi(i,:),'-');
    text(x(1),fi(i,1),int2str(i));
end
plot(x,sum(fi)/n,'--k'); % f i görelim

