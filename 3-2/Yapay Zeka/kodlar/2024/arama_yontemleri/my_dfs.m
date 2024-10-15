function [sehir_dizi,maliyet,ss,cc] = my_dfs_v2(sq_sdist,bas_i,son_i,liste_goster)

% depth first search ile bas_i ile son_i arasinda yol (sehir_dizi) bulur,
% maliyet ini bulur,
% ss: listenin buyuklugunun zaman icinde degisimi
% cc: listeden eleman cekme sayisi
% liste_goster==1 ise her adimdaki listeyi ekrana yazar

import java.util.Stack
s=Stack();
m=Stack();
%item.sehir_dizi=bas_i;
%item.maliyet=0;
%s.push(item);
sehir_dizi=bas_i;
maliyet=0;
s.push(sehir_dizi);
m.push(maliyet);
% item i java objesine donusturmek gerekiyor galiba??

bulundu=0;
ss=zeros(1,10000); % her bir secimdeki stack size i tutar
cc=1; % secim sayisini tutar
while bulundu~=1 && s.isEmpty()~=1
    if liste_goster==1
        % stack in mevcut halini yazdiralim:
        yed_s=Stack();
        yed_m=Stack();
        yed_s=s.clone();
        yed_m=m.clone();
        sd={};
        mm=[];
        t=1;
        while yed_s.isEmpty()~=1
            sd{t}=yed_s.pop();
            mm(t)=yed_m.pop();
            t=t+1;
        end
        stc={};
        for i=t-1:-1:1
            stc{i}=[int2str(sd{i}') ' M= ' num2str(mm(i))];
        end
        
        stc
    end
    ss(cc)=size(s); cc=cc+1;
    
    sehir_dizi=s.pop();
    maliyet=m.pop();
    csehir=sehir_dizi(end);
    if csehir==son_i
        bulundu=1;
    else
        gidilen_sehirler=find(sq_sdist(csehir,:));
        if size(gidilen_sehirler,2)>0 % gidilen þehir varsa
            for i=1: size(gidilen_sehirler,2) % teker teker ekle stack e
                if ismember(gidilen_sehirler(i),sehir_dizi)==0 % zaten gidilmemisse
                    ysehir_dizi = [sehir_dizi' gidilen_sehirler(i)];
                    ymaliyet    = maliyet+sq_sdist(gidilen_sehirler(i),csehir);
                    s.push(ysehir_dizi);
                    m.push(ymaliyet);
                end
            end
        end
    end
    
end
ss=ss(1:cc-1);
cc=cc-1;
end