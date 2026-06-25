function [Y]=myconv(x,h,n,m);
H=[h,zeros(1,m)]; %ters çevrilecek olan h fonksiyonuna 
% işlem yapılabilmesi için 0 değerlerinin eklenmesi

for i=1:n+m-1
  Y(i)=0;
  for j=1:m
    if(i-j+1>0)
      Y(i)=Y(i)+x(j)*H(i-j+1);
    else
    end
  end
end
end