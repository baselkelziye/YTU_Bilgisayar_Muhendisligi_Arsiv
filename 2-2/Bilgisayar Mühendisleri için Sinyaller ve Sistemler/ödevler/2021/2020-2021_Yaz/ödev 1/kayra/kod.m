clear all
clc
n=input('Lutfen ilk isaretin eleman sayisini giriniz');
k=input('Lutfen ilk isaretin ilk elemaninin yatay degerini giriniz');
m=input('Lutfen ikinci isaretin eleman sayisini giriniz');
l=input('Lutfen ikinci isaretin ilk elemaninin yatay degerini giriniz');
for i=1:1:n
 fprintf('Lutfen ilk isaretin %d elemanini giriniz',i);
 x(i)=input('');
end
for i=1:1:m
 fprintf('Lutfen ikinci isaretin %d elemanini giriniz',i);
 y(i)=input('');
end
y1n=conv(x,y);
for i=1:1:m+n-1
 if i>m
 y(i)=0;
 end
 if i>n
 x(i)=0;
 end
end
cks=k+l:k+l+m+n-2;
for i=1:1:m+n-1
 grs(i)=0;
end
for i=1:1:m+n-1
 for j=1:1:i
 if j<=m && i-j+1<=n
 grs(i)=grs(i)+x(i-j+1)*y(j);
 end

 end
end
figure(1);
subplot(1,2,1);
stem(cks,grs,'Linewidth',3);
grid on
xlabel('n');
ylabel('y ekseni');
title('Kendi kodum');
subplot(1,2,2);
stem(cks,y1n,'Linewidth',3);
grid on
xlabel('n');
ylabel('y ekseni');
title('Hazır kod');
cat(1,x,y,grs,y1n)