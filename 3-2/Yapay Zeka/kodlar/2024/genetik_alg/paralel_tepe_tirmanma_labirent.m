% 1 agent sol dan saga engellere takilmadan gitmeye calisacak
% genetik alg, kromozom: X adet (k*k lik pattern ve hareketi)
clear all;
close all;
% ortam N*N etrafý duvarla cevrili, ici random engel dolu
N=10; % ortamin boyu
G=0.2; % duvar oraný
K=3; % pattern buyuklugu
P=4; % pattern sayisi
PS=50; % populasyon buyuklugu
GS=100; % generation sayisi
HS=30; % her bireyin hareket sayisi
mut_r= 0.2; % mutasyon orani
best_keep = 0.2; % iyilerin ne kadarini bir sonraki nesle aktaralim
delta=(K-1)/2; % delta K ya bagli K=3 için +1 -1 , K=5 için +2 -2
hareketler=[0 1; -1 0; 0 -1; 1 0]; % 1 2 3 4 saðdan baþla saatin tersi yonune
harita=zeros(N+1,N+1); %0 boþ, 1 dolu
harita(1,:)=1; harita(N+1,:)=1; harita(:,1)=1; harita(:,N+1)=1;
%imshow(imresize(harita,10));
duvar_sayi=N*N*G;
duvarX=ceil(N*rand(duvar_sayi,1));
duvarY=ceil(N*rand(duvar_sayi,1));
for i=1:size(duvarX,1)
    harita(duvarX(i),duvarY(i))=1; 
end
figure;
imshow(imresize(harita,10));

% harita=[1	1	1	1	1	1	1	1	1	1	1;
% 1	0	1	0	0	0	1	0	0	0	1;
% 1	0	1	0	0	0	1	0	0	0	1;
% 1	0	1	0	1	0	1	0	0	0	1;
% 1	0	1	0	1	0	1	0	0	0	1;
% 1	0	0	0	1	0	1	0	0	0	1;
% 1	1	1	1	0	0	1	0	0	0	1;
% 1	0	0	0	0	0	1	0	0	0	1;
% 1	0	1	1	1	1	1	1	0	0	1;
% 1	0	0	0	0	0	0	0	0	0	1;
% 1	1	1	1	1	1	1	1	1	1	1];
% figure;
% imshow(imresize(harita,10));

basX=2;basY=2; % baslangic
bitX=9;bitY=9; % bitis

%patternleri uret  PS x K*K*P 
% %50 sini 1 yap
pp = randi(2,PS,K*K*P)-1;
%pattern lere karsilik hareketleri uret P x PS
hh = randi(4,PS,P);

odul_ort=zeros(1,GS);

