clear all;
close all;
% bir noktadan baslayip alaný minimum donusle taramak
% tepe tirmanma alg ile
% fitness1: en çok alan gezmesi  / gezebilecegi-gezdigi hucre sayisi
% fitness3: yön deðiþtirme miktarý

% sonra eklenebilecekler :
% biren çok robot
% iletiþim kýsýtlarý vb.

% olasý hareketler [0 8] 0 olduðu yerde kalmasý 1-8 yönler
hareket=[0 0; 0 1; -1 1; -1 0; -1 -1; 0 -1; 1 -1 ; 1 0; 1 1];

% ardisik hareketler arasi maliyetler:
ac_t=[2:9];
ac=(ac_t-2)*45; ac=[0 ac]; % 0 0 45 90 135 180 225 270 315

Mx=8;My=Mx; % ortam buyuklugu
M=zeros(Mx,My);% M matrisi ortam
P=200; % yon sayisi
u=Mx*Mx-1; % her bireyin uzunluðu
mu=0.01; % degisim orani
mu_start=mu;
mu_dec=0.99; % azalma orani
mu_inc=1.01; % artma orani
tk_max=50; % tk_max kez ayni kaldýysa restart
G=3000; % iterasyon sayisi
%cross=2; % crossover 1: tek noktadan 2: cift noktadan
%BK=P-P/2; % sonraki nesle direkt kopyalanan en iyi birey sayisi
B=zeros(1,u); % bireyler
bas=[1 1];
%son=[55 55];
max_f1=u+1;
%max_f2=sum(abs(bas-son));
max_f3=180*(u-1);
bb=zeros(1,G); %cozumlerin iyilik degerini tutar
%ob=bb; % her neslin ortalama degerini tutar
% ilk bireyleri uret
tic
B=round(8*rand(1,u)); % 0 8 arasi sayýlarla doldur
best_val=10;
tk=1; % kac kez ardisik ayni kaldigi
mus=zeros(1,G);
for i=1:G
    % çözümün ve ondan üretilebileceklerim fitness larini hesapla
    f1=zeros(1,P+1);  f3=f1; %f2=f1; 
    % P adet yeni path uret. once P kez kopyala P yi sonra rasgele degisim yap.
    %sonra tum pathler icin fitness hesapla
        
    BSS=repmat(B,P,1);
    d_ind=rand(P,u)<mu; % degisecek hucreler
    yy=round(8*rand(P,u)); % nelerle degisecekleri
    BSS(d_ind)=yy(d_ind); % degistir
        
    BSS=[B;BSS];% ilki B olsun
    
    for j=1:P+1
        M=zeros(Mx,My); % ortamý 0 la
        birey=BSS(j,:);
        % bireyin hareketini olustur
        kxy=bas;
        M(kxy(1),kxy(2))=1;  % baslangýçta
        for k=1:u
            p_kxy=kxy+hareket(birey(k)+1,:); % hareketi olustur
            if p_kxy(1)<1 || p_kxy(2)<1 || p_kxy(1)>Mx  || p_kxy(2)>Mx % disari cikarsa yerinde kalsin
            else % disari cikmadi hareket et
                kxy=p_kxy;
            end
            M(kxy(1),kxy(2))=k+1;
        end
        % path olustu
        %figure;image(2*M);
        f1(j)=u-size(find(M),1)+1; % max-gezdigi hucre sayisi
        %f2(j)=sum(abs(son-kxy)); % hedefe uzaklik
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
    n_f1=f1/max_f1; n_f3=f3/max_f3; %n_f2=f2/max_f2; 
    w=n_f1+n_f3;
    b_ind=1;%B(u_ind)+1; % mevcutun BS nin kacinci satiri oldugu
    
    % w si en kucuk olan
    [val bi]=min(w);
    if w(bi)<w(b_ind) % en iyisi mevcut olandan iyi ise degistir
        B=BSS(bi,:);
        tk=0; % degisti ise 0 la
        if mu<=mu_start
            mu=mu*mu_dec; % mutasyon oranini azalt
        else
            mu=mu_start;
        end
    else
        tk=tk+1; % degismedi ise 1 arttir
        mu=mu*mu_inc; % mutasyon oranini arttýr
    end
    bb(i)=val;
    if best_val>val
        best_val=val;
        best_B=B;
    end
    
    if tk==tk_max % tk_max kez ayni kaldýysa restart
        B=round(8*rand(1,u));
        tk=0;
        mu=mu_start;
    end
    mus(i)=mu;
    
    
end
figure;plot(mus); title(['mu degisimi']);
figure;plot(bb); % en iyileri ciz
best_val

% en iyi bireyi ciz
M=zeros(Mx,My); % ortamý 0 la
birey=best_B;
% bireyin hareketini olustur
kxy=bas;
M(kxy(1),kxy(2))=1;  % baslangýçta
rota=zeros(2,u);
for k=1:u
    p_kxy=kxy+hareket(birey(k)+1,:); % hareketi olustur
    if p_kxy(1)<1 || p_kxy(2)<1 || p_kxy(1)>Mx  || p_kxy(2)>Mx % disari cikarsa yerinde kalsin
    else % disari cikmadi hareket et
        kxy=p_kxy;
    end
    M(kxy(1),kxy(2))=k+1;
    rota(:,k)=kxy;
end
%M(son(1),son(2))=64;
% path olustu
figure;image((64/u)*M);
figure; plot(rota(1,:),rota(2,:));
axis([0 Mx+1 0 Mx+1]);

toc
