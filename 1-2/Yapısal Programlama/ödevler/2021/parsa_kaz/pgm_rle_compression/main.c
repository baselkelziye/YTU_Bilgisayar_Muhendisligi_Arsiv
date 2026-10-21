/*
    Parsa Kazerooni
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef uint
typedef unsigned int uint; // readability > non-standard
#endif

#define MAXVAL 255 // maxval: default maximum value of a pixel's color 

// <PGM> ......................................................................
typedef struct PGM{
    // can be inherited by P2 and P5 structs
    // int type; // P2->2 P5->5 etc.  #TODO
    uint width, height;
    uint maxval; // range: 0..65536
    uint **raster;
} PGM;

PGM* initPGM(uint width, uint height){
    PGM* newPGM = (PGM*) malloc(sizeof(PGM));
    if (newPGM == NULL){
        fprintf(stderr, "[-] Allocation Error: PGM\n");
        exit(EXIT_FAILURE);
    }
    // PGM ok
    newPGM->width = width;
    newPGM->height = height;

    newPGM->raster = (uint**) malloc(height*sizeof(uint*));
    if(newPGM->raster == NULL){
        fprintf(stderr, "[-]  Allocation Error: PGM.Raster height\n");
        exit(EXIT_FAILURE);
    }
    for (uint i = 0; i < height; i++){
        newPGM->raster[i] = (uint*) malloc(width* sizeof(uint));
        if(newPGM->raster[i] == NULL){
            fprintf(stderr, "[-] Allocation Error: PGM.Raster width\n");
            exit(EXIT_FAILURE);
        }
    }
    // everything OK
    return newPGM;
}
void freePGM(PGM* pgm){
    for (uint i = 0; i < pgm->height; i++){
        free(pgm->raster[i]);
    }
    free(pgm->raster);
    free(pgm);
}

void printPGM(PGM* pgm){
    printf("PGM {\n");
    printf("Width=%u\nHeight=%u\n", pgm->width, pgm->height);
    printf("MaxVal= %u\n", pgm->maxval);
    for(uint i=0; i<pgm->height; i++){
        for(uint j=0; j<pgm->width; j++)
            printf("%u ", pgm->raster[i][j]);
        printf("\n");
    }
    printf("}\n");
}

PGM* freadPGM(FILE *fin){
    // To read the data of a given PGM file stream, and return the PGM object
    char magicWord[2];
    int width, height, maxval;
    int _flag;
    
    // fscanf() + check -> successfull input ( 4 operations should be OK)
    _flag = fscanf(fin, "%s%d%d%d", magicWord, &width, &height, &maxval) == 4;
    // check -> magicWord == P2 or P5
    _flag &= (!strcmp(magicWord, "P2") || !strcmp(magicWord, "P5")); 
    
    if(!_flag){ // input not OK
        fprintf(stderr, "[-] Reading Error: Invalid PGM file!\n");
        exit(EXIT_FAILURE);
    }
    PGM *pgm = initPGM(width, height);
    // if(!pgm) // within initPGM() it exits the program if it failed. 
    // pgm was allocated successfully
    pgm->maxval = maxval;

    // read the Raster Data;
    for(uint i=0; _flag && i<pgm->height; i++){
        for(uint j=0; _flag && j<pgm->width; j++)
            _flag = fscanf(fin ,"%u", &(pgm->raster[i][j])) == 1;
    }
    return pgm;
}

void fwritePGM(FILE* fout, PGM* pgm){
    // Serialize, Write PGM object to the filestream
    // format: http://netpbm.sourceforge.net/doc/pgm.html

    // MagicWord: For now, Only P2
    fprintf(fout, "P2\n");

    // Width Length
    fprintf(fout, "%u %u\n", pgm->width, pgm->height);

    // Maxval
    fprintf(fout, "%u\n", pgm->maxval);

    // Raster
    for(uint i=0; i < pgm->height; i++){
        for(uint j=0; j < pgm->width; j++)
            fprintf(fout, "%u ", pgm->raster[i][j]);
        fprintf(fout, "\n");
    }
    // EOF
}

uint getColorAtIndex(PGM* pgm, uint ind){
    // Flattened Raster
    // get the color value in the raster[row][col]
    // row col determined by ind
    // row = ind / width, col = ind % width;
    if( ind >= pgm->width * pgm->height) // If out of range
        return -1; // == MAX_INT 65535

    return pgm->raster[ind / pgm->width][ind % pgm->width];
}
// uint* getPixelPointerAtIndex(PGM* pgm, uint ind); // useless

// </PGM> .....................................................................
// <RLE> ......................................................................

typedef struct PGM_RLE{
    uint width, height;
    uint size; // # of different colors
    uint *data[2]; // pointer to list of [COUNT, COLOR]
}PGM_RLE;

PGM_RLE* initPGM_RLE(uint width, uint height){
    PGM_RLE* newPGM_RLE = (PGM_RLE*) malloc(sizeof(PGM_RLE));
    if (newPGM_RLE == NULL){
        fprintf(stderr, "[-] Allocation Error: PGM_RLE\n");
        exit(EXIT_FAILURE);
    }

    newPGM_RLE->width = width;
    newPGM_RLE->height = height;
    newPGM_RLE->size = 0;

    // Allocate the *data[]
    // data[0] used for storing colors, data[1]
    newPGM_RLE->data[0] = (uint*) malloc(width * height * sizeof(uint));
    newPGM_RLE->data[1] = (uint*) malloc(width * height * sizeof(uint));
    if (newPGM_RLE->data[0] == NULL || newPGM_RLE->data[1] == NULL){
        fprintf(stderr, "[-] Allocation Error: PGM_RLE.data\n");
        exit(EXIT_FAILURE);
    }
    return newPGM_RLE;
}


void freePGM_RLE(PGM_RLE* pgm_rle){
    free(pgm_rle->data);
    free(pgm_rle);
}


void printPGM_RLE(PGM_RLE* pgm_rle){
    printf("PGM_RLE{\n");
    printf("Width= %u\n", pgm_rle->width);
    printf("Height= %u\n", pgm_rle->height);
    
    printf("<COUNT, COLOR>\n");
    for (uint i = 0; i < pgm_rle->size; i++){
        printf("<%u, %u>\n", pgm_rle->data[0][i], pgm_rle->data[1][i]);
    }

    printf("}\n");
}

void fwritePGM_RLE(FILE* fout, PGM_RLE* pgm_rle){
    // Write the pgme_rle on a file
    // first line : $width $height 
    fprintf(fout, "%u %u\n", pgm_rle->width, pgm_rle->height);
    
    // 2nd..EOF : $color $count
    for (int i = 0; i < pgm_rle->size; i++){
        fprintf (fout, "%u %u\n", pgm_rle->data[0][i], pgm_rle->data[1][i]);
    }
}

PGM_RLE* freadPGM_RLE(FILE* fin){
    // read fin and return the PGM_RLE object
    // format: 
    // WIDTH HEIGHT
    // COUNT1 COLOR1
    // COUNT2 COLOR2
    // ..

    int _flag;
    uint width, height;
    
    _flag = fscanf(fin, "%u%u", &width, &height) == 2; // 2 successfull scans

    if(!_flag){
        fprintf(stderr, "[-] Read Error: PGM_RLE\n");
        exit(EXIT_FAILURE);
    }

    PGM_RLE* pgm_rle = initPGM_RLE(width, height);

    // read RLE data
    uint ind = 0;
    int count, color; // For the sake of readability, #EXTRA #BLOAT
    while (fscanf(fin, "%d%d", &count, &color) != EOF
            && ind < width * height) {
        // A big file more than num of pixels won't be valid.
        pgm_rle->data[0][ind] = count;
        pgm_rle->data[1][ind] = color;
        ind++;
    }
    
    if(!_flag){
        fprintf(stderr, "[-] Read Error: PGM_RLE.data\n");
        exit(EXIT_FAILURE);
    }

    pgm_rle->size = ind;
    // everything OK
    return pgm_rle;
}

int isValidPGM_RLE(PGM_RLE* pgm_rle){
    // to check if a pgm_rle is valid to decode to a pgm
    
    // 1. # of pixels should be equal to width * height
    uint numOfPixels = 0;
    for (uint i=0; i < pgm_rle->size; i++)
        numOfPixels += pgm_rle->data[0][i]; // += count
    if (numOfPixels != pgm_rle->width * pgm_rle->height){
        fprintf(stderr, "[!] invalid RLE Warning: Num of Pixels\n");
        return 0; // Warning: Doesn't Exit(EXIT_FAILURE) like the errors
    }
    // 2. colors in range of 0..maxval
    for (uint i=0; i < pgm_rle->size; i++)
        if (pgm_rle->data[1][i] > MAXVAL){
            fprintf(stderr, "[!] invalid RLE Warning: MaxVal\n");
            return 0;
        }
    // 3. consecutive duplicate colors
    for (uint i=0; i < pgm_rle->size - 1; i++)
        if (pgm_rle->data[1][i] == pgm_rle->data[1][i+1]){
            fprintf(stderr, "[!] invalid RLE Warning: "
                            "Consecutive Duplicate Colors\n");
            return 0;
        }
    // everything OK
    return 1;
}

PGM_RLE* encodePGM_RLE(PGM* pgm){
    // encode a pgm file via RLE approach
    PGM_RLE* pgm_rle = initPGM_RLE(pgm->width, pgm->height);
    // pgm_rle ok; within initPGM_RLE(), program exits if it failed.

    // Read and Encode Raster
    uint size = 0; // will be assigned as pgm_rle->size;
    uint currentColor, count;

    // short * short could overflow ==> used int 
    int rasterLen = pgm->width * pgm->height;
    for (int i=0; i < rasterLen; i++) {
        uint currentColor = getColorAtIndex(pgm, i);
        count = 1;
        while ( i+1 < rasterLen && getColorAtIndex(pgm, i+1) == currentColor){
            count++;
            i++;
        }
        // finished counting, append to data
        pgm_rle->data[0][size] = count;
        pgm_rle->data[1][size] = currentColor;
        size++;
    }
    
    pgm_rle->size = size;
    
    return pgm_rle;
}

PGM* decodePGM_RLE(PGM_RLE* pgm_rle){
    // Decode PGM_RLE to a PGM object
    if ( !isValidPGM_RLE(pgm_rle)){
        fprintf(stderr, "[-] Decode Error: Invalid PGM_RLE\n");
        exit(EXIT_FAILURE);
    }

    PGM* pgm = initPGM(pgm_rle->width, pgm_rle->height);

    // Calculate pgm.maxval
    uint maxval = 0; // getMax(pgm_rle.data.colors)
    for (uint i=0; i < pgm_rle->size; i++)
        if (pgm_rle->data[1][i] > maxval)
            maxval = pgm_rle->data[1][i];
    pgm->maxval = maxval;

    // Generate Raster from RLE data
    uint width = pgm_rle->width; // Readability
    uint count, color; // copy of count, Readability
    uint indx = 0; // used for raster position;
    for (uint i=0; i < pgm_rle->size; i++){
        count = pgm_rle->data[0][i]; //
        color = pgm_rle->data[1][i]; // Readability
        while (count > 0){
            pgm->raster[indx/width][indx%width] = color;
            count--, indx++;
        }
    }
    // (Since PGM_RL Validated) ->
    // -> No need to control unexpected situations like overflow etc.

    // everything OK
    return pgm;
}

// Operations on PGM_RLE
void replaceColor_RLE(PGM_RLE* pgm_rle, uint srcColor, uint destColor){
    // Change all the occurrences of a srcColor to destColor
    for (uint i=0; i < pgm_rle->size; i++)
        if(pgm_rle->data[1][i] == srcColor)
            pgm_rle->data[1][i] = destColor;
}

void changePixel_RLE(PGM_RLE* pgm_rle, uint x, uint y, uint value);
    // Change the value a pixel at Point (x, y) 
    // #LIMITED_TIME to Implement *data[] as a LinkedList


void histogram_RLE(PGM_RLE* pgm_rle){
    // Calculate the frequency of each color
    // The Space Ineffiecent Algorithm
    // --> since MAXVAL as 255 is not big
    uint histogram[MAXVAL+1] = {0};
    for (uint i=0; i < pgm_rle->size; i++)
        histogram[pgm_rle->data[1][i]] += pgm_rle->data[0][i];
    

    printf("Histogram: \n");
    printf("(COLOR -> COUNT)\n");
    for(uint i=0; i < MAXVAL+1; i++){
        if(histogram[i] != 0)
            printf("%u -> %u\n", i, histogram[i]);
    }
}

int main(int argc, char** argv){

    // Parse Command Line Arguments
    enum {
        ENCODE_MODE, 
        DECODE_MODE, 
        UPDATECOLOR_MODE, UPDATEPIXEL_MODE, 
        HISTOGRAM_MODE
    } mode = ENCODE_MODE;

    uint optind = 1;
    if ( optind < argc && argv[optind][0] == '-') {
        switch (argv[optind][1]) {
        case 'e': mode = ENCODE_MODE; break; // -e : encode 'filename'
        case 'd': mode = DECODE_MODE; break; // -d : decode 'filename'
        case 'c': mode = UPDATECOLOR_MODE; break; // -c : Change Color 
        case 'p': mode = UPDATEPIXEL_MODE; break; // -p incomplete
        case 'h': mode = HISTOGRAM_MODE; break; // # TODO differs with --help
        default:
            fprintf(stderr, "Usage: %s [-edcp]"
                            "[filename]\n", argv[0]);
            exit(0);
        }
    }
    else{
        fprintf(stderr, "Usage: %s [-edcp] [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // after - modifier, get filename
    optind = 2; // filename

    // input file name
    char filename[_MAX_FNAME]; // Max file name = 256
    if(argv[optind] != NULL){
        memcpy(filename, argv[optind], (strlen(argv[optind])+1));
    }
    else{
        printf("Enter the pgm filename (ex. input.pgm): ");
        scanf("%s", filename);
    }
    // File
    FILE *fin = fopen(filename, "r");
    if(fin == NULL){
        fprintf(stderr, "[-] Couldn't open the file: \"%s\"\n", filename);
        exit(EXIT_FAILURE);
    }
    // File is OK!
    
    if(mode == ENCODE_MODE){ // ENCODE 
        // Read pgm file
        PGM *pgm = freadPGM(fin);
        fclose(fin);
        
        PGM_RLE *pgm_rle = encodePGM_RLE(pgm);
        
        // Write to file
        char outputfilename[_MAX_FNAME] = "test_encoded.txt"; // #TODO dynamic
        FILE *fout = fopen(outputfilename, "w"); // overwrite mode
        if(fout == NULL){
            fprintf(stderr, "[-] Couldn't open the file: \"%s\"\n", outputfilename);
            exit(EXIT_FAILURE);
        }
        // write encoded file
        fwritePGM_RLE(fout, pgm_rle);
        fclose(fout);

        free(pgm_rle);
        freePGM(pgm);
    }
    else if (mode = DECODE_MODE){
        PGM_RLE* pgm_rle = freadPGM_RLE(fin);

        // Decode
        PGM* pgm = decodePGM_RLE(pgm_rle);

        // Write to file
        char outputfilename[_MAX_FNAME] = "dencoded.pgm"; // #TODO dynamic
        FILE *fout = fopen(outputfilename, "w"); // overwrite mode
        if(fout == NULL){
            fprintf(stderr, "[-] Couldn't open the file: \"%s\"\n", outputfilename);
            exit(EXIT_FAILURE);
        }
        // write decoded pgm
        fwritePGM(fout, pgm);
        fclose(fout);

        free(pgm_rle);
        freePGM(pgm);
    }
    else if (mode == UPDATECOLOR_MODE){
        PGM_RLE* pgm_rle = freadPGM_RLE(fin);

        uint srcColor, destColor;
        printf("Enter srcColor destColor:\n");
        scanf("%d%d", &srcColor, &destColor);

        // replace
        replaceColor_RLE(pgm_rle, srcColor, destColor);

        // write
        char outputfilename[_MAX_FNAME] = "test_encoded.txt"; // #TODO dynamic
        FILE *fout = fopen(outputfilename, "w"); // overwrite mode
        if(fout == NULL){
            fprintf(stderr, "[-] Couldn't open the file: \"%s\"\n", outputfilename);
            exit(EXIT_FAILURE);
        }
        // write encoded file
        fwritePGM_RLE(fout, pgm_rle);
        fclose(fout);

        free(pgm_rle);
    }
    else if (mode == HISTOGRAM_MODE){
        PGM_RLE* pgm_rle = freadPGM_RLE(fin);


        // histogram
        histogram_RLE(pgm_rle);

        free(pgm_rle);
    }
    
    
    

    
    // ..........................................................................
    

    
    

}