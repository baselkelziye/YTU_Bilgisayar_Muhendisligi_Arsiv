function result=myConv(x,n,y,m)
    len=n+m-1;
    result=zeros(1,len);

    for i=1:n
        for j=1:m
            result(i+j-1)=result(i+j-1)+x(i)*y(j);
        end
    end
end

function y=denklem(x,M)
    y=x;
    for i=1:M
        for n=400*i+1:length(x)
            y(n)=y(n)+0.5*i*x(n-400*i);
        end
    end
end
function y=impulseFunc(M)
    h=zeros(1,400*M+1);
    h(1)=1;
    for i=1:M
        h(400*i+1)=0.5*i;
    end
    y=h;
end
function seslendirme(x,name)
    fprintf('Start %s\n',name);
    sound(x,16000);
    pause(length(x)/16000);
    pause(1);
end
%% 1.soru
n=input('x[] uzunlugunu girin : ');
nStart=input('x dizisinin ilk indexini girin : ');
x=zeros(1,n);
for i=1:n
    x(i)=input(sprintf('x[%d] =',i-1+nStart));
end

m=input('y[] uzunlugunu girin : ');
mStart=input('y dizisinin ilk indexini girin : ');
y=zeros(1,m);
for i=1:m
    y(i)=input(sprintf('y[%d] =',i-1+mStart));
end

convStart=nStart+mStart;
resultOfMyConv=myConv(x,n,y,m);
resultOfConv=conv(x,y,"full");
convAxis=convStart:convStart+length(resultOfConv)-1;
%% 2.soru
figure;
subplot(4,1,1);
stem(nStart:nStart+n-1, x, 'filled'); %x[n]
title('x[n]');
xlabel('n'); ylabel('x[n]');

subplot(4,1,2);
stem(mStart:mStart+m-1, y, 'filled'); %y[n]
title('y[n]');
xlabel('n'); ylabel('y[n]');

subplot(4,1,3);
stem(convAxis, resultOfMyConv, 'filled');%myConv
title('myConv(x[n], y[n])');
xlabel('n'); ylabel('Amplitude');

subplot(4,1,4);
stem(convAxis, resultOfConv, 'filled');%conv
title('conv(x[n], y[n])');
xlabel('n'); ylabel('Amplitude');

fprintf('\nx[] -> ');disp(x)
fprintf('y[] -> ');disp(y)
fprintf('myConv[] -> ');disp(resultOfMyConv)
fprintf('conv[] -> ');disp(resultOfConv)

%% 3.soru 
%5 Saniye Ses kaydetme 
recObj = audiorecorder(16000,16,1); %% kayıt başlatma nesnesi
disp('Start speaking for 5s')
recordblocking(recObj, 5); %% kayıt işlemi
disp('End of Recording.')
sound5 = getaudiodata(recObj,'double'); %% kaydedilen sesi x değişkenine saklama
% 10 Saniye Ses kaydetme
disp('Start speaking for 10s')
recordblocking(recObj, 10); 
disp('End of Recording.')
sound10 = getaudiodata(recObj,'double');
%% X1 ve X2 fonksiyonlarinin impulse fonksiyonu ile conv islemleri

resultOfConv5_3=conv(sound5,impulseFunc(3),"full");
resultOfConv5_4=conv(sound5,impulseFunc(4),"full");
resultOfConv5_5=conv(sound5,impulseFunc(5),"full");

resultOfMyConv5_3=myConv(sound5,length(sound5),impulseFunc(3),1201);% M*400+1
resultOfMyConv5_4=myConv(sound5,length(sound5),impulseFunc(4),1601);
resultOfMyConv5_5=myConv(sound5,length(sound5),impulseFunc(5),2001);

resultOfConv10_3=conv(sound10,impulseFunc(3),"full");
resultOfConv10_4=conv(sound10,impulseFunc(4),"full");
resultOfConv10_5=conv(sound10,impulseFunc(5),"full");

resultOfMyConv10_3=myConv(sound10,length(sound10),impulseFunc(3),1201);
resultOfMyConv10_4=myConv(sound10,length(sound10),impulseFunc(4),1601);
resultOfMyConv10_5=myConv(sound10,length(sound10),impulseFunc(5),2001);
%% Seslerin grafikleri
figure;
subplot(2,1,1);
plot(sound5);
title('5s Ses');
subplot(2,1,2);
plot(sound10);
title('10s Ses');
%% Ses sonuclarinin grafiklesmesi
Y5_3=denklem(sound5,3);
Y10_3=denklem(sound10,3);
Y5_4=denklem(sound5,4);
Y10_4=denklem(sound10,4);
Y5_5=denklem(sound5,5);
Y10_5=denklem(sound10,5);

figure;
title('5 saniye');

subplot(3,3,1);
plot(Y5_3);
xlim([0 100000]);title('denklem M=3');

subplot(3,3,4);
plot(resultOfConv5_3);title('conv M=3');

subplot(3,3,7);
plot(resultOfMyConv5_3);title('myConv M=3');

subplot(3,3,2);
plot(Y5_4);
xlim([0 100000]);title('denklem M=4');

subplot(3,3,5);
plot(resultOfConv5_4);title('conv M=4');

subplot(3,3,8);
plot(resultOfMyConv5_4);title('myConv M=4');

subplot(3,3,3);
plot(Y5_5);
xlim([0 100000]);title('denklem M=5');

subplot(3,3,6);
plot(resultOfConv5_5);title('conv M=5');

subplot(3,3,9);
plot(resultOfMyConv5_5);title('myConv M=5');
sgtitle('5 saniye ses grafikleri');

figure;
subplot(3,3,1);
plot(Y10_3);
xlim([0 200000]);title('denklem M=3');

subplot(3,3,4);
plot(resultOfConv10_3);title('conv M=3');

subplot(3,3,7);
plot(resultOfMyConv10_3);title('myConv M=3');

subplot(3,3,2);
plot(Y10_4);
xlim([0 200000]);title('denklem M=4');

subplot(3,3,5);
plot(resultOfConv10_4);title('conv M=4');

subplot(3,3,8);
plot(resultOfMyConv10_4);title('myConv M=4');

subplot(3,3,3);
plot(Y10_5);
xlim([0 200000]);title('denklem M=5');

subplot(3,3,6);
plot(resultOfConv10_5);title('conv M=5');

subplot(3,3,9);
plot(resultOfMyConv10_5);title('myConv M=5');
sgtitle('10 saniye ses grafikleri');
%% sonuclarin seslendirilmesi
seslendirme(sound5,'sound5');
seslendirme(sound10,'sound10');

seslendirme(resultOfMyConv5_3,'myConv t=5 M=3');
seslendirme(resultOfConv5_3,'conv t=5 M=3');
seslendirme(resultOfMyConv5_4,'myConv t=5 M=4');
seslendirme(resultOfConv5_4,'conv t=5 M=4');
seslendirme(resultOfMyConv5_5,'myConv t=5 M=5');
seslendirme(resultOfConv5_5,'conv t=5 M=5');

seslendirme(resultOfMyConv10_3,'myConv t=10 M=3');
seslendirme(resultOfConv10_3,'conv t=10 M=3');
seslendirme(resultOfMyConv10_4,'myConv t=10 M=4');
seslendirme(resultOfConv10_4,'conv t=10 M=4');
seslendirme(resultOfMyConv10_5,'myConv t=10 M=5');
seslendirme(resultOfConv10_5,'conv t=10 M=5');