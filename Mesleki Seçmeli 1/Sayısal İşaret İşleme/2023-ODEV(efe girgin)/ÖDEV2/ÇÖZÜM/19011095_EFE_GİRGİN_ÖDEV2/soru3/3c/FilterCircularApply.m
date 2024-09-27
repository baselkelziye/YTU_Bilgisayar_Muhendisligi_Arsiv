% Define the filter kernel based on the given coefficients
h = [1/16, -1/8, 1/16; -1/8, 1/4, -1/8; 1/16, -1/8, 1/16];
h = padarray(h, [1 1], 0, 'both'); % padding to account for δ(n-2,m) terms

% Read the input image and convert to grayscale if necessary
img = imread('img.png');
if size(img, 3) == 3
    img = rgb2gray(img);
end

% Apply the filter to the image
filtered_img = conv2(img, h, 'same');

% Compute the 2D FFT of the filtered image and shift the zero frequency component to the center
fft_filtered_img = fftshift(fft2(filtered_img));

% Get the size of the image
[nrows, ncols] = size(filtered_img);

% Define the grid for the frequency domain
[u, v] = meshgrid(1:ncols, 1:nrows);
u = u - ncols/2 - 1; % Shifting to center the origin
v = v - nrows/2 - 1;

% Calculate radius for each point in the frequency domain
radius = sqrt(u.^2 + v.^2);

% Normalize the frequency range
normalized_radius = radius / max(nrows, ncols);

% Create the frequency mask with the given constraints
frequency_mask = (normalized_radius >= 0.01) & (normalized_radius <= 0.45);

% Apply the phase shift at the origin (128, 128)
origin = [128, 128];
angle = atan2((v-origin(2)), (u-origin(1)));
angle_mask = abs(angle - deg2rad(45)) <= deg2rad(1); % within 1 degree

% Combine the frequency mask and the angle mask
combined_mask = frequency_mask & angle_mask;

% Apply the combined mask and phase shift to the FFT of the filtered image
phase_shift = exp(1i * deg2rad(45));
fft_filtered_img_masked = fft_filtered_img .* combined_mask .* phase_shift;

% Perform the inverse 2D FFT to get the final processed image
processed_img = ifft2(ifftshift(fft_filtered_img_masked));

% Display the results
figure, imshow(img), title('Original Image');
figure, imshow(log(1 + abs(fftshift(fft2(double(img))))), []), title('FFT of Original Image');
figure, imshow(abs(processed_img), []), title('Processed Image');
