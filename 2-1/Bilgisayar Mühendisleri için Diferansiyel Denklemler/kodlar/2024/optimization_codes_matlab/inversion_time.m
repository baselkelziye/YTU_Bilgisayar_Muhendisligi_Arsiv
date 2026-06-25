
% matrix inversion

clear all;
close all;

% matrix (n,n)
% repeat number r
r=10;
i=1;
Mtime=[];
Mstd=[];
for n=5:10:500 % matrix N
    Etime=zeros(1,r);
    for j=1:r % repeat 
        M=rand(n,n);
        estart=clock;
        MT=inv(M);
        eend=clock; 
        ttemp=eend-estart;
        Etime(j)= ttemp(4)*3600+ttemp(5)*60+ttemp(6);
    end
    Mtime(i)=mean(Etime);
    Mstd(i)=std(Etime);
    i=i+1;
    n
end
plot([5:10:500],Mtime)
hold on;
plot([5:10:500],Mstd,'r-')
xlabel('matrix size');
ylabel('time (second)');
