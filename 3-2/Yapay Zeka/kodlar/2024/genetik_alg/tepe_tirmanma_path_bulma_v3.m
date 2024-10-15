clear all;
close all;
% bir noktadan bir noktaya giden yol bulmak
% tepe tirmanma ile
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

P=2000; % yon sayisi
u=40; % her bireyin uzunluðu
mu=0.02; % degisim orani
G=1000; % iterasyon sayisi
%cross=2; % crossover 1: tek noktadan 2: cift noktadan
%BK=P-P/2; % sonraki nesle direkt kopyalanan en iyi birey sayisi
B=zeros(1,u); % bireyler
bas=[50 50];
son=[55 55];
max_f1=u+1;
max_f2=sum(abs(bas-son));
max_f3=180*(u-1);
bb=zeros(1,G); %cozumlerin iyilik degerini tutar
%ob=bb; % her neslin ortalama degerini tutar
% ilk bireyleri uret
B=round(8*rand(1,u)); % 0 8 arasi sayýlarla doldur
best_val=10;
tk=1; % kac kez ardisik ayni kaldigi
for i=1:G
    % çözümün ve ondan üretilebileceklerim fitness larini hesapla
    f1=zeros(1,P+1);  f2=f1; f3=f1;
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
    b_ind=1;%B(u_ind)+1; % mevcutun BS nin kacinci satiri oldugu
    
    % w si en kucuk olan
    [val bi]=min(w);
    if w(bi)<w(b_ind) % en iyisi mevcut olandan iyi ise degistir
        B=BSS(bi,:);
        tk=0; % degisti ise 0 la
    else
        tk=tk+1; % degismedi ise 1 arttir
        
    end
    bb(i)=val;
    if best_val>val
        best_val=val;
        best_B=B;
    end
    if tk==10 % 10 kez ayni kaldýysa restart
        B=round(8*rand(1,u));
        tk=0;
    end
    
    
end
plot(bb); % en iyileri ciz
best_val

% en iyi bireyi ciz
M=zeros(Mx,My); % ortamý 0 la
birey=best_B;
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

