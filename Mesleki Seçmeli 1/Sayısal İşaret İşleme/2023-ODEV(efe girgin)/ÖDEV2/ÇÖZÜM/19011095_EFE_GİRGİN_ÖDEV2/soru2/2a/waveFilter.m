% Define the filter coefficients
coefficients = ones(3) / 9;  % 3x3 matrix filled with 1/9

% Define the frequency range for both dimensions
omega = linspace(-pi, pi, 100);
[O1, O2] = meshgrid(omega, omega);

% Initialize the frequency response matrix
H = zeros(size(O1));

% Calculate the frequency response of the filter
for n1 = -1:1
    for n2 = -1:1
        H = H + coefficients(n1+2, n2+2) * exp(-1j * (n1 * O1 + n2 * O2));
    end
end

% Compute magnitude and phase response
magnitude_response = abs(H);
phase_response = angle(H);

% Plot the magnitude response
figure;
subplot(1, 2, 1);
mesh(O1, O2, magnitude_response);
title('Magnitude Response');
xlabel('Frequency \omega_1');
ylabel('Frequency \omega_2');
zlabel('Magnitude');
colormap jet;  % Color scheme

% Plot the phase response
subplot(1, 2, 2);
mesh(O1, O2, phase_response);
title('Phase Response');
xlabel('Frequency \omega_1');
ylabel('Frequency \omega_2');
zlabel('Phase');
colormap jet;  % Color scheme

% Display the plots
