% Read the image
img = imread('img.png'); % Corrected path
if size(img, 3) == 3
    img = rgb2gray(img); % Convert to grayscale if it's a color image
end

% Define the filter coefficients based on 2a
filterCoefficients = ones(3, 3) / 9;

% Apply the 2D FIR filter using conv2 function
filteredImg = conv2(double(img), filterCoefficients, 'same');

% Display the original and filtered images
figure;
subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(filteredImg, []);
title('Filtered Image');

% Save the filtered image to file
filteredImagePath = 'C:\\Users\\MONSTER\\Desktop\\2b\\filtered_image.png'; % Save in the same directory as the input image
imwrite(uint8(filteredImg), filteredImagePath);
