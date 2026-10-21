# MATLAB Signal and Image Processing Applications

This project contains two MATLAB programs focused on fundamental digital signal processing and image processing applications. The first code works on discrete-time convolution, audio recording, echo-system modeling, and system response analysis. The second code performs frequency-domain image filtering using the 2D Fourier Transform to remove periodic noise from an image.

---

## Project Overview

This repository includes two MATLAB scripts:

1. A signal processing script that implements a custom convolution function, compares it with MATLAB's built-in `conv` function, records audio signals, models an LTI echo system, analyzes impulse response, and studies the effects of system parameters.
2. An image processing script that reads a noisy image, transforms it into the frequency domain, detects noise peaks in the Fourier spectrum, applies a notch filter, and reconstructs a cleaner image using inverse Fourier Transform.

Both codes demonstrate practical applications of MATLAB in analyzing signals and images through time-domain and frequency-domain methods.

---

# 1. `Discrete-Time Convolution and Audio Echo System Analysis.m`

## Purpose

The purpose of this code is to implement and verify a custom convolution function, then use it in a discrete-time LTI system that produces echo-like effects on recorded audio signals.

## Main Topics Covered

- Discrete-time convolution
- Custom convolution implementation
- Comparison with MATLAB `conv`
- Mean Squared Error calculation
- Audio recording and playback
- LTI system impulse response
- Echo system modeling
- Parameter analysis using `A` and `M`

## Main Functions

### `myConv(x, nx, y, ny)`

This function calculates the convolution of two discrete-time signals manually.

Inputs:

- `x`: First signal
- `nx`: Index vector of the first signal
- `y`: Second signal
- `ny`: Index vector of the second signal

Outputs:

- `z`: Convolution result
- `nz`: Index vector of the convolution result

The function also checks:

- Empty inputs
- Vector format
- Numeric values
- Equal signal/index lengths
- Consecutive index vectors

### `system_direct(x, M, A)`

This function calculates the output of the echo system directly from the system equation.

The system is:

```matlab
y[n] = x[n] + sum(A*k*x[n - 400k])
```

where:

- `A` controls echo strength
- `M` controls the number of delayed echo components

### `create_h(M, A)`

This function creates the impulse response of the LTI system:

```matlab
h[n] = δ[n] + Σ(A*k)δ[n - 400k]
```

## Data Sets Used for Convolution Test

### Data Set 1: Positive Values

```matlab
x1 = [1 7 9];
nx1 = 0:2;
y1 = [2 3 1];
ny1 = 0:2;
```

This data set is used to test convolution with positive values.

### Data Set 2: Negative and Zero Values

```matlab
x2 = [3 -2 0 4];
nx2 = -1:2;
y2 = [1 0 -2];
ny2 = -1:1;
```

This data set tests the function with negative and zero values.

## Audio Processing Part

The code records two audio signals:

- `X1`: 5-second audio recording
- `X2`: 10-second audio recording

Sampling frequency:

```matlab
fs = 8000;
```

The recordings are saved as:

```text
X1.wav
X2.wav
```

## System Analysis

The code analyzes an LTI system with the following parameters:

```matlab
A = 0.5;
M = 3;
```

The output is calculated in two ways:

1. Direct equation method
2. Convolution with the impulse response

The results are compared with MATLAB's built-in `conv` function using MSE.

## Parameter Analysis

The code studies the effect of changing:

### `M`

```matlab
M_values = [3 4 5];
```

Increasing `M` increases the number of echo components.

### `A`

```matlab
A_values = [0.3 0.8];
```

Increasing `A` increases the amplitude and strength of the echoes.

## Outputs

The script produces:

- Printed convolution results
- MSE values
- Multiple plots for input signals and convolution outputs
- Audio recordings
- Audio playback of original and processed signals
- Parameter analysis plots

---

# 2. `Frequency-Domain Noise Removal from Images Using 2D Fourier Transform.m`

## Purpose

The purpose of this code is to remove periodic noise from an image using frequency-domain filtering.

## Main Topics Covered

