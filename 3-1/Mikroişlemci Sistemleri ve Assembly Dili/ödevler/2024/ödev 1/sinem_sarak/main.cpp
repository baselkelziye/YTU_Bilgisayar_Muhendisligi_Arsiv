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
    const char* inputFilename = "lena.png";
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
        XOR ESI, ESI
        MOV EBX, image
        MOV EDI, outputImage

        traverseImageForInverse:
            CMP ESI, number_of_pixels
            JAE doneinversing
            MOV AH, 255
            MOV AL, [EBX + ESI]
            SUB AH,AL
            MOV [EDI+ESI], AH

            INC ESI
            JMP traverseImageForInverse
        doneinversing:
        
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
    unsigned int len = 256;
    number_of_pixels = width * height;

    // Q-2 (a) - Compute the histogram of the input image.

    __asm {
        MOV ECX, number_of_pixels
        MOV ESI, image
        XOR EDI,EDI
        MOV EBX, hist
        
        traverseImageForHist :

            XOR EAX,EAX
            MOV AL, [ESI+EDI]
            MOV DL, 4
            MUL DL
            MOV EDX, [EBX + EAX]   
            INC EDX
            MOV [EBX + EAX], EDX
            INC EDI

        LOOP traverseImageForHist
            doneHist :
        
    }
    /* Q-2 (b) - Compute the Cumulative Distribution Function cdf
                    and save it to cdf array which is defined above. */

    // CDF Calculation (cdf[i] = cdf[i-1] + hist[i])
    /*int i;
    printf("\n histogram: \n");
    for (i = 0;i < 256;i++) {
        printf(" %d ", hist[i]);
    }
    printf("\n-------------\n");
    */
    __asm {
        MOV EBX, hist
        MOV EAX, [EBX] //al = hist[0]
        MOV EDI, cdf 
        MOV [EDI], EAX //cdf[0] = hist[0]

        XOR ESI,ESI
        INC ESI

        makeCDF:
            
            CMP ESI,len
            JAE CDFend

            MOV EAX, [EBX+ESI*4] // al = hist[i]
            DEC ESI
            ADD EAX, [EDI+ESI*4] //al = hist[i] + cdf[i-1]
            INC ESI

            MOV [EDI+ESI*4], EAX


            INC ESI
            JMP makeCDF

        CDFend:

    }

    /*
    printf("\ncdf matrix: \n");
    for(i=0;i<256;i++){
        printf(" %d ", cdf[i]);
    }*/

    /* Q-2 (c) - Normalize the Cumulative Distribution Funtion 
                    that you have just calculated on the same cdf array. */

    // Normalized cdf[i] = ((cdf[i] - min_cdf) * 255) / range
    // range = (number_of_pixels - min_cdf)
    unsigned int min_cdf = number_of_pixels , range;

    __asm {
        
        //find min_cdf:
        MOV ECX,len
        MOV EBX, cdf
        XOR EAX,EAX

        findMinLoop:

            MOV EDX, [EBX + EAX]
            CMP EDX, 0
            JZ notMin

            CMP EDX, min_cdf
            JAE notMin

            MOV min_cdf, EDX

        notMin:     
            ADD EAX,4
        LOOP findMinLoop

        //------------------------------------------------

        MOV EAX, min_cdf
        MOV EDX, number_of_pixels
        SUB EDX,EAX
        MOV range,EDX 

        XOR ESI,ESI
        MOV ECX,len
        MOV EBX,cdf

        normalise:

            
            MOV EAX,[EBX+ESI]
            CMP EAX, 0
            JE  negativeVal

            SUB EAX,min_cdf
            MOV EDX, 255
            MUL EDX

            XOR EDX,EDX
            DIV range

            MOV[EBX+ESI],EAX

            negativeVal:
            ADD ESI,4
            LOOP normalise


    }
    //printf("\nmin cdf: %d", min_cdf);
    /*printf("\n\n normalised cdf:\n");
    for (i = 0;i < 256;i++) {
        printf(" %d ", cdf[i]);
    }*/

    /* Q-2 (d) - Apply the histogram equalization on the image.
                    Write the new pixels to outputImage. */
	// Here you only need to get a pixel from image, say the value of pixel is 107
	// Then you need to find the corresponding cdf value for that pixel
	// The output for the pixel 107 will be cdf[107]
	// Do this for all the pixels in input image and write on output image.
    __asm {
        MOV EBX,image
        MOV EDI, outputImage
        MOV ESI,cdf
        MOV DL,4

        XOR ECX,ECX

        applyhistogram:

            CMP ECX, number_of_pixels
            JAE endofimage
            XOR EAX,EAX
            MOV AL,[EBX+ECX]
            MUL DL
            MOV EAX, [ESI + EAX]
            MOV [EDI + ECX],AL

            INC ECX
            JMP applyhistogram

        endofimage:
        
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
