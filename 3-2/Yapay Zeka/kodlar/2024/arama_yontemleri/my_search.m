clear all;
close all;

% arama algoritmalarinin 2 sehir arasi yol bulmada performanslarini görelim
% harita olustur
sehir_sayisi=8;
% sehir koordinatlarý (0-100) arasinda olusturuluyor
ekm=0; 
ekv=0;
% tum olasi yollarýn en uzunlarýndan ne kadarini silsin
sil_oran=0.2;  % yogun harita icin kucuk deger
%[sehir_koor,mesafe_matrisi] = harita_olustur(sehir_sayisi,ekm,ekv,sil_oran);
%save 'h4.mat' sehir_koor mesafe_matrisi sehir_sayisi;

load h1.mat
harita_cizdir(sehir_sayisi,sehir_koor,mesafe_matrisi);

% bas ve son sehirleri secelim
son_i=1;
hedef_uz=pdist2(sehir_koor,sehir_koor(son_i,:)); % hedefe kus ucusu mesafeler
[V bas_i]=max(hedef_uz); % son_i ye en uzak sehri secelim

liste_goster=0; % algoritma her adimda listeyi gostersin mi?


[sehir_dizi_bfs,maliyet_bfs,liste_buyuklugu_bfs,adimsayisi_bfs] = my_bfs(mesafe_matrisi,bas_i,son_i,liste_goster);
X=['breadth first yol=' num2str(sehir_dizi_bfs')]; disp(X);

[sehir_dizi_as,maliyet_as,liste_buyuklugu_as,adimsayisi_as] = my_astar(mesafe_matrisi,bas_i,son_i,hedef_uz,liste_goster);
X=['astar yol=' num2str(sehir_dizi_as')]; disp(X);

[sehir_dizi_bsfs,maliyet_bsfs,liste_buyuklugu_bsfs,adimsayisi_bsfs] = my_bestfs(mesafe_matrisi,bas_i,son_i,hedef_uz,liste_goster);
X=['best first yol=' num2str(sehir_dizi_bsfs')]; disp(X);

[sehir_dizi_ucs,maliyet_ucs,liste_buyuklugu_ucs,adimsayisi_ucs] = my_ucs(mesafe_matrisi,bas_i,son_i,liste_goster);
X=['uniform cost yol=' num2str(sehir_dizi_ucs')]; disp(X);

[sehir_dizi_dfs,maliyet_dfs,liste_buyuklugu_dfs,adimsayisi_dfs] = my_dfs(mesafe_matrisi,bas_i,son_i,liste_goster);
X=['depth first yol=' num2str(sehir_dizi_dfs')]; disp(X);

%adim_sayilari=[adimsayisi_ucs adimsayisi_bfs adimsayisi_dfs adimsayisi_as adimsayisi_bsfs];
%liste_buyuklukleri=[liste_buyuklugu_ucs liste_buyuklugu_bfs liste_buyuklugu_dfs liste_buyuklugu_as liste_buyuklugu_bsfs];
%sort(adim_sayilari)

figure;
plot(liste_buyuklugu_ucs);
xlabel('adým no');
ylabel('liste boyutu');
hold on
plot(liste_buyuklugu_bfs);
plot(liste_buyuklugu_dfs);
plot(liste_buyuklugu_as);
plot(liste_buyuklugu_bsfs);
legend('ucs','bfs','dfs','astar','bestfs');
title({['maliyetler: dfs=' num2str(maliyet_dfs) ' bfs=' num2str(maliyet_bfs) ' ucs=' num2str(maliyet_ucs) ' bsfs=' num2str(maliyet_bsfs) ' as=' num2str(maliyet_as)];...
    ['adimsayilari: dfs=' num2str(adimsayisi_dfs) ' bfs=' num2str(adimsayisi_bfs) ' ucs=' num2str(adimsayisi_ucs) ' bsfs=' num2str(adimsayisi_bsfs) ' as=' num2str(adimsayisi_as)]});

% haritalar: h1 h2 h3
% yorumlar:
% ucs optimal ama adým sayýsý genelde bfs den buyuk: cunku hep en kucuk adýmlarý atýyor
% bfs en az sayýda sehir iceren yollarlardan birini buluyor
% yogun haritalarda listeler (dfs haricinde) hizla buyuyor




