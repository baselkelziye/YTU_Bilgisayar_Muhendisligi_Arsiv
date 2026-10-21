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
        mov ecx, number_of_pixels // toplam piksel sayisini ecx'e ata
        mov esi, image // input_image
        mov edi, outputImage // output_image

        dongu:
            mov al, byte ptr[esi] // pikseli AL'ye ata
            mov bl, 255 // BL'ye 255 ata
            sub bl, al // 255ten pikseli cikart
            mov byte ptr[edi], bl // outputImage'in indeksine kaydet

            inc esi     // bir sonraki input piksele gec
            inc edi     // bir sonraki output piksele gec
            dec ecx     // dongu degiskenini 1 azalt
            jnz dongu    // dongu degiskeni 0 olana kadar devam et.
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

        mov esi, image           // image
        mov edi, hist           // histogram
        mov ecx, number_of_pixels // number_of_pixels counter'ý

        hist_loop :
            xor eax, eax            // eax sýfýrla
            mov al, byte ptr[esi]  // pixel'i al
            inc dword ptr[edi + eax * 4] // o piksel degeri icin histogram degerini arttir
            inc esi                 // sonraki piksele gec
            loop hist_loop

    }

    /* Q-2 (b) - Compute the Cumulative Distribution Function cdf
                    and save it to cdf array which is defined above. */

    // CDF Calculation (cdf[i] = cdf[i-1] + hist[i])
    
    __asm {

        mov esi, hist           // histogram
        mov edi, cdf            // cdf

        // cdf'in ilk degeri histogramin ilk degeriyle ayni
        mov eax, [esi]
        mov[edi], eax

        mov ecx, 255           // kalan degerler icin 255 dongu

        cdf_loop:
            mov eax, [edi]         // cdf[i-1]'deki degeri eax'te tut
            add esi, 4             // esi hist[i] gösterecek
            add edi, 4             // edi cdf[i] gösterecek
            add eax, [esi]         // cdf[i-1]'e hist[i] ekle
            mov[edi], eax         // cdf[i] = cdf[i-1] + hist[i]  
            loop cdf_loop         // ecx = 0 olana kadar donguye devam et.

    }

    /* Q-2 (c) - Normalize the Cumulative Distribution Funtion 
                    that you have just calculated on the same cdf array. */

    // Normalized cdf[i] = ((cdf[i] - min_cdf) * 255) / range
    // range = (number_of_pixels - min_cdf)

    __asm {
        // 0 olmayan min_cdf'i bulucaz
        mov esi, cdf
        mov ecx, 256           // counter

        //sýfýrdan buyuk ilk elemani minimum olarak set 
        find_first_nonzero:
            mov eax, [esi]     // cdf'i al
            test eax, eax      // 0 mý diye bak
            jnz found_first    // 0 degilse bulduk
            add esi, 4         // eger 0'sa bir sonraki elemana gec
            loop find_first_nonzero

        found_first :
            mov min_cdf, eax       // bulunan 0 olmayan degeri min olarak sakla

            
        min_loop :
            mov eax, [esi]     // cdf'i al
            test eax, eax      // 0 mý diye bak
            jz not_min         // 0'sa geç
            cmp eax, min_cdf
            jae not_min        // degeri minimumla kýyasla, eðer büyükse geç
            mov min_cdf, eax   // eger 0dan büyük ve minimum cdf'ten küçük bir sayý bulursak guncelle
        not_min :
            add esi, 4         
            loop min_loop

            // Calculate range
            mov eax, number_of_pixels
            sub eax, min_cdf
            mov range, eax         // range = number_of_pixels - min_cdf

            // Normalize
            mov esi, cdf
            mov ecx, 256          // counter
        normalize_loop:
            mov eax, [esi]    // cdf'i al
            sub eax, min_cdf  // minimumu cýkart
            mov ebx, 255      // 255le carp
            mul ebx
            div range         // range'e bol
            mov[esi], eax    // normalize olmus degeri sakla
            add esi, 4        // sonraki cdf degerine gec
            loop normalize_loop
    }

    /* Q-2 (d) - Apply the histogram equalization on the image.
                    Write the new pixels to outputImage. */
	// Here you only need to get a pixel from image, say the value of pixel is 107
	// Then you need to find the corresponding cdf value for that pixel
	// The output for the pixel 107 will be cdf[107]
	// Do this for all the pixels in input image and write on output image.
    __asm {

        mov esi, image          // image
        mov edi, outputImage    // output
        mov ecx, number_of_pixels // piksel sayisi

        equalize_loop :
            xor eax, eax
            mov al, byte ptr[esi]  // image pikselini al
            mov ebx, cdf           // CDF listesini al
            mov eax, [ebx + eax * 4] // o pikselin CDF'ini al
            mov byte ptr[edi], al // o pikselin yeni degerini tut
            inc esi                // bir sonraki image pikseline gec
            inc edi                // bir sonraki output pikseline gec
            loop equalize_loop

    }
    /*
    
        printf("Image values: \n");
    for (int i = 0; i < number_of_pixels; i++) {
        printf("%d ", outputImage[i]);
    }
    printf("\n\n\n");
    
    
    */

    

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