- Image reading
- Grayscale conversion
- 2D Fourier Transform
- Fourier spectrum visualization
- Noise peak detection
- Notch filter design
- Inverse Fourier Transform
- Image restoration

## Required Input File

This code requires an image file named:

```text
noisy_image.png
```

The image must be in the same folder as the MATLAB script.

## Processing Steps

### 1. Read the Image

The image is read using:

```matlab
img = imread('noisy_image.png');
```

If the image is RGB, it is converted to grayscale. Then it is converted to double precision using `im2double`.

### 2. Display Image Information

The script prints:

- Image size
- Pixel value range

### 3. Apply 2D Fourier Transform

The Fourier Transform is calculated using:

```matlab
F = fft2(grayImg);
F_shifted = fftshift(F);
```

The shifted spectrum places the low-frequency components at the center.

### 4. Visualize the Frequency Spectrum

The code displays:

- Fourier magnitude spectrum
- Logarithmic Fourier magnitude spectrum

The logarithmic spectrum makes frequency peaks easier to observe.

### 5. Detect Noise Frequencies

The code ignores the center low-frequency area and detects strong frequency peaks outside the center.

Important parameters:

```matlab
centerMaskRadius = 25;
thresholdValue = mean(tempSpectrum(:)) + 2.5 * std(tempSpectrum(:));
num_peak_pairs = 2;
```

The code also finds symmetric peak locations because Fourier noise peaks usually appear in pairs.

### 6. Design a Notch Filter

The filter mask is initialized as all ones:

```matlab
H = ones(rows, cols);
```

Then small circular regions around detected noise peaks are set to zero.

Filter radius:

```matlab
radius = 7;
```

### 7. Apply the Filter

The frequency-domain image is filtered by:

```matlab
G_shifted = F_shifted .* H;
```

### 8. Reconstruct the Image

The image is reconstructed using inverse Fourier Transform:

```matlab
G = ifftshift(G_shifted);
restoredImg = ifft2(G);
restoredImg = real(restoredImg);
```

Finally, the image is normalized to the range `[0, 1]`.

## Outputs

The script produces:

- Original noisy grayscale image
- Fourier magnitude spectrum
- Logarithmic Fourier spectrum
- Detected noise frequency plot
- Frequency-domain filter mask
- Filtered Fourier spectrum
- Restored/cleaned image

---

## Requirements

Recommended MATLAB toolboxes:

- Signal Processing basics
- Image Processing Toolbox
- Audio support functions

Main MATLAB functions used:

```matlab
conv
stem
plot
audiorecorder
recordblocking
getaudiodata
audiowrite
sound
imread
rgb2gray
im2double
fft2
fftshift
ifftshift
ifft2
imshow
```

---

## How to Run

### For `24011949.m`

1. Open MATLAB.
2. Put `24011949.m` in the working folder.
3. Run the script.
4. Allow microphone access when audio recording starts.
5. Speak or create sound during the 5-second and 10-second recordings.
6. Observe the command window outputs, figures, and audio playback.

### For `Sas_24011949(6).m`

1. Open MATLAB.
2. Put `Sas_24011949(6).m` and `noisy_image.png` in the same folder.
3. Run the script.
4. Observe the Fourier spectrum, detected noise peaks, filter mask, and cleaned image.

---

## Notes

- `24011949.m` creates two audio files: `X1.wav` and `X2.wav`.
- `Sas_24011949(6).m` will not run unless `noisy_image.png` exists in the same folder.
- The custom convolution function is validated by comparing it with MATLAB's built-in `conv`.
- MSE values close to zero indicate that the custom convolution implementation works correctly.
- In the image filtering code, the filter radius and number of peak pairs can be adjusted depending on the noise pattern.

---

## Conclusion

These MATLAB codes demonstrate two important applications of signal and image processing:

1. In the first code, convolution is implemented manually and applied to audio-based LTI echo system analysis.
2. In the second code, frequency-domain filtering is used to detect and remove periodic noise from an image.

Together, the codes show how MATLAB can be used to analyze, process, verify, and visualize signals and images effectively.
