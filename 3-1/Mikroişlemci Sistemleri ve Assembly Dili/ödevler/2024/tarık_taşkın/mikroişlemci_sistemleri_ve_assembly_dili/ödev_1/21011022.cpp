#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>

#define pixel_max(a) ((a) <= 255 ? (a) : 255)
#define pixel_min(a) ((a) >= 0 ? (a) : 0)

// Function to read an image in grayscale
unsigned char* readImage(const char* filename, int& width, int& height, int& channels) {
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 1); // Load as grayscale
    if (!image) {
        std::cerr << "Failed to load image: " << stbi_failure_reason() << std::endl;
        return nullptr;
    }
    std::cout << "Image loaded successfully!" << std::endl;
    std::cout << "Width: " << width << ", Height: " << height << ", Channels: " << channels << std::endl;
    return image;
}

// Function to write an image to a PNG file
bool writeImage(const char* filename, unsigned char* image, int width, int height) {
    if (!image) {
        std::cerr << "Image data is null before writing!" << std::endl;
        return false;
    }
    if (width <= 0 || height <= 0) {
        std::cerr << "Invalid image dimensions: width = " << width << ", height = " << height << std::endl;
        return false;
    }
    // For grayscale images, stride is the same as the width
    int stride = width;
    if (stbi_write_png(filename, width, height, 1, image, stride) == 0) {
        std::cerr << "Failed to write the image to file: " << filename << std::endl;
        return false;
    }
    std::cout << "Image written successfully to: " << filename << std::endl;
    return true;
}

