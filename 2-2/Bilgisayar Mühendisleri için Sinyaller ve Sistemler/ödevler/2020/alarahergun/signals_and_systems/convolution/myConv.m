function conv_y = myConv(a_y, b_y)
  
%fonksiyonun matlab'deki conv eşdeğeri olması için
%iki değerin de default olarak 1'den başladığını kabul ediyoruz.
  
%oncelikle h[n] fonksiyonunu h[-n] olacak sekilde ayarlamaliyiz.

b_y = flip(b_y);
%ters çevirdiğimizde bu değere ulaşıyoruz

toplam = 0;
b_x = 1:length(b_y); %çalışacağımız indisleri ayarladık
a_x = 1:length(a_y);

%konvolüsyon fonksiyonunun uzunluğunu belirliyoruz
conv_b = a_x(length(a_x))+b_x(length(b_x)) - 1;

%burada fonksiyonun ne kadar kaydırılacağını öğrendik
difference = length(b_y) - 1;
b_x = b_x - difference; %ve ona göre kaydırdık

conv_x = 1:conv_b; %MATLAB fonksiyonu otomatik olarak 1'den başlatıyor
conv_y = zeros(1, length(conv_x));

	
  %indis değerleri aynı olduğu taktirde değerlerini çarpıyoruz
for i = 1:length(conv_x)
   for j = 1:length(a_x)
       for k = 1:length(b_x)
           if b_x(k) == a_x(j)
               toplam = toplam + b_y(k) * a_y(j); 
           end
       end
   end
   conv_y(i) = toplam;
   toplam = 0; %her iterasyonun sonunda toplam'ı sıfırlıyoruz 
   b_x = b_x + 1;
end

stem(conv_x, conv_y); %kolaylık olması için en sonda çizdiriyoruz
end
