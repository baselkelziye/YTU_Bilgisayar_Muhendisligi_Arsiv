clear all;
close all;

N=100; % nokta sayisi
CN=50; % centroid sayisi
G=3000; % guncelleme sayisi
lr=0.99; % en yakini yaklastirma orani
lr2=0.99; % komsularini yaklastirma orani  
dlr=0.99; % lr nin azalma orani

P=rand(N,2); % points
C=rand(CN,2); % centroids
% cizdir
plot(P(:,1),P(:,2),'*');
hold on;
plot(C(:,1),C(:,2),'r*');

for i=1:CN-1
    % i. noktadan i+1. noktaya çizgi çiz
    line([C(i,1) C(i+1,1) ],[ C(i,2) C(i+1,2)]);
end

% hepsi bir öncesine ve bir sonrasina bagli olacak
% 2-49 arasi standart, 1. ve N. farkli.
sirali=1:CN;
komsular=[(sirali-1)' (sirali+1)'];
komsular(1,1)=CN;
komsular(CN,2)=1; % dongusel komsuluk icin 1, dogrusal için N olmali

for i=1:G
    % bir nokta sec
    j=P(randi(N),:);
    % ona en yakin centroid i bul
    [D,k] = pdist2(C,j,'euclidean','Smallest',1);
    % centroid ve komsularini guncelle
    C(k,:)=C(k,:)-lr*(C(k,:)-j);
    gk=komsular(k,:); % guncellenecek komsulari bul
    % kumsulari guncelle
    %if gk(1)<N
        C(gk(1),:)=C(gk(1),:)-lr2*(C(gk(1),:)-j);
    %end
    %if gk(2)<N
        C(gk(2),:)=C(gk(2),:)-lr2*(C(gk(2),:)-j);
    %end
    
    %yaklastirma oranini guncelle 
    if mod(i,20) == 1
        lr=lr*dlr;
        lr2=lr;
    end
    
%     % cizdir
%     if mod(i,20) == 1
%         figure;
%         plot(P(:,1),P(:,2),'*');
%         hold on;
%         plot(C(:,1),C(:,2),'k*');
%         hold on;
% %         plot(j(1),j(2),'r*');
% %         hold on;
%         
%         for i=1:N-1
%             % i. noktadan i+1. noktaya çizgi çiz
%             line([C(i,1) C(i+1,1) ],[ C(i,2) C(i+1,2)]);
%         end
%         pause(2);
%         close all;
%     end
end

figure;
plot(P(:,1),P(:,2),'*');
hold on;
plot(C(:,1),C(:,2),'r*');
hold on;
for i=1:CN-1
    % i. noktadan i+1. noktaya çizgi çiz
    line([C(i,1) C(i+1,1) ],[ C(i,2) C(i+1,2)]);
end
