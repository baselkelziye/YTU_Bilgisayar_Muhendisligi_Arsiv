%% myConv Function
function result = myConv(x, n, y, m)
convSize = n + m - 1;
result = zeros(1, convSize);

for i=1:1:convSize
    k = max(i - m + 1, 1);

    while k <= length(x) && k <= i
        result(i) = result(i) + x(k) * y(i - k + 1);
        k = k + 1;
    end
end
end

%% Section - 1
%% Input ile conv islemi
function section1()
fprintf('Zero Indexes are starting from 1 not 0 (for matlab)\n\n');

x = input('Enter array x with [ ] around them example: [1, 2, 3] = '); 

%% Kullanicinin indexleri dogru girdigi varsayilmistir

zeroIndexOfX = input('Enter index of zero in array X = ');
fprintf('x: [%s]', join(string(x), ','));
fprintf(', zero index: %d\n', zeroIndexOfX);

y = input('Enter array y with [ ] around them example: [1, 2, 3] = '); 

zeroIndexOfY = input('Enter index of zero in array Y = ');

fprintf('y: [%s]', join(string(y), ','));
fprintf(', zero index: %d\n', zeroIndexOfY);

result = myConv(x, length(x), y, length(y));

zeroIndexOfResult = zeroIndexOfX + zeroIndexOfY - 1;

fprintf('\nresult: [%s]', join(string(result), ','));
fprintf(', zero index: %d\n', zeroIndexOfResult);
end

%% Section - 2 
%% Rastgele inputlar ile conv islemi
function section2()


for i=1:1:2
a = randi([0 9],1, randi(5)); %% Dizi sınırlar içerisinde oluşturulur
aZeroIndex = mod(randi(5), length(a)) + 1; %% Rastgele bir sıfır noktası seçilir

aX = int32(zeros(1, length(a))); %% X ekseni için dizi oluşturulur

for i=length(a):-1:1
    aX(i) = i - aZeroIndex;
end

b = randi([0 9],1, randi(5));
bZeroIndex = mod(randi(5), length(b)) + 1;
bX = int32(zeros(1, length(b)));

for i=length(b):-1:1
    bX(i) = i - bZeroIndex;
end

resultSize = length(a) + length(b) - 1;

rMy = myConv(a, length(a), b, length(b));
rMyX = zeros(1, resultSize);

rZeroIndex = aZeroIndex + bZeroIndex - 1;

for i=resultSize:-1:1
    rMyX(i) = i - rZeroIndex;
end

rMatlab = conv(a, b);
rMatlabX = zeros(1, resultSize);
for i=resultSize:-1:1
    rMatlabX(i) = i - rZeroIndex;
end

fprintf('\nX[N]: [%s], Zero Index = %d', join(string(a), ','), aZeroIndex);
fprintf('\nY[M]: [%s], Zero Index = %d', join(string(b), ','), bZeroIndex);
fprintf('\nmyConv:     [%s], Zero Index = %d', join(string(rMy), ','), rZeroIndex);
fprintf('\nmatlabConv: [%s], Zero Index = %d\n', join(string(rMatlab), ','), rZeroIndex);

figure
t = tiledlayout(2,2);
ax1 = nexttile;
stem(aX, a);
title(ax1, 'Input A')

ax2 = nexttile;
stem(bX, b);
title(ax2, 'Input B')

ax3 = nexttile;
stem(rMyX, rMy);
title(ax3, 'myConv')

ax4 = nexttile;
stem(rMatlabX, rMatlab);
title(ax4, 'Matlab Conv')
end
end

%% Section - 3
function audioData = record(n)

%% Ses kaydetme
recObj = audiorecorder(8000, 16, 1);
disp('Start speaking.')
recordblocking(recObj, n); 
disp('End of Recording.'); 
audioData = getaudiodata(recObj);
end

%% Section - 4
function system(x)
A = 0.5; %% Sistemin siddeti
delay = 400; %% Gecikme
lengthX = length(x) / 8000;

%% Impulse Response Olustur
for M = 3:1:5
h = zeros(1, delay * M + 1);
h(1) = 1;
for k = 1:M
    h(400 * k + 1) = A * k;
end

myY = myConv(x, length(x), h, length(h));
y = conv(x, h);

figure('Name', " Saniye = " + lengthX + ", M = " + M + "", 'NumberTitle', 'off');
t = tiledlayout(3,1);
ax1 = nexttile;
plot(x);
title(ax1, 'Input')
ax2 = nexttile;
plot(myY);
title(ax2, 'myConv')
ax3 = nexttile;
plot(y);
title(ax3, 'Matlab Conv')
fprintf('\nmyConv çıktısı caliniyor: Saniye = %d, M = %d\n', lengthX, M);
sound(myY);
pause(lengthX);
fprintf('\nMatlab Conv çıktısı caliniyor: Saniye = %d, M = %d\n', lengthX, M);
sound(y);
pause(lengthX);
end
end


function section4()

disp('5 saniyelik ses kaydediliyor.')
x1 = record(5);
disp('Sesiniz:')
sound(x1);
disp('Ara veriliyor')
pause(10);
disp('10 saniyelik ses kaydediliyor.')
x2 = record(10);
disp('Sesiniz:')
sound(x2);
pause(15);

disp('Sistem uygulaniyor');
system(x1);
pause(1);
system(x2);
end

%% RUN

selection = input('Hangi bolum calistirilsin? (1 - 2 - 4): ');

switch selection
    case 1
        section1();
    case 2
        section2();
    case 4
        section4();
    otherwise
        disp('Gecersiz input');
end