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
    //char pixel_color = 255;
    __asm {
        // Your assembly code here...
        MOV ECX, number_of_pixels
        XOR ESI, ESI
        MOV DH, 255
        L1:
            MOV EBX, image
            MOV AL, [EBX + ESI]
            MOV DL, DH
            SUB DL, AL
            MOV EBX, outputImage
            MOV [EBX + ESI], DL
            INC ESI
            LOOP L1
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
    unsigned int min_cdf, range;
    number_of_pixels = width * height;
       
    // Q-2 (a) - Compute the histogram of the input image.
    __asm {
        // Your assembly code here...
        MOV ECX, number_of_pixels
        XOR ESI, ESI
        
        L2:
            MOV EBX, image
            XOR EAX, EAX
            MOV AL, [EBX + ESI]
            MOV EDI, EAX
            MOV EBX, hist
            INC DWORD PTR [EBX + EDI * 4] //hist dizisi int olduðundan dolayý indexi 4le çarptýk
            INC ESI
            LOOP L2
    }

    /* Q-2 (b) - Compute the Cumulative Distribution Function cdf
                    and save it to cdf array which is defined above. */

    // CDF Calculation (cdf[i] = cdf[i-1] + hist[i])
    
    __asm {
        // Your assembly code here...
        MOV EBX, hist
        MOV EAX, [EBX]
        MOV EBX, cdf
        MOV [EBX], EAX //cdf[0] = hist[0]
        MOV ECX, 255
        XOR ESI, ESI
        ADD ESI, 4 //cdf[1]'den baþlýyor
        L3:
            MOV EBX, hist
            MOV EAX, [EBX + ESI] //hist[i]
            MOV EBX, cdf
            MOV EDX, [EBX + ESI - 4] //cdf[i-1]
            ADD EAX, EDX
            MOV [EBX + ESI], EAX
            ADD ESI, 4
            LOOP L3
    }
   
    /* Q-2 (c) - Normalize the Cumulative Distribution Funtion 
                    that you have just calculated on the same cdf array. */

    // Normalized cdf[i] = ((cdf[i] - min_cdf) * 255) / range
    // range = (number_of_pixels - min_cdf)

    __asm {
        // Your assembly code here...
        MOV EBX, cdf
        L_min: //cdf'deki ilk nonzero element min_cdf olacak
            MOV EAX, [EBX]
            TEST EAX, EAX //eðer EAX sýfýr ise zf 1 olur
            JNZ FOUND
            ADD EBX, 4
            JMP L_min
        FOUND:
            MOV min_cdf, EAX
  
        MOV EAX, number_of_pixels
        SUB EAX, min_cdf
        MOV range, EAX 
        MOV EBX, cdf
        MOV ECX, 256
        XOR ESI, ESI
        L4:
            MOV EAX, [EBX + ESI]
            SUB EAX, min_cdf
            MOV EDI, 255
            MUL EDI
            MOV EDI, range
            DIV EDI
            MOV [EBX + ESI], EAX
            ADD ESI, 4
            LOOP L4
    }

    /* Q-2 (d) - Apply the histogram equalization on the image.
                    Write the new pixels to outputImage. */
	// Here you only need to get a pixel from image, say the value of pixel is 107
	// Then you need to find the corresponding cdf value for that pixel
	// The output for the pixel 107 will be cdf[107]
	// Do this for all the pixels in input image and write on output image.
    
    __asm {
        // Your assembly code here...
        MOV ECX, number_of_pixels
        XOR ESI, ESI

        L5:
            MOV EBX, image
            XOR EAX, EAX
            MOV AL, [EBX + ESI]
            MOV EDI, EAX
            MOV EBX, cdf
            MOV EAX, [EBX + EDI * 4] //cdf dizisi int olduðundan dolayý 4le çarptýk
            MOV EBX, outputImage
            MOV [EBX + ESI], AL
            INC ESI
            LOOP L5
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
