clc
clear all
t=input('x[t] işaretinin en büyük üssünü giriniz');
y=input('y[t] işaretinin en büyük üssünü giriniz');
j=t;
for i=1:1:t+1;
    
    fprintf('Lutfen x[t] işaretinin üssü %d olanın katsayisini giriniz',j);
    j=j-1;
a(i)=input('');
end
j=y;
for i=1:1:y+1;
    fprintf('Lutfen y[t] işaretinin üssü %d olanın katsayisini giriniz',j);
    j=j-1;
b(i)=input('');
end
[b,a] = eqtflength(b,a);
[z,p,k] = tf2zp(b,a)
fvtool(b,a,'polezero')
text(real(z)+.1,imag(z),'Zero')
text(real(p)+.1,imag(p),'Pole')




t=input('x[t] işaretinin en büyük üssünü giriniz');
y=input('y[t] işaretinin en büyük üssünü giriniz');
j=t;
for i=1:1:t+1;
    
    fprintf('Lutfen x[t] işaretinin üssü %d olanın katsayisini giriniz',j);
    j=j-1;
a(i)=input('');
end
j=y;
for i=1:1:y+1;
    fprintf('Lutfen y[t] işaretinin üssü %d olanın katsayisini giriniz',j);
    j=j-1;
b(i)=input('');
end
[b,a] = eqtflength(b,a);
[z,p,k] = tf2zpk(b,a)
fvtool(b,a,'polezero')
text(real(z)+.1,imag(z),'Zero')
text(real(p)+.1,imag(p),'Pole')