for i=1:GS % generation sayisi
    %i
    % her bireyi degerlendir
    oduller=zeros(1,PS); % bireylerin odulleri
    curr_posS=zeros(PS,2); % bireylerin son geldikleri noktalar
    moves=zeros(PS,HS,2);
    for j=1:PS
        patternsJ=pp(j,:);
        hareketsJ=hh(j,:);
        curr_pos=[basX basY];
        for k=1:HS % hareketlerini yaptir
            etraf=harita(curr_pos(1)-delta:curr_pos(1)+delta,curr_pos(2)-delta:curr_pos(2)+delta); 
            % hareketi bul
            es=repmat(reshape(etraf',1,K*K),1,P);
            fs=patternsJ-es;
            fs=reshape(fs,K*K,P);
            benzerlik_sayisi=sum(fs==0);
            % bunlardan hangisi max ise onun hareketini yap
            [mi, mm]=max(benzerlik_sayisi); % mm. pattern in hareketini yap
            hareket=hareketsJ(mm);
            temp_pos=[curr_pos(1)+hareketler(hareket,1) curr_pos(2)+hareketler(hareket,2)];
            if (harita(temp_pos(1),temp_pos(2))==1) 
                % hareketini degistir
                hh(j,mm)=mod(hh(j,mm)+randi(3,1,1)-1,4) +1 ;
                break % orasi dolu ise bu bireyi durdur
            else
                curr_pos=temp_pos; % bossa git
                if curr_pos(2)==N % en sola vardýysa bireyi durdur
                    moves(j,k,:)=curr_pos;
                    break
                end
            end
            % hareketi gorsellestirmek icin depolamak lazim curr_pos lari
            moves(j,k,:)=curr_pos; % j.bireyin k. konumu
        end
        % gelinen noktayi degerlendir
        oduller(j)=curr_pos(2); % sola ne kadar yakinsa o kadar iyi
        curr_posS(j,:)=curr_pos; % bireylerin son geldigi yerler 
    end
    [si, sm]=max(oduller); % bu neslin en iyisinin odulu (si) ve indisi (sm)
    odul_ort(i)=mean(oduller);
    
    tempp_pp=pp;
    tempp_hh=hh;
    
    %oduller
    % bireyleri degistir
    % en iyi %best_keep i tut geri kalanina mutasyon uygula
    deg_sayi=round(PS*(1-best_keep));
    [rv ri]=sort(oduller);
    deg_i=ri(1:deg_sayi); % degiseceklerin indisleri
    same_i=ri(deg_sayi+1:end); % ayni kalacaklarin indisleri
    same_sayi=PS-deg_sayi;
    for j=1:deg_sayi
        % pattern leri degistir
        % K*K*P lik dizide degisecek indisleri uret
        birsayi=round(K*K*P*mut_r);
        birler=ones(1,birsayi);
        degisecekler=[birler zeros(1,K*K*P-birsayi)];
        rri=randperm(K*K*P);
        degisecekler=degisecekler(rri); % 1 leri degistir 0 lari ayni birak
        % kotuleri degistir yeni uret
        temp_pp=pp(deg_i(j),:); 
        
        % iyileri degistirip yeni uret
        %rnd_iyi_ind=randi(same_sayi); 
        %temp_pp=pp(same_i(rnd_iyi_ind),:); 
        
        degisecek_indisler=find(degisecekler==1);
        yeni_halleri=abs(temp_pp(degisecek_indisler)-1); % 1 -> 0 , 0 -> 1
        temp_pp(degisecek_indisler)=yeni_halleri;
        pp(deg_i(j),:)=temp_pp; % yenisi eskinin uzerine yaz
        
        
        % hareketi degistir
        % P lik dizide degisecek indisleri uret
        birsayi=ceil(P*mut_r);
        birler=ones(1,birsayi);
        degisecekler=[birler zeros(1,P-birsayi)];
        rri=randperm(P);
        degisecekler=degisecekler(rri); % 1 leri degistir 0 lari ayni birak
        % kotuleri degistir yeni uret
        temp_hh=hh(deg_i(j),:);
        
        % iyileri degistirip yeni uret
%         rnd_iyi_ind=randi(same_sayi); 
%         temp_hh=hh(same_i(rnd_iyi_ind),:); 
        
        degisecek_indisler=find(degisecekler==1);
        yeni_halleri=mod(temp_hh(degisecek_indisler)+randi(3,1,birsayi)-1,4) +1 ; % 1-3 ekle mod4 al 1 ekle 
        temp_hh(degisecek_indisler)=yeni_halleri;
        hh(deg_i(j),:)=temp_hh; % yenisi eskinin uzerine yaz
        
        % hepsinden rasgele sec degistir
%         rnd_ind=randi(P); 
%         temp_hh=hh(rnd_iyi_ind,:); 
%         degisecek_indisler=find(degisecekler==1);
%         yeni_halleri=mod(temp_hh(degisecek_indisler)+randi(3,1,birsayi)-1,4) +1 ; % 1-3 ekle mod4 al 1 ekle 
%         temp_hh(degisecek_indisler)=yeni_halleri;
%         hh(rnd_iyi_ind,:)=temp_hh; % yenisi eskinin uzerine yaz

    end
    
    

end

curr_posS
figure;
plot(odul_ort)

for i=1:HS
    if moves(sm,i,1)>0
    harita(moves(sm,i,1),moves(sm,i,2))=0.5;
    end
end
figure;imshow(imresize(harita,10));
%reshape(tempp_pp(sm,:),K,K,P)
reshape(tempp_pp(sm,:),K*K,P)'
tempp_hh(sm,:)




