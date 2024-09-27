% Read the input image
img = imread('img.png');

% Check if the image is grayscale; if not, convert to grayscale
if ndims(img) == 3
    img = rgb2gray(img);
end

% Define the filter based on the given coefficients
filter = (1/9) * [1 1 1; 1 1 1; 1 1 1];

% Apply the filter to the image
filtered_img = conv2(double(img), filter, 'same');

% Perform FFT and shift the origin to the center
fft_img = fft2(filtered_img);
fft_img_shifted = fftshift(fft_img);

% Define the phase and frequency requirements
min_freq = 0.01;
max_freq = 0.45;
phase = 45; % degrees

% Apply the frequency constraints and phase shift
[nrows, ncols] = size(filtered_img);
[u, v] = meshgrid(-(ncols/2):(ncols/2 - 1), -(nrows/2):(nrows/2 - 1));
radius = sqrt(u.^2 + v.^2);

% Create a mask for the frequency constraints
freq_mask = (radius >= min_freq * max(nrows, ncols)) & (radius <= max_freq * max(nrows, ncols));

% Apply the phase shift at the origin
phase_shift = exp(1i * deg2rad(phase));
fft_img_shifted = fft_img_shifted .* freq_mask .* phase_shift;

% Shift back and perform inverse FFT
ifft_img_shifted = ifftshift(fft_img_shifted);
result_img = ifft2(ifft_img_shifted);

% Display the results
figure, imshow(img), title('Original Image');
figure, imshow(abs(result_img), []), title('Filtered Image with Frequency Constraints and Phase Shift');
