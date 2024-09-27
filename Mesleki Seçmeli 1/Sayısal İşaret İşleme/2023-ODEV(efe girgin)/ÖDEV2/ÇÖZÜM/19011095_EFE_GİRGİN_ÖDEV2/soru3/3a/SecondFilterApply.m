% Define the filter coefficients
h = [ 1/16,  -1/8,  1/16;
     -1/8,    1/4, -1/8;
      1/16,  -1/8,  1/16];

% Calculate the 2D frequency response of the filter
[H, f1, f2] = freqz2(h, 128, 128);

% Calculate magnitude and phase response
magnitude = abs(H);
phase = angle(H);

% Plot the magnitude response
figure;
mesh(f1, f2, magnitude);
title('Magnitude Response');
xlabel('Frequency (f1)');
ylabel('Frequency (f2)');
zlabel('Magnitude');

% Plot the phase response
figure;
mesh(f1, f2, phase);
title('Phase Response');
xlabel('Frequency (f1)');
ylabel('Frequency (f2)');
zlabel('Phase (radians)');
