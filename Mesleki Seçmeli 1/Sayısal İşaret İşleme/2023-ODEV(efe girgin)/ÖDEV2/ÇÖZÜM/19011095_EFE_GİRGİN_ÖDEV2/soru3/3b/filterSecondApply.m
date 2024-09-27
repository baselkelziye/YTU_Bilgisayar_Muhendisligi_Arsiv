% Read the input image (assuming the file is in the current directory)
img = imread('img.png');

% Check if the image is RGB, convert it to grayscale
if size(img, 3) == 3
    img = rgb2gray(img);
end

% Define the filter kernel based on the coefficients
h = [1/16, -1/8, 1/16; -1/8, 1/4, -1/8; 1/16, -1/8, 1/16];

% Pad the filter to make it 5x5 as implied by the delta functions spacing
h_padded = padarray(h, [1 1], 0, 'both');

% Apply the filter to the image
filtered_img = conv2(double(img), double(h_padded), 'same');

% Compute the 2D FFT of the filtered image
fft_img = fft2(filtered_img);
fft_img_shifted = fftshift(fft_img);

% Create a frequency mask according to the given specs
[nrows, ncols] = size(filtered_img);
[u, v] = meshgrid(-(ncols/2):(ncols/2 - 1), -(nrows/2):(nrows/2 - 1));
radius = sqrt(u.^2 + v.^2);
angle_mask = abs(atan2(v,u) - pi/4) < (pi/90); % 45 degrees tolerance

% Normalized frequency constraints
min_freq = 0.01 * nrows;
max_freq = 0.3 * nrows;

% Create a radial mask
freq_mask = (radius >= min_freq) & (radius <= max_freq);

% Combine angle and frequency masks
combined_mask = freq_mask & angle_mask;

% Apply the phase shift of 45 degrees
phase_shift = exp(1i * pi/4);
fft_img_shifted = fft_img_shifted .* combined_mask * phase_shift;

% Perform the inverse FFT
ifft_img_shifted = ifftshift(fft_img_shifted);
result_img = ifft2(ifft_img_shifted);

% Display the original and processed images
figure, imshow(img), title('Original Image');
figure, imshow(log(1 + abs(fftshift(fft2(double(img))))), []), title('FFT of Original Image');
figure, imshow(abs(result_img), []), title('Processed Image with Filter and Frequency Constraints');
