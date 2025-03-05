clear all
a=[0.028, 0.056, 0.110, 0.083, 0.042, 0.014, 0.014, 0.014, 0.028, 0.069, 0.125, 0.139, 0.125, 0.083, 0.056, 0.014];

figure
bar(a);

b(1)=a(1);
for i=2:16
  b(i)=b(i-1)+a(i);
endfor

figure
bar(b)

for i=1:100
  c(i)=rand;
endfor
c=sort(c);

j=1;
for i=1:100
  while(c(i)>b(j) && j<=16)
    j=j+1;
  endwhile
  s(i)=j;
endfor

for i=1:16
  bin(i)=sum(s==i);
endfor

figure
bar(bin)
