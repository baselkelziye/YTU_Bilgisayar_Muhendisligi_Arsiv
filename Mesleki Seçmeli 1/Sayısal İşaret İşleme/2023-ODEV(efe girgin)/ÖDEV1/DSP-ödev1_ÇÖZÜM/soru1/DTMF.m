close all   
format long g
                        
key =  ['1','2','3','A'
        '4','5','6','B'
        '7','8','9','C'
        '*','0','#','D'];
[tel,fs]=audioread('tel.wav');  %decode edilmek istenen ses kaydı

sound(tel);
n = 10; %tuş sayısı
len=length(tel); %sinyalin uzunluğu
fprintf("%d",len);
d = floor(len/n); %tuş sesi uzunluğu
T = 1/fs; %periyot
t = (0:d-1)*T; %time vector

num=1:n; %tuşların tutulduğu vector
tell = zeros(n,d);  %her bir tuşun tutulacağı matris
for k=1:n
    tell(k,1:d) = tel((k-1)*d+1:k*d);
    Y = abs(fft(tell(k,:)));
    P = Y/d;
    P1 = P(1:d/2+1);
    P1(2:end-1) = 2*P1(2:end-1);
    f = fs*(0:(d/2))/d;
   
    peak=P1(1); %tepe noktası bulma
for i=2:d/2+1
    if (peak<P1(i))
        peak = P1(i);
        d1=i;
    end
end
    peak=P1(1); %2. tepe noktası bulma
for i=2:d/2+1
    if (i~=d1 && peak<P1(i))
        peak = P1(i);
        d2=i;
    end
end
%tepe noktalarındaki frekans değerleri
    F1=f(d1);   
    F2=f(d2);   
%bulunan frekans değerlerinin hangisinin Low/High Frequency olduğunu belirleme    
    if (F1<F2)
        FL=F1;
        FH=F2;
    else
        FL=F2;
        FH=F1;
    end
%Frekans değerlerine göre tuşların bulunduğu satır ve sütunları belirleme
    if(FL>650 && FL<710)
        L=1;
    elseif(FL>720 && FL<800)
            L=2;
    elseif(FL>810 && FL<900)
            L=3;
    elseif(FL>920)
            L=4;
    end

 if(FH>1150 && FH<1280)
      H=1;
 elseif(FH>1290 && FH<1420)
      H=2;
 elseif(FH>1430 && FH<1560)
      H=3;
 elseif(FH>1570) 
     H=4;
 end
 num(k)=key(L,H);
%fprintf("Number %d is %c\n",k,num(k));

   % figure(k)
   % plot(f,P1) 
   % title(k,['Number ',num(k),' Spectrum'])
   % xlabel('f (Hz)')
  %  ylabel('|P1(f)|')
end
fprintf('\n\tTotal Number is: %s\n',num);
figure(k+1);
plot(tel);
figure(k+2);
stem(tel);