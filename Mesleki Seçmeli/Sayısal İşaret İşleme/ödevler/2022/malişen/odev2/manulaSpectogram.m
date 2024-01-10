function out = manulaSpectogram(x, win, noverlap, nfft)
x = x(:);
n = length(x);
wlen = length(win);
nUnique = ceil((1+nfft)/2); % number of uniqure points
L = fix((n-noverlap)/(wlen-noverlap)); % number of signal frames
out = zeros(L, nUnique);
index = 1:wlen;
    for i = 0:L-1
        xw = win.*x(index);
        % added transformation
        if length(xw) > nfft
            xw = sum(buffer(xw, nfft), 2);
        end
        % end of added transformation
        X = fft(xw, nfft);
        out(i+1, :) = X(1:nUnique);
        index = index + (wlen - noverlap);
    end
end

