clear all;
close all;
% bir noktadan bir noktaya giden yol bulmak
% genetik alg ile
% fitness1: en çok alan gezmesi  / gezebilecegi-gezdigi hucre sayisi
% fitness2: vardýðý yerin hedefe yakýnlýðý
% fitness3: yön deðiþtirme miktarý

% sonra eklenebilecekler :
% biren çok robot, carpisma,
% iletiþim kýsýtlarý vb.

% olasý hareketler [0 8] 0 olduðu yerde kalmasý 1-8 yönler
hareket=[0 0; 0 1; -1 1; -1 0; -1 -1; 0 -1; 1 -1 ; 1 0; 1 1];

% ardisik hareketler arasi maliyetler:
ac_t=[2:9];
ac=(ac_t-2)*45; ac=[0 ac]; % 0 0 45 90 135 180 225 270 315

Mx=100;My=100; % ortam buyuklugu
M=zeros(Mx,My);% M matrisi ortam
P=5000; % populasyon buyuklugu
u=40; % her bireyin uzunluðu
mu=0.005; % mutasyon orani
G=500; % nesil sayisi
cross=2; % crossover 1: tek noktadan 2: cift noktadan
BK=P-P/4; % sonraki nesle direkt kopyalanan en iyi birey sayisi
B=zeros(P,u); % bireyler
bas=[50 50];
son=[55 55];
max_f1=u+1;
max_f2=sum(abs(bas-son));
max_f3=180*(u-1);
bb=zeros(1,G); %her nesilin en iyi bireyinin iyilik degerini tutar
ob=bb; % her neslin ortalama degerini tutar
% ilk bireyleri uret
B=round(8*rand(P,u)); % 0 8 arasi sayýlarla doldur
for i=1:G
    % bireylerin fitness larini hesapla
    f1=zeros(1,P);  f2=f1; f3=f1;
    for j=1:P
        M=zeros(Mx,My); % ortamý 0 la
        birey=B(j,:);
        % bireyin hareketini olustur
        kxy=bas;
        M(kxy(1),kxy(2))=1;  % baslangýçta
        for k=1:u
            kxy=kxy+hareket(birey(k)+1,:); % hareket et
            if kxy(1)==0 || kxy(2)==0
                dd=4;
            end
            M(kxy(1),kxy(2))=k+1;
        end
        % path olustu
        %figure;image(2*M);
        f1(j)=u-size(find(M),1)+1; % max-gezdigi hucre sayisi
        f2(j)=sum(abs(son-kxy)); % hedefe uzaklik
        % f3 yön deðiþtirme miktarý
        birey_arti=birey+1;
        birey_2=birey_arti(2:end);
        birey_1=birey_arti(1:end-1);
        a1=ac(birey_1); a2=ac(birey_2);
        fark=abs(a1-a2);
        fark(fark>180)=360-fark(fark>180);
        f3(j)=sum(fark);
        %title(['f1=',num2str(f1(j)),' f2=' ,num2str(f2(j)),' f3=' ,num2str(f3(j)),' birey=' num2str(birey_arti)]);
    end
    % fitness a göre seçim yap
    % f1 buyuk, f2 buyuk, f3 buyuk olsun istiyoruz
    n_f1=f1/max_f1; n_f2=f2/max_f2; n_f3=f3/max_f3;
    w=n_f1+n_f2+n_f3;
    %w=n_f2;
    n_w=w/sum(w); % n_w de minlerin secilme sansi yuksek olmalý
    n_w=1-n_w;
    n_w=n_w/sum(n_w);
    % rulet tekeri
    [sorted,inds]=sort(n_w);
    rn_w(inds)=1:P;
    rn_w=rn_w/sum(rn_w);
    [val best_ind]=max(rn_w);
    %best_ind
    bb(i)=w(best_ind);
    ob(i)=mean(w);
    secilenler = randsample(P,P,true,rn_w);
    % yeni bireyleri üret % tek/cift noktali crossover
    YB=zeros(P,u); % yeni bireyler
    for j=1:P/2
        b1=B(secilenler(j),:);
        b2=B(secilenler(j+(P/2)),:);
        if cross==1 % tek noktalý crossover
            kesme=round((u-3)*rand(1,1))+2; % 2 - (u-1) arasi sayi
            YB(j,:)      =[b1(1:kesme) b2(kesme+1:end)];
            YB(j+(P/2),:)=[b2(1:kesme) b1(kesme+1:end)];
        else
            % cift noktalý crossover
            kesme=round((u-3)*rand(1,2))+2; % 2 - (u-1) arasi 2 sayi
            kesme=sort(kesme); % kucukten buyuge sirala
            YB(j,:)      =[b1(1:kesme(1)) b2(kesme(1)+1:kesme(2)) b1(kesme(2)+1:end) ];
            YB(j+(P/2),:)=[b2(1:kesme(1)) b1(kesme(1)+1:kesme(2)) b2(kesme(2)+1:end) ];
        end
    end
    if BK>0 % B deki en iyi BK degeri YB ye kopyala
        YB(inds(BK+1:end),:)=B(inds(BK+1:end),:); 
    end
    % mutasyon uygula
    d_ind=rand(P,u)<mu; % degisecek hucreler
    yy=round(8*rand(P,u)); % nelerle degisecekleri
    YB(d_ind)=yy(d_ind);
    B=YB; % yeni nesil hazir
    
end

plot(bb); % en iyileri ciz
hold on;
plot(ob); % ortlamayý çiz

% en iyi bireyi ciz
M=zeros(Mx,My); % ortamý 0 la
birey=B(best_ind,:);
% bireyin hareketini olustur
kxy=bas;
M(kxy(1),kxy(2))=1;  % baslangýçta
for k=1:u
    kxy=kxy+hareket(birey(k)+1,:); % hareket et
    M(kxy(1),kxy(2))=k+1;
end
M(son(1),son(2))=64;
% path olustu
figure;image((50/u)*M);