int main() {
    // Input and output file paths
    const char* inputFilename = "input_image3.png";
    const char* outputFilename1 = "output_image1.png";
    const char* outputFilename2 = "output_image2.png";

    // Image data variables
    int width, height, channels; // channels = 1 (grayscale)
    unsigned int number_of_pixels;

    // Read the input image
    unsigned char* image = readImage(inputFilename, width, height, channels);
    if (!image) 
        return -1; // Exit if the image failed to load

    // Allocate memory for the output image
    unsigned char* outputImage = new unsigned char[width * height];
    if (!outputImage) {
        std::cerr << "Failed to allocate memory for output image!" << std::endl;
        stbi_image_free(image);
        return -1;
    }

    // image is 1d array 
    // with length = width * height
    // pixels can be used as image[i] 
    // pixels can be updated as image[i] = 100, etc.
    // a pixel is defined as unsigned char
    // so a pixel can be 255 at max, and 0 at min.

    /* -------------------------------------------------------- QUESTION-1 -------------------------------------------------------- */
    
    /* Q-1 Inverse the colors of image. 
    Inverse -> pixel_color = 255 - pixel_color */

    number_of_pixels = width * height;
    __asm {
        MOV ECX, number_of_pixels   // N = width * height
        MOV EBX, image
        MOV EDI, outputImage
        XOR ESI, ESI                // i = 0
        XOR EAX, EAX

        inverseLoop :
        MOV AL, [EBX + ESI]         // AL = image[i]
        NOT AL                      // AL = !image[i] = 255 - image[i]
        MOV [EDI + ESI], AL         // outputImage[i] = AL
        INC ESI
        LOOP inverseLoop        
    }

    // Write the modified image as output_image1.png
    if (!writeImage(outputFilename1, outputImage, width, height)) {
        stbi_image_free(image);
        return -1;
    }
    stbi_image_free(outputImage); // Clear the outputImage.

    /* -------------------------------------------------------- QUESTION-2 -------------------------------------------------------- */
    /* Histogram Equalization */

    outputImage = new unsigned char[width * height];
    if (!outputImage) {
        std::cerr << "Failed to allocate memory for output image!" << std::endl;
        stbi_image_free(image);
        return -1;
    }

    unsigned int* hist = (unsigned int*)malloc(sizeof(unsigned int) * 256);
    unsigned int* cdf = (unsigned int*)malloc(sizeof(unsigned int) * 256);

    // Check if memory allocation succeeded
    if (hist == NULL) {
        std::cerr << "Memory allocation for hist failed!" << std::endl;
        return -1;
    }
    if (cdf == NULL) {
        std::cerr << "Memory allocation for cdf failed!" << std::endl;
        free(hist);
        return -1;
    }

    // Both hist and cdf are initialized as zeros.
    for (int i = 0; i < 256; i++) {
        hist[i] = 0;
        cdf[i] = 0;
    }

    // You can define new variables here... As a hint some variables are already defined.
    unsigned int min_cdf = 0, range;
    number_of_pixels = width * height;

    // Q-2 (a) - Compute the histogram of the input image.
    __asm {
        MOV ECX, number_of_pixels   // N = number_of_pixels
        MOV EDI, hist
        XOR ESI, ESI                // i = 0
        XOR EAX, EAX

        histLoop :
        MOV EBX, image
        MOV AL, [EBX + ESI]         // AL = image[i]
        MOV EBX, EAX
        INC DWORD PTR[EDI + EBX * 4]   // hist[image[i]]++
        INC ESI
        LOOP histLoop        
    }

    /* Q-2 (b) - Compute the Cumulative Distribution Function cdf
                    and save it to cdf array which is defined above. */

    // CDF Calculation (cdf[i] = cdf[i-1] + hist[i])
    
    __asm {
        MOV ECX, 255                // N = 255, cdf[0] dongu disinda tanimlaniyor. 
        MOV EBX, cdf
        MOV EDI, hist
        MOV ESI, 4                  // i = 1

        MOV EAX, [EDI]              // EAX = cdf[0]
        MOV [EBX], EAX              // cdf[0] = hist[0]
        cdfLoop :
        MOV EAX, [EBX + ESI - 4]    // EAX = cdf[i - 1]
        ADD EAX, [EDI + ESI]        // EAX = cdf[i - 1] + hist[i]
        MOV [EBX + ESI], EAX        // cdf[i] = cdf[i - 1] + hist[i]
        ADD ESI, 4
        LOOP cdfLoop        
    }

    /* Q-2 (c) - Normalize the Cumulative Distribution Funtion 
                    that you have just calculated on the same cdf array. */

    // Normalized cdf[i] = ((cdf[i] - min_cdf) * 255) / range
    // range = (number_of_pixels - min_cdf)
    unsigned int cdfSize = 255;
    __asm {
        MOV ECX, 256                // N = 256             
        MOV EBX, cdf
        XOR ESI, ESI                // i = 0

        findMinCdf:
        CMP [EBX + ESI], 0          // cdf[i] > 0 ise min_cdf = cdf[i], 0'dan farkli ilk deger min_cdf olur.
        JBE next                    // cdf[i] <= 0 ise next etiketine atla
        MOV EAX, [EBX + ESI]        // EAX = cdf[i]
        MOV min_cdf, EAX            // min_cdf = EAX
        JMP endLoop                 // min_cdf degeri belirlendikten sonra dongu sonlandirilir.
        next: ADD ESI, 4
        LOOP findMinCdf
        endLoop:

        MOV ECX, 256                // N = 256
        MOV EAX, number_of_pixels   // EAX = number_of_pixels = width * height
        MOV range, EAX              // range = EAX = number_of_pixels
        MOV EAX, min_cdf            // EAX = min_cdf
        SUB range, EAX              // range = number_of_pixels - min_cdf
        XOR ESI, ESI                // i = 0

        normCdfLoop:
        MOV EAX, [EBX + ESI]        // EAX = cdf[i]
        SUB EAX, min_cdf            // EAX = cdf[i] - min_cdf
        XOR EDX, EDX
        MUL cdfSize                 // EAX = (cdf[i] - min_cdf) * 255
        DIV range                   // EAX = ((cdf[i] - min_cdf) * 255) / range
        MOV [EBX + ESI], EAX        // cdf[i] = EAX = ((cdf[i] - min_cdf) * 255) / range
        ADD ESI, 4
        LOOP normCdfLoop        
    }

    /* Q-2 (d) - Apply the histogram equalization on the image.
                    Write the new pixels to outputImage. */
	// Here you only need to get a pixel from image, say the value of pixel is 107
	// Then you need to find the corresponding cdf value for that pixel
	// The output for the pixel 107 will be cdf[107]
	// Do this for all the pixels in input image and write on output image.
    __asm {
        MOV ECX, number_of_pixels   // N = number_of_pixels
        XOR ESI, ESI                // i = 0
        XOR EAX, EAX

        apply:
        MOV EBX, image
        MOV AL, [EBX + ESI]         // AL = image[i]
        MOV EDI, EAX                // EDI = EAX = image[i]
        MOV EBX, cdf
        MOV EAX, [EBX + EDI * 4]      // EAX = cdf[image[i]]
        MOV EBX, outputImage
        MOV [EBX + ESI], AL         // output[i] = cdf[image[i]]
        INC ESI
        LOOP apply        
    }

    // Write the modified image
    if (!writeImage(outputFilename2, outputImage, width, height)) {
        stbi_image_free(image); 
        return -1;
    }

    // Free the image memory
    stbi_image_free(image);
    stbi_image_free(outputImage);

    return 0;
}
