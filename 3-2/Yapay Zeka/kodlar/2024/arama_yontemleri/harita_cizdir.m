function harita_cizdir(sehir_sayisi,sehir_koor,sq_sdist)

% simdi yollari gosterelim:
figure;
plot(sehir_koor(:,1),sehir_koor(:,2),'*');
hold on;
for i=1:sehir_sayisi
    text(sehir_koor(i,1),sehir_koor(i,2),int2str(i),'Color','red','FontSize',18);
end
for i=1:sehir_sayisi
    for j=i+1:sehir_sayisi
        if sq_sdist(i,j)>0
            line([sehir_koor(i,1),sehir_koor(j,1)],[sehir_koor(i,2),sehir_koor(j,2)]);
            orta_x=(sehir_koor(i,1)+sehir_koor(j,1))/2;
            orta_y=(sehir_koor(i,2)+sehir_koor(j,2))/2;
            text(orta_x,orta_y,num2str(sq_sdist(i,j)));
        end
    end
end

end
