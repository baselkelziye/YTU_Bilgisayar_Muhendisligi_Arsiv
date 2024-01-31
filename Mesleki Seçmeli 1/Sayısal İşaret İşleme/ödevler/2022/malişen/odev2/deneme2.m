
%% data
[data,Fs] = audioread('Audio2.wav');

channel = 1;
signal = data(:,channel);
samples = length(signal);

spectrogram_dB = 100;  
%% decimate
% decim  = 1 ise bisey olmaz
decim = 2;
if decim>1
    signal = decimate(signal,decim);
    Fs = Fs/decim;
end
nfft=200;
window = hamming(nfft);
window = window(:);
win = window;
%disp(win);

 
[sg,fsg,tsg] = myspecgram(signal,win,Fs);  
%[sg,tsg,fsg] = myspecgram(signal,win,Fs);  




% Lineer den FFT cevirimi
sg_dBpeak = 20*log10(abs(sg))+20*log10(2/length(fsg));     
%sg_dBpeak=fft(sg.*hamming(nfft))*4/nfft; % hanning only

% saturation of the dB range : 
% saturation_dB = 60;  % dB range scale (means , the lowest displayed level is XX dB below the max level)
min_disp_dB = round(max(max(sg_dBpeak))) - spectrogram_dB;
sg_dBpeak(sg_dBpeak<min_disp_dB) = min_disp_dB;

% plots spectrogram
figure(2);
imagesc(tsg,fsg,sg_dBpeak);colormap('gray');
%imagesc(fsg,tsg,sg_dBpeak);colormap("hot");
axis('xy');colorbar('vert');grid
title([' Spectrogram / Fs = ' num2str(Fs/2) ' Hz / Delta f = ' num2str(fsg(2)-fsg(1)) ' Hz ']);
xlabel('Time (s)');ylabel('Frequency (Hz)');
%xlabel('Frequency (Hz)');ylabel('Time (s)');


function  [sg,freq_vector,time] = myspecgram(signal,win, Fs)
nfft = length(win); %
Overlap = 0.5;
dt = 1/Fs;
signal = signal(:);
samples = length(signal);

% uzunluk nfft den kisa ise zero ile doldur
if samples<nfft
    s_tmp = zeros(nfft,1);
    s_tmp((1:samples)) = signal;
    signal = s_tmp;
    samples = nfft;
end


   offset = fix(Overlap*nfft);
   noverlap = Overlap*nfft;
   spectnum = fix((samples-noverlap)/(nfft-noverlap));	


    sg = [];
    for i=1:spectnum
        start = (i-1)*offset;
        sw = signal((1+start):(start+nfft)).*win;
        sg = [sg (abs(fft(sw))*4/nfft)];     
        %sg=fft(sw.*hamming(nfft))*4/nfft; % hamming only 
        time(i) = (start+nfft/2)*dt; 
    end


    if rem(nfft,2)    % nfft tek
        select = (1:(nfft+1)/2)';
    else
        select = (1:nfft/2+1)';
    end
    
sg = sg(select,:);
freq_vector = (select-1)*Fs/nfft;

end 